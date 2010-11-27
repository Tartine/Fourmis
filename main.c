#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include "image.h"
#include "fourmis.h"

int main ( int argc, char* argv[] )
{
    SDL_Surface* screen = NULL;
    SDL_Surface* fond = NULL;
    SDL_Surface* sucre = NULL;
    SDL_Surface* antfarm = NULL;
    ant_t *ant;



    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

   screen = SDL_SetVideoMode(X, Y, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    matrix_init();

    atexit(SDL_Quit);

    fond = load_image("fond.bmp");
    sucre = load_image("sugar.bmp");
    antfarm = load_image("Sans titre.bmp");


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
        blit_image(570, 410, antfarm, screen);

        SDL_Flip(screen);
    }

    SDL_FreeSurface(fond);
    SDL_FreeSurface(antfarm);
    SDL_FreeSurface(sucre);

    printf("Exited cleanly\n");
    return 0;
}
