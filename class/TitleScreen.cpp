//
// CPP File - TitleScreen
//
// TitleScreen, the scene of the first real scene.
//
// More infos may come here..
//
//

#include "TitleScreen.hpp"
#include "OnWaves1.hpp"
#include "Intro.hpp"
#include "About.hpp"

TitleScreen::TitleScreen(void)
{
  if (!this->_font.loadFromFile("rsrcs/dpcomic.ttf") ||
      !this->_buffer1.loadFromFile("rsrcs/select.wav") ||
      !this->_buffer2.loadFromFile("rsrcs/quit.wav") ||
      !this->_texbg.loadFromFile("rsrcs/wavePhase.png") ||
      !this->_texlogo.loadFromFile("rsrcs/Logo.png"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }

  this->_offset = 0;
  this->_sens = false;

  this->_sound1.setBuffer(this->_buffer1);
  this->_sound2.setBuffer(this->_buffer2);

  this->setHasMusic(true);
  this->setMusic("rsrcs/Casa_Bossa_Nova.wav");
  this->getMusic().setLoop(true);
  this->getMusic().play();

  this->_logo = sf::Sprite(_texlogo);
  this->_logo.move(0, -40);
  this->_sizlogo = _texlogo.getSize();

  this->_bg = sf::Sprite(_texbg);
  this->_sizbg = _texbg.getSize();

  selected = TitleScreen::PLAY;

  //Set Colors
  this->_nonSelected = sf::Color(60, 60, 60);
  this->_isSelected = sf::Color(0, 196, 0);

  //Set Play Text
  this->_play.setFont(this->_font);
  this->_play.setString("Play!");
  this->_play.setCharacterSize(216);
  this->_play.setFillColor(sf::Color::White);
  this->_play.setOutlineThickness(6.3f);

  //Set Quit Text
  this->_quit.setFont(this->_font);
  this->_quit.setString("Quit");
  this->_quit.setCharacterSize(85);
  this->_quit.setFillColor(sf::Color::White);
  this->_quit.setOutlineThickness(3.6f);

  //Set About Us Text
  this->_about.setFont(this->_font);
  this->_about.setString("About us");
  this->_about.setCharacterSize(85);
  this->_about.setFillColor(sf::Color::White);
  this->_about.setOutlineThickness(3.6f);

  //Set positions
  this->_play.move(120, 440);
  this->_quit.move(1000, 580);
  this->_about.move(600, 580);
}

TitleScreen::~TitleScreen(void) {}

void		TitleScreen::draw(void)
{
  this->Win()->clear(sf::Color(151, 206, 240));
  this->Win()->draw(this->_bg);

  ++_offset;
  if (_offset % 10 == 0)
    this->_logo.move(0, (_sens ? -1 : 1));
  if (_offset % 250 == 0)
    {
      _offset = 0;
      _sens = !_sens;
    }
  this->Win()->draw(this->_logo);

  // Draw des choix
  this->_play.setOutlineColor(this->_nonSelected);
  this->_quit.setOutlineColor(this->_nonSelected);
  this->_about.setOutlineColor(this->_nonSelected);
  switch (this->selected)
    {
    case TitleScreen::PLAY:
      this->_play.setOutlineColor(this->_isSelected);
      break ;
    case TitleScreen::QUIT:
      this->_quit.setOutlineColor(this->_isSelected);
      break ;
    case TitleScreen::ABOUT:
      this->_about.setOutlineColor(this->_isSelected);
      break ;
    }
  this->Win()->draw(this->_play);
  this->Win()->draw(this->_quit);
  this->Win()->draw(this->_about);
}

void		TitleScreen::OnKeyPressed(void)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      if (this->selected > TitleScreen::PLAY)
	{
	  if (this->selected == TitleScreen::ABOUT)
	    this->selected = TitleScreen::PLAY;
	  else
	    this->selected = TitleScreen::ABOUT;
	  this->_sound1.play();
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      if (this->selected < TitleScreen::QUIT)
	{
	  if (this->selected == TitleScreen::PLAY)
	    this->selected = TitleScreen::ABOUT;
	  else
	    this->selected = TitleScreen::QUIT;
	  this->_sound1.play();
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
      if (this->selected == TitleScreen::PLAY)
	{
	  this->Main()->setScene(new Intro);
	}
      else if (this->selected == TitleScreen::ABOUT)
	{
	  this->Main()->setScene(new About);
	}
      else
	{
	  this->_sound2.play();
	  while (this->_sound2.getStatus() == sf::Sound::Playing) {}
	  this->Win()->close();
	}
    }
}
