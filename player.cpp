#pragma once
#include "player.h"
#include "engine.h"
//Constructor
Player::Player(Vector2f position)
{
	Health = 20000;
	maxHealth = 20000;

	Food = 0;
	maxFood = 100000;

	Water = 0;
	maxWater = 100000;

	Weight = 0;
	maxWeight = 100;

	can = 0;
	soda = 0;
	meat = 0;

	moveTime = 0;
	speed = 128;
	m_Position = position;
	goal_PositionX = m_Position.x;
	goal_PositionY = m_Position.y;

	UpPressed = false;
	DownPressed = false;
	LeftPressed = false;
	RightPressed = false;

	// load all correct textures
	m_TextureUp.loadFromFile("up.png");
	m_TextureDown.loadFromFile("down.png");
	m_TextureLeft.loadFromFile("left.png");
	m_TextureRight.loadFromFile("right.png");

	// create rect to navigate through the spriresheet
	rectSourceSprite = sf::IntRect(0, 0, 64, 64);

	m_Sprite.setTexture(m_TextureRight);
	m_Sprite = Sprite(m_TextureRight, rectSourceSprite);

	m_Sprite.setOrigin(32, 32);
	m_Sprite.setPosition(m_Position);

}

//Add health to the player
void Player::AddHealth(int h)
{
	Health = Health + h;
	//if health exceeds the max, set it to maxHealth
	if (Health > maxHealth)
	{
		Health = maxHealth;
	}
}

void Player::ReduceHealth(int red)
{
	Health = Health - red;

	if (Health < 0)
	{
		Health = 0;
	}
}

void Player::AddFood(int add)
{
	Food = Food + add;

	if (Food > maxFood)
	{
		Food = maxFood;
	}
}

void Player::ReduceFood(int red)
{
	Food = Food - red;

	if (Food < 0)
	{
		Food = 0;
	}
}



void Player::AddWater(int add)
{
	Water = Water + add;

	if (Water > maxWater)
	{
		Water = maxWater;
	}
}

void Player::ReduceWater(int red)
{
	Water = Water - red;

	if (Water < 0)
	{
		Water = 0;
	}
}




void Player::AddWeight(int add)
{
	Weight = Weight + add;

	if (Weight > maxWeight)
	{
		Weight = maxWeight;
	}
}

void Player::ReduceWeight(int red)
{
	Weight = Weight - red;

	if (Weight < 0)
	{
		Weight = 0;
	}
}


int Player::getHealth()
{
	return Health;
}

int Player::getFood()
{
	return Food;
}

int Player::getWater()
{
	return Water;
}

int Player::getWeight()
{
	return Weight;
}

int Player::getAxe()
{
	return axe;
}

int Player::getCans()
{
	return can;
}

int Player::getSodas()
{
	return soda;
}

int Player::getMeat()
{
	return meat;
}


FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

Vector2f Player::getCenter()
{
	return m_Position;
}


bool Player::isAlive()
{
	if (Health > 0)
		return true;
	else
		return false;
}


//Movement section
void Player::moveLeft()
{
	LeftPressed = true;
}

void Player::moveRight()
{
	RightPressed = true;
}

void Player::moveUp()
{
	UpPressed = true;
}

void Player::moveDown()
{
	DownPressed = true;
}


void Player::stopLeft()
{
	LeftPressed = false;
}

void Player::stopRight()
{
	RightPressed = false;
}

void Player::stopUp()
{
	UpPressed = false;
}

void Player::stopDown()
{
	DownPressed = false;
}
int Player::getMaxWeight()
{
	return this->maxWeight;
}

int Player::getMaxWater()
{
	return this->maxWater;
}

int Player::getMaxFood()
{
	return this->maxFood;
}

