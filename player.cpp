#include "player.h"
//Constructor
Player::Player(Vector2f position)
{
	Health = 100;
	maxHealth = 100;

    Cold = 100;
	maxCold = 100;

	Food = 100;
	maxFood = 100;

	Water = 100;
	maxWater = 100;

	Weight = 100;
	maxWeight = 100;

	rifle = 0;
	ammo = 0;
	match = 0;
	stick = 0;
	can = 0;
	soda = 0;
	raw_meat = 0;
	cooked_meat = 0;
	water_held = 0;
	pot = 0;

	moveTime = 0;
	speed = 128;
	goal_PositionX = m_Position.x;
	goal_PositionY = m_Position.y;

	m_Position = position;

	UpPressed = false;
	DownPressed = false;
	LeftPressed = false;
	RightPressed = false;

	// load all correct textures
	//m_TextureUp.loadFromFile("graphics/player/up.png");
	//m_TextureDown.loadFromFile("graphics/player/down.png");
	//m_TextureLeft.loadFromFile("graphics/player/left.png");
	//m_TextureRight.loadFromFile("graphics/player/right.png");

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

	//if health exceeds the max, set it to maxHealth
	if (Health < 0)
    {
		Health = 0;
	}
}

void Player::AddCold(int add)
{
	Cold = Cold + add;
	//if health exceeds the max, set it to maxHealth
	if (Cold > maxCold)
    {
		Cold = maxCold;
	}
}


void Player::ReduceCold(int red)
{
	Cold = Cold - red;

	//if health exceeds the max, set it to maxHealth
	if (Cold < 0)
    {
		Cold = 0;
	}
}


void Player::AddFood(int add)
{
	Food = Food + add;
	//if health exceeds the max, set it to maxHealth
	if (Food > maxFood)
    {
		Food = maxFood;
	}
}

void Player::ReduceFood(int red)
{
	Food = Food - red;

	//if health exceeds the max, set it to maxHealth
	if (Food < 0)
    {
		Food = 0;
	}
}



void Player::AddWater(int add)
{
	Water = Water + add;
	//if health exceeds the max, set it to maxHealth
	if (Water > maxWater)
    {
		Water = maxWater;
	}
}

void Player::ReduceWater(int red)
{
	Water = Water - red;

	//if health exceeds the max, set it to maxHealth
	if (Water < 0)
    {
		Water = 0;
	}
}




void Player::AddWeight(int add)
{
	Weight = Weight + add;

	//if health exceeds the max, set it to maxHealth
	if (Weight > maxWeight)
    {
		Weight = maxWeight;
	}
}

void Player::ReduceWeight(int red)
{
	Weight = Weight - red;

	//if health exceeds the max, set it to maxHealth
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

int Player::getCold()
{
    return Cold;
}

int Player::getWeight()
{
    return Weight;
}

int Player::getRifle()
{
    return rifle;
}

int Player::getAmmo()
{
    return ammo;
}

int Player::getMatches()
{
    return match;
}

int Player::getStick()
{
    return stick;
}

int Player::getCans()
{
    return can;
}

int Player::getSodas()
{
    return soda;
}

int Player::getRawMeat()
{
    return raw_meat;
}

int Player::getCookedMeat()
{
    return cooked_meat;
}

int Player::getWaterHeld()
{
    return water_held;
}

int Player::getPots()
{
    return pot;
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
			//set to U to allow continuous movement up
			move = 'U';
		}
		else if (DownPressed && m_Position.y + 128 < mapBounds.y)
		{
			goal_PositionY = m_Position.y + 128;
			//set to D to allow continuous movement down
			move = 'D';
		}
		else if (LeftPressed && !(m_Position.x - 128 < 0))
		{
			goal_PositionX = m_Position.x - 128;
			//set to L to allow continuous movement left
			move = 'L';
		}
		else if (RightPressed && m_Position.x + 128 < mapBounds.x)
		{
			goal_PositionX = m_Position.x + 128;
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

