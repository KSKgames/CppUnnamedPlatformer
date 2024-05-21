#include<SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<windows.h>
#include<SFML/Audio.hpp>
#include<chrono>
#include"LevelSystem.h"
#include"ObjectSystem.h"

//https://stackoverflow.com/questions/61225576/how-to-seperate-unit-testing-from-main-program-in-c
const float TimeStep = 5.0;
const int WinSizeX = 1280;
const int WinSizeY = 720;

struct sprite
{   //parametry pocz¹tkowe
    float velocityOnX = 0;
    float velocityOnY = 0;
    float spriteX = 0;
    float spriteY = 0;
    float sizeX = 0;
    float sizeY = 0;
}; sprite hero;

bool onFloor(float x, float y) //tymczasowe latanie dziury w programie
{
    if(y < 600.0)
    {
        return false;
    }

    return true;
}

void physics()
{
    if(hero.velocityOnX > 0)
    {
        hero.velocityOnX = hero.velocityOnX - 1;
    }
    if(hero.velocityOnX < 0)
    {
        hero.velocityOnX = hero.velocityOnX + 1;
    }
    if(!onFloor(hero.spriteX, hero.spriteY))
    {
        hero.velocityOnY = hero.velocityOnY + 0.2;
    }
    else
    {
        hero.velocityOnY = 0;
    }
}


int main()
{
    gm::GameObjectList ObjList;
    ObjList.AddObj(gm::basicObj("lol", "lolek"));

    //sprawy techniczne
    sf::Sprite sprite1;
    sf::Texture sprite1Texture;
    sf::RenderWindow window(sf::VideoMode(WinSizeX, WinSizeY), "Genialna platformówka");
    sf::Music music1;
    music1.openFromFile("U.ogg");
    sprite1Texture.loadFromFile("tymczasowySprite.png");

    music1.play();
    sprite1.setTexture(sprite1Texture);

    while(window.isOpen())
    {
        //odpowiednie zapetlenie muzyczki
        if(music1.getPlayingOffset().asSeconds() > 140.f)
        {
            music1.setPlayingOffset(sf::seconds(8.f));
        }

        physics();
        //sterowanie
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            hero.velocityOnX = -1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            hero.velocityOnX = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(onFloor(hero.spriteX, hero.spriteY)) 
            {
                hero.velocityOnY = -4;
            }
        }

        //aktualizowanie pozycji
        hero.spriteX = hero.spriteX + TimeStep * hero.velocityOnX;
        hero.spriteY = hero.spriteY + TimeStep * hero.velocityOnY;
        sprite1.setPosition(sf::Vector2f(hero.spriteX, hero.spriteY));

        //zamykanie okienka (eventy)
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        //rysowanie (docelowo moze tablica sprite'ow i petla rysujaca)
        window.clear();
        window.draw(sprite1);
        window.display();
        Sleep(10);
    }
}