#ifndef ANIM_HPP
#define	ANIM_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class	Anim
{
public:
	Anim(std::string file, int	_posX, int	_posY, int	_sizeX, int	_sizeY, int _frame);
	~Anim();
	void	Move(float,float);
	sf::Sprite	_spr;
private:
	sf::Texture	_text;
	sf::IntRect	_rec;
	int			_posX;
	int			_posY;
	int			_sizeX;
	int			_sizeY;
	int			_frame;
	sf::Clock	clock;
};

#endif
