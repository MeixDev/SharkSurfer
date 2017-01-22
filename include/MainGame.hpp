//
// Header File - MainGame class.
//
// Started by MeixDev on 01/20/17, 28:58
//
// Empty for infos..
//
//
//

#ifndef MAINGAME_CPP_
# define MAINGAME_CPP_

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include "AScene.hpp"
# include "Player.hpp"

class	MainGame
{
public:
  MainGame(void);
  ~MainGame(void);

  sf::RenderWindow	*Win(void)		const;
  void			setWin(sf::RenderWindow *);

  AScene		*Scene(void)		const;
  void			setScene(AScene *);;

  std::string const	&Title(void)		const;
  void			setTitle(std::string const &);

  bool const		&getEasterEgg(void)	const;
  void			setEasterEgg(bool value);

  void			drawEasterEgg(void);

  Player		*getPlayer(void);
  void			setPlayer(Player *);

private:
  sf::RenderWindow	*win;
  AScene		*scn;
  std::string		title;
  bool			_easterEgg;
  sf::RectangleShape	_rectangle;
  Player		*_player;
};

#endif /* !MAINGAME_CPP_ */
