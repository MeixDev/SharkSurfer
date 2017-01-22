//
// Header File - OnWaves1
//
// First level
//
// More infos may come here..
//
//

#ifndef ONWAVES1_HPP_
# define ONWAVES1_HPP_

# include "OnWaves.hpp"

class	OnWaves1	:	public OnWaves
{
public:
  OnWaves1(void);
  virtual ~OnWaves1(void);

  virtual void		draw(void);

  // Handler for keys
  virtual void		OnKeyPressed(void);

};

#endif /* !ASCENE_HPP_ */
