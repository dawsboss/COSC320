//This namespoace is used for logging data into files
#include<iostream>
#include<fstream>

namespace Logger{
  std::string filename;
  std::fstream file;


  //Name the file with no file type
  void init(std::string f){
    filename = f+".txt";
    file.open(f, std::ios::out);
  }

  void close(){
    file.close();
  }

  void log(std::string s){
    file << s;
  }

  void logln(std::string s){
    file << s << std::endl;
  }

  void ln(){
    file << " " << std::endl;
  }

  std::string getFile(){
    return filename;
  }
};
