#include"CameraSystem.h"
gm::camera::update(vectorFloat playerPos){
	if(moveDir.x == 0){
		if(position.x + playerMoveLimits.x < playerPos.x + startOffsetFromPlayer.x)
			moveDir.x = 1;
		else if(position.x - playerMoveLimits.x > playerPos.x + startOffsetFromPlayer.x)
			moveDir.x = -1;
	}
	else {
		if(!lockX) position.x += moveDir.x * camSpeed;
		if(abs(position.x - playerPos.x) < stopDistance) moveDir.x = 0;  //!!!!
	}
	if(moveDir.y == 0){
		if(position.y + playerMoveLimits.y < playerPos.y + startOffsetFromPlayer.y)
			moveDir.y = 1;
		else if(position.y - playerMoveLimits.y > playerPos.y + startOffsetFromPlayer.y)
			moveDir.y = -1;
	}
	else{
		if(!lockY)  position.y += moveDir.y * camSpeed;
		if(abs(position.y - playerPos.y) < stopDistance) moveDir.y = 0;  //!!!!
	}
}

gm::camera::camera(vectorInt playerPos, vectorInt offsetFromPlayer, vectorFloat playerMoveLimits, float stoppingDistanceFromPlayer, float speed){
	position.x = playerPos.x + offsetFromPlayer.x;
	position.y = playerPos.y + offsetFromPlayer.y;
	startOffsetFromPlayer = offsetFromPlayer;
	this->playerMoveLimits = playerMoveLimits;
	stopDistance = stoppingDistanceFromPlayer;
	camSpeed = speed;
}
gm::vectorInt gm::camera::getSize(){
	return size;
}