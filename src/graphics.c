/* name : graphics.c
 * author : matheo thomas
 * date : 14-12-23
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphics.h"

void showWindow(SDL_Renderer *renderer){
	SDL_Rect rect;
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	rect.x = rect.y = 20;
	rect.w = rect.h = 400;
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);
}
