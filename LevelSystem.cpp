#include"LevelSystem.h"
#include"GameEssentials.h"
#include<fstream>
#include<iostream>
gm::level::level(std::string fileName){
	std::ifstream file(fileName);
	std::string line;
	while(std::getline(file, line)){
		std::cout << line<<'\n';
	}
}