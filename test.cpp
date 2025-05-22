//Used by enemy to track player
void Wolf::MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition)
{
	//Used to measure distance from player
	Vector2f distance;
	distance.x = 0;
	distance.y = 0;
	if (moveTime <= totalTime)
	{
		//set position to goal position
		m_Position.x = goal_PositionX;
		m_Position.y = goal_PositionY;
		m_Sprite.setPosition(m_Position);
		//Determine distance to player
		if (m_Position.x < pPosition.x)
		{
			distance.x = pPosition.x - m_Position.x;
		}
		else
		{
			distance.x = m_Position.x - pPosition.x;
		}
		if (m_Position.y < pPosition.y)
		{
			distance.y = pPosition.y - m_Position.y;
		}
		else
		{
			distance.y = m_Position.y - pPosition.y;
		}


		//Check used to make sure the enemy stops moving at the player
		if ((distance.x < 127 && distance.y < 255) || (distance.x < 255 && distance.y < 127))
		{
			randnum = 0;
			moveTime = totalTime + 1;
		}
		//Determine where enemy should move
		else {
			if (distance.x > distance.y)
			{
				if (m_Position.x < pPosition.x)
				{
					randnum = 4;
					goal_PositionX = m_Position.x + speed;
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
				else
				{
					randnum = 3;
					goal_PositionX = m_Position.x - speed;
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
				moveTime = totalTime + 1;
			}

			else if (distance.x < distance.y)
			{
				if (m_Position.y < pPosition.y)
				{
					randnum = 2;
					goal_PositionY = m_Position.y + speed;
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
				else
				{
					randnum = 1;
					goal_PositionY = m_Position.y - speed;
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
				moveTime = totalTime + 1;
			}
			//Else to move enemy if x distance and y distance are the same
			else {
				if (m_Position.y < pPosition.y)
				{
					randnum = 2;
					goal_PositionY = m_Position.y + speed;

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
				else
				{
					randnum = 1;
					goal_PositionY = m_Position.y - speed;

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
				moveTime = totalTime + 1;
			}

		}

	}
}




//Used by deer to run from player
void Deer::MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition)
{
	//Used to measure distance from player
	Vector2f distance;
	distance.x = 0;
	distance.y = 0;
	if (moveTime <= totalTime)
	{
		//set position to goal position
		m_Position.x = goal_PositionX;
		m_Position.y = goal_PositionY;
		m_Sprite.setPosition(m_Position);
		//Determine distance to player
		if (m_Position.x < pPosition.x)
		{
			distance.x = pPosition.x - m_Position.x;
		}
		else
		{
			distance.x = m_Position.x - pPosition.x;
		}
		if (m_Position.y < pPosition.y)
		{
			distance.y = pPosition.y - m_Position.y;
		}
		else
		{
			distance.y = m_Position.y - pPosition.y;
		}



        if (distance.x > distance.y)
        {
            if (m_Position.x < pPosition.x)
            {
                randnum = 3;
                goal_PositionX = m_Position.x - speed;
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
            else
            {
                randnum = 4;
                goal_PositionX = m_Position.x + speed;
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
            moveTime = totalTime + 1;
        }

        else if (distance.x < distance.y)
        {
            if (m_Position.y < pPosition.y)
            {
                randnum = 1;
                goal_PositionY = m_Position.y - speed;
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
            else
            {
                randnum = 2;
                goal_PositionY = m_Position.y + speed;
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
            moveTime = totalTime + 1;
        }
        //Else to move deer if x distance and y distance are the same
        else {
            if (m_Position.y < pPosition.y)
            {
                randnum = 1;
                goal_PositionY = m_Position.y - speed;
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
            else
            {
                randnum = 2;
                goal_PositionY = m_Position.y + speed;
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
            moveTime = totalTime + 1;
        }

	}
}
