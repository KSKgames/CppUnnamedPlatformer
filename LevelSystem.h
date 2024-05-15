#pragma once
#include"GameEssentials.h"
#include"ObjectSystem.h"
#include"CameraSystem.h"
namespace gm{
	const std::string fileMarking = "LEVELDATA";
	class level{
	public:
		vectorInt playerStartPos; 
		std::vector<basicObj> objects;
		level(std::string fileName); //loadlevelFromFile
	};
}