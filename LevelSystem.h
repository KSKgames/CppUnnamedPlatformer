#pragma once
#include"GameEssentials.h"
#include"ObjectSystem.h"
#include"CameraSystem.h"
#include<unordered_map>

namespace gm{
	const std::string fileMarking = "LEVELDATA";
	class level{
	private:
		struct ObjRef{ //struktura przechowuje obiekt jako czyste dane, wczytane z pliku i tylko odniesienie do obiektu obiektu
			vectorInt pos;
			float rot;
			basicObj& objRef;
			std::unordered_map<std::string, int> params; //possibly change to str,int
			ObjRef(int posX, int posY, float r, basicObj& objectRef, std::unordered_map<std::string, int> parameters);
		};
	public:
		vectorInt playerStartPos; 
		std::vector<ObjRef> objectRefs;
		level(std::string fileName, OBJECT_LIST OBJECT_LIST); //loadlevelFromFile
	};
}