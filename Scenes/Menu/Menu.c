#include <gb/gb.h>
#include "SplashScreen_data.c"
#include "SplashScreen_map.c"

void RunMenu() {
  HIDE_SPRITES;

  // Draws background
  set_bkg_data(0, 183, SplashScreen_data);
  set_bkg_tiles(0, 0, 20, 18, SplashScreen_map);

  SHOW_BKG;
  DISPLAY_ON;

  waitpad(J_START);
  GoToInstructions();
}