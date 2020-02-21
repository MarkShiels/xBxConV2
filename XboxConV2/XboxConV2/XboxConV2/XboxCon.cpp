//author: Mark Shiels
#include "XboxCon.h"

//default constructor

ButtTexts::ButtTexts()
{
	if (!buttFont.loadFromFile("Assets/Fonts/Hack-Regular.ttf"))
	{
		std::cout << "Can't load font." << std::endl;
	}

	text.setFont(buttFont);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(20);

	//std::cout << "Archer" << std::endl;
}

xBxCon::xBxCon()
{
	std::cout << "Fuuuuuuuuu" << std::endl;
	textSetup();
	
	//dpAxisText.text.setPosition(300, 500);

}

void xBxCon::textSetup()
{
	//std::cout << "manchu" << std::endl;

	buttTextA.text.setString("A");
	buttTextA.text.setPosition(750, 420);
	buttTextB.text.setString("B");
	buttTextB.text.setPosition(750, 360);
	buttTextX.text.setString("X");
	buttTextX.text.setPosition(750, 300);
	buttTextY.text.setString("Y");
	buttTextY.text.setPosition(750, 240);
	buttTextLB.text.setString("LB");
	buttTextLB.text.setPosition(175, 90);
	buttTextRB.text.setString("RB");
	buttTextRB.text.setPosition(635, 90);
	buttTextOptions.text.setString("Options");
	buttTextOptions.text.setPosition(100, 500);
	buttTextMenu.text.setString("Menu");
	buttTextMenu.text.setPosition(715, 540);
	buttTextLeftClick.text.setString("Left Stick Click");
	buttTextLeftClick.text.setPosition(0, 320);
	buttTextRightClick.text.setString("Right Stick Click");
	buttTextRightClick.text.setPosition(520, 530);
	trigAxText.text.setPosition(300, 100);
	leftStickAxisText.text.setPosition(5, 180);
	rightStickAxisText.text.setPosition(520, 520);
	buttUpText.text.setString("Up");
	buttUpText.text.setPosition(220, 520);
	buttDownText.text.setString("Down");
	buttDownText.text.setPosition(220, 550);
	buttLeftText.text.setString("Left");
	buttLeftText.text.setPosition(180, 535);
	buttRightText.text.setString("Right");
	buttRightText.text.setPosition(240, 535);
}

void xBxCon::init(sf::RenderWindow* t_window)
{
	m_window = t_window;

	if (!imgTexture.loadFromFile("Assets/Images/controller.jpg"))

	{

	}

	imgSprite.setTexture(imgTexture);
	imgSprite.setPosition(0, 0);

}

//update method, tracks axis changes
void xBxCon::update(sf::Time t_timePerFrame)
{

	/*trigAx = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);//change controller
	trigAxText.text.setString("Triggers: " + std::to_string(trigAx));

	leftStickAxis.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);//change controller
	leftStickAxis.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);//change controller
	leftStickAxisText.text.setString("LS: " + std::to_string(leftStickAxis.x) + "\n    " + std::to_string(leftStickAxis.y));

	rightStickAxis.x = sf::Joystick::getAxisPosition(0, sf::Joystick::U);//change controller
	rightStickAxis.y = sf::Joystick::getAxisPosition(0, sf::Joystick::V);//change controller
	rightStickAxisText.text.setString("RS: " + std::to_string(rightStickAxis.x) + "\n    " + std::to_string(rightStickAxis.y));

	dpAxis.x = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX);
	dpAxis.y = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY);

	dpAxis.x < -dpadThreshold ? m_currentState.DpadLeft = true : m_currentState.DpadLeft = false ;
	dpAxis.x > dpadThreshold ? m_currentState.DpadRight = true : m_currentState.DpadRight = false;
	dpAxis.y > dpadThreshold ? m_currentState.DpadUp = true : m_currentState.DpadUp = false;
	dpAxis.y < -dpadThreshold ? m_currentState.DpadDown = true : m_currentState.DpadDown = false;*/

	updateFaceButts();
	updateDpad();
}

void xBxCon::updateFaceButts()
{
	if (joSt.isButtonPressed(0, 6)) m_window->close();
	if (joSt.isButtonPressed(0, 0)) m_currentState.A = true;
	else m_currentState.A = false;
	if (joSt.isButtonPressed(0, 1)) m_currentState.B = true;
	else m_currentState.B = false;
	if (joSt.isButtonPressed(0, 2)) m_currentState.X = true;
	else m_currentState.X = false;
	if (joSt.isButtonPressed(0, 3)) m_currentState.Y = true;
	else m_currentState.Y = false;
	if (joSt.isButtonPressed(0, 4)) m_currentState.LB = true;
	else m_currentState.LB = false;
	if (joSt.isButtonPressed(0, 5)) m_currentState.RB = true;
	else m_currentState.RB = false;
	if (joSt.isButtonPressed(0, 7)) m_currentState.Start = true;
	else m_currentState.Start = false;
	
}

