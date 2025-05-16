#include "engine.h"

void Engine::draw()
{

// Iterate through the mobs
	m_Window.draw((pPlayer)->getSprite());

	m_Window.setView(m_BlackoutView);

	//HUD view used for elements that don't move

	//change view to m_HudView to set HUD graphics
	m_Window.setView(m_HudView);
	m_Window.draw(FoodBar);
	m_Window.draw(HealthBar);
	m_Window.draw(WaterBar);
	m_Window.draw(HealthText);
	m_Window.draw(FoodText);
	m_Window.draw(WaterText);

}