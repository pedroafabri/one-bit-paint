#include <gb/gb.h>
#include "Instructions_data.c"
#include "Instructions_map.c"

void RunInstructions() {
  HIDE_SPRITES;

  while(joypad()){}

  // Draws background
  set_bkg_data(0, 196, Instructions_data);
  set_bkg_tiles(0, 0, 20, 18, Instructions_map);

  SHOW_BKG;
  DISPLAY_ON;

  waitpad(J_START);
  GoToCanvas();
}