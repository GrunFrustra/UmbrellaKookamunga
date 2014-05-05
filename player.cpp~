#include "player.h"
#include "gamedata.h"
#include "frameFactory.h"

void Player::advanceFrame(Uint32 ticks) {
	timeSinceLastFrame += ticks;
	if (timeSinceLastFrame > frameInterval) {
          if(direction == 0){
            //currentFrame = ((currentFrame+1) % numberOfFrames);
            currentFrame = (currentFrame == (numberOfFrames/2)-1 ? 0 : (currentFrame+1) % numberOfFrames );
		timeSinceLastFrame = 0;
            }
          else{
          currentFrame = (currentFrame == numberOfFrames-1 ? (numberOfFrames/2) : ((currentFrame+1) % numberOfFrames) );
                timeSinceLastFrame = 0;
          }
	}

}

Player::Player( const std::string& name) :
  Drawable(name, 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"X"), 
                    Gamedata::getInstance().getXmlInt(name+"Y")), 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"SpeedX"),
                    Gamedata::getInstance().getXmlInt(name+"SpeedY"))
           ),
  frames( FrameFactory::getInstance().getFrames(name) ),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight")),

  currentFrame(0),
  numberOfFrames( Gamedata::getInstance().getXmlInt(name+"Frames") ),
  frameInterval( Gamedata::getInstance().getXmlInt(name+"FrameInterval") ),
  timeSinceLastFrame( 0 ),
  strategy(  ),
  frameWidth(frames[0]->getWidth()),
  frameHeight(frames[0]->getHeight()),
  direction(0)
{ }

Player::Player(const Player& s) :
  Drawable(s), 
  frames(s.frames),
  worldWidth( s.worldWidth ),
  worldHeight( s.worldHeight ),
  currentFrame(s.currentFrame),
  numberOfFrames( s.numberOfFrames ),
  frameInterval( s.frameInterval ),
  timeSinceLastFrame( s.timeSinceLastFrame ),
  strategy(  ),
  frameWidth( s.frameWidth ),
  frameHeight( s.frameHeight ),
  direction( s.direction )
  { }

void Player::draw() const { 
  Uint32 x = static_cast<Uint32>(X());
  Uint32 y = static_cast<Uint32>(Y());
  frames[currentFrame]->draw(x, y);
}



void Player::update(Uint32 ticks) { 
  advanceFrame(ticks);

  //Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  Vector2f incr(0.0, 12.0);
  setPosition(getPosition() + incr);
  //timeSinceLastBullet += ticks;
  //bullets.update(ticks);
  /*
  if ( Y() < 0) {
    velocityY( abs( velocityY() ) );
    velocityY(0);
  }
  if ( Y() > worldHeight-frameHeight) {
    velocityY( -abs( velocityY() ) );
    velocityY(0);
  }

  if ( X() < 0) {
    velocityX( abs( velocityX() ) );
    velocityX(0);
  }
  if ( X() > worldWidth-frameWidth) {
    velocityX( -abs( velocityX() ) );
    velocityX(0);
  }  
  */
}

/*void Player::shoot() {
  if ( timeSinceLastBullet > bulletInterval) {
    Vector2f vel = getVelocity();
    float x;
    float y = Y()+frameHeight/4;
    if ( vel[0] > 0 ) {
      x = X()+frameWidth;
      vel[0] += minBulletSpeed;
    }
    else {
      x = X();
      vel[0] -= minBulleetSpeed;
    }
    bullets.shoot( Vector2f(x, y), vel);
    timeSinceLastBullet = 0;
  }

}*/

void Player::down(Uint32 ticks) {
  advanceFrame(ticks);

  Vector2f incr(0.0, 12.0);
  setPosition(getPosition() + incr);
  if ( Y() > worldHeight-frameHeight) {
    up(23);
  }
}

void Player::up(Uint32 ticks) {
  advanceFrame(ticks);

  Vector2f incr(0.0, -12.0);
  setPosition(getPosition() + incr);
  if ( Y() < 0) {
    down(23);
  }
}

void Player::left(Uint32 ticks) {
  advanceFrame(ticks);

  Vector2f incr(-12.0, 0.0);
  setPosition(getPosition() + incr);
  direction = 1;
  if ( X() < 0) {
    right(23);
  }
}

void Player::right(Uint32 ticks) {
  advanceFrame(ticks);
  Vector2f incr(12.0, 0.0);
  setPosition(getPosition() + incr);
  direction = 0;
  if ( X() > worldWidth-frameWidth) {
    left(23);
  } 
} 
