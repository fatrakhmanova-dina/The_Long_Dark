#pragma once

#include "player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	//Default Constructor
	Player(Vector2f position = Vector2f(128,128));
	//Function to move
	//virtual void Movement(float elapsedTime, float totalTime, Vector2f mapBounds) = 0;

	//Function to get variables
	Vector2i getPosition();

	int getHealth();
	//Will return hunger bar
	int getFood();
	//Will return water bar
	int getWater();
	//Will return cool bar
	int getCold();
	//Will return weight carried
	int getWeight();
    //Will return number of shotguns
	int getRifle();
	//Will return number of ammo
	int getAmmo();
	//Will return number of matches
	int getMatches();
	//Will return number of sticks
	int getStick();
	//Will return number of cans
	int getCans();
	//Will return number of sodas
	int getSodas();
	//Will return number of raw meat
	int getRawMeat();
	//Will return number of cooked meat
	int getCookedMeat();
	//Will return number of water held
	int getWaterHeld();
	//Will return number of pots
	int getPots();


    //Returns the sprite
	Sprite getSprite();

	//bool isAttacked();

	//Will check if player is alive
	bool isAlive();

	//Eat food
	void EatFood();


	void ReduceHealth(int reduce);
	void AddHealth(int h);

    void ReduceCold(int reduse);
    void AddCold(int add);

    void ReduceFood(int reduse);
    void AddFood(int add);

    void ReduceWater(int reduse);
    void AddFood(int add);

    void ReduceWeight(int reduse);
    void AddWeight(int add);

    void Pickup(std::string name);
	// Moving functions
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();




	//void Spawn(int h, int mh, int l, int d, float x, float y);
protected:
	// The player health
	int Health;
	// The max health value the player can have
	int maxHealth;
	// The current position of player
	Vector2i m_Position;
	// The hunger bar
	int Food;
	int maxFood;
	// The water bar
	int Water;
	int MaxWater;
	// The cool bar
	int Cold;
	int maxCold;
	// The weight player can carry
	int Weight;
	int maxWeight;

	//All the items player can have, the current number of items
	int rifle;
	int ammo;
	int match;
	int stick;
	int can;
	int soda;
	int raw_meat;
	int cooked_meat;
	int water_held;
	int pot;


	//Player sprite
	Sprite m_Sprite;

	//Player texture
	Texture m_TextureUp;
	Texture m_TextureDown;
	Texture m_TextureLeft;
	Texture m_TextureRight;

	IntRect rectSourceSprite;

	//Used to determine which way to move each movement call
	char move;
	//direction variables
	bool UpPressed;
	bool DownPressed;
	bool LeftPressed;
	bool RightPressed;

};
