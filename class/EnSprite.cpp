//
// CPP File - EnSprite
//
// Contains the Sprite & Texture of the enemy.
// The "anim" function is used to animate the sprite
//
// Do it, Sismo.
//

#include "EnSprite.hpp"

EnSprite::EnSprite(std::string const &file,
		   unsigned int nbFrames,
		   unsigned int speed)
{
  if (!_tex.loadFromFile(file))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }
  _sprite = sf::Sprite(_tex);
  _nbFrames = nbFrames;
  _curFrame = 0;
  _speed = speed;
  _spriteDim = _tex.getSize();
}

EnSprite::~EnSprite(void)
{}

sf::Texture const	&EnSprite::getTex(void)		const
{ return _tex; }

sf::Sprite const	&EnSprite::getSprite(void)	const
{ return _sprite; }

unsigned int	EnSprite::getMaxFrames(void)	const
{ return _nbFrames; }

unsigned int	EnSprite::getCurFrame(void)	const
{ return _curFrame; }

void		EnSprite::setCurFrame(unsigned int v)
{ _curFrame = v; }

unsigned int	EnSprite::getSpeed(void)	const
{ return _speed; }

void		EnSprite::setSpeed(unsigned int v)
{ _speed = v; }

sf::Vector2u	EnSprite::getSpriteDim(void)	const
{ return _spriteDim; }


// Here's the challenge:
// You must be able to animate the sprite, with the chosen speed
// If you need anything about DeathFrames and all, do as you wish.
// Just explain me afterwards.. </3
void		EnSprite::anim(void)
{}
