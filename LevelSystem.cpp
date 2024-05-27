#include"LevelSystem.h"
#include"ObjectSystem.h"
#include"GameEssentials.h"
#include<fstream>
#include<iostream>
#include<map>
gm::level::level(std::string fileName,ObjList ObjectList, camera cam):cam(cam){
	std::ifstream file(fileName);
	std::string line;
	if(std::getline(file, line)){
		if(line == "LEVELDATA"){ //add comments
			while(std::getline(file, line)){
				std::string objName, paramName, temp;
				std::map<std::string, std::string> parameters;
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
				
				//checking if object's definition is valid
				if (parameters.count("x") != 1 || parameters.count("y") != 1 || objName == "")
					continue;

				int id = ObjectList.idByName(objName);
				if (id<0) continue;
				objects.add(ObjectList.getObject(id));
				id = objects.size()-1;
				objects.getObject(id).instantiate(parameters);
			}
		}
	}
}