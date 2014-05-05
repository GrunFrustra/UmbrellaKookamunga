#include "vector2f.h"
#include "ioManager.h"
#include "aaline.h"
#include "clock.h"
#include "viewport.h"

class Hud {
public:
  Hud();
  void draw(unsigned int) const;
private:
  unsigned width;
  unsigned height;
  Vector2f pos;
  const IOManager& io;
  SDL_Surface* screen;
  Clock& clock;
  Viewport& viewport;
  const Uint32 GOLD;
};
