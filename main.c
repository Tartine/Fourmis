#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include "image.h"
#define X 800
#define Y 600


int main ( int argc, char* argv[] )
{
    SDL_Surface* fond = NULL;
    SDL_Surface* sucre = NULL;

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit(SDL_Quit);

    SDL_Surface* screen = SDL_SetVideoMode(X, Y, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    fond = load_image("fond.bmp");
    sucre = load_image("sugar.bmp");


    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = true;
                break;

            case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            }
        }

        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        blit_image(0, 0, fond, screen);
        blit_image(50, 50, sucre, screen);

        SDL_Flip(screen);
    }

    SDL_FreeSurface(fond);
    SDL_FreeSurface(sucre);

    printf("Exited cleanly\n");
    return 0;
}
