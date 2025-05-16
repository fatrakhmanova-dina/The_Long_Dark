#pragma once
#include "engine.h"

void Engine::setupUI()
{

	backgroundTexture.loadFromFile("menu.png");
	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);

	//All the text used for the game
	font.loadFromFile("KOMIKAP_.ttf");

	//introText font

	HealthText.setFont(font);
	HealthText.setString("Health");
	HealthText.setCharacterSize(25);
	HealthText.setFillColor(Color::Black);
	HealthText.setPosition(100, 900);

	FoodText.setFont(font);
	FoodText.setString("Food");
	FoodText.setCharacterSize(25);
	FoodText.setFillColor(Color::Black);
	FoodText.setPosition(100, 800);

	WaterText.setFont(font);
	WaterText.setString("Water");
	WaterText.setCharacterSize(25);
	WaterText.setFillColor(Color::Black);
	WaterText.setPosition(100, 700);

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

	HealthBar.setFillColor(Color::Green);
	HealthBar.setPosition(100, 900);

	FoodBar.setFillColor(Color::Yellow);
	FoodBar.setPosition(100, 800);

	WaterBar.setFillColor(Color::Red);
	WaterBar.setPosition(100, 700);
}