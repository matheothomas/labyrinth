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
#include "laby.h"

void showWindow(SDL_Renderer *renderer, int **laby){
	SDL_Rect rect;
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	rect.x = rect.y = 20;
	rect.w = rect.h = 760;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	int x1, y1, x2, y2;
	int ratio = 900/SIZE;
	for(int i = 0; i < SIZE*SIZE; i++){
		for(int j = 0; j < SIZE*SIZE; j++){
			if(laby[i][j] == 1){
				printf("laby[%d][%d] = 1\n", i, j);

				y1 = ratio*(i/SIZE) + 40;
				x1 = ratio*(i%SIZE) + 40;
				y2 = ratio*(j/SIZE) + 40;
				x2 = ratio*(j%SIZE) + 40;
				//printf("%d, %d, %d, %d\n", x1, y1, x2, y2);
				SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
				//SDL_RenderDrawLine(renderer, 40*i/SIZE, 40*i%SIZE, 40*j/SIZE, 40*j%SIZE);

			}
		}
	}


	SDL_RenderPresent(renderer);
}
