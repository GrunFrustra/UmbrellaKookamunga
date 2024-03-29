#include <cmath>
#include "sprite.h"
#include "gamedata.h"
#include "frameFactory.h"
static int change = 100000;
static int here = 64;
Sprite::Sprite(const std::string& name) :
  Drawable(name,
           Vector2f(rand() % (6400 - Gamedata::getInstance().getXmlInt(name+"X") + 1) + 1, 
                    rand() % Gamedata::getInstance().getXmlInt(name+"Y")), 
           Vector2f(rand() % Gamedata::getInstance().getXmlInt(name+"SpeedX") + 50, 
                    rand() % Gamedata::getInstance().getXmlInt(name+"SpeedY") + 150) 
           ),
  frame( FrameFactory::getInstance().getFrame(name) ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false),
  spawn(here)
{ }

Sprite::Sprite(const string& n, const Vector2f& pos, const Vector2f& vel):
  Drawable(n, pos, vel), 
  frame( FrameFactory::getInstance().getFrame(n) ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false),
  spawn(here)
{ }

Sprite::Sprite(const string& n, const Vector2f& pos, const Vector2f& vel,
               const Frame* frm):
  Drawable(n, pos, vel), 
  frame( frm ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false),
  spawn(here)
{ }

Sprite::Sprite(const Sprite& s) :
  Drawable(s), 
  frame(s.frame),
  frameWidth(s.getFrame()->getWidth()),
  frameHeight(s.getFrame()->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false),
  spawn(here)
{ }

Sprite& Sprite::operator=(const Sprite& rhs) {
  Drawable::operator=( rhs );
  frame = rhs.frame;
  frameWidth = rhs.frameWidth;
  frameHeight = rhs.frameHeight;
  worldWidth = rhs.worldWidth;
  worldHeight = rhs.worldHeight;
  done = rhs.done;
  spawn = rhs.spawn;
  return *this;
}

void Sprite::draw() const { 
  Uint32 x = static_cast<Uint32>(X());
  Uint32 y = static_cast<Uint32>(Y());
  frame->draw(x, y); 
}

int Sprite::getDistance(const Sprite *obj) const { 
  return hypot(X()-obj->X(), Y()-obj->Y());
}

void Sprite::update(Uint32 ticks) { 
  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);
  //int spawn = rand() % (64-2+1)+2; spawn *= 10;
  //int spawn = 20 q0;
  change -= ticks;
  if(change <= 0){ 
    here = rand() % (64-4+1)+4; here *= 100;
    change = 1000000;
  }
  if ( Y() < 0) {
    velocityY( abs( velocityY() ) );
    
  }
  if ( Y() > worldHeight-frameHeight) {
    velocityY( abs( velocityY() ) );
    //setPosition(Vector2f(rand() % (6400 - 100 + 1) + 1, 
    //                rand() % 100));
    setPosition(Vector2f(rand() % (here - (here-400) + 1) + (here-400), 
                    rand() % 100));
    done = true;
  }

  if ( X() < 0) {
    velocityX( abs( velocityX() ) );
  }
  if ( X() > worldWidth-frameWidth) {
    velocityX( -abs( velocityX() ) );
  }  
}
