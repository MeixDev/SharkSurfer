//
// CPP File - Dialog
//
// Class that can be used a Dialog in most scenes.
//
// More infos may come..
//
//

#include "Dialog.hpp"

Dialog::Dialog(std::string const &line,
	       std::string const &mugshot,
	       Dialog *next) :
  _next(next), _parent(NULL), string(line)
{
  if (!this->_texmug.loadFromFile(mugshot) ||
      !this->_texui.loadFromFile("rsrcs/UI.png") ||
      !this->_font.loadFromFile("rsrcs/dpcomic.ttf") ||
      !this->_typingbf.loadFromFile("rsrcs/typing.wav") ||
      !this->_texvalid.loadFromFile("rsrcs/Arrow.png"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }

  _typing.setBuffer(_typingbf);

  _mugshot = sf::Sprite(_texmug);
  _sizemug = _texmug.getSize();
  _mugshot.move(10, 720 - _sizemug.y - 7);

  _ui = sf::Sprite(_texui);
  _sizeui = _texui.getSize();
  _ui.move(0, 720 - _sizeui.y);

  _valid = sf::Sprite(_texvalid);
  _sizevalid = _texvalid.getSize();
  _valid.move(1280 - _sizevalid.x - 15, 720 - _sizevalid.y - 15);

  _text.setFont(_font);
  _text.setString("");
  _text.setCharacterSize(70);
  _text.setFillColor(sf::Color::White);
  _text.move(380, 500);

  _left = false;
  _offset = 0;

  _sizestr = string.size();
  _index = 0;
  // ^ Line of text
}

Dialog::~Dialog(void)
{
}

sf::RenderWindow	*Dialog::Win(void)	const
{ return (_win); }

void			Dialog::setWin(sf::RenderWindow *w)
{ _win = w; }

AScene			*Dialog::Scene(void)	const
{ return (_parent); }

void			Dialog::setScene(AScene *d)
{
  this->_parent = d;
}

void		Dialog::reset(void)
{
  _sub = "";
  _index = 0;

  _clock.restart();
}

void		Dialog::draw(void)
{
  sf::Time t = this->_clock.getElapsedTime();
  if (_index <= _sizestr)
    if ((t.asSeconds() > (0.06f * (_index + 1))))
      {
	_sub = string.substr(0, ++_index);
	this->_text.setString(_sub);
	this->_typing.play();
      }
  this->Win()->draw(this->_ui);
  this->Win()->draw(this->_text);
  this->Win()->draw(this->_mugshot);
  if (_index > _sizestr)
    {
      if (!this->_left)
	{
	  ++_offset;
	  if (_offset % 10 == 0)
	    this->_valid.move(0, -1);
	  if (_offset == 90)
	    {
	      _offset = 0;
	      this->_left = true;
	    }
	}
      else
	{
	  ++_offset;
	  if (_offset % 10 == 0)
	    this->_valid.move(0, 1);
	  if (_offset == 90)
	    {
	      _offset = 0;
	      this->_left = false;
	    }
	}
      this->Win()->draw(this->_valid);
    }
}

void		Dialog::OnKeyPressed(void)
{
  if (_index > _sizestr)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
	  sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
	  if (_next == NULL)
	    this->Scene()->setBoolDial(false);
	  else
	    {
	      _next->reset();
	      this->Scene()->setDialog(_next);
	    }
	}
    }
}
