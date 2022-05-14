#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInRange(int min, int max);

int main(int argc, char *argv[]) {
  srand(time(0));

  const int LIVES = 3;
  const int MIN = 1;
  const int MAX = 10;

  unsigned int remainingLives = LIVES;
  int random = randInRange(MIN, MAX);
  int guess;

  bool isFirstGuess = true;
  do {
    if (remainingLives <= 0) {
      printf("\n---------------------------------\n");
      printf("It was %d :(\n", random);

      return 1;
    }

    if (isFirstGuess)
      isFirstGuess = false;
    else {
      printf("\n");
      for (int i = 0; i < LIVES; i++) {
        if (i < remainingLives)
          printf("❤️ ");
        else
          printf("💔");
      }
      printf("\n");

      if (guess < random)
        printf("HINT: Too low 🤔\n");
      else
        printf("HINT: Too high 🤔\n");
    }

    int input;
    do {
      printf("Guess a number between %d..%d: ", MIN, MAX);
      scanf("%d", &input);
    } while (input < MIN || input > MAX);
    guess = input;

    remainingLives--;
  } while (guess != random);

  printf("\n---------------------------------\n");
  printf("You won! 🥳\n");

  return 0;
}

int randInRange(int min, int max) { return rand() % (max - min + 1) + min; }
