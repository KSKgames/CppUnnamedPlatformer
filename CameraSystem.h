#pragma once
#include"GameEssentials.h"
#include"LevelSystem.h"
namespace gm{
	class camera{
	private:
		vectorFloat moveDir = {0,0};
		vectorFloat playerMoveLimits = {10,10}; //max dist before camera starts moving
		vectorInt startOffsetFromPlayer;
		vectorInt size;
		float stopDistance = 0.2; //distance from player at which the camera stops; 
	public:
		vectorFloat position;
		float camSpeed = 0.1;
		bool lockX = false, lockY = true;
		void update(vectorFloat playerPos);
		camera(vectorInt playerPos, vectorInt offsetFromPlayer, vectorFloat playerMoveLimits, float stoppingDistanceFromPlayer, float speed);
		vectorInt getSize();
		//float velocityToOffsetRatio; TBD
		//renderowanie bêdzie siê odbywa³o na bazie ró¿nic miêdzy zmienn¹ position a pozycjami innych obiektów w tym gracza
		//renderowanie bêdzie w oddzielnych plikach "Rendering" tam bêdzie includowany sfml
	};
}
