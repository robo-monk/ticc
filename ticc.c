#include <stdio.h>

const BOXES_LEN = 9;

enum BoxState {
  EMPTY = 0,
  X = 1,
  Y = 2
};

struct GameState {
  int turn;
  enum BoxState boxes[BOXES_LEN];
};

struct GameState init_game() {

  enum BoxState boxes[BOXES_LEN];

  int i;
  for (i = 0; i < BOXES_LEN; i++)
    boxes[i] = EMPTY;
               
  struct GameState game = { 0, boxes };

  return game;
}


int main() {
  printf("starting tic tac toe super engine");

  struct GameState game = init_game();

  return 0;
}
