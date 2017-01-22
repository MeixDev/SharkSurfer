//
// Header File - Dialog
//
// Class that can be used to call a Dialog in most scenes.
//
// More infos may come..
//
//

#ifndef DIALOG_HPP_
# define DIALOG_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <string>
# include <iostream>

class	AScene;

class	Dialog
{
public:
  Dialog(std::string const &line,
	 std::string const &mugshot,
	 Dialog *next = NULL);
  ~Dialog(void);

  sf::RenderWindow	*Win(void)	const;
  void			setWin(sf::RenderWindow *);

  AScene		*Scene(void)	const;
  void			setScene(AScene *);

  void		reset(void);

  void		draw(void);

  void		OnKeyPressed(void);



private:
  sf::RenderWindow	*_win;
  Dialog		*_next;
  AScene		*_parent;
  sf::Clock		_clock;

  sf::Sprite		_mugshot;
  sf::Texture		_texmug;
  sf::Vector2u		_sizemug;

  sf::Sprite		_ui;
  sf::Texture		_texui;
  sf::Vector2u		_sizeui;

  sf::Sprite		_valid;
  sf::Texture		_texvalid;
  sf::Vector2u		_sizevalid;

  bool			_left;
  int			_offset;

  sf::Font		_font;
  sf::Text		_text;

  sf::SoundBuffer	_typingbf;
  sf::Sound		_typing;

  std::string const	string;
  std::string		_sub;
  unsigned int		_sizestr;
  unsigned int		_index;

};

# include "AScene.hpp"

#endif /* !DIALOG_HPP_ */
