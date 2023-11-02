
// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <iostream>
#include "include/easy_sdl.h"
#include <math.h>
#include "include/mandelbrot.h"

struct pixel_t {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

const pixel_t colors[] = {
    {66, 30, 15}, /* r, g, b */
    {25, 7, 26},
    {9, 1, 47},
    {4, 4, 73},
    {0, 7, 100},
    {12, 44, 138},
    {24, 82, 177},
    {57, 125, 209},
    {134, 181, 229},
    {211, 236, 248},
    {241, 233, 191},
    {248, 201, 95},
    {255, 170, 0},
    {204, 128, 0},
    {153, 87, 0},
{106, 52, 3} };
const int NCOLORS = sizeof(colors)/sizeof(colors[0]);

int main(int argc, char* args[]) {
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;
  SDL_Renderer *renderer;


  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow(
			    "sdl_mandelbrot",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );

  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }

  screenSurface = SDL_GetWindowSurface(window);
  renderer = SDL_CreateRenderer(window, -1, 0);

  for (int i = 0; i < SCREEN_WIDTH; ++i) {
    for (int j = 0; j < SCREEN_HEIGHT; ++j) {
      int it = mapMandelbrot(i,j);
      int c = 0 ? (it >= MAXIT) : map(it, 0, 1000, 0, 255);

      if (it < MAXIT) {
        SetPixelColor(screenSurface, i, j,
          colors[it % NCOLORS].r,
          colors[it % NCOLORS].g,
          colors[it % NCOLORS].b
          );
      } else {
          SetPixelColor(screenSurface, i, j, 0, 0, 0);
      }
    }
  }

  bool keep_window_open = true;
  while(keep_window_open)
  {
    SDL_Event e;
    while(SDL_PollEvent(&e) > 0)
    {
      switch(e.type)
      {
          case SDL_QUIT:
              keep_window_open = false;
              break;
      }
      SDL_UpdateWindowSurface(window);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}