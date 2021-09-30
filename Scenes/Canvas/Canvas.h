struct cursorStruct
{
  int x;
  int y;
};

typedef struct cursorStruct Cursor;

// Function declaration
void init();
void blinkCursor(int *i);
void checkInput(Cursor *c);
void moveCursor(Cursor *c);
int newY(int pos, int movement);
int newX(int pos, int movement);
void paint(int x, int y);
void erase(int x, int y);


