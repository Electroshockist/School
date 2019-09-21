#include "Debug.h"
#include <algorithm>

using namespace std;

string Debug::outputileName = "Game301Engine.log";
MessageType Debug::currentSeverity = MessageType::TYPE_NONE;
string Debug::projectPath = "";


void Debug::debugInit() {
	ofstream out;
	out.open(outputileName, ios::out);
	out.close();

	currentSeverity = MessageType::TYPE_FATAL_ERROR;
}

void Debug::debugInit(string & filename) {
	outputileName = filename;
	Debug::debugInit();
}

void Debug::setProjectPath(const string argv0) {
	//find position of the word "Debug" in path
	size_t pos = argv0.rfind("Debug");

	//truncate at position
	projectPath = argv0.substr(0, pos);

	// convert string to lower case
	for_each(projectPath.begin(), projectPath.end(), [](char & c) {
		c = ::tolower(c);
	});
}

string Debug::getProjectPath() {
	return projectPath;
}

void Debug::setSeverity(MessageType type) {
	currentSeverity = type;
}

void Debug::info(const string & message, const string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Info: " + message, simplifyFileName(filename), line);
}

void Debug::trace(const string & message, const string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Trace: " + message, simplifyFileName(filename), line);
}

void Debug::warning(const string & message, const string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Warning: " + message, simplifyFileName(filename), line);
}

void Debug::error(const string & message, const string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Error: " + message, simplifyFileName(filename), line);
}

void Debug::fatalError(const string & message, const string & filename, const int line) {
	log(MessageType::TYPE_INFO, "Fatal Error: " + message, simplifyFileName(filename), line);
}

void Debug::log(const MessageType type, const string & message, const string & filename, const int line) {
	ofstream file;
	file.open(outputileName, ios::app | ios::out);
	if (type <= currentSeverity && currentSeverity > MessageType::TYPE_NONE) {
		file << message << "\nin " << filename << " on line " << line << endl;
	}
	file.flush();
	file.close();
}

string Debug::simplifyFileName(const string filename) {
	cout << "Project path:" <<  projectPath << endl << "File path:" << filename << endl << "Subtracted path:" << filename.substr(projectPath.size()) << "\n\n";
	//truncate at position
	return filename.substr(projectPath.size());
}
