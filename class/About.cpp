//
// CPP File - About
//
// The page talking of the team !
//
// More infos may come here..
//
//

#include "About.hpp"
#include "TitleScreen.hpp"

About::About(void)
{
  if (!_font.loadFromFile("rsrcs/dpcomic.ttf"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }

  _thanks.setFont(_font);
  _thanks.setString("Thanks for playing!");
  _thanks.setCharacterSize(140);
  _thanks.setFillColor(sf::Color::White);
  _thanks.move(100, -20);

  _brought.setFont(_font);
  _brought.setString("The game was brought to you by:");
  _brought.setCharacterSize(80);
  _brought.setFillColor(sf::Color::White);
  _brought.move(40, 115);

  _devnames.setFont(_font);
  _devnames.setString("MeixDev (Lead Developer)\nSismoso (Developer)\nZLF aka Zleuf (Main Artist)\nCrocowaifu (Artist)\nand Lurivar (Helper)");
  _devnames.setCharacterSize(80);
  _devnames.setFillColor(sf::Color::White);
  _devnames.move(90, 200);

  _space.setFont(_font);
  _space.setString("(Press space to go back...)");
  _space.setCharacterSize(80);
  _space.setFillColor(sf::Color::White);
  _space.move(420, 600);
}

About::~About(void)
{}

void		About::draw(void)
{
  this->Win()->draw(_thanks);
  this->Win()->draw(_brought);
  this->Win()->draw(_devnames);
  this->Win()->draw(_space);
}

void		About::OnKeyPressed(void)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
      this->Main()->setScene(new TitleScreen);
    }
}
