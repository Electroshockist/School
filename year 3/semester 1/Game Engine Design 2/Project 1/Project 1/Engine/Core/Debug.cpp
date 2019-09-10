#include "Debug.h"

std::string Debug::fileName = "Game301EngineLog.txt";
MessageType Debug::currentSeverity = MessageType::TYPE_NONE;

void Debug::debugInit() {
	std::ofstream out;
	out.open(fileName, std::ios::out);
	out.close();

	currentSeverity = MessageType::TYPE_FATAL_ERROR;
}

void Debug::debugInit(std::string & filename) {
	fileName = filename;
	Debug::debugInit();
}

void Debug::setSeverity(MessageType type) {
	currentSeverity = type;
}

void Debug::info(const std::string & message, const std::string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Info: " + message, filename, line);
}

void Debug::trace(const std::string & message, const std::string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Trace: " + message, filename, line);
}

void Debug::warning(const std::string & message, const std::string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Warning: " + message, filename, line);
}

void Debug::eror(const std::string & message, const std::string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Error: " + message, filename, line);
}

void Debug::fatalerror(const std::string & message, const std::string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Fatal Error: " + message, filename, line);
}

void Debug::log(const MessageType type, const std::string & message, const std::string & filename, const int line) {
	std::ofstream file;
	file.open(fileName, std::ios::app | std::ios::out);
	if (type <= currentSeverity && currentSeverity > MessageType::TYPE_NONE) {
		file << message << " in: " << filename << " on line: " << line << std::endl;
	}
	file.flush();
	file.close();
}
