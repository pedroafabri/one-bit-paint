#include "Canvas.h"
#include "CanvasSprites.c"

int cursorBlinkTick = 0;
int buttonPressed = 0;

void RunCanvas()
{
  unsigned int cursorIndex = 0;
  SHOW_SPRITES;

  // Initialize cursor at 0 0
  Cursor cursor = {0, 0};
  init();

  while (CURRENT_SCENE == SCENE_CANVAS)
  {
    checkInput(&cursor);
    moveCursor(&cursor);
    blinkCursor(&cursorIndex);
    // delay(10);
  }
}

/**
 * Initializes the scene
 */
void init()
{
  set_sprite_data(0, 4, Sprites);

  set_bkg_data(0, 4, Sprites);
  for (int x = 0; x < 20; x++)
  {
    for (int y = 0; y < 18; y++)
    {
      set_bkg_tile_xy(x, y, 0x02);
    }
  }

  set_sprite_tile(0, 0);
  move_sprite(0, 8, 16);
  SHOW_SPRITES;
  SHOW_BKG;
  DISPLAY_ON;
}

/**
 * Checks the joypad input and acts accordingly
 */
void checkInput(Cursor *c)
{

  switch (joypad())
  {
  case J_UP:
    if(buttonPressed == 1) return;
    buttonPressed = 1;
    c->y = newY(c->y, -1);
    break;

  case J_DOWN:
    if(buttonPressed == 1) return;
    buttonPressed = 1;
    c->y = newY(c->y, 1);
    break;

  case J_LEFT:
    if(buttonPressed == 1) return;
    buttonPressed = 1;
    c->x = newX(c->x, -1);
    break;

  case J_RIGHT:
    if(buttonPressed == 1) return;
    buttonPressed = 1;
    c->x = newX(c->x, 1);
    break;

  case J_A:
    paint(c->x, c->y);
    break;

  case J_B:
    erase(c->x, c->y);
    break;

  case J_SELECT:
    GoToMenu();
    break;

  default:
    buttonPressed = 0;
  }
}

/**
 * Calculates the new Y position.
 * Pass a negative value as second parameter to move upwards.
 */
int newY(int pos, int movement)
{
  pos += movement;
  if (pos > 17) pos = 0;
  if (pos < 0) pos = 17;
  return pos;
}

/**
 * Calculates the new X position.
 * Pass a negative value as second parameter to move backwards.
 */
int newX(int pos, int movement)
{
  pos += movement;
  if (pos > 19) pos = 0;
  if (pos < 0) pos = 19;
  return pos;
}
/**
 * Moves the cursor accordingly
 * Coordinates are based on 8x8 tiles.
 * So x:1 and y:1 will move the sprite do x:8 and y:8
 */
void moveCursor(Cursor *c)
{
  int newX = 8 + (c->x * 8);  // X 8 Offset
  int newY = 16 + (c->y * 8); // Y 16 Offset
  move_sprite(0, newX, newY);
}

/**
 * Blinks the cursor changing from sprite 1 to 0 and vice-versa
 */
void blinkCursor(int *i)
{
  cursorBlinkTick++;
  if(cursorBlinkTick > 400) cursorBlinkTick = 0;
  if(cursorBlinkTick != 0) return;

  *i = (*i + 1) % 2;
  set_sprite_tile(0, *i);
}

void paint(int x, int y)
{
  set_bkg_tile_xy(x, y, 0x03);
}

void erase(int x, int y) 
{
  set_bkg_tile_xy(x, y, 0x02);
}