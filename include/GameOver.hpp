//
// Header File - GameOver
//
// Too bad, you lost.
//
// More infos may come here..
//
//

#ifndef GAMEOVER_HPP_
# define GAMEOVER_HPP_

# include "AScene.hpp"

class	GameOver	:	public AScene
{
public:
  GameOver(void);
  virtual ~GameOver(void);

  virtual void			draw(void);

  // Handler for keys
  virtual void			OnKeyPressed(void);

private:

  sf::Font	_font;
  sf::Text	_gameover;
  sf::Text	_score;
  sf::Text	_pressspace;
  bool		_scoreset;
};

# include "MainGame.hpp"

#endif /* !ASCENE_HPP_ */
