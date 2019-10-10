#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H
#include <sstream>
#include <map>
#include <vector>
#include <memory>
#include <glew.h>
#include "../Core/Debug.h"

class ShaderHandler{
	ShaderHandler();
	~ShaderHandler();

	static std::unique_ptr<ShaderHandler> shaderInstance;
    friend std::default_delete<ShaderHandler>;
	static std::map<std::string, GLuint> programs;

	std::string readShader(const std::string& fileName);

	GLuint createShader(GLenum shadertype,
						const std::string& source,
						const std::string& shaderName
						);

public:
		//delete constructors for singleton
	ShaderHandler(const ShaderHandler&) = delete;
	ShaderHandler(ShaderHandler&&) = delete;
	ShaderHandler& operator=(const ShaderHandler&) = delete;
	ShaderHandler& operator=(ShaderHandler&&) = delete;

	void onDestroy();
	void createProgram(const std::string& shaderName,
					   const std::string& vertexShaderFileName,
					   const std::string& fragmentShaderFileName);
	static const GLuint getShader(const std::string & shaderName);

	static ShaderHandler* getInstance();
};

#endif //SHADERHANDLER_H

