/*#include<fstream>
#include<string>
#include<iostream>
#include"LevelSystem.h"
using namespace std;

int strToInt(string str){
	if(str == "") return 0;
	int n = 0, p = 10;
	n += (int)str[str.length() - 1] - 48;
	for(int i = str.length() - 2; i > 0; i--){
		n += ((int)str[i] - 48) * p;
		p *= 10;
	}
	if((int)str[0] == 45) n *= -1;
	else if(str.length() > 1) n += ((int)str[0] - 48) * p;
	return n;
}
float strToFloat(string str){
	float n = 0;
	string text;
	bool idx = 0;
	for(char c : str){
		if(c == ',' && !idx){
			n = strToInt(text);
			text = "";
			idx = 1;
		}
		else
			text += c;
	}
	//konwertowanie na float (mno¿enie drugiego tekstu przez d³ugoœæ)	
	
}




LevelSystem::LevelSystem(string fileName){
	ifstream file(fileName);
	string line;int i = 0;
	bool isLoadingObjects = false;
	if(file.is_open())
	while(getline(file, line)){
		if(line[0] == '#'){
			isLoadingObjects = false;
			string text;
			for(char c : line){
				text += c;
				if(line == "#OBJECTS"){
					isLoadingObjects = true;
					break;
				}
				else if(line == "#LEVEL"){
					LevelMarkers.push_back(i+1);
					break;
				}
			}
		}else if(isLoadingObjects)
			loadObject(line);
		i++;
	}
}

void LevelSystem::loadObject(string dataString){
	string text;
	object newObject;
	string objName;
	char paramBuffer;
	for(char c : dataString){
		switch(c){
		case ':':
			if(objName == "")
				swap(text, objName);
			break;
		case '(':
			//zapisywanie rodzaju parametru (tylko pierwsza litera sie liczy)
			paramBuffer = text[0];
			text = "";
			break;
		case ')':
			//wczytywanie parametru
			switch(paramBuffer){ 
			case 't':
				newObject.texture = text;
				break;
			case 's':
				break;
			case 'o':
				newObject.opacity = text;
			}
			text = "";
			break;
		default:
			text += c;
			break;
		}
	}
}

void LevelSystem::LoadLevel(int lvlIndex){
	
}
*/

//https://stackoverflow.com/questions/9711977/using-the-fstream-getline-function-inside-a-class