#pragma once
#include "engine.h"

void Engine::setupUI()
{

	backgroundTexture.loadFromFile("graphics/menu.png");
	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);

	//All the text used for the game
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	//introText font

	HealthText.setFont(font);
	HealthText.setString("Health");
	HealthText.setCharacterSize(25);
	HealthText.setFillColor(Color::Black);
	HealthText.setPosition(55, 950);

	FoodText.setFont(font);
	FoodText.setString("Food");
	FoodText.setCharacterSize(25);
	FoodText.setFillColor(Color::Black);
	FoodText.setPosition(55, 1000);

	WaterText.setFont(font);
	WaterText.setString("Food");
	WaterText.setCharacterSize(25);
	WaterText.setFillColor(Color::Black);
	WaterText.setPosition(55, 1000);

	WinText.setFont(font);
	WinText.setString("You win!");
	WinText.setCharacterSize(100);
	WinText.setFillColor(Color::Green);
	WinText.setPosition(960, 540);

	LoseText.setFont(font);
	LoseText.setString("You Lose...");
	LoseText.setCharacterSize(100);
	LoseText.setFillColor(Color::Red);
	LoseText.setPosition(955, 535);

	HealthBar.setFillColor(Color::Red);
	HealthBar.setPosition(50, 950);

	FoodBar.setFillColor(Color::Cyan);
	FoodBar.setPosition(50, 950);

	WaterBar.setFillColor(Color::Magenta);
	WaterBar.setPosition(50, 950);
}