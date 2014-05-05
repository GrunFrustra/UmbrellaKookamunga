#ifndef MULTIBULLETS__H
#define MULTIBULLETS__H
#include <string>
#include "drawable.h"

class MultiBullets : public Drawable {
public:
  MultiBullets(const std::string&);
  MultiBullets(const std::string&, const Vector2f& pos, const Vector2f& vel);
  MultiBullets(const std::string&, 
         const Vector2f& pos, const Vector2f& vel, const Frame*);
  MultiBullets(const MultiBullets& s);
  virtual ~MultiBullets() { } 
  MultiBullets& operator=(const MultiBullets&);

  virtual const Frame* getFrame() const { return frame; }
  virtual void draw() const;
  void shoot(const Vector2f& pos, const Vector2f& objVel);
  bool tooFar(){ return done; }
  virtual void update(Uint32 ticks);

private:
  const Frame * frame;
  int frameWidth;
  int frameHeight;
  int worldWidth;
  int worldHeight;
  bool done;
  int getDistance(const MultiBullets*) const;
  
};
#endif
