
#ifndef VISUALIZER_H
#define VISUALIZER_H

#define BPP 8
#define FPS 60
#define WIDTH 1000
#define HEIGHT 800

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "sort/sort.h"

void visualize(int *array, int size, struct queue *states);

#endif /* ! VISUALIZER_H */
