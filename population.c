#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PIXEL *generate_random_image(int width, int height, int max_color) {
  PIXEL *data = (PIXEL *)malloc(width * height * sizeof(PIXEL)); 
  printf("pop");

  int i;
  for (i = 0; i < width*height; i++) {
    data[i].r = rand() % (max_color + 1); 
    data[i].g = rand() % (max_color + 1);
    data[i].b = rand() % (max_color + 1);
  }

  return data;
}

Individual *generate_population(int population_size, int width, int height, int max_color) {
  Individual *population = (Individual *)malloc(population_size * sizeof(Individual));
  printf("pop2I");  

  int i;
  for (i = 0; i < population_size; i++) {
    PPM_IMAGE *image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
    printf("pop2img");
    image->width = width;
    image->height = height;
    image->max_color = max_color;

    image->data = generate_random_image(width, height, max_color);

    population[i].image = *image;
  }

  return population;
}
