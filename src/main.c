#include "mydefs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  return str_to_u32(buffer);
}

int main() {
  printf("Guess the Number!\n");

  const u32 max_num = prompt("Enter the max number that computer can choose\n=> ");
  if (max_num == U32_MAX) {
    printf("E: Not a correct number\n");
    return EXIT_FAILURE;
  }

  const u32 tries = prompt("Enter the number of tries you want to take\n=> ");
  if (tries == U32_MAX) {
    printf("E: Not a correct number\n");
    return EXIT_FAILURE;
  }

  const u32 hints_after =
      prompt("Enter the number of try after which you want to see hints\n=> ");
  if (hints_after == U32_MAX) {
    printf("E: Not a correct number\n");
    return EXIT_FAILURE;
  }

  return 0;
}
