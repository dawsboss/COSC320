#include<iostream>
#include "../../Logger/Logger"

int mian(){
  Logger::init("Ree");
  Logger::log("Test");
  std::cout<<" "<<std::endl;
  Logger::close();
}
