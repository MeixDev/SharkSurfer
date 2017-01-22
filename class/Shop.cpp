#include <SFML/Graphics.hpp>
#include "../include/Shop.hpp"
#include "OnWaves1.hpp"

Shop::Shop()
{
	// Load des images necessaires a la scene
	if (!_texMove.loadFromFile("rsrcs/spr_sheet.png") ||
		!_texStand.loadFromFile("rsrcs/stand.png")	||
		!_texBG.loadFromFile("rsrcs/bg.png")		||
		!_font.loadFromFile("rsrcs/dpcomic.ttf"))
	{
		std::cerr << "Couldn't load File" << std::endl;
		exit(1);
	}

	this->setHasMusic(true);
	this->setMusic("rsrcs/Casa_Bossa_Nova.wav");
	this->getMusic().setLoop(true);
	this->getMusic().play();

	// Initialisation des sprite et des textures des différents elements
	_recMove = sf::IntRect(0, 0, 70, 72);
	_sprMove = sf::Sprite(_texMove);
	_sprMove.setTextureRect(sf::IntRect(0, 0, 70, 72));
	_sizMove = _texMove.getSize();

	_recStand = sf::IntRect(0,0,67,74);
	_sprStand = sf::Sprite(_texStand);
	_sprStand.setTextureRect(sf::IntRect(0, 0, 67, 74));
	_sizStand = _texStand.getSize();

	_text.setFont(_font);
	_text.setString("Space to interact !");
	_text.setCharacterSize(65);
	_text.setFillColor(sf::Color::Green);
	_text.setOutlineThickness(2.3f);
	_text.setPosition(30, 40);

	// Set de la position de Butch
	_sprMove.setPosition(10, 320);
	_rectBG = sf::IntRect(0, 0, 1280, 720);
	_sprBG	= sf::Sprite(_texBG);
	_sprBG.setTextureRect(sf::IntRect(0, 0, 1280, 720));

}

Shop::~Shop() {}

void	Shop::OnKeyPressed()
{
	if (getBoolDial())
	  getDialog()->OnKeyPressed();
	else
	  {
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	      {
		if (_onGunz)
		  setDialog(new Dialog("Heya. In the final version of\nthe game, I will sell WEAPONS.", "rsrcs/MsGunz.png", new Dialog("So you can defeat all\nthose damn frost monsters.", "rsrcs/MsGunz.png")));
		if (_onPonton)
		  setDialog(new Dialog("That's the way to the Wave.\nBut those damn devs were slow.", "rsrcs/Butch.png", new Dialog("But it's their first creation.\nAnd they just learnt C++", "rsrcs/Butch.png", new Dialog("In two weeks !\nSo please be tolerant!", "rsrcs/Butch.png", new Dialog("So sadly, there is no\nmuch to see there.", "rsrcs/Butch.png", new Dialog("But if you really want to go..\nYou can press the 'Up' key here.", "rsrcs/Butch.png"))))));
		if (_onHouse)
		  setDialog(new Dialog("The nurse isn't here ?..\nWell, it's not like I needed her.", "rsrcs/Butch.png", new Dialog("In the final version..\nShe will sell health upgrades.", "rsrcs/Butch.png")));
	      }
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	      {
		if (_onPonton)
		  this->Main()->setScene(new OnWaves1);
	      }
	    // Catch de la touche utilisee pour le déplacement
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	      {
		if (this->Win()->getSize().x > 1280)
		  _sprMove.move(0.30f,0);
		else
		  _sprMove.move(0.25f,0);
	      }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	      {
		// Si le personnage doit aller dans l'autre sens, inversion du sprite en verifiant que le rectangle n'est pas au debut de la sprite sheet
		if (_recMove.left > 0)
		  _sprMove.setTextureRect(sf::IntRect(_recMove.left, 0, -70, 72));
		else
		  _sprMove.setTextureRect(sf::IntRect(280, 0, -70, 72));
		if (this->Win()->getSize().x > 1280)
		  _sprMove.move(-0.30f, 0);
		else
		  _sprMove.move(-0.25f, 0);
	      }
	  }
}

