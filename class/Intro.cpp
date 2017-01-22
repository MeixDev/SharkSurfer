//
// CPP File - Intro
//
// Let me tell you a story
//
// More infos may come here..
//
//

#include "Intro.hpp"
#include "Shop.hpp"

#define ZLF	"rsrcs/ZLF.png"
#define BALD	"rsrcs/BaldGuy.png"
#define AFRO	"rsrcs/AfroBro.png"
#define BUTCH	"rsrcs/Butch.png"
#define SHARKY	"rsrcs/Sharky.png"
#define AFF	"rsrcs/Aff.png"

Intro::Intro(void)
{
  if (!_font.loadFromFile("rsrcs/dpcomic.ttf") ||
      !_texbg.loadFromFile("rsrcs/bgfinal.png") ||
      !_texzlf.loadFromFile("rsrcs/spr_zleuf.png") ||
      !_texafro.loadFromFile("rsrcs/spr_friend1.png") ||
      !_texbald.loadFromFile("rsrcs/spr_friend2.png"))
    {
      std::cerr << "Something shady happened.. Where did my file go ?!" << std::endl;
      exit(1);
    }

  _butch = new Anim("rsrcs/stand.png", 370, 300, 67, 74, 4);
  _butch->_spr.setScale(2.0f, 2.0f);

  _bg = sf::Sprite(_texbg);
  _zlf = sf::Sprite(_texzlf);
  _afro = sf::Sprite(_texafro);
  _bald = sf::Sprite(_texbald);
  _zlf.setScale(2.0f, 2.0f);
  _zlf.move(500, 300);
  _afro.setScale(2.0f, 2.0f);
  _afro.move(600, 280);
  _bald.setScale(2.0f, 2.0f);
  _bald.move(700, 300);

  this->setHasMusic(true);
  this->setMusic("rsrcs/Beachfront_Celebration.wav");
  this->getMusic().play();

  _text.setFont(_font);
  _text.setString("Press any key.. S will skip the dialog.");
  _text.setCharacterSize(70);
  _text.setFillColor(sf::Color::White);
  _text.setOutlineColor(sf::Color::Black);
  _text.setOutlineThickness(3.0f);
  _text.move(100, 100);
  _talked = false;
}

Intro::~Intro(void)
{
  delete _butch;
}

void		Intro::draw(void)
{
  //Draw scene
  this->Win()->draw(_bg);
  this->Win()->draw(_zlf);
  this->Win()->draw(_afro);
  this->Win()->draw(_bald);
  _butch->Move(0.0f, 0.0f);
  this->Win()->draw(_butch->_spr);
  if (!this->_talked)
    this->Win()->draw(_text);
  if (this->getBoolDial())
    this->getDialog()->draw();
}

void		Intro::OnKeyPressed(void)
{
  if (this->getBoolDial())
    this->getDialog()->OnKeyPressed();
  else
    {
      if (!_talked)
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    this->Main()->setScene(new Shop);
	  else
	    {
	      setDialog(new Dialog("Damn, that was a nice one!", AFRO,
				   new Dialog("Yeah, even tho Zleuf missed it\nlike a total noob.", BALD, new Dialog("Didn't ya', Zle-...", BALD, new Dialog("The only thing I miss is\nyour mom.", ZLF, new Dialog("Wahaha! It's the best to be\nwith you guys.", BUTCH, new Dialog("I sure hope nothing bad\nwill happen, tho.", BUTCH, new Dialog("Yeah, that'd be a shame.", SHARKY, new Dialog("Totall-..", BALD, new Dialog("1 WEEK !!!", AFF, new Dialog("Whut ?!", SHARKY, new Dialog("1 WEEK ! THAT'S ALL YOU'VE\nGOT LEFT BEFORE DOOM!", AFF, new Dialog("Wut.. Why ?! But what are you\ntalking about ?!", BUTCH, new Dialog("THE FROSTWAVE IS COMIN', AND\nNOTHING WILL STAY UNFREEZED.", AFF, new Dialog("NOT EVEN THE SEA ITSELF!", AFF, new Dialog("OMG!", BUTCH, new Dialog("OMG!", SHARKY, new Dialog("OMG!", AFRO, new Dialog("OMG!", ZLF, new Dialog("OM-...!", BALD, new Dialog("OMG!", AFF, new Dialog(".. What are you surprised of,\nold man ?", SHARKY, new Dialog("I FORGOT TO SWITCH OFF\nDA OVEN. GOTTA GO. CYA!", AFF, new Dialog("Sharky, Zleuf, everyone!\nWe only have one week left.", BUTCH, new Dialog("We should hurry back to\nthe sea while we can.", BUTCH, new Dialog("Let's enjoy it while\nwe can...", SHARKY, new Dialog("YEAH, LET'S GOOOO!", ZLF)))))))))))))))))))))))))));
	      _talked = true;
	    }
	}
      else
	this->Main()->setScene(new Shop);
    }
}
