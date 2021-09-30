#include <gb/gb.h>
#include <stdio.h>
#include "Scenes/Scenes.c"
#include "Scenes/Scenes.h"
#include "Scenes/Menu/Menu.c"
#include "Scenes/Canvas/Canvas.c"

void main() {

  while(1) {
    switch (CURRENT_SCENE)
    {
    case SCENE_MENU:
      RunMenu();
      break;

    case SCENE_CANVAS:
      RunCanvas();
      break;
    
    default:
      break;
    }
  }
}

