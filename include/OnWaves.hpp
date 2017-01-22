//
// Header File - OnWaves
//
// Here comes the gameplay !
//
// More infos may come here..
//
//

#ifndef ONWAVES_HPP_
# define ONWAVES_HPP_

# include "AScene.hpp"
#include "Anim.hpp"

class	Player;

class	OnWaves	:	public AScene
{
public:
  OnWaves(void);
  virtual ~OnWaves(void);

  virtual void		draw(void);

  // Handler for keys
  virtual void		OnKeyPressed(void);

  unsigned int		getLocScore(void)	const;
  void			setLocScore(unsigned int);

private:

  sf::Clock		_clock;
  sf::Clock		clock;
  Anim		*Ani;
  Anim		*Anime;
  Anim		*A;
  unsigned int		_lscore;

  sf::Sprite		_sprhp;
  sf::Texture		_texhp;
  sf::Vector2u		_sizhp;

  sf::Sprite		_sprmer;
  sf::Texture		_texmer;
  sf::Vector2u		_sizmer;

  sf::Sprite		_sprwave;
  sf::Texture		_texwave;
  sf::Vector2u		_sizwave;

  sf::Font		_font;
  sf::Text		_textscore;

  void			draw_background(void);
  void			draw_wave(void);
  void			draw_health(void);
  void			draw_score(void);
  void			draw_enemies();
  Anim			*An;
  bool			inv;
  sf::Clock		invC;

  sf::SoundBuffer	_buffer;
  sf::Sound		_hurt;
};

# include "Player.hpp"

#endif /* !ASCENE_HPP_ */
