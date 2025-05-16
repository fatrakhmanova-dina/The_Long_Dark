#include <iostream>
#include "engine.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

int main()
{
	// seed the pseudo number generator
	srand(static_cast<unsigned int>(time(0)));

	Engine engine; // create engine object

	engine.run(); // run it

    return 0;
}