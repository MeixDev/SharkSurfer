//
// Header File - EnSprite
//
// Contains the Sprite & Texture of the enemy.
// The "anim" function is used to animate the sprite.
//
// Do it, Sismo.
//

#ifndef ENSPRITE_HPP_
# define ENSPRITE_HPP_

# include <SFML/Graphics.hpp>
# include <string>
# include <iostream>

class	EnSprite
{
public:
  // Feel free to add more stuff if necessary.
  EnSprite(std::string const &file,
	   unsigned int nbFrames,
	   unsigned int speed);
  ~EnSprite(void);

  sf::Texture const	&getTex(void)		const;

  sf::Sprite const	&getSprite(void)	const;

  unsigned int	getMaxFrames(void)	const;

  unsigned int	getCurFrame(void)	const;
  void		setCurFrame(unsigned int);

  unsigned int	getSpeed(void)		const;
  void		setSpeed(unsigned int);

  sf::Vector2u	getSpriteDim(void)	const;

  void		anim(void);

private:
  sf::Texture	_tex;
  sf::Sprite	_sprite;
  unsigned int	_nbFrames;
  unsigned int	_curFrame;
  unsigned int	_speed;
  sf::Vector2u	_spriteDim;
};

#endif /* !ENSPRITE_HPP_ */
