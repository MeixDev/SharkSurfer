//
// Header File - Enemy
//
// Standard class for all the ennemies of the game
//
// More infos ?..
//
//

#ifndef ENEMY_HPP_
# define ENEMY_HPP_

# include <SFML/Graphics.hpp>
# include "EnSprite.hpp"

class	Enemy
{
public:
  Enemy(void);
  virtual ~Enemy(void);

  unsigned int	getHP(void)		const;
  void		setHP(unsigned int);

  unsigned int	getSpeed(void)		const;
  void		setSpeed(unsigned int);

  unsigned int	getAngle(void)		const;
  void		setAngle(unsigned int);

  EnSprite	*getSprite(void)	const;
  void		setSprite(EnSprite *);

  virtual void		act(void)		= 0;
  virtual void		shoot(void)		= 0;

private:
  unsigned int	_hp;
  unsigned int	_speed;

  unsigned int	_angle;
  int		_offset;
  bool		_sens;

  EnSprite	*_sprite;

  // Projectiles ?..
};

#endif /* !ENEMY_HPP_ */
