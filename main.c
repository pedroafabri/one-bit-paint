#include <gb/gb.h>
#include <stdio.h>
#include "Scenes/Scenes.c"
#include "Scenes/Scenes.h"
#include "Scenes/Menu/Menu.c"
#include "Scenes/Canvas/Canvas.c"
#include "Scenes/Instructions/Instructions.c"

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

    case SCENE_INSTRUCTIONS:
      RunInstructions();
      break;
    
    default:
      break;
    }
  }
}

