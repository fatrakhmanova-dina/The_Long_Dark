#pragma once
#include <list>
#include "player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "item.h"

using namespace sf;

class Player
{
public:
	//Default Constructor
	Player(Vector2f position = Vector2f(128, 128));

	//Function to get variables
	FloatRect getPosition();

	Sprite getSprite();

	//Function to get center of object
	Vector2f getCenter();

	int getHealth();
	//Will return hunger bar
	int getFood();
	//Will return water bar
	int getWater();
	//Will return weight
	int getWeight();
	//Will return number of axe
	int getAxe();
	//Will return number of cans
	int getCans();
	//Will return number of sodas
	int getSodas();
	//Will return number of meat
	int getMeat();

	//Returns the spriteSprite getSprite();

	int getMaxWeight();
	int getMaxFood();
	int getMaxWater();
	//bool isAttacked();

	//Will check if player is alive
	bool isAlive();

	//Eat food
	//void EatFood(Food f);


	void ReduceHealth(int reduce);
	void AddHealth(int h);

	void ReduceFood(int reduse);
	void AddFood(int add);

	void ReduceWater(int reduse);
	void AddWater(int add);

	void ReduceWeight(int reduse);
	void AddWeight(int add);

	//void Pickup(std::string name);
	// Moving functions
	void Movement(float elapsedTime, float totalTime, Vector2f mapBounds);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopDown();
	void stopUp();

	void PickUp(Item* item);
	void Use(int type);

	std::list<Item*> getInventory();
protected:
	// The player health
	int Health;
	// The max health value the player can have
	int maxHealth;
	// The current position of player
	Vector2f m_Position;
	float goal_PositionX;
	float goal_PositionY;
	float moveTime;
	int speed;
	// The hunger bar
	int Food;
	int maxFood;
	// The water bar
	int Water;
	int maxWater;
	// The weight player can carry
	int Weight;
	int maxWeight;

	//All the items player can have, the current number of items
	int axe;
	int can;
	int soda;
	int meat;

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

	std::list<Item*> Inventory;
	std::list<Item*>::const_iterator iteri;
};