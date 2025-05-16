#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "player.h"

#include <iostream>
#include<vector>
#include<ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <sstream>
#include <list>
#include <stdexcept>

using namespace sf;

class Engine
{
public:
	Engine(); // Constructor

	// Run the game
	void run();

	void setupUI(); // Setup all UI
	void input(); // Input implementation
	void draw();

private:
	// Set up window variables
	Vector2f m_Resolution; // To store the resolution of the screen

	RenderWindow m_Window; // main window
	View m_MainView; // main view
	View m_BlackoutView; // view for the dark screen
	View m_HudView; // HUD view

	/****** Game Properties *******/

	// Time variables
	Time m_Time; // store total time of the game
	float m_TimeAsSeconds; // store total time as seconds

	// random num variable helper
	int randnum;

	/****** Player Properties *******/

//	float staminaDecrease;
//	float m_AttackTimer;
//	float m_EatTimer;
	/*********** Set up game objects **********/
	Tilemap* tileMap;

	// Store map bounds
	Vector2f mapBounds;

	// Create a pointer of type Player
	Player* pPlayer;

	// create a list of pointers to mobs(deers and wolfes)
//	std::list<Mob*> players;
//	std::list<Item*> players;

	// Iterators for the lists
//	std::list<Mob*>::const_iterator iter;
//	std::list<Item*>::const_iterator iter;

	/********** HUD *********/


	Texture backgroundTexture;
	Sprite background;

	Font font;

	// Text for MENU m_State 
	Text playText;
	// Text for Intro m_State
	Text introText;
	//Text for end m_State
	Text loseText;

	std::stringstream introStream;

	std::stringstream pauseStream;
	std::stringstream loadedStream;

	//Text for Playing m_State
	Text HealthText;

	Text FoodText;

	Text WaterText;

//	Text ColdText;

	Text WinText;

	Text LoseText;

	RectangleShape HealthBar;// Display player health
	float HealthBarStartWidth = 200; // Set initial width and height
	float HealthBarHeight = 40;

	RectangleShape FoodBar;
	float FoodBarStartWidth = 200;
	float FoodBarHeight = 40;

	RectangleShape WaterBar;
	float WaterBarStartWidth = 200;
	float WaterBarHeight = 40;

//	RectangleShape ColdBar;
//	float ColdBarStartWidth = 200;
//	float ColdBarHeight = 40;
};
#endif