//
// CPP File - OnWaves
//
// Here comes the gameplay !
//
// More infos may come here..
//
//

#include "OnWaves.hpp"
#include "GameOver.hpp"

OnWaves::OnWaves(void)
{
  if (!_texhp.loadFromFile("rsrcs/Heart.png") ||
      !_texmer.loadFromFile("rsrcs/Background.png") ||
      !_texwave.loadFromFile("rsrcs/Wave.png") ||
      !_font.loadFromFile("rsrcs/dpcomic.ttf") ||
      !_buffer.loadFromFile("rsrcs/hurt.wav"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }

  _hurt.setBuffer(_buffer);

  this->setHasMusic(true);
  this->setMusic("rsrcs/Adventure_Meme.wav");
  this->getMusic().setVolume(50);
  this->getMusic().setLoop(true);
  this->getMusic().play();

  _sprhp = sf::Sprite(_texhp);
  _sizhp = _texhp.getSize();
  _sprmer = sf::Sprite(_texmer);
  _sizmer = _texmer.getSize();
  _sprwave = sf::Sprite(_texwave);
  _sizwave = _texwave.getSize();
  _sprwave.move(100, 0);
  _textscore.setFont(_font);
  _textscore.setCharacterSize(80);
  _textscore.setFillColor(sf::Color::White);
  _textscore.setOutlineColor(sf::Color::Black);
  _textscore.setOutlineThickness(3.4f);
  _textscore.move(760, -20);
  _lscore = 0;

	// Set du jouer et des ennemis de base
	An = new Anim("rsrcs/SharkSurf.png", 200, 360, 69, 98, 2);
	Ani = new Anim("rsrcs/piaf.png", 1240, 310, 50, 43, 3);
	Anime = new Anim("rsrcs/craby.png", 1240, 240, 94, 146, 4);
	A = new Anim("rsrcs/Weasel.png", 1240, 650, 84, 52, 8);
}

OnWaves::~OnWaves(void)
{}

void		OnWaves::draw_background(void)
{
  static unsigned int cnt = 0;
  static unsigned int offset = 0;
  _sprmer.setPosition(0.0f - offset, 0.0f);
  for (unsigned int i = 0 ; i < 6 ; ++i)
    {
      this->Win()->draw(_sprmer);
      _sprmer.move(_sizmer.x, 0.0f);
    }
  ++cnt;
  if (cnt == 10)
    {
      ++offset;
      cnt = 0;
    }
  offset %= 255;
}

void		OnWaves::draw_enemies()
{
	// Creation et affichage des ennemis
	if (clock.getElapsedTime().asMilliseconds() > 7000)
	{
		A = new Anim("rsrcs/Weasel.png", 1240, (5 + rand() % 743), 83, 52, 8);
		Anime = new Anim("rsrcs/craby.png", 1240, (15 + rand() % 650), 94, 146, 4);
		Ani = new Anim("rsrcs/piaf.png", 1240, (10 + rand() % 700), 50, 43, 3);
		clock.restart();
	}
	if (_clock.getElapsedTime().asMilliseconds() > 1000)
	  {
	    _lscore += 100;
	    _clock.restart();
	  }
	if (this->Win()->getSize().x > 1280)
	  {
	    A->Move(-0.30f, 0);
	    Ani->Move(-0.25f, 0);
	    Anime->Move(-0.20f, 0);
	  }
	else
	  {
	    A->Move(-0.51f, 0);
	    Ani->Move(-0.42f, 0);
	    Anime->Move(-0.40f, 0);
	  }
	this->Win()->draw(A->_spr);
	this->Win()->draw(Ani->_spr);
	this->Win()->draw(Anime->_spr);
}

// Might need some modifications.
// In order to anim the wave...
void		OnWaves::draw_wave(void)
{
	this->Win()->draw(An->_spr);
  this->Win()->draw(_sprwave);
}

void		OnWaves::draw_health(void)
{
  _sprhp.setPosition(10.0f, 10.0f);
  unsigned int curHP = this->Main()->getPlayer()->getCurHealth();
  for (unsigned int i = 0 ; i < curHP ; ++i)
    {
      this->Win()->draw(_sprhp);
      _sprhp.move(0, _sizhp.y + 10);
    }
}

void		OnWaves::draw_score(void)
{
  std::stringstream	oss;
  oss << "Score: " << std::setfill('0') << std::setw(8) << _lscore;
  oss.flush();
  _textscore.setString(oss.str());
  this->Win()->draw(_textscore);
}

void		OnWaves::draw(void)
{
  // Draws the background
  draw_background();
  // Draws the wave
  draw_wave();
  //Draws Life
  draw_health();
  //Draws the score
  draw_enemies();
  draw_score();
  srand(time(NULL));

	// Set des bordures avec les box de collision
  sf::RectangleShape    line1(sf::Vector2f(1280, 1));
  sf::RectangleShape 	line2(sf::Vector2f(720, 1));
  sf::RectangleShape    line3(sf::Vector2f(1280, 1));
  sf::RectangleShape    line4(sf::Vector2f(720, 1));

  line2.rotate(90);
  line4.rotate(90);
  line1.setPosition(0, this->Win()->getSize().y);
  line2.setPosition(350, 0);
  line3.setPosition(0, 0);
  line4.setPosition(100, 0);

  sf::FloatRect bordB = line1.getGlobalBounds();
  sf::FloatRect bordD = line2.getGlobalBounds();
  sf::FloatRect bordH = line3.getGlobalBounds();
  sf::FloatRect bordG = line4.getGlobalBounds();

  // Get de la position du joueur et affichage
  sf::Vector2f j = An->_spr.sf::Transformable::getPosition();
  this->Win()->draw(An->_spr);
	An->Move(0,0);

	// Catch des touches utilisees
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	  {
	    if (this->Win()->getSize().x > 1280)
	      An->Move(0, 0.20f);
	    else
	      An->Move(0, 0.35f);
	  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	  {
	    if (this->Win()->getSize().x > 1280)
	      An->Move(0, -0.20f);
	    else
	      An->Move(0, -0.35f);
	  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	  {
	    if (this->Win()->getSize().x > 1280)
	      An->Move(0.20f, 0);
	    else
	      An->Move(0.35f, 0);
	  }
	if	(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	  {
	    if (this->Win()->getSize().x > 1280)
	      An->Move(-0.20f, 0);
	    else
	      An->Move(-0.35f, 0);
	  }

	// Set des box engobantes du personnage et des ennemis
	sf::FloatRect boundingBox = An->_spr.getGlobalBounds();
	sf::FloatRect craby = Anime->_spr.getGlobalBounds();
	sf::FloatRect weasel = A->_spr.getGlobalBounds();
	sf::FloatRect piaf = Ani->_spr.getGlobalBounds();

	// Check des collisions avec les bords
	if (boundingBox.intersects(bordD) || boundingBox.intersects(bordG) || boundingBox.intersects(bordB) || boundingBox.intersects(bordH))
		An->_spr.setPosition(j.x, j.y);

	// Set des frames d'invincibilite
	if (invC.getElapsedTime().asSeconds() > 4)
		inv = false;

	// Check des collisions avec les ennemis
	if ((boundingBox.intersects(craby) && inv != true) || (boundingBox.intersects(weasel) && inv != true) || (boundingBox.intersects(piaf) && inv != true))
	{
		inv = true;
		invC.restart();
		this->Main()->getPlayer()->setCurHealth(this->Main()->getPlayer()->getCurHealth() - 1);
		_hurt.play();
		if (this->Main()->getPlayer()->getCurHealth() == 0)
		  {
		    this->Main()->getPlayer()->setScore(_lscore);
		    this->Main()->setScene(new GameOver);
		  }
	}
}

void		OnWaves::OnKeyPressed(void)
{}

unsigned int	OnWaves::getLocScore(void)	const
{ return (_lscore); }

void		OnWaves::setLocScore(unsigned int v)
{ _lscore = v; }
