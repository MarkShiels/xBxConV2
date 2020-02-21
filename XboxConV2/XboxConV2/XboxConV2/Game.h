//author: Mark Shiels
#pragma once
#include "XboxCon.h"


class Game
{

	sf::RenderWindow	window;
	sf::RenderWindow*	windowPtr;

	xBxCon				controller;

	


public:

	Game();
	void	LoadContent();
	void	run();
	void	update(sf::Time t_timePerFrame);
	void	draw();

};


