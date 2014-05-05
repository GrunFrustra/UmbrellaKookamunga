#include <cmath>
#include "multibullets.h"
#include "gamedata.h"
#include "frameFactory.h"

MultiBullets::MultiBullets(const std::string& name) :
 Drawable(name,
           Vector2f(rand() % (6400 - Gamedata::getInstance().getXmlInt(name+"X") + 1) + 1, 
                    rand() % Gamedata::getInstance().getXmlInt(name+"Y")), 
           Vector2f(rand() % Gamedata::getInstance().getXmlInt(name+"SpeedX"), 
                    rand() % Gamedata::getInstance().getXmlInt(name+"SpeedY")) 
           ),
  frame( FrameFactory::getInstance().getFrame(name) ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false)
{ }

MultiBullets::MultiBullets(const string& n, const Vector2f& pos, const Vector2f& vel):
  Drawable(n, pos, vel), 
  frame( FrameFactory::getInstance().getFrame(n) ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false)
{ }

MultiBullets::MultiBullets(const string& n, const Vector2f& pos, const Vector2f& vel,
               const Frame* frm):
  Drawable(n, pos, vel), 
  frame( frm ),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false)
{ }

MultiBullets::MultiBullets(const MultiBullets& s) :
  Drawable(s), 
  frame(s.frame),
  frameWidth(s.getFrame()->getWidth()),
  frameHeight(s.getFrame()->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),
  done(false)
{ }

MultiBullets& MultiBullets::operator=(const MultiBullets& rhs) {
  Drawable::operator=( rhs );
  frame = rhs.frame;
  frameWidth = rhs.frameWidth;
  frameHeight = rhs.frameHeight;
  worldWidth = rhs.worldWidth;
  worldHeight = rhs.worldHeight;
  done = rhs.done;
  return *this;
}

void MultiBullets::draw() const { 
  Uint32 x = static_cast<Uint32>(X());
  Uint32 y = static_cast<Uint32>(Y());
  frame->draw(x, y); 
}

int MultiBullets::getDistance(const MultiBullets *obj) const { 
  return hypot(X()-obj->X(), Y()-obj->Y());
}

void MultiBullets::update(Uint32 ticks) { 
  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( Y() < 0) {
    velocityY( abs( velocityY() ) );
    done = true;
  }
  if ( Y() > worldHeight-frameHeight) {
    velocityY( -abs( velocityY() ) );
    done = true;
    //setPosition(Vector2f(rand() % (6400 - 100 + 1) + 1, 
    //                rand() % 100));
  }

  if ( X() < 0) {
    velocityX( abs( velocityX() ) );
    done = true;
  }
  if ( X() > worldWidth-frameWidth) {
    velocityX( -abs( velocityX() ) );
    done = true;
  }  
}
