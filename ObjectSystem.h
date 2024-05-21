#pragma once
#include"GameEssentials.h"
#include<unordered_map>

namespace gm{
	struct collider{
		std::vector<vectorFloat> points;
		float radius = 0;
		collider(std::vector<vectorFloat> points);
		collider(float radius);
	};
	class basicObj{
	private:
		vectorInt pos = {0,0};
		vectorFloat scale = {1.0,1.0};
		vectorInt realSize; //set it after loading texture to memory (will have to make texture loading system first)
		std::string texture;
		gm::collider& collider;
	public:
		//basicObj& operator=(const basicObj& rhs);
		std::string name;
		std::unordered_map<std::string, int> params; //PARAMETERS
		vectorFloat getScale();
		vectorInt getRealSize(); 
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

	class GameObjectList {
	private:
		std::vector<basicObj> objects;
	public:
		void LoadFromFile(std::string filename);
		void Add(basicObj obj);
		basicObj& GetObjByName(std::string name);
		GameObjectList();
	};
}


//https://en.sfml-dev.org/forums/index.php?topic=5944.0
//https://en.sfml-dev.org/forums/index.php?topic=5273.0