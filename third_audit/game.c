#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "string_lib.h"

void game_c(){
  int i = 0;
  int wecan = 0;
  char** cities = (char**)malloc(255);
  int quitTrigger = 0;
  char city[255] = { 0 };
  while (quitTrigger == 0) {
    fgets(city, 255, stdin);
    if (str_chr(city, '\n') == 0 && i != 0) {
      quitTrigger = 1;
      break;
    }
    else {
      i++;
      cities = (char**)realloc(cities, i * 255);
      cities[i - 1] = (char*)realloc(cities[i-1], str_len(city));
      cities[i - 1] = str_cpy(str_tolower(city), cities[i - 1]);
    }
  }
  for (size_t x = 0; x < i; x++) {
    int len = str_len(cities[x]);
    for (size_t y = 0; y < i; y++) {
      if (x != y)
        if (cities[x][len-1] == cities[y][0]) {
          wecan++;
        }
        else {
          wecan--;
        }
    }
  }
  if (wecan > 0)
    printf("We can play in game!\n");
}
