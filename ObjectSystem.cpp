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
//overloading operator= https://stackoverflow.com/questions/12902751/how-to-clone-object-in-c-or-is-there-another-solution
//to copy https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-copy-constructor
//why so difficult https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
/*
gm::basicObj& gm::basicObj::operator=(const gm::basicObj& rhs){
	return *this;
}
*/

void gm::OBJECT_LIST::loadObjectsFromFile(std::string filename){
	//TO BE DONE
}
void gm::OBJECT_LIST::addObject(std::string objectName,basicObj objectData){
	//DO IT NEXT: add objectData to objects[objectName]
}
gm::basicObj& gm::OBJECT_LIST::getObjectByName(std::string name){
	//DO IT NEXT NEXT:
	/*if (objects.count(name) == 1) {
		return objects[name];
	}
	else{
		// Return default object
	}*/
	basicObj lol("lol"); //to fix
	return lol;//to fix
}

//basicObj getters
gm::vectorFloat gm::basicObj::getScale(){return scale;}
std::string gm::basicObj::getTexture(){return texture;}
gm::collider& gm::basicObj::getCollider(){return collider;}
gm::vectorInt gm::basicObj::getRealSize(){ return realSize;}
//basicObj methods are in ObjectBehaviur.cpp
