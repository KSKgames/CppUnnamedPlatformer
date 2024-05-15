#include<string>



class basicObj{
public:
	std::string texture;
	float sx=1.0, sy=1.0;
	//collider
	virtual void spawnBehaviour(){};
};

class damageObj : public basicObj {
public:
	int damage;
	//dmg_collider
};
class movingObj : public basicObj {

};
class enemyObj : public damageObj, public movingObj{

};