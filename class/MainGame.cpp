//
// CPP File - MainGame class.
//
// Started by MeixDev on 01/21/17, 00:02
//
// Empty for infos..
//
//
//

#include "MainGame.hpp"
#include <cstdlib>
#include <ctime>

MainGame::MainGame(void)
{
  srandom(time(NULL));
  switch (random() % 11)
    {
    case 0:
      this->title = "Sharky & Butch: Let's save Hyrriu!";
      break ;
    case 1:
      this->title = "Sharky & Butch: The last Wave";
      break ;
    case 2:
      this->title = "Sharky & Butch: Yet another random Title";
      break ;
    case 3:
      this->title = "Sharky & Butch: The Frostwave's malediction";
      break ;
    case 4:
      this->title = "Sharky & Butch: \"ELEVEN different titles! Yes sir!\"";
      break ;
    case 5:
      this->title = "Sharky & Butch: Zleuf isn't salty";
      break ;
    case 6:
      this->title = "Sharky & Butch: A lovely story not-telling game!";
      break ;
    case 7:
      this->title = "Sharky & Butch: Soda powered game";
      break ;
    case 8:
      this->title = "Sharky & Butch: A GGJ2017 Game. At least we tried!";
      break ;
    case 9:
      this->title = "Sharky & Butch: The revenge of the return of the Frost";
      break ;
    case 10:
      this->title = "Sharky & Butch: It's not a glitch, it's a feature!";
      break ;
    }
  this->win = new sf::RenderWindow(sf::VideoMode(1280, 720),
				   this->title,
				   sf::Style::Titlebar | sf::Style::Close);
  this->scn = NULL;
  this->_easterEgg = false;
  this->_rectangle = sf::RectangleShape(sf::Vector2f(1280, 20));
  this->_rectangle.setFillColor(sf::Color(40, 40, 40, 120));
  this->_player = new Player;
}

MainGame::~MainGame(void)
{
  delete win;
}

sf::RenderWindow	*MainGame::Win(void)		const
{
  return (this->win);
}

void			MainGame::setWin(sf::RenderWindow *nwin)
{
  this->win = nwin;
}

AScene			*MainGame::Scene(void)		const
{
  return (this->scn);
}

void			MainGame::setScene(AScene *nscn)
{
  delete this->scn;
  this->scn = nscn;
  this->scn->setWindow(this->win);
  this->scn->setMain(this);
}

std::string const	&MainGame::Title(void)		const
{
  return (this->title);
}

void			MainGame::setTitle(std::string const &t)
{
  this->title = t;
}

bool const		&MainGame::getEasterEgg(void)	const
{
  return (this->_easterEgg);
}

void			MainGame::setEasterEgg(bool value)
{
  this->_easterEgg = value;
}

void			MainGame::drawEasterEgg(void)
{
  this->_rectangle.setPosition(sf::Vector2f(0, 0));
  for (int i = 0 ; i < 31 ; ++i)
    {
      this->_rectangle.move(0, 20);
      this->win->draw(this->_rectangle);
      this->_rectangle.move(0, 30);
    }
}

Player			*MainGame::getPlayer(void)
{
  return (this->_player);
}

void			MainGame::setPlayer(Player *p)
{
  delete this->_player;
  this->_player = p;
}
