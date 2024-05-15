#include"LevelSystem.h"
#include"GameEssentials.h"
#include<fstream>
#include<iostream>
#include<unordered_map>
gm::level::level(std::string fileName){
	std::ifstream file(fileName);
	std::string line;
	if(std::getline(file, line)){
		if(line == "LEVELDATA"){
			while(std::getline(file, line)){
				std::string objName, paramName, temp;
				std::unordered_map<std::string, std::string> parameters;
				for(char c : line){//optimise this if level loading is too slow
					if(c == ','){
						if(objName == "") swap(objName, temp);
						else if(paramName != ""){
							if(parameters[paramName] == "") swap(parameters[paramName], temp);
							paramName = "";
						}
					}
					else if(c == ':'){
						if(paramName == "") swap(paramName, temp);
					}
					else if(c != ' '){
						temp += c;
					}
				}
				if(paramName != ""){
					if(parameters[paramName] == "") swap(parameters[paramName], temp);
					paramName = "";
				}
				std::cout << '\n' << objName << ": \n";
				std::cout << "x: " << parameters["x"] << '\n';
				std::cout << "y: " << parameters["y"] << '\n';
			}
		}
	}
}