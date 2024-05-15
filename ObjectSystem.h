#pragma once
#include"GameEssentials.h"

namespace gm{ //! nazwa przestrzeni nazw !
	struct collider{
		std::vector<vectorFloat> points;
		float radius = 0;
		collider(std::vector<vectorFloat> points);
		collider(float radius);
	};
	collider nullCollider = collider(std::vector<vectorFloat>());

	class basicObj{
	private:
		vectorInt pos = {0,0};
		vectorFloat scale = {1.0,1.0};
		vectorInt realSize; //set it after loading texture to memory (will have to make texture loading system first)
		std::string texture;
		gm::collider& collider;
	public:
		vectorFloat getScale();
		vectorInt getRealSize(); //there should 
		std::string getTexture();
		gm::collider& getCollider();
		virtual void onSpawn();
		virtual void onUpdate();
		basicObj(std::string texture);
		basicObj(std::string texture,gm::collider& collider);
		basicObj(std::string texture, gm::collider& collider, int sx, int sy);
		basicObj(std::string texture, int sx, int sy);
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
}


//https://en.sfml-dev.org/forums/index.php?topic=5944.0
//https://en.sfml-dev.org/forums/index.php?topic=5273.0