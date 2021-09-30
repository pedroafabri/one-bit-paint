#include "Scenes.h"

static int CURRENT_SCENE = 0;

void goToScene(int newScene) {
  CURRENT_SCENE = newScene;
}

void GoToMenu() {
  goToScene(SCENE_MENU);
}

void GoToCanvas() {
  goToScene(SCENE_CANVAS);
}

void GoToInstructions(){
  goToScene(SCENE_INSTRUCTIONS);
}
