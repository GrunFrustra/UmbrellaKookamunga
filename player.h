#ifndef PLAYER__H
#define PLAYER__H
#include <string>
#include <vector>
#include "drawable.h"
#include "collisionStrategy.h"

class Player : public Drawable {
public:

  Player(const std::string&);
  Player(const Player&);
  virtual ~Player() { } 

  virtual void draw() const;
  virtual void update(Uint32 ticks);
  virtual const Frame* getFrame() const { 
    return frames[currentFrame];   
  }
  bool collidedWith(const Drawable* d) const {
    return strategy.execute(*this, *d);
  }
  void shoot();
  //unsigned int bulletCount() const { return bullets.bulletCount(); }
  //unsigned int freeCount() const { return bullets.freeCount(); } 
  void down(Uint32 ticks);
  void up(Uint32 ticks);
  void left(Uint32 ticks);
  void right(Uint32 ticks);

protected:
  const std::vector<Frame *> frames;
  int worldWidth;
  int worldHeight;

  //bullets
  /*std::string bulletName;
  float bulletInterval;
  float timeSinceLastBullet;
  float minBulletSpeed;
  MultiBullets bullets;
  */
  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  RectangularCollisionStrategy  strategy;
  int frameWidth;
  int frameHeight;
  int direction;

  void advanceFrame(Uint32 ticks);
  
};
#endif
