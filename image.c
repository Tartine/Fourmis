#include <SDL/SDL.h>

SDL_Surface* load_image(const char * filename)
{
    SDL_Surface* loadimage = NULL;
    SDL_Surface* optimage = NULL;

    loadimage = SDL_LoadBMP(filename);

    if(loadimage != NULL)
    {
        optimage = SDL_DisplayFormat(loadimage);

        SDL_FreeSurface(loadimage);
    }

    return optimage;
}

void blit_image(int x, int y, SDL_Surface* source, SDL_Surface* dest)
{
    SDL_Rect pos;

    pos.x = x;
    pos.y = y;

    SDL_BlitSurface(source, NULL, dest, &pos);
}
