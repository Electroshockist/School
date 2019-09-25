#include "ShaderHandler.h"

std::unique_ptr<ShaderHandler> ShaderHandler::shaderInstance = nullptr;

std::map<std::string, GLuint> ShaderHandler::programs = std::map<std::string, GLuint>();


ShaderHandler::ShaderHandler() {}

ShaderHandler::~ShaderHandler() {
	onDestroy();
}

void ShaderHandler::onDestroy() {
	for(auto index : programs) {
		glDeleteProgram(index.second);
	}
	programs.clear();
}

std::string ShaderHandler::readShader(const std::string & fileName) {
	std::string shaderCode;
	std::ifstream file;
	file.exceptions(std::ifstream::badbit);
	try {
		file.open(fileName.c_str());
		std::stringstream tmpStream;
		tmpStream << file.rdbuf();
		file.close();
		shaderCode = tmpStream.str();
	}
	catch(const std::ifstream::failure error) {
		Debug::error("Could not read shader at " + fileName, __FILE__, __LINE__);
		return "";
	}
	return shaderCode;
}

GLuint ShaderHandler::createShader(GLenum shaderType, const std::string & source, const std::string & shaderName) {
	GLint compileResult = 0;
	GLuint shader = glCreateShader(shaderType);
	const char* shaderCode = source.c_str();
	const GLint shaderSize = source.size();
	glShaderSource(shader, 1, &shaderCode, &shaderSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if(!compileResult) {
		GLint logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> shaderLog(logLength);
		glGetShaderInfoLog(shader, logLength, NULL, &shaderLog[0]);
		std::string logString(shaderLog.begin(), shaderLog.end());
		Debug::error("Shader " + shaderName + " failed to compile. " + shaderLog[0], __FILE__, __LINE__);
	}
	return shader;
}

ShaderHandler * ShaderHandler::getInstance() {
	if(shaderInstance.get() == nullptr) {
		shaderInstance.reset(new ShaderHandler());
	}
	return nullptr;
}

void ShaderHandler::createProgram(const std::string & shaderName, const std::string & vertexShaderFileName, const std::string & fragmentShaderFileName) {
	std::string vertexShaderCode = readShader(vertexShaderFileName);
	std::string fragmentShaderCode = readShader(fragmentShaderFileName);

	GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderCode, shaderName);
	GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderCode, shaderName);

	GLint linkResult = 0;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

	if(!linkResult) {
		GLint logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> programLog(logLength);
		glGetProgramInfoLog(program, logLength, NULL, &programLog[0]);
		std::string logString(programLog.begin(), programLog.end());
		Debug::error("Shader " + shaderName + " failed to link. " + programLog[0], __FILE__, __LINE__);
		return;
	}
	programs[shaderName] = program;
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

const GLuint ShaderHandler::getShader(const std::string & shaderName) {
	if(programs.find(shaderName) != programs.end()) {
		return programs[shaderName];
	}
	return 0;
}
