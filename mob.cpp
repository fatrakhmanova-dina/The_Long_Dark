#include "mob.h"


bool Wolf::IsHostile()
{
	return true;
}

bool Deer::IsHostile()
{
	return false;
}

//Constructor
Mob::Mob(Vector2f position)
{
	Health = 75;
	maxHealth = 75;

	speed = 128;
	moveTime = 0;

	m_Position = position;
	goal_PositionX = m_Position.x;
	goal_PositionY = m_Position.y;

	// load all correct textures
	m_TextureUp.loadFromFile("mup.png");
	m_TextureDown.loadFromFile("mdown.png");
	m_TextureLeft.loadFromFile("mleft.png");
	m_TextureRight.loadFromFile("mright.png");

	// create rect to navigate through the spriresheet
	rectSourceSprite = sf::IntRect(0, 0, 64, 64);

	m_Sprite.setTexture(m_TextureRight);
	m_Sprite = Sprite(m_TextureRight, rectSourceSprite);

	m_Sprite.setOrigin(32, 32);
	m_Sprite.setPosition(m_Position);
}

FloatRect Mob::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Mob::getSprite()
{
	return m_Sprite;
}

Vector2f Mob::getCenter()
{
	return m_Position;
}



void Mob::Movement(float elapsedTime, float totalTime, Vector2f mapBounds)
{
	//Decide where to move randomly, unless player is within sight,
	//in which case, attempt to move to player.

	//Check if enough time has passed to allow movement
	if (moveTime <= totalTime)
	{
		m_Position.x = goal_PositionX;
		m_Position.y = goal_PositionY;
		m_Sprite.setPosition(m_Position);

		//Calculate a random number, number isn't changed until total run time reaches certain value;
		randnum = rand() % 4 + 1;



		//moveTime will be totalTime plus a certain amount to keep movement going the same way for a while.
		moveTime = totalTime + 1;

		//Set goal position based on randnum
		if (randnum == 1)
		{
			//go up
			goal_PositionY = m_Position.y - speed;
		}
		if (randnum == 2)
		{
			//go down
			goal_PositionY = m_Position.y + speed;
		}
		if (randnum == 3)
		{
			//go left
			goal_PositionX = m_Position.x - speed;
		}
		if (randnum == 4)
		{
			//go right
			goal_PositionX = m_Position.x + speed;
		}

	}


	//move based on randnum
	if (randnum == 1)
	{
		//go up
		if (m_Position.y > goal_PositionY)
		{
			m_Position.y -= speed * elapsedTime;


			m_Sprite = Sprite(m_TextureUp, rectSourceSprite);

		}
		//Used to ensure character doesn't move past boundary
		else
		{
			m_Position.y = goal_PositionY;


			m_Sprite = Sprite(m_TextureUp, rectSourceSprite);
		}
	}
	if (randnum == 2)
	{
		//go down
		if (m_Position.y < goal_PositionY)
		{
			m_Position.y += speed * elapsedTime;

			m_Sprite = Sprite(m_TextureDown, rectSourceSprite);
		}
		//Used to ensure character doesn't move past boundary
		else
		{
			m_Position.y = goal_PositionY;


			m_Sprite = Sprite(m_TextureDown, rectSourceSprite);
		}
	}
	if (randnum == 3)
	{
		//go left
		if (m_Position.x > goal_PositionX)
		{
			m_Position.x -= speed * elapsedTime;


			m_Sprite = Sprite(m_TextureLeft, rectSourceSprite);

		}
		//Used to ensure character doesn't move past boundary
		else
		{
			m_Position.x = goal_PositionX;

			m_Sprite = Sprite(m_TextureLeft, rectSourceSprite);
		}
	}
	if (randnum == 4)
	{
		//go right
		if (m_Position.x < goal_PositionX)
		{
			m_Position.x += speed * elapsedTime;

			m_Sprite = Sprite(m_TextureRight, rectSourceSprite);

		}
		//Used to ensure character doesn't move past boundary
		else
		{
			m_Position.x = goal_PositionX;

			m_Sprite = Sprite(m_TextureRight, rectSourceSprite);
		}
	}



	m_Sprite.setOrigin(32, 32);
	m_Sprite.setPosition(m_Position);
}