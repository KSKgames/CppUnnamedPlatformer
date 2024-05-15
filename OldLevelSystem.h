/*#pragma once
#include<unordered_map>
#include<vector>

class LevelSystem{
private:
	struct object{
		int sx=0,sy=0;
		std::string texture="sprite.png";
		int damage = 0;
		float opacity = 1.0;
		//ColliderType collider;
	};
	std::vector<int> LevelMarkers;
	std::unordered_map<std::string,object> objects;
	void loadObject(std::string dataString);
public:
	LevelSystem(std::string fileName);
	void LoadLevel(int lvlIndex);
};
*/