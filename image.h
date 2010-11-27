#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

SDL_Surface* load_image(const char * filename);
void blit_image(int x, int y, SDL_Surface* source, SDL_Surface* dest);

#endif // IMAGE_H_INCLUDED
