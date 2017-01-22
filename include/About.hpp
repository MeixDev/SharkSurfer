//
// Header File - About
//
// The page talking of the team !
//
// More infos may come here..
//
//

#ifndef ABOUT_HPP_
# define ABOUT_HPP_

# include "AScene.hpp"

class	About		:	public AScene
{
public:
  About(void);
  virtual ~About(void);

  virtual void			draw(void);

  // Handler for keys
  virtual void			OnKeyPressed(void);

private:
  sf::Font	_font;
  sf::Text	_thanks;
  sf::Text	_brought;
  sf::Text	_devnames;
  sf::Text	_space;
};

#endif /* !ABOUT_HPP_ */
