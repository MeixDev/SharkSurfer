//
// CPP File - Player
//
// Class containing things the player must carry around.
//
// More infos ?..
//
//

#include "Player.hpp"

Player::Player(void) :
  _money(0), _score(0), _curHealth(3),
  _maxHealth(3), _weapon(Player::NORMAL)
{}

Player::~Player(void)
{}

unsigned int	Player::getMoney(void)			const
{ return (_money); }

void		Player::setMoney(unsigned int v)
{ _money = v; }

unsigned int	Player::getScore(void)			const
{ return (_score); }

void		Player::setScore(unsigned int v)
{ _score = v; }

unsigned int	Player::getCurHealth(void)	const
{ return (_curHealth); }

void		Player::setCurHealth(unsigned int v)
{ _curHealth = v; }

unsigned int	Player::getMaxHealth(void)		const
{ return (_maxHealth); }

void		Player::setMaxHealth(unsigned int v)
{ _maxHealth = v; }

unsigned int	Player::getLives(void)			const
{ return (_lives); }

void		Player::setLives(unsigned int v)
{ _lives = v; }

Player::Weapon	Player::getWeapon(void)			const
{ return (_weapon); }

void		Player::setWeapon(Player::Weapon v)
{ _weapon = v; }
