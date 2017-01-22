//
// Header File - TitleScreen
//
// TitleScreen, the scene of the first real scene.
//
// More infos may come here..
//
//

#ifndef TITLESCREEN_HPP_
# define TITLESCREEN_HPP_

# include "AScene.hpp"

class	TitleScreen	:	public AScene
{
public:

  enum	Selection
    {
      PLAY = 0,
      ABOUT = 1,
      QUIT = 2
    };

  TitleScreen(void);
  ~TitleScreen(void);

  void			draw(void);

  // Handler for keys
  void			OnKeyPressed(void);

private:

  // Text & Fonts. Had to reload the font cuz'.. Who knows why.
  sf::Font		_font;
  sf::Text		_play;
  sf::Text		_quit;
  sf::Text		_about;
  sf::Color		_nonSelected;
  sf::Color		_isSelected;
  Selection		selected;

  sf::Sprite		_bg;
  sf::Texture		_texbg;
  sf::Vector2u		_sizbg;

  sf::Sprite		_logo;
  sf::Texture		_texlogo;
  sf::Vector2u		_sizlogo;

  // Selection sound
  sf::SoundBuffer	_buffer1;
  sf::Sound		_sound1;

  // Quit sound ?..
  sf::SoundBuffer	_buffer2;
  sf::Sound		_sound2;

  unsigned int		_offset;
  bool			_sens;
};

#endif /* !ASCENE_HPP_ */
