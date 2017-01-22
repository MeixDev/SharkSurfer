#ifndef SHOP_HPP_
#define SHOP_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "AScene.hpp"
#include "Anim.hpp"

class Shop : public AScene
{
public:
  Shop();
  ~Shop();
private:
  sf::Sprite	_sprMove;
  sf::Texture	_texMove;
  sf::Vector2u	_sizMove;
  sf::IntRect	_recMove;

  sf::Sprite	_sprStand;
  sf::Texture	_texStand;
  sf::Vector2u	_sizStand;
  sf::IntRect	_recStand;

  sf::Sprite	_sprBG;
  sf::Texture	_texBG;
  sf::IntRect	_rectBG;

  sf::Text	_text;
  sf::Font	_font;
  sf::Clock	clock;

  bool		_onGunz;
  bool		_onPonton;
  bool		_onHouse;

  void	OnKeyPressed();
  void	draw();
};

#endif
