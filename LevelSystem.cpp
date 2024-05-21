#include"LevelSystem.h"
#include"ObjectSystem.h"
#include"GameEssentials.h"
#include<fstream>
#include<iostream>
#include<unordered_map>
gm::level::level(std::string fileName, gm::GameObjectList& gameObjectList){
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
				
				//checking if object's definition is valid
				if (parameters.count("x") != 1 || parameters.count("y") != 1 || objName == "")
					continue;

				//x,y,r
				int x = strToInt(parameters["x"]);
				int y = strToInt(parameters["y"]);
				float r = 0;
				if (parameters.count("r") == 1)
					r = strToFloat(parameters["r"]);
				parameters.erase("x");
				parameters.erase("y");
				parameters.erase("r");

				objectRefs.push_back(VirtualObj(x, y, r, gameObjectList.GetObjByName(objName), parameters));
			}
		}
	}
}
gm::level::VirtualObj::VirtualObj(int posX,int posY,float rotation,basicObj& object,std::unordered_map<std::string, std::string> parameters) :object(object){
	pos.x = posX;
	pos.y = posY;
	rot = rotation;
}