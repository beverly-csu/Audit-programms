#include <stdio.h>
#include <stdlib.h>

int str_len(char* string) {
  int i = 0;
  while (1)
    if (string[i] != '\0' && string[i] != '\n')
      i++;
    else if (string[i] == '\n')
      break;
    else if (string[i] == '\0')
      break;
  return i;
}

char* str_cpy(char* string, char* dest) {
  int len = str_len(string);
  for (size_t i = 0; i <= len; i++) {
    dest[i] = string[i];
  }
  return dest;
}

int str_chr(char* string, char chr) {
  int len = str_len(string);
  for (size_t i = 0; i <= len; i++) {
    if (string[i] == chr)
      return i;
  }
  return 0;
}

char* str_spec_chr(char* string, char spec) {
  int len = str_len(string);
  for (size_t i = 0; i <= len; i++) {
    if (string[i] == spec)
      string[i] = '\0';
  }
  return string;
}

char* str_tolower(char* string) {
  int len = str_len(string);
  char* eng_lower = "abcdefghijklmnopqrstuvwxyz";
  char* eng_bigger = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (size_t i = 0; i <= len; i++) {
    for (size_t x = 0; x < 27; x++) {
      if (string[i] == eng_bigger[x])
        string[i] = eng_lower[x];
    }
  }
  return string;
}
