//
// CPP File - AScene
//
// Abstract class to handle all da' scenes
//
// More infos may come here..
//
//

#include "AScene.hpp"

AScene::AScene(void) :
  win(NULL), _dialog(NULL), _onDial(false), _hasMusic(false)
{}

AScene::~AScene(void)
{
  if (this->_hasMusic)
    _music.stop();
}

sf::RenderWindow	*AScene::Win(void)		const
{
  return (this->win);
}

void		AScene::setWindow(sf::RenderWindow *nwin)
{
  this->win = nwin;
}

MainGame		*AScene::Main(void)		const
{
  return (this->main);
}

void			AScene::setMain(MainGame *m)
{
  this->main = m;
}

sf::Event		&AScene::Event(void)
{
  return (this->event);
}

Dialog			*AScene::getDialog(void)	const
{ return (this->_dialog); }

void			AScene::setDialog(Dialog *d)
{
  if (d == NULL)
    {
      this->_onDial = false;
      delete this->_dialog;
      return ;
    }
  this->_onDial = true;
  if (this->_dialog != NULL)
    delete this->_dialog;
  this->_dialog = d;
  d->setWin(this->Win());
  d->setScene(this);
}

bool			AScene::getBoolDial(void)	const
{ return (_onDial); }

void			AScene::setBoolDial(bool v)
{ _onDial = v; }

bool			AScene::getHasMusic(void)	const
{ return (_hasMusic); }

void			AScene::setHasMusic(bool v)
{ _hasMusic = v; }

sf::Music		&AScene::getMusic(void)
{ return (_music); }

void			AScene::setMusic(std::string const &filename)
{ _music.openFromFile(filename); }
