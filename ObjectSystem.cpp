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
//basicObj
gm::vectorFloat gm::basicObj::getScale() { return scale; }
std::string gm::basicObj::getTexture() { return texture; }
gm::collider& gm::basicObj::getCollider() { return collider; }
gm::vectorInt gm::basicObj::getRealSize() { return realSize; }
void gm::basicObj::instantiate(std::map<std::string, std::string> params) {
	for (std::pair<std::string, std::string> pair : params) {
		if (pair.first == "x") this->pos.x = strToInt(pair.second);
		else if (pair.first == "y") this->pos.y = strToInt(pair.second);
		else if (pair.first == "r") this->r = strToFloat(pair.second);
		else if (pair.first == "sx") this->scale.x = strToFloat(pair.second);
		else if (pair.first == "sy") this->scale.y = strToFloat(pair.second);
		else otherParams.insert(pair);
	};
}


//other basicObj methods are in ObjectBehaviur.cpp

//ObjList
void gm::ObjList::loadFromFile(std::string filename) {
	objects.push_back(gm::basicObj("null", "null"));
}

void gm::ObjList::add(basicObj obj) {
	objects.push_back(obj);
}

int gm::ObjList::size() {
	return objects.size();
}

int gm::ObjList::idByName(std::string name){
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i].name == name) return i;
		return -1;
	}
}
gm::basicObj& gm::ObjList::getObject(int id) {
	return objects[id];
}


