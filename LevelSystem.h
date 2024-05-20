#pragma once
#include"GameEssentials.h"
#include"ObjectSystem.h"
#include"CameraSystem.h"
#include<unordered_map>

namespace gm{
	const std::string fileMarking = "LEVELDATA";
	class level{
	private:
		struct VirtualObj{ //jest to odniesienie do obiektu
			vectorInt pos;
			float rot;
			std::unordered_map<std::string, int> params;
			basicObj& object;										//maybe refactor the format: (or do it in ObjectSystem)
			VirtualObj(int posX, int posY, float r, basicObj& object, std::unordered_map<std::string, std::string> parameters);
		};
	public:
		vectorInt playerStartPos; 
		std::vector<VirtualObj> objectRefs;
		level(std::string fileName, OBJECT_LIST OBJECT_LIST); //loadlevelFromFile
	};
}