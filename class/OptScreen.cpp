//
// CPP File - OptScreen
//
// OptScreen is the first scene of the game.
// It's used to ask the user if he wants to go Fullscreen
//
//
//

#include "OptScreen.hpp"
#include "TitleScreen.hpp"
#include "Shop.hpp"

OptScreen::OptScreen(void)
{
  if (!this->_font.loadFromFile("rsrcs/dpcomic.ttf") ||
      !this->_buffer.loadFromFile("rsrcs/select.wav") ||
      !this->_easterbf.loadFromFile("rsrcs/easter.wav"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }
  this->_sound.setBuffer(this->_buffer);
  this->_easter.setBuffer(this->_easterbf);
  this->_choice = false;
  this->_konami = 0;

  this->_asking.setFont(this->_font);
  this->_asking.setString("Hey there!\nThis game can be played as both\nWindowed or Fullscreen.\nPlease choose your favorite:");
  this->_asking.setCharacterSize(72);
  this->_asking.setFillColor(sf::Color::White);

  this->_nonSelected = sf::Color(60, 60, 60);
  this->_isSelected = sf::Color(0, 196, 0);

  this->_windowed.setFont(this->_font);
  this->_windowed.setString("Windowed!");
  this->_windowed.setCharacterSize(112);
  this->_windowed.setFillColor(sf::Color::White);
  this->_windowed.setOutlineColor(this->_isSelected);
  this->_windowed.setOutlineThickness(3.6f);

  this->_fullscreen.setFont(this->_font);
  this->_fullscreen.setString("Fullscreen!");
  this->_fullscreen.setCharacterSize(112);
  this->_fullscreen.setFillColor(sf::Color::White);
  this->_fullscreen.setOutlineColor(this->_nonSelected);
  this->_fullscreen.setOutlineThickness(3.6f);

  this->_asking.move(100, 100);
  this->_windowed.move(120, 500);
  this->_fullscreen.move(720, 500);
}

OptScreen::~OptScreen(void) {}

void		OptScreen::draw(void)
{
  this->Win()->draw(this->_asking);
  if (!this->_choice)
    {
      this->_windowed.setOutlineColor(this->_isSelected);
      this->_fullscreen.setOutlineColor(this->_nonSelected);
    }
  else
    {
      this->_fullscreen.setOutlineColor(this->_isSelected);
      this->_windowed.setOutlineColor(this->_nonSelected);
    }
  this->Win()->draw(this->_windowed);
  this->Win()->draw(this->_fullscreen);
}

void		OptScreen::OnKeyPressed(void)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      if (this->_konami < 2)
	++this->_konami;
      else
	this->_konami = 0;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      if (this->_konami < 4)
	++this->_konami;
      else
	this->_konami = 0;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      if (this->_konami == 4 || this->_konami == 6)
	++this->_konami;
      else
	this->_konami = 0;
      if (this->_choice)
	{
	  this->_choice = false; // Aka "Windowed!"
	  this->_sound.play();
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      if (this->_konami == 5 || this->_konami == 7)
	++this->_konami;
      else
	this->_konami = 0;
      if (!this->_choice)
	{
	  this->_choice = true; // Aka "Fullscreen!"
	  this->_sound.play();
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
      if (this->_konami == 8)
	++this->_konami;
      else
	this->_konami = 0;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      if (this->_konami == 9)
	{
	  this->_easter.play();
	  this->Main()->setEasterEgg(true);
	}
      else
	this->_konami = 0;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
      if (this->_choice)
	this->replaceWindow(sf::Style::Fullscreen);
      else
	this->replaceWindow(sf::Style::Titlebar | sf::Style::Close);
      this->Main()->setScene(new TitleScreen);
    }
}

void		OptScreen::replaceWindow(sf::Uint32 style)
{
  delete this->Win();
  this->Main()->setWin(new sf::RenderWindow(sf::VideoMode(1280, 720),
					    this->Main()->Title(),
					    style));
  this->setWindow(this->Main()->Win());
}
