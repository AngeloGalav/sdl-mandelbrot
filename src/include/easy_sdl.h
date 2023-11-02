#include <SDL2/SDL.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void SetPixelColor(SDL_Surface* surf, uint x, uint y, uint r, uint g, uint b);

float map(float x, float in_min, float in_max, float out_min, float out_max);