#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Returns a random number between the given min and max
 */
int randInRange(int min, int max);

/**
 * Prints usage to stdout
 */
void usage();

int main(int argc, char *argv[]) {
  srand(time(0));

  /* Change these in order to modify game rules */
  const int LIVES = 3;
  const int MIN = 1;
  const int MAX = 10;

  /* Game state */
  unsigned int remainingLives = LIVES;
  int random = randInRange(MIN, MAX);
  int guess;

  bool isFirstGuess = true;
  do {
    /* Checks wether if the game is over or not */
    if (remainingLives <= 0) {
      printf("\n---------------------------------\n");
      printf("It was %d :(\n", random);

      return 1;
    }

    /* Displays the current state of lives */
    printf("\n");
    for (int i = 0; i < LIVES; i++) {
      if (i < remainingLives)
        printf("❤️ ");
      else
        printf("💔");
    }
    printf("\n");

    if (isFirstGuess)
      isFirstGuess = false;
    else {
      /* Gives the player a hint about how close he/she is */
      int range = (MAX - MIN) / 4;
      int difference = guess - random;

      printf("HINT: ");
      if (difference < -range)
        printf("Too low");
      else if (difference < 0)
        printf("A bit low");
      else if (difference > range)
        printf("Too high");
      else
        printf("A bit high");
      printf(" 🤔\n");
    }

    /* Prompts until the player gives a valid number
    (between MIN and MAX constants) */
    int input;
    do {
      printf("Guess a number between %d..%d: ", MIN, MAX);
      scanf("%d", &input);
    } while (input < MIN || input > MAX);
    guess = input;

    /* Decrements remaining lives on each prompt */
    remainingLives--;
  } while (guess != random);

  /* Congragulates the player after the loop is over
  (i.e. after the player has won) */
  printf("\n---------------------------------\n");
  printf("You won! 🥳\n");

  return 0;
}

int randInRange(int min, int max) { return rand() % (max - min + 1) + min; }

void usage() {
  printf("SYNOPSIS\n"
         "\t20q [-l lives] [-r range]\n");

  printf("\n");

  printf("OPTIONS\n");
  printf("\t-l lives\n"
         "\t\tDefines number of lives\n");
  printf("\t-r range\n"
         "\t\tDefines random range (e.g. 1,10 means 1 through 10)\n");
}
