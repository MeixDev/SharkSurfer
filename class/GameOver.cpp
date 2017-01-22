//
// CPP File - GameOver
//
// Too bad, you lost
//
// More infos may come here..
//
//

#include "GameOver.hpp"
#include "TitleScreen.hpp"

GameOver::GameOver(void)
{
  if (!_font.loadFromFile("rsrcs/dpcomic.ttf"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }
  _gameover.setFont(_font);
  _pressspace.setFont(_font);
  _score.setFont(_font);

  _gameover.setString("Game Over!");
  _gameover.setCharacterSize(200);
  _gameover.setFillColor(sf::Color::White);
  _gameover.setOutlineColor(sf::Color::Red);
  _gameover.setOutlineThickness(4.0f);

  _pressspace.setString("Press Space to go back...");
  _pressspace.setCharacterSize(80);
  _pressspace.setFillColor(sf::Color::White);

  _score.setCharacterSize(80);
  _score.setFillColor(sf::Color::White);

  _gameover.move(200, 200);
  _pressspace.move(255, 600);
  _score.move(255, 100);
  _scoreset = false;
}

GameOver::~GameOver(void) {}

void		GameOver::draw(void)
{
  if (!_scoreset)
    {
      std::stringstream	oss;
      oss << "Score: " << std::setfill('0') << std::setw(8) << this->Main()->getPlayer()->getScore();
      oss.flush();
      _score.setString(oss.str());
      _scoreset = true;
    }
  this->Win()->draw(_score);
  this->Win()->draw(_gameover);
  this->Win()->draw(_pressspace);
}

void		GameOver::OnKeyPressed(void)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      this->Main()->setPlayer(new Player);
      this->Main()->setScene(new TitleScreen);
    }
}
