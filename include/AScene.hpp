//
// Header File - AScene
//
// AScene is an Abstract class to handle all our scenes
//
// More infos may come here..
//
//

#ifndef ASCENE_HPP_
# define ASCENE_HPP_

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include "Dialog.hpp"

class	MainGame;

class	AScene
{
public:
  AScene(void);
  virtual ~AScene(void);

  typedef		void	(AScene::*fctKeyboard)(void);

  sf::RenderWindow	*Win(void)			const;
  void			setWindow(sf::RenderWindow *);

  MainGame		*Main(void)			const;
  void			setMain(MainGame *);

  sf::Event		&Event(void);

  virtual void			draw(void)			= 0;

  // Handler for keys
  virtual void			OnKeyPressed(void)		= 0;

  Dialog		*getDialog(void)		const;
  void			setDialog(Dialog *);

  bool			getBoolDial(void)		const;
  void			setBoolDial(bool v);

  bool			getHasMusic(void)		const;
  void			setHasMusic(bool v);

  sf::Music		&getMusic(void);
  void			setMusic(std::string const &filename);

private:
  sf::RenderWindow	*win;
  MainGame		*main;
  sf::Event		event;
  Dialog		*_dialog;
  bool			_onDial;
  sf::Music		_music;
  bool			_hasMusic;
};

# include "MainGame.hpp"

#endif /* !ASCENE_HPP_ */
