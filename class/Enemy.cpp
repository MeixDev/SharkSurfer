//
// CPP File - Enemy
//
// Standard class for all the ennemies of the game
//
// More infos ?..
//
//

#include "Enemy.hpp"

// Attributes should be set by Children class.
Enemy::Enemy(void) :
  _hp(0), _speed(0), _angle(0), _offset(0), _sens(false), _sprite(NULL)
{}

Enemy::~Enemy(void)
{}

unsigned int	Enemy::getHP(void)		const
{ return _hp; }

void		Enemy::setHP(unsigned int v)
{ _hp = v; }

unsigned int	Enemy::getSpeed(void)		const
{ return _speed; }

void		Enemy::setSpeed(unsigned int v)
{ _speed = v; }

unsigned int	Enemy::getAngle(void)		const
{ return _angle; }

void		Enemy::setAngle(unsigned int v)
{ _angle = v; }

EnSprite	*Enemy::getSprite(void)		const
{ return _sprite; }

void		Enemy::setSprite(EnSprite *v)
{ _sprite = v; }
