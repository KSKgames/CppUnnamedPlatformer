#include"ObjectSystem.h"

//collider constructors
//https://stackoverflow.com/questions/14047191/overloading-operators-in-typedef-structs-c
gm::collider::collider(std::vector<vectorFloat> points) :points(points){};
gm::collider::collider(float radius) :radius(radius){};

//basicObj constructors
//https://stackoverflow.com/questions/30069384/provides-no-initializer-for-reference-member
gm::basicObj::basicObj(std::string name, std::string texture) :collider(nullCollider){
	this->name = name;
	this->texture = texture;
}
gm::basicObj::basicObj(std::string name, std::string texture, gm::collider& collider) :collider(collider){
	this->name = name;
	this->texture = texture;
}
gm::basicObj::basicObj(std::string name, std::string texture, gm::collider& collider, int sx, int sy) :collider(collider){
	this->name = name;
	this->texture = texture;
	scale.x = sx;
	scale.y = sy;
}
gm::basicObj::basicObj(std::string name, std::string texture, int sx, int sy) :collider(nullCollider){
	this->name = name;
	this->texture = texture;
	scale.x = sx;
	scale.y = sy;
}

gm::GameObjectList::GameObjectList() {
	objects.push_back(basicObj("null", "null"));
}

void LoadFromFile(std::string filename) {
	//TO BE DONE
}

void gm::GameObjectList::Add(basicObj obj) {
	objects.push_back(obj);
}
gm::basicObj& gm::GameObjectList::GetObjByName(std::string name) {
	for (basicObj& obj : objects)
		if (obj.name == name) return obj;

	return objects[0]; //return default
}

//basicObj getters
gm::vectorFloat gm::basicObj::getScale(){return scale;}
std::string gm::basicObj::getTexture(){return texture;}
gm::collider& gm::basicObj::getCollider(){return collider;}
gm::vectorInt gm::basicObj::getRealSize(){ return realSize;}
//basicObj methods are in ObjectBehaviur.cpp
