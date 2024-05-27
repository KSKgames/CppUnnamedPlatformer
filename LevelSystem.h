#pragma once
#include"GameEssentials.h"
#include"ObjectSystem.h"
#include"CameraSystem.h"
#include<unordered_map>

namespace gm{
	const std::string fileMarking = "LEVELDATA";
	class level{
	public:
		camera cam;
		vectorInt playerStartPos; //maybe change to an object
		ObjList objects;
		level(std::string fileName, ObjList GameObjects,camera cam); //loadlevelFromFile
	};
}