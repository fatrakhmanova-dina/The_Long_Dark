#include "engine.h"

void Engine::draw()
{

	// Iterate through the mobs
	m_Window.draw((pPlayer)->getSprite());

	for (iter = Mobs.begin(); iter != Mobs.end(); ++iter)
	{
		m_Window.draw((*iter)->getSprite());
	}

	for (iter1 = Items.begin(); iter1 != Items.end(); ++iter1)
	{
		m_Window.draw((*iter1)->getSprite());
	}

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