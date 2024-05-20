#include"LevelSystem.h"
#include"ObjectSystem.h"
#include"GameEssentials.h"
#include<fstream>
#include<iostream>
#include<unordered_map>
gm::level::level(std::string fileName,OBJECT_LIST GameObjects){
	std::ifstream file(fileName);
	std::string line;
	if(std::getline(file, line)){
		if(line == "LEVELDATA"){ //add comments
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
				if(parameters.count("r") == 0)
					parameters["r"]="0";
				/*
				if(!(parameters.count("x") != 1 || parameters.count("y") != 1 || objName == ""))
					objectRefs.push_back(ObjRef(parameters["x"], parameters["y"], parameters["r"], OBJECT_LIST.getObjectByName(objName)));				
				*/
			}
		}
	}
}
gm::level::ObjRef::ObjRef(int posX,int posY,float rotation,basicObj& objectRef,std::unordered_map<std::string, int> parameters) :objRef(objectRef){
	pos.x = posX;
	pos.y = posY;
	rot = rotation;
	params = parameters;
}