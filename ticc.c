#include <stdio.h>

const BOXES_LEN = 9;

enum BoxState {
  EMPTY = 0,
  X = 1,
  O = 2
};


struct GameState {
  int turn;
  enum BoxState boxes[BOXES_LEN];
};

enum BoxState derive_next_box_state(struct GameState *game) {
  printf("checking turn for game (i: %d) \n\n", game->turn);
  enum BoxState next_box_state = (game->turn) % 2 == 0 ? X : O;

  return next_box_state;
}

struct GameState init_game() {

  enum BoxState boxes[BOXES_LEN];

  int i;
  for (i = 0; i < BOXES_LEN; i++)
    boxes[i] = EMPTY;
               
  struct GameState game = { 0, boxes };

  return game;
}

void play(struct GameState *game, int index) {
  enum BoxState new_box = derive_next_box_state(game);
  printf("placing at %d (turn: %c) \n\n", index, new_box == 1 ? 'x' : 'o');

  game->turn += 1;
}

int main() {
  printf("starting tic tac toe super engine \n\n");

  struct GameState game = init_game();

  play(&game, 3);
  play(&game, 4);

  return 0;
}
