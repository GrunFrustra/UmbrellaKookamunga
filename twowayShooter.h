#ifndef TWOWAY_MULTISPRITE__H
#define TWOWAY_MULTISPRITE__H

#include <string>
#include <iostream>
#include <vector>
#include "drawable.h"
#include "multibullets.h"

class TwowayShooter : public Drawable {
public:
  TwowayShooter(const std::string&);
  TwowayShooter(const TwowayShooter&);
  virtual ~TwowayShooter() { }
  virtual const Frame* getFrame() const { return frames[currentFrame]; }
  
  virtual void draw() const;
  virtual void update(Uint32 ticks);
  void setFramesLeft() { frames = framesLeft; }
  void setFramesRight() { frames = framesRight; }
  void shoot();
  unsigned int bulletCount() const { return bullets.bulletCount(); }
  unsigned int freeCount() const { return bullets.freeCount(); }

protected:
  int frameWidth;
  int frameHeight;
  Vector2f initialVelocity;
  int worldWidth;
  int worldHeight;




}