void	Shop::draw()
{
  if (_sprMove.getPosition().x > 30 && _sprMove.getPosition().x < 100)
    {
      _onGunz = true;
      _onPonton = false;
      _onPonton = false;
    }
  else if (_sprMove.getPosition().x > 400 && _sprMove.getPosition().x < 650)
    {
      _onGunz = false;
      _onPonton = true;
      _onHouse = false;
    }
  else if (_sprMove.getPosition().x > 800 && _sprMove.getPosition().x < 1100)
    {
      _onGunz = false;
      _onPonton = false;
      _onHouse = true;
    }
  else
    {
      _onGunz = false;
      _onPonton = false;
      _onHouse = false;
    }
	// Creation des bordures de la fenetre pour la gestion des collisions
	sf::RectangleShape line2(sf::Vector2f(720, 1));
	line2.rotate(90);
	line2.setPosition(this->Win()->getSize().x, 0);
	sf::RectangleShape line4(sf::Vector2f(720, 1));
	line4.rotate(90);
	line4.setPosition(0, 0);
	sf::FloatRect bordD = line2.getGlobalBounds();
	sf::FloatRect bordG = line4.getGlobalBounds();

	// Recuperation de la position du personnage
	if (this->Win()->getSize().x > 1280)
		_sprMove.setPosition(_sprMove.getPosition().x, 500);
	sf::Vector2f j = _sprMove.sf::Transformable::getPosition();

	// Affichage du fond avant l'affichage de Butch
	if (this->Win()->getSize().x > 1280)
		_sprBG.setScale(1.5f, 1.5f);
	this->Win()->draw(_sprBG);

	// Si une touche de deplacement est utilisee
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// Verification du temps ecoule depuis l'initialisationd de la clock
		if (clock.getElapsedTime().asMilliseconds() > 250.0f)
		{
			// Si le rectangle du sprite est au bout de la sprite sheet retour au debut
			if (_recMove.left == 210)
				_recMove.left = 0;
			// Sinon deplacement du rectangle a afficher de la taille d'un sprite (ici 70)
			else
				_recMove.left += 70;
			// set du rectangle de texture a afficher et reset de la clock
			_sprMove.setTextureRect(_recMove);
		    clock.restart();
		}

		// Appel de la fonction qui s'occupe de set l'image en fonction de la touche
		OnKeyPressed();

		// Set de la box de collision et verification de la collision avec les bords de l'ecran
		sf::FloatRect boundingBox = _sprMove.getGlobalBounds();
		if (boundingBox.intersects(bordD) || boundingBox.intersects(bordG))
		{
			_sprMove.setPosition(j.x, j.y);
		}

		// Affichage du sprite
		if (this->Win()->getSize().x > 1280)
			_sprMove.setScale(3, 3);
		else
			_sprMove.setScale(2, 2);
		this->Win()->draw(_sprMove);
	}

	// Sinon utilisation de la sprite sheet avec le personnage immobile
	else
	{
		if (clock.getElapsedTime().asMilliseconds() > 300.0f)
		{
			if (_recStand.left == 201)
		 	   _recStand.left = 0;
		    else
		       _recStand.left += 67;
		    _sprStand.setTextureRect(_recStand);
		    clock.restart();
		}

		// Set de la position à l'endroit ou le mouvement s'est arrete
		_sprStand.setPosition(j);
		if (this->Win()->getSize().x > 1280)
			_sprStand.setScale(3, 3);
		else
			_sprStand.setScale(2, 2);
		this->Win()->draw(_sprStand);
	}
	if ((_onGunz || _onPonton || _onHouse) && !getBoolDial())
	  this->Win()->draw(_text);
	if (getBoolDial())
	  getDialog()->draw();
}
