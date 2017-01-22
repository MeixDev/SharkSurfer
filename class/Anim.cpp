#include "Anim.hpp"


Anim::Anim(std::string file, int posX, int posY, int sizeX, int sizeY, int f)
{
	if (!_text.loadFromFile(file))
	{
		std::cerr << "Couldn't load File" << std::endl;
		exit(1);
	}

	_frame = f;
	_posX = posX;
	_posY = posY;
	_sizeX = sizeX;
	_sizeY = sizeY;

	_rec = sf::IntRect(0, 0, _sizeX, _sizeY);
	_spr = sf::Sprite(_text);
	_spr.setTextureRect(sf::IntRect(0, 0, _sizeX, _sizeY));
	_spr.setPosition(_posX, _posY);
}

Anim::~Anim()
{}

void	Anim::Move(float speedX, float speedY)
{
	if (clock.getElapsedTime().asMilliseconds() > 150)
	{
		if (_rec.left == (_sizeX * _frame) - _sizeX)
			_rec.left = 0;
		else
			_rec.left += _sizeX;
		_spr.setTextureRect(_rec);
		clock.restart();
	}
	_spr.move(speedX, speedY);
}
