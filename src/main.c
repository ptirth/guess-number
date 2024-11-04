#include "mydefs.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

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

int main() {
  printf("Guess the Number!\n");
  return 0;
}
