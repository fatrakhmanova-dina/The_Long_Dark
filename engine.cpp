#include "engine.h"
#include "tilemap.h"
Engine::Engine()
{
	/***** Game Window and Views *****/

	// Get the width and height of the screen and apply it  to x and y of the resolution variable.
	m_Resolution.x = VideoMode::getDesktopMode().width;
	m_Resolution.y = VideoMode::getDesktopMode().height;

	// Create the m_Window with a title and in full screen and store it in the variable
	m_Window.create(VideoMode(m_Resolution.x, m_Resolution.y), "Can You Survive?", Style::Fullscreen);

	/** Setup the views **/
	// Main view
	m_MainView.reset(FloatRect(0, 0, m_Resolution.x, m_Resolution.y));
	// Blackout view
	m_BlackoutView.reset(FloatRect(0, 0, m_Resolution.x, m_Resolution.y));
	// HUD view
	m_HudView.reset(FloatRect(0, 0, m_Resolution.x, m_Resolution.y));

	/***** Game Properties Set up *****/

	// timers
	m_TimeAsSeconds = 0;

	randnum = 0;

	// Point tilemap to a new object
	tileMap = new Tilemap();

	// Save map boundaries for future use such as camera and player block
	mapBounds = tileMap->getMapBounds();

	/***** Characters Properties Set up *****/

	pPlayer = nullptr;

	// Create a stream object and open objects.txt file
	std::ifstream objectFile("objects.txt");

	// Open the text file
	if (objectFile.is_open())
	{
		Vector2f objectPosition(0, 0); // first tile position at 0, 0

		std::string line; // Create a string to access each line of the document

		int row = 0; // first row

		// Iterate through the lines of the text file
		for (line; getline(objectFile, line);)
		{
			// If the object position is outside map bounds on Y
			if (objectPosition.y > mapBounds.y)
			{
				// Display error to console
				std::cout << "Row size of objects.txt file cannot be greater than bounds of map.\n";
				return; // stop program
			}
			// For each letter in this line
			for (char& t : line)
			{
				// If the object position is outside the map bounds on X
				if (objectPosition.x > mapBounds.x)
				{
					// Displayer error to console
					std::cout << "Column size of objects.txt file cannot be greater than bounds of map.\n";
					return; // stop the program
				}
				// Switch character check if it's....
				switch (t)
				{
					// If it's the player
				case '1':
					// If player is pointing to a null pointer, i.e., no player yet
					if (pPlayer == nullptr)
					{
						// Create a new player and point to it
						pPlayer = new Player(objectPosition);
					}
					// If there is already a player created
					else
					{
						// Displayer an error and stop the program.
						std::cout << "There can only be one player. Please check objects.txt file, there shouldn't be more than one 1 char.\n";
						return;
					}
					break;
					// If it's an enemy
//				case '2':
//					break;
				}
				// next tile to the right (each tile is 128 pixels)
				objectPosition.x += 128;
			}
			// Return to the left most tile and one row down
			objectPosition = Vector2f(0, objectPosition.y + 128);
		}
	}
	else
	{
		// If it can't find the objects.txt file, print an error and close the program
		std::cout << "Cannot find objects.txt file. Please create a file with objects (player, enemies, collectibles, etc)"; //debug can't find file
		return;
	}

	// Close the object
	objectFile.close();

	setupUI();

}

