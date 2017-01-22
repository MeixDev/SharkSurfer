//
// Header File - OptScreen
//
// OptScreen is the first screen of the game.
// It's used to ask the user if he wants to go Fullscreen
//
//
//

#ifndef OPTSCREEN_HPP_
# define OPTSCREEN_HPP_

# include "AScene.hpp"

class	OptScreen	:	public AScene
{
public:
  OptScreen(void);
  ~OptScreen(void);

  void			draw(void);

  void			OnKeyPressed(void);

private:
  // Texts and Fonts
  // Colors are used to see which mode is currently selected
  sf::Font		_font;
  sf::Text		_asking;
  sf::Text		_windowed;
  sf::Text		_fullscreen;
  sf::Color		_nonSelected;
  sf::Color		_isSelected;
  bool			_choice;

  sf::SoundBuffer	_buffer;
  sf::Sound		_sound;

  sf::SoundBuffer	_easterbf;
  sf::Sound		_easter;

  // Easter Egg. ;)
  int			_konami;

  void			replaceWindow(sf::Uint32);
};

#endif /* !ASCENE_HPP_ */
