#include <stdio.h>

const int BOXES_LEN = 9;

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
  for (i = 0; i < BOXES_LEN; i++) boxes[i] = EMPTY;
               
  struct GameState game = { 0, *boxes };
  return game;
}

void play(struct GameState *game, int index) {
  enum BoxState new_box = derive_next_box_state(game);
  printf("placing at %d (turn: %c) \n\n", index, new_box == 1 ? 'x' : 'o');

  (game->boxes)[index] = new_box;
  game->turn += 1;
}

void render(struct GameState *game) {
  char symbols[] = { '-', 'X', 'O' };
  int i, ii;
  printf("\n------------\n");

  for (i=0; i <  3; i++) {
    for (ii=0; ii < 3; ii++) {
      printf("| %c ", symbols[(game->boxes)[3*i + ii]]);
      // printf("| %d ", 3*i + ii);
      // printf("| %d ", (game->boxes)[3*i + ii]);
    }
    printf("|\n------------\n");
  }
};

int main() {
  printf("starting tic tac toe super engine \n\n");

  struct GameState game = init_game();

  play(&game, 0);
  render(&game);
  play(&game, 3);
  render(&game);
  play(&game, 4);
  render(&game);

  return 0;
}