void Engine::run()
{
	Clock clock;

	//Start of while loop, runs game while window is open
	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();

		m_Time += dt;

		m_TimeAsSeconds = m_Time.asSeconds();

		input(); // Input implementation

		//Set stamina and health bar size based on stamina and health
		HealthBar.setSize(Vector2f(2 * pPlayer->getHealth(), HealthBarHeight));
		FoodBar.setSize(Vector2f(2 * pPlayer->getFood(), FoodBarHeight));
		WaterBar.setSize(Vector2f(2 * pPlayer->getWater(), WaterBarHeight));

		//////////Here should be some actions, which is connected with cold, water, food, health amount

		///////////Here should be mechanics, connected with collisions between player and mobs

		/****************************  CAMERA  *******************************/

		// calculate where camera will be centered
		Vector2f cameraCenter = m_MainView.getCenter();

		// if player x position is less the center of screen width
		if (pPlayer->getCenter().x < (VideoMode::getDesktopMode().width / 2 - 64))
		{
			// camera center will stay there instead (as in, it will not outside the bounds of the map)
			cameraCenter.x = (VideoMode::getDesktopMode().width / 2) - 64;
		}
		// if player x position is more than the map bound width minus center of screen width 
		else if (pPlayer->getCenter().x > (mapBounds.x - VideoMode::getDesktopMode().width / 2) - 64)
		{
			// camera center will stay there instead (as in, it will not outside the bounds of the map)
			cameraCenter.x = (mapBounds.x - VideoMode::getDesktopMode().width / 2) - 64;
		}
		else
		{
			cameraCenter.x = pPlayer->getCenter().x;
		}
		// if player x position is less the center of screen height
		if (pPlayer->getCenter().y < (VideoMode::getDesktopMode().height / 2) - 64)
		{
			// camera center will stay there instead (as in, it will not outside the bounds of the map)
			cameraCenter.y = (VideoMode::getDesktopMode().height / 2) - 64;
		}
		// if player x position is more than the map bound width minus center of screen height 
		else if (pPlayer->getCenter().y > (mapBounds.y - VideoMode::getDesktopMode().height / 2) - 64)
		{
			// camera center will stay there instead (as in, it will not outside the bounds of the map)
			cameraCenter.y = (mapBounds.y - VideoMode::getDesktopMode().height / 2) - 64;
		}
		else
		{
			// else just center on player instead
			cameraCenter.y = pPlayer->getCenter().y;
		}

		// Set main view center to be same as the above calculation
		m_MainView.setCenter(cameraCenter);

		// Clear the screen and set the current view to Main View
		m_Window.clear(Color(135, 206, 235)); // clear the m_Window
		m_Window.setView(m_MainView);

		// get the minimum camera view by dividing the width and height of the screen 
		int minCameraViewX = cameraCenter.x - VideoMode::getDesktopMode().width / 2;
		int minCameraViewY = cameraCenter.y - VideoMode::getDesktopMode().height / 2;

		int maxCameraViewX = (cameraCenter.x + VideoMode::getDesktopMode().width / 2) + 256;
		int maxCameraViewY = (cameraCenter.y + VideoMode::getDesktopMode().height / 2) + 256;

		// Limit the maximum and minimum values to not be greater 
		// or lesser than the actual boundaries of the map
		if (minCameraViewX < 0) minCameraViewX = 0;
		if (minCameraViewY < 0) minCameraViewY = 0;

		if (maxCameraViewX > mapBounds.x) maxCameraViewX = mapBounds.x;
		if (maxCameraViewY > mapBounds.y) maxCameraViewY = mapBounds.y;


		//////////Here is mechanic of moving mobs towards or from player
		/*for (iterE = Mob.begin(); iterE != Mob.end(); ++iterE)
		{

			if ((*iterE)->getCenter().y > minCameraViewY && (*iterE)->getCenter().y < maxCameraViewY
				&& (*iterE)->getCenter().x > minCameraViewX && (*iterE)->getCenter().x < maxCameraViewX)
			{

				(*iterE)->MoveTowards(dtAsSeconds, m_TimeAsSeconds, pPlayer->getCenter());
			}
		}*/

		////////////Move mobs
		/*for (iter = Mob.begin(); iter != Mob.end(); ++iter)
		{
			(*iter)->Movement(dtAsSeconds, m_TimeAsSeconds, mapBounds);
		}*/
		pPlayer->Movement(dtAsSeconds, m_TimeAsSeconds, mapBounds);

		std::vector<std::vector<Tile*>> map = (tileMap->getMap());

		// for each row of tiles
		for (int i = (minCameraViewY / 128); i < maxCameraViewY / 128; i++)
		{
			// for each tile on that row
			for (int j = minCameraViewX / 128; j < maxCameraViewX / 128; j++)
			{
				// draw that tile
				m_Window.draw(map[i][j]->getSprite());
			}
		}
	
		///////////Here should be some logic about mobs actions

	    draw();
	    m_Window.display();
    }
}