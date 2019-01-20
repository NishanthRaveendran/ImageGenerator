#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

void mutate(Individual *individual, double rate) {
  int size = individual->image.width * individual->image.height;
  int n = size * (rate/100);

  int maxcol = individual->image.max_color;
  int j = 0;

  int i;
  for (i = 0; i < n; i++) {
    j = rand() % (size + 1);
    individual->image.data[j].r = rand() % (maxcol + 1);
    individual->image.data[j].g = rand() % (maxcol + 1);
    individual->image.data[j].b = rand() % (maxcol + 1);
  }
}

void mutate_population(Individual *individual, int population_size, double rate) {
  int x = population_size/4;
  int i;
  for (i=x; i < population_size; i++) {
    mutate(&individual[i], rate);
  } 
}
