#pragma once
#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER
/// <summary>
/// @author Peter Lowe
/// @co-author Mark Shiels
/// @date 16.09.19
/// </summary>
#include <SFML/Graphics.hpp>
/// <summary>
/// data to store the current state of the controller
/// </summary>

#include <iostream>

//enum for the face buttons
enum cntrlrButt
{
	A,
	B,
	X,
	Y,
	LB,
	RB,
	Options,
	Menu,
	LeftCLick,
	RightClick

};

struct GamePadState
{
	bool A{ false };
	bool B{ false };
	bool X{ false };
	bool Y{ false };
	bool LB{ false };
	bool RB{ false };
	bool LeftThumbStickClick{ false };
	bool RightThumbStickClick{ false };
	bool DpadUp{ false };
	bool DpadDown{ false };
	bool DpadLeft{ false };
	bool DpadRight{ false };
	bool Start{ false };
	bool Back{ false };
	bool Xbox{ false };
	float RTrigger{ 0.0f };
	float LTrigger{ 0.0f };
	sf::Vector2f RightThumbStick{ 0.0f,0.0f };
	sf::Vector2f LeftThumbStick{ 0.0f,0.0f };
};

//a class for all the sf::text
class ButtTexts
{

public:

	ButtTexts();
	sf::Text text;
	sf::Font buttFont;
	
};

/// <summary>
/// Xbox controller class to query current state of controller
/// to mimic the controller states like XNA
/// </summary>
class xBxCon
{
private:

	// deadzone for the dpad (really a joystick)
	const int dpadThreshold = 50;
	sf::RenderWindow*	m_window;

	float trigAx = 0.0f;
	sf::Vector2f leftStickAxis = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f rightStickAxis = sf::Vector2f (0.0f, 0.0f);
	sf::Vector2f dpAxis = sf::Vector2f(0.0f,0.0f);

public:

    sf::Joystick joSt;
	// number of connected controllers
	static int s_noOfControllers;

	// index count for multiple controllers if connected
	int sf_Joystick_index = 0;

	// the current state of all the buttons
	GamePadState m_currentState;

	// the previous state to use to check for the moment a button is pressed
    GamePadState m_previousState;

	sf::Font	buttFont;

	//sf::texts 
	ButtTexts	buttTextA;
	ButtTexts	buttTextB;
	ButtTexts	buttTextX;
	ButtTexts	buttTextY;
	ButtTexts	buttTextLB;
	ButtTexts	buttTextRB;
	ButtTexts	buttTextLeftClick;
	ButtTexts	buttTextRightClick;
	ButtTexts	buttTextOptions;
	ButtTexts	buttTextMenu;
	ButtTexts	trigAxText;
	ButtTexts	leftStickAxisText;
	ButtTexts	rightStickAxisText;
	ButtTexts	dpAxisText;
	ButtTexts	buttUpText;
	ButtTexts	buttDownText;
	ButtTexts	buttLeftText;
	ButtTexts	buttRightText;
	ButtTexts	lastButtText;

	xBxCon();
	//~xBxCon();
	
	bool	isConnect{ false };
	bool	connect{ false };

	int		lastButt{ -1 };

	sf::Texture imgTexture;
	sf::Sprite	imgSprite;

	void	textSetup();
	void	init(sf::RenderWindow* t_window);
	void	cntrlrPressEvent(sf::Event t_event);
	void	cntrlrReleaseEvent(sf::Event t_event);
	void	buttSwitch(int t_cntrlrButt);
	void	update(sf::Time t_timePerFrame);
	void	updateFaceButts();
	void	updateDpad();
	void	draw();
	
};
#endif // !XBOX360CONTROLLER
