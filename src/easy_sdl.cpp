#include "include/easy_sdl.h"

void SetPixelColor(SDL_Surface* surf, uint x, uint y, uint r, uint g, uint b) {
    ((Uint32*)surf->pixels)[(y*surf->w) + x] = SDL_MapRGB(surf->format, r, g, b);
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}