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
		//renderowanie b�dzie si� odbywa�o na bazie r�nic mi�dzy zmienn� position a pozycjami innych obiekt�w w tym gracza
		//renderowanie b�dzie w oddzielnych plikach "Rendering" tam b�dzie includowany sfml
	};
}
