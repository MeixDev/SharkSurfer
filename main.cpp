#include "MainGame.hpp"
#include "OptScreen.hpp"
#include <iostream>

void		_onKeyPressed()
{
  std::cout << "WOW!" << std::endl;
}

int		main(void)
{
  MainGame	*main = new MainGame;
  main->setScene(new OptScreen);

  main->Win()->setVerticalSyncEnabled(true);

  while (main->Win()->isOpen())
    {
      // Checks all events triggered since last loop
      while (main->Win()->pollEvent(main->Scene()->Event()))
	{
	  switch (main->Scene()->Event().type)
	    {
	      // Closes the Window as asked
	    case sf::Event::Closed:
	      main->Win()->close();
	      break ;

	      // Enters "KeyPressed function
	    case sf::Event::KeyPressed:
	      main->Scene()->OnKeyPressed();
	      break ;

	      // Default case : Nothing.
	    default:
	      break ;
	    }

	}
      // Clears the Window with black color
      main->Win()->clear(sf::Color::Black);

      // Drawings
      main->Scene()->draw();

      // EasterEgg
      if (main->getEasterEgg())
	main->drawEasterEgg();

      // Displays the current window
      main->Win()->display();
    }

  return (0);
}
