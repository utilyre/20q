#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInRange(int min, int max);

int main(int argc, char *argv[]) {
  srand(time(0));

  const int MIN = 1;
  const int MAX = 10;
  const int LIMIT = 3;

  int random = randInRange(MIN, MAX);

  int guess;
  unsigned int counter;

  bool isFirstGuess = true;
  do {
    if (counter > LIMIT) {
      printf("\n---------------------------------\n");
      printf("It was %d :(\n", random);

      return 1;
    }

    if (isFirstGuess)
      isFirstGuess = false;
    else {
      if (guess < random)
        printf("HINT: Too low!\n");
      else
        printf("HINT: Too high!\n");
    }

    printf("Guess a number between %d..%d: ", MIN, MAX);
    scanf("%d", &guess);
    counter++;
  } while (guess != random);

  printf("\n---------------------------------\n");
  printf("You won!\n");

  return 0;
}

int randInRange(int min, int max) { return rand() % (max - min + 1) + min; }
