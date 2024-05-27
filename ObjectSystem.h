#pragma once
#include"GameEssentials.h"
#include<map>

namespace gm{
	struct collider{
		std::vector<vectorFloat> points;
		float radius = 0;
		collider(std::vector<vectorFloat> points);
		collider(float radius);
	};

	class basicObj{
	private:
		vectorInt pos = {0,0};float r = 0;
		vectorFloat scale = {1.0,1.0};
		std::string texture;
		gm::collider& collider;
		vectorInt realSize; //CHANGE ON RESIZE AND RETEXTURE - set it after loading texture to memory (will have to make texture loading system first)
		//rectInt realBounds; //CHANGE ON REROTATE (returns the bounds of the object for camera, based or real size and rotation)
		std::map<std::string, std::string> otherParams;
	public:
		//basicObj& operator=(const basicObj& rhs);
		void instantiate(std::map<std::string,std::string> params);
		std::string name;
		vectorFloat getScale(); 
		//rectInt getRealBoundaries(); //^^^
		vectorInt getRealSize(); //^^^
		std::string getTexture();
		gm::collider& getCollider();
		virtual void onSpawn();
		virtual void onUpdate();
		basicObj(std::string name, std::string texture);
		basicObj(std::string name, std::string texture,gm::collider& collider);
		basicObj(std::string name, std::string texture, gm::collider& collider, int sx, int sy);
		basicObj(std::string name, std::string texture, int sx, int sy);
	};
	class damageObj : public basicObj {
	public:
		int damage;
		gm::collider dmgCollider;
	};
	class movingObj : public basicObj {

	};
	class enemyObj : public damageObj{
		//moving obj 2.0?
	};

	static collider nullCollider = collider(std::vector<vectorFloat>());

	class ObjList {
	private:
		std::vector<basicObj> objects;
	public:
		void loadFromFile(std::string filename);
		void add(basicObj obj);
		int idByName(std::string name);
		int size();
		basicObj& getObject(int id);
	};
}


//https://en.sfml-dev.org/forums/index.php?topic=5944.0
//https://en.sfml-dev.org/forums/index.php?topic=5273.0