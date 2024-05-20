#pragma once
#include<string> //mo�e wprowadzimy nasze w�asne struktury zamiast std?
#include<vector>

namespace gm{
	int strToInt(std::string str);
	float strToFloat(std::string str);
	struct vectorInt{
		int x = 0;
		int y = 0;
	};
	struct vectorFloat{
		float x = 0;
		float y = 0;
	};
	struct rectInt{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
	};
}