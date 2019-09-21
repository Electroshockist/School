#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <iostream>
#include <fstream>

enum class MessageType : unsigned short {
	TYPE_NONE = 0,
	TYPE_FATAL_ERROR,
	TYPE_ERROR,
	TYPE_WARNING,
	TYPE_TRACE,
	TYPE_INFO
};
class Debug {
public:
	Debug(const Debug&) = delete;
	Debug(Debug&&) = delete;
	Debug& operator=(const Debug&) = delete;
	Debug& operator=(Debug&&) = delete;
	Debug() = delete;

	///for siplifying debugging
	//only supply with main's argv[0]
	static void setProjectPath(const std::string argv0);
	static std::string getProjectPath();

	static void debugInit();
	static void debugInit(std::string& filename);
	static void setSeverity(MessageType type);

	static void info(const std::string& message, const std::string& filename, const int line);
	static void trace(const std::string& message, const std::string& filename, const int line);
	static void warning(const std::string& message, const std::string& filename, const int line);
	static void error(const std::string& message, const std::string& filename, const int line);
	static void fatalError(const std::string& message, const std::string& filename, const int line);

private:
	static void log(const MessageType type, const std::string& message, const std::string& filename, const int line);
	static std::string simplifyFileName(const std::string filename);

	static MessageType currentSeverity;
	static std::string outputileName;
	static std::string projectPath;
};
#endif //DEBUG_H