void xBxCon::updateDpad()
{
	dpAxis.x = joSt.getAxisPosition(0, sf::Joystick::Axis::PovX);
	dpAxis.y = joSt.getAxisPosition(0, sf::Joystick::Axis::PovY);

	if (dpAxis.x > dpadThreshold)
	{
		m_currentState.DpadRight = true;
		m_currentState.DpadLeft = false;

	}
	else if (dpAxis.x < -dpadThreshold)
	{
	
		m_currentState.DpadRight = false;
		m_currentState.DpadLeft = true;
	
	}
	else
	{

		m_currentState.DpadRight = false;
		m_currentState.DpadLeft = false;

	}

	if (dpAxis.y > dpadThreshold)
	{
		m_currentState.DpadUp = true;
		m_currentState.DpadDown = false;

	}
	else if (dpAxis.y < -dpadThreshold)
	{

		m_currentState.DpadUp = false;
		m_currentState.DpadDown = true;

	}
	else
	{

		m_currentState.DpadUp = false;
		m_currentState.DpadDown = false;

	}
}

//changes button state on button release
/*void xBxCon::cntrlrReleaseEvent(sf::Event t_event)
{
	
	switch (lastButt)// this is most likely the biggest problem in the button logic, should have switched something else
	{
	case 0:
		m_currentState.A = false;
		break;
	case 1:
		m_currentState.B = false;
		break;
	case 2:
		m_currentState.X = false;
		break;
	case 3:
		m_currentState.Y = false;
		break;
	case 4:
		m_currentState.LB = false;
		break;
	case 5:
		m_currentState.RB = false;
		break;
	case 6:
		m_currentState.Back = false;
		break;
	case 7:
		m_currentState.Start = false;
		break;
	case 8:
		m_currentState.LeftThumbStickClick = false;
		break;
	case 9:
		m_currentState.RightThumbStickClick = false;
		break;

	default:
		break;

	}


	//testing button release
	std::cout << m_currentState.A << std::endl;
	std::cout << m_currentState.B << std::endl;
	std::cout << m_currentState.X << std::endl;
	std::cout << m_currentState.Y << std::endl;
	std::cout << m_currentState.LB << std::endl;
	std::cout << m_currentState.RB << std::endl;
	std::cout << m_currentState.Back << std::endl;
	std::cout << m_currentState.Start << std::endl;
	std::cout << m_currentState.LeftThumbStickClick << std::endl;
	std::cout << m_currentState.RightThumbStickClick << std::endl;
	std::cout << "------------------" << std::endl;

}
*/


//changes the state for a pressed button, updates the last button pressed
/*void xBxCon::buttSwitch(int t_cntrlrButt)
{
	switch (t_cntrlrButt)
	{
	case 0:
		m_previousState.A = m_currentState.A;
		m_currentState.A = true;
		break;
	case 1:
		m_previousState.B = m_currentState.B;
		m_currentState.B = true;
		break;
	case 2:
		m_previousState.X = m_currentState.X;
		m_currentState.X = true;
		break;
	case 3:
		m_previousState.Y = m_currentState.Y;
		m_currentState.Y = true;
		break;
	case 4:
		m_previousState.LB = m_currentState.LB;
		m_currentState.LB = true;
		break;
	case 5:
		m_previousState.RB = m_currentState.RB;
		m_currentState.RB = true;
		break;
	case 6:
		m_previousState.Back = m_currentState.Back;
		m_currentState.Back = true;
		break;
	case 7:
		m_previousState.Start = m_currentState.Start;
		m_currentState.Start = true;
		break;
	case 8:
		m_previousState.LeftThumbStickClick = m_currentState.LeftThumbStickClick;
		m_currentState.LeftThumbStickClick = true;
		break;
	case 9:
		m_previousState.RightThumbStickClick = m_currentState.RightThumbStickClick;
		m_currentState.RightThumbStickClick = true;
		break;

	default:
		break;

	}
	
}*/

void xBxCon::draw()
{

	if (m_currentState.A)
	{
		m_window->draw(buttTextA.text);
		std::cout << "A" << std::endl;
	}
	if (m_currentState.B) 
	{
		m_window->draw(buttTextB.text);
		std::cout << "B" << std::endl;
	}
	if (m_currentState.X)
	{
		m_window->draw(buttTextX.text);
		std::cout << "X" << std::endl;
	}
	if (m_currentState.Y) 
	{
		m_window->draw(buttTextY.text);
		std::cout << "Y" << std::endl;
	}
	if (m_currentState.LB)
	{
		m_window->draw(buttTextLB.text);
		std::cout << "LB" << std::endl;
	}
	if (m_currentState.RB)
	{
		m_window->draw(buttTextRB.text);
		std::cout << "RB" << std::endl;
	}
	/*if (m_currentState.Back)
	{
		m_window->draw(buttTextOptions.text);
		std::cout << "Options" << std::endl;
	}*/
	if (m_currentState.Start)
	{
		m_window->draw(buttTextMenu.text);
		std::cout << "Menu" << std::endl;
	}
	//if (m_currentState.LeftThumbStickClick) m_window->draw(buttTextLeftClick.text);
	//if (m_currentState.RightThumbStickClick) m_window->draw(buttTextRightClick.text);
	if (m_currentState.DpadUp)
	{
		m_window->draw(buttUpText.text);
		std::cout << "Up" << std::endl;
	}
	if (m_currentState.DpadDown)
	{
		m_window->draw(buttDownText.text);
		std::cout << "Down" << std::endl;
	}
	if (m_currentState.DpadLeft)
	{
		m_window->draw(buttLeftText.text);
		std::cout << "Left" << std::endl;
	}
	if (m_currentState.DpadRight)
	{
		m_window->draw(buttRightText.text);
		std::cout << "Right" << std::endl;
	}

	/*m_window->draw(trigAxText.text);
	m_window->draw(leftStickAxisText.text);
	m_window->draw(rightStickAxisText.text);*/

	m_window->draw(imgSprite);
}