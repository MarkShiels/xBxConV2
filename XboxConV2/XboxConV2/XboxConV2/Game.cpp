
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   
#include <iostream>

	

int main()
{
	Game Game;
	Game.LoadContent();
	Game.run();
}


Game::Game() : window(sf::VideoMode(900, 600), "BWah")
// Default constructor
{
	windowPtr = &window;
}

void Game::LoadContent()
{
	controller.init(windowPtr);

	//to check if a controller is connected
	if (controller.joSt.isConnected(0))//change controller if needed
	{
		std::cout << "Controller 0 connected" << std::endl;
	}

	
}

void Game::run()
{
	srand(time(nullptr));
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//if (event.type == sf::Event::JoystickButtonPressed)
			//{
			//	//quit if the back\options button is pressed
			//	if (controller.joSt.isButtonPressed(0, 6)) window.close();//change controller if needed
			//	
			//	//pass button press to controller
			//	else controller.cntrlrPressEvent(event);	
			//}
			//else if (event.type == sf::Event::JoystickButtonReleased)
			//{
			//	//pass button release event to controller
			//	controller.cntrlrReleaseEvent(event);
			//}
			//

		}

		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			update(timePerFrame);
			draw();
			timeSinceLastUpdate = sf::Time::Zero;
		}

	}

}


void Game::update(sf::Time t_timePerFrame)
{
	controller.update(t_timePerFrame);

}


void Game::draw()
{
	window.clear();

	controller.draw();

	window.display();
}

