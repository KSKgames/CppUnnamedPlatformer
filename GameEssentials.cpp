#include "GameEssentials.h"
#include<iostream>
int gm::strToInt(std::string str) {
	int num = 0, n=1;
	for (int i = str.length()-1; i>=(str[0]=='-'); i--) {
		num += (str[i] - 48) * n;
		n *= 10;
	}
	if (str[0] == '-') num *= -1;
	return num;
}

float gm::strToFloat(std::string str) {
	bool mode = 0;
	float n = 1;
	for(char t:str) {
		if (mode)
			n /= 10;
		else if(t=='.')
			mode = 1;
	}
	float num = 0;
	for (int i = str.length() - 1; i >=(str[0]=='-');i--) {
		if (str[i] != '.') {
			num += (str[i] - 48) * n;
			n *= 10;
		}
	}
	if (str[0] == '-') num *= -1;
	return num;
}