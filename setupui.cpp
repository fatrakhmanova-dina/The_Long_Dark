#pragma once
#include "engine.h"

void Engine::setupUI()
{
	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);

	//All the text used for the game
	font.loadFromFile("KOMIKAP_.ttf");

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

	HealthBar.setFillColor(Color::Green);
	HealthBar.setPosition(100, 900);

	FoodBar.setFillColor(Color::Yellow);
	FoodBar.setPosition(100, 800);

	WaterBar.setFillColor(Color::Red);
	WaterBar.setPosition(100, 700);
}