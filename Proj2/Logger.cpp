#include "Logger.h"

namespace Logger{
	std::string filename;
	std::fstream file;
	//Put functions in here and you wouldn't need Logger::
};

void Logger::init(std::string s){
	filename = s+".csv";
	file.open(filename, std::ios::out);
}

void Logger::close(){
	file.close();
}

void Logger::log(int s){
	file <<s <<",";
}

void Logger::logln(int s){
	file << s << std::endl;
}

void Logger::ln(){
	file << std::endl;
}

std::string Logger::getFile(){
	return filename;
}




