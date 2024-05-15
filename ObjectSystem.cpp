#include"ObjectSystem.h"
//collider constructors
//https://stackoverflow.com/questions/14047191/overloading-operators-in-typedef-structs-c
gm::collider::collider(std::vector<vectorFloat> points) :points(points){};
gm::collider::collider(float radius) :radius(radius){};

//basicObj constructors
//https://stackoverflow.com/questions/30069384/provides-no-initializer-for-reference-member
gm::basicObj::basicObj(std::string texture) :collider(nullCollider){
	this->texture = texture;
}
gm::basicObj::basicObj(std::string texture, gm::collider& collider) :collider(collider){
	this->texture = texture;
}
gm::basicObj::basicObj(std::string texture, gm::collider& collider, int sx, int sy) :collider(collider){
	this->texture = texture;
	scale.x = sx;
	scale.y = sy;
}
gm::basicObj::basicObj(std::string texture, int sx, int sy) :collider(nullCollider){
	this->texture = texture;
	scale.x = sx;
	scale.y = sy;
}
//basicObj getters
gm::vectorFloat gm::basicObj::getScale(){return scale;}
std::string gm::basicObj::getTexture(){return texture;}
gm::collider& gm::basicObj::getCollider(){return collider;}
gm::vectorInt gm::basicObj::getRealSize(){ return realSize;}
//basicObj methods are in ObjectBehaviur.cpp
