#include "Player.h"
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
	water = 0;
	pot = 0;

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
void Player::addHealth(float h)
{
	Health = Health + h;
	//if health exceeds the max, set it to maxHealth
	if (Health > maxHealth)
    {
		Health = maxHealth;
	}
}

void Player::reduceHealth(float red)
{
	Health = Health - red;

	//if health exceeds the max, set it to maxHealth
	if (Health < 0)
    {
		Health = 0;
	}
}

void Player::addCold(float add)
{
	Cold = Cold + add;
	//if health exceeds the max, set it to maxHealth
	if (Cold > maxCold)
    {
		Cold = maxCold;
	}
}


void Player::reduceCold(float red)
{
	Cold = Cold - red;

	//if health exceeds the max, set it to maxHealth
	if (Cold < 0)
    {
		Cold = 0;
	}
}


void Player::addFood(float add)
{
	Food = Food + add;
	//if health exceeds the max, set it to maxHealth
	if (Food > maxFood)
    {
		Food = maxFood;
	}
}

void Player::reduceFood(float red)
{
	Food = Food - red;

	//if health exceeds the max, set it to maxHealth
	if (Food < 0)
    {
		Food = 0;
	}
}



void Player::addWater(float add)
{
	Water = Water + add;
	//if health exceeds the max, set it to maxHealth
	if (Water > maxWater)
    {
		Water = maxWater;
	}
}

void Player::reduceWater(float red)
{
	Water = Water - red;

	//if health exceeds the max, set it to maxHealth
	if (Water < 0)
    {
		Water = 0;
	}
}




void Player::addWeight(float add)
{
	Weight = Weight + add;

	//if health exceeds the max, set it to maxHealth
	if (Weight > maxWeight)
    {
		Weight = maxWeight;
	}
}

void Player::reduceWeight(float red)
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



Vector2i Player::getPosition()
{
    return m_Position;
}


bool isAlive()
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
