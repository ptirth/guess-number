#include "mydefs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LEN 121

static u32 str_to_u32(const char *string) {
  const size_t len = strlen(string);
  u32 num = 0;

  for (size_t i = 0; i < len; ++i) {
    const char current_char = string[i];
    if (current_char - '0' < 0 || current_char - '0' > 9)
      return U32_MAX;  // Indicates invalid format

    const u32 digit = current_char - '0';
    num = num * 10 + digit;
  }
  return num;
}

static char *getline(char buffer[MAX_LINE_LEN]) {
  char c;
  size_t i = 0;

  for (; i < MAX_LINE_LEN - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    buffer[i] = c;
  }
  buffer[++i] = '\0';

  return buffer;
}

static u32 prompt(const char *message) {
  printf("%s", message);

  char buffer[MAX_LINE_LEN] = {0};
  getline(buffer);

  const u32 answer = str_to_u32(buffer);
  if (answer == U32_MAX) {
    printf("E: Not a correct number\n");
    exit(EXIT_FAILURE);
  }

  return answer;
}

int main() {
  printf("Guess the Number!\n");

  const u32 max_num = prompt("Enter the max number that computer can choose\n=> ");
  if (max_num == 0) {
    printf("E: Max number can't be set to zero\n");
    return EXIT_FAILURE;
  }

  const u32 tries = prompt("Enter the number of tries you want to take\n=> ");
  if (tries == 0) {
    printf("E: You need at least one try\n");
    return EXIT_FAILURE;
  }

  const u32 hints_after =
      prompt("Enter the number of try after which you want to see hints\n=> ");
  if (hints_after > tries - 1) {
    printf("E: You can't have hints on every try\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));
  const u32 chosen_number = rand() % (max_num + 1);

  printf("\nStarting the game...\n");

  for (u32 i = 1; i <= tries; ++i) {
    if (i == 1) {
      printf("-> Guess the number\n=> ");
    } else if (i < tries) {
      printf("-> Try again\n=> ");
    } else {
      printf("Last try! Think carefully\n=> ");
    }

    const u32 guess = prompt("");
    if (guess == chosen_number) {
      printf("---> You won!\n");
      return EXIT_SUCCESS;
    }
  }

  printf("Game over!\n");
  return 0;
}
