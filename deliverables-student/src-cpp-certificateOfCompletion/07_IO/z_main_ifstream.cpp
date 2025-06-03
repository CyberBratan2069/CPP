// see https://stackoverflow.com/questions/58601912/c-reading-in-from-a-text-file

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]){
  std::string all_lines;
  if (argc==2){
    std::ifstream file(argv[1]);
    //Read each line
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        all_lines += line + '\n';
    }
  } else {
  	std::cout << "usage: a.out file_name" << std::endl;
  }
  
  std::cout << "<" << all_lines << ">"  <<  std::endl;
  return 0;
}
