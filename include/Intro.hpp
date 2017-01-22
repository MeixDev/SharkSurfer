//
// Header File - Intro
//
// Let me tell you a story !
//
// More infos may come here..
//
//

#ifndef INTRO_HPP_
# define INTRO_HPP_

# include "AScene.hpp"
# include "Dialog.hpp"
# include "Anim.hpp"

class	Intro	:	public AScene
{
public:
  Intro(void);
  virtual ~Intro(void);

  void			draw(void);

  // Handler for keys
  void			OnKeyPressed(void);

private:
  bool		_talked;
  sf::Font	_font;
  sf::Text	_text;

  sf::Sprite	_bg;
  sf::Texture	_texbg;

  Anim		*_butch;

  sf::Sprite	_zlf;
  sf::Texture	_texzlf;

  sf::Sprite	_afro;
  sf::Texture	_texafro;

  sf::Sprite	_bald;
  sf::Texture	_texbald;

};

# include "MainGame.hpp"

#endif /* !ASCENE_HPP_ */
