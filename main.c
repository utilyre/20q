#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInRange(int min, int max);

int main(int argc, char *argv[]) {
  srand(time(0));

  const int MIN = 1;
  const int MAX = 10;

  int random = randInRange(MIN, MAX);
  printf("HINT: %d is chosen.\n", random);

  return 0;
}

int randInRange(int min, int max) { return rand() % (max - min + 1) + min; }