void Player::Movement(float elapsedTime, float totalTime, Vector2f mapBounds)
{
	//If enough total time has passed, the player can move again
	if (moveTime <= totalTime)
	{
		//Set position to current goal position
		m_Position.x = goal_PositionX;
		m_Position.y = goal_PositionY;
		m_Sprite.setPosition(m_Position);
		//move set to c to stop movement until button is pressed.
		move = 'c';
		//Checks direction pressed to see where to move character
		if (UpPressed && !(m_Position.y - 128 < 0))
		{
			goal_PositionY = m_Position.y - 128;
			m_Sprite = Sprite(m_TextureUp, rectSourceSprite);
			//set to U to allow continuous movement up
			move = 'U';
		}
		else if (DownPressed && m_Position.y + 128 < mapBounds.y)
		{
			goal_PositionY = m_Position.y + 128;
			m_Sprite = Sprite(m_TextureDown, rectSourceSprite);
			//set to D to allow continuous movement down
			move = 'D';
		}
		else if (LeftPressed && !(m_Position.x - 128 < 0))
		{
			goal_PositionX = m_Position.x - 128;
			m_Sprite = Sprite(m_TextureLeft, rectSourceSprite);
			//set to L to allow continuous movement left
			move = 'L';
		}
		else if (RightPressed && m_Position.x + 128 < mapBounds.x)
		{
			goal_PositionX = m_Position.x + 128;
			m_Sprite = Sprite(m_TextureRight, rectSourceSprite);
			//set to R to allow continuous movement right
			move = 'R';
		}
		//move not being c means that a movement has been registered
		if (move != 'c')
		{
			//moveTime will be totalTime plus a certain amount to keep movement going the same way for a while.
			moveTime = totalTime + 0.5;
		}
	}
	//If moveTime is still larger than totalTime, then the character will continue moving in the same direction as what was inputted

	//Depending on what move is, the player will continue moving in the previously inputted direction
	if (move == 'U')
	{
		if (m_Position.y > goal_PositionY)
		{
			m_Position.y -= speed * elapsedTime;

		}
		else
		{
			m_Position.y = goal_PositionY;

		}

	}
	if (move == 'D')
	{
		if (m_Position.y < goal_PositionY)
		{
			m_Position.y += speed * elapsedTime;

		}
		else
		{
			m_Position.y = goal_PositionY;

		}
	}
	if (move == 'L')
	{
		if (m_Position.x > goal_PositionX)
		{
			m_Position.x -= speed * elapsedTime;

		}
		else
		{
			m_Position.x = goal_PositionX;

		}
	}
	if (move == 'R')
	{
		if (m_Position.x < goal_PositionX)
		{
			m_Position.x += speed * elapsedTime;
		}
		else
		{
			m_Position.x = goal_PositionX;
		}
	}

	// set origin and position
	m_Sprite.setOrigin(32, 32);
	m_Sprite.setPosition(m_Position);
}

void Player::PickUp(Item* item)
{
		if (item->getType() == 5)
			can++;
		else if (item->getType() == 6)
			soda++;
		else if (item->getType() == 7)
			meat++;
		else if (item->getType() == 4)
		{
			if (axe < 1)
			{
				m_TextureUp.loadFromFile("tup.png");
				m_TextureDown.loadFromFile("tdown.png");
				m_TextureLeft.loadFromFile("tleft.png");
				m_TextureRight.loadFromFile("tright.png");

				// create rect to navigate through the spriresheet
				rectSourceSprite = sf::IntRect(0, 0, 64, 64);

				m_Sprite.setTexture(m_TextureRight);
				m_Sprite = Sprite(m_TextureRight, rectSourceSprite);

				m_Sprite.setOrigin(32, 32);
				axe++;
			}
			else
				return;

		}
		Weight += item->getWeight();
		Inventory.push_back(item);
		std::cout << " picked up" << std::endl;

}

void Player::Use(int type)
{
	if (type == 5)
	{
		if (can >= 1)
		{
			for (iteri = Inventory.begin(); iteri != Inventory.end(); ++iteri)
			{
				if ((*iteri)->getType() == 5)
				{
					if (Water == maxWater && Food == maxFood)
						break;
					else
					{
						AddWater((*iteri)->getWater_val());
						AddFood((*iteri)->getFood_val());
						ReduceWeight((*iteri)->getWeight());
						Inventory.erase(iteri);
						can--;
						break;
					}
				}
			}
		}
	}
	if (type == 6)
	{
		if (soda >= 1)
		{
			for (iteri = Inventory.begin(); iteri != Inventory.end(); ++iteri)
			{
				if ((*iteri)->getType() == 6)
				{
					if (Water == maxWater && Food == maxFood)
						break;
					else
					{
						AddWater((*iteri)->getWater_val());
						AddFood((*iteri)->getFood_val());
						ReduceWeight((*iteri)->getWeight());
						Inventory.erase(iteri);
						soda--;
						break;
					}
				}
			}
		}
	}
	if (type == 7)
	{
		if (meat >= 1)
		{
			for (iteri = Inventory.begin(); iteri != Inventory.end(); ++iteri)
			{
				if ((*iteri)->getType() == 7)
				{
					if (Water == maxWater && Food == maxFood)
						break;
					else
					{
						AddWater((*iteri)->getWater_val());
						AddFood((*iteri)->getFood_val());
						ReduceWeight((*iteri)->getWeight());
						Inventory.erase(iteri);
						meat--;
						break;
					}
				}
			}
		}
	}
}

std::list<Item*> Player::getInventory()
{
	return this->Inventory;
}
