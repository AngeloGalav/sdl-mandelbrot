#include "include/mandelbrot.h"
#include "include/easy_sdl.h"
#include <iostream>

int mapMandelbrot(uint xp, uint yp, float scaleXl, float scaleXr, float scaleYl, float scaleYr){
    int it = 0, x = 0, y = 0;
    while (x*x + y*y <= (2*2) && it < MAXIT)
    {
        int xt = x*x - y*y + xp;
        y = 2*x*y + yp;
        x = xt;
        it++;
    }

    return it;
}


int mapMandelbrot(uint xp, uint yp){
    float xpm =  map(xp, 0, SCREEN_WIDTH, -2.00, 0.47);
    float ypm =  map(yp, 0, SCREEN_HEIGHT, -1.12, 1.12);
    int it = 0;
    float x = 0, y = 0;
    while (x*x + y*y <= (2*2) && it < MAXIT)
    {
        float xt = x*x - y*y + xpm;
        y = 2*x*y + ypm;
        x = xt;
        it++;
    }

    return it;
}