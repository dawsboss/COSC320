//This namespoace is used for logging data into files
//This version og Logger will log numbers in to a .CSV file for graphing
//Make sure to seperate variables/rows by a ln()
#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<fstream>


namespace Logger{
		//CSV: X ......
		//		 Y ......
		//		 ..
		//		 ..
		//		 ..

  //Name the file with no file type
  void init(std::string);

  void close();

  void log(int);

  void logln(int);

  void ln();

  std::string getFile();
  
};
#endif
