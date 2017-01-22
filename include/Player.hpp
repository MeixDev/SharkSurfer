//
// Header File - Player
//
// Class containing things the player must carry around.
//
// More infos ?..
//
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

class	Player
{
public:

  enum	Weapon
    {
      NORMAL
      //...
    };

  Player(void);
  ~Player(void);

  unsigned int		getMoney(void)		const;
  void			setMoney(unsigned int);

  unsigned int		getScore(void)		const;
  void			setScore(unsigned int);

  unsigned int		getCurHealth(void)	const;
  void			setCurHealth(unsigned int);

  unsigned int		getMaxHealth(void)	const;
  void			setMaxHealth(unsigned int);

  unsigned int		getLives(void)		const;
  void			setLives(unsigned int);

  Weapon		getWeapon(void)		const;
  void			setWeapon(Weapon);

private:
  unsigned int		_money;
  unsigned int		_score;
  unsigned int		_curHealth;
  unsigned int		_maxHealth;
  unsigned int		_lives;
  Weapon		_weapon;
};

#endif /* !PLAYER_HPP_ */
