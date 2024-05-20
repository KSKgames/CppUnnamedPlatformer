#include "GameEssentials.h"
#include<iostream>
int gm::strToInt(std::string str) {
	int num = 0, n=1;
	for (int i = str.length()-1; i>=0; i--) {
		num += (str[i] - 48) * n;
		n *= 10;
	}
	return num;
}

float gm::strToFloat(std::string str) {
	std::string toConvert;
	bool mode = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {mode = 1; continue;}
		toConvert += str[i]; //TO END
	}
}