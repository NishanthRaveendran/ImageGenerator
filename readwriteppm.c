#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PPM_IMAGE *read_ppm(const char *file_name) {
  FILE *fp = fopen(file_name, "rb");

  PPM_IMAGE *image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
  printf("read");

  fscanf(fp, "%*s");
  fscanf(fp, "%d %d", &image->width, &image->height);
  fscanf(fp, "%d", &image->max_color);

  image->data = (PIXEL *)malloc(image->width * image->height * sizeof(PIXEL));
  printf("readp");

  int i;
  for (i = 0; i < (image->width * image->height); i++) {
    fscanf(fp, "%d %d %d ", &image->data[i].r, &image->data[i].g, &image->data[i].b);
  }

  fclose(fp);
  return image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image) {
  FILE *fp = fopen(file_name, "wb");

  fprintf(fp, "P3\n");
  fprintf(fp, "%d %d\n", image->width, image->height);
  fprintf(fp, "%d\n", image->max_color);

  int i;
  for (i = 0; i < (image->width * image->height); i++) {
    fprintf(fp, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
    if (i % image->width == 0) fprintf(fp, "\n");
  }

  fclose(fp);
}
