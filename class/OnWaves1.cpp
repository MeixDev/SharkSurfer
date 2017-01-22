
//
// CPP File - OnWaves1
//
// First level
//
// More infos may come here..
//
//

#include "OnWaves1.hpp"
#include "GameOver.hpp"

OnWaves1::OnWaves1(void)
{}

OnWaves1::~OnWaves1(void)
{}

void		OnWaves1::draw(void)
{
  // Draw de la scene
  // ...
  OnWaves::draw();
  if (this->getBoolDial() == true)
    this->getDialog()->draw();
}

void		OnWaves1::OnKeyPressed(void)
{
  if (this->getBoolDial() == true)
    this->getDialog()->OnKeyPressed();
  else
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
	  sf::Keyboard::isKeyPressed(sf::Keyboard::Return ))
	this->setDialog(new Dialog("He's back yo!", "rsrcs/Butch.png"));
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	this->setLocScore(this->getLocScore() + 13);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
	  this->Main()->getPlayer()->setCurHealth(this->Main()->getPlayer()->getCurHealth() - 1);
	  if (this->Main()->getPlayer()->getCurHealth() == 0)
	    {
	      this->Main()->setScene(new GameOver);
	    }
	}
    }
}
