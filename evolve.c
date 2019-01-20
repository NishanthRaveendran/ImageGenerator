#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int cmpfunc (const void *a, const void *b) {
  Individual *A = (Individual *)a;
  Individual *B = (Individual *)b;
 
  if (A->fitness > B->fitness)
    return 1;
  else if (A->fitness < B->fitness)
    return -1;
  else 
    return 0;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate) {
  PPM_IMAGE *X = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  printf("evol");

  int width, height, maxcol;
  width = image->width;
  height = image->height;
  maxcol = image->max_color;

  Individual *individual = generate_population(population_size, width, height, maxcol);
  comp_fitness_population(image->data, individual, population_size);

  qsort(individual, population_size, sizeof(Individual), cmpfunc);

  int i;
  for (i=0; i < num_generations; i++) {
    crossover(individual, population_size);

    mutate_population(individual, population_size, rate);

    comp_fitness_population(image->data, individual, population_size);

    qsort(individual, population_size, sizeof(Individual), cmpfunc);
  }

  X = &individual[0].image;

  int j;
  for (j=1; j < population_size; j++) {
    free(individual[j].image.data);
  }
  free(individual);

  return X;
}

void free_image(PPM_IMAGE *p) {
  free(p->data);
  free(p);  
}

