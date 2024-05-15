#pragma once
#include"GameObject.h"

class Component
{
enum ComponentType{ Collider, Mover, Rotator, Damage };
private:
	ComponentType type;
public:
	Component(ComponentType _type);
	void update(GameObject* gameObject);
};