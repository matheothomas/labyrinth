/* name : main.c
 * author : matheo thomas
 * date : 14-12-23
 */

#include <stdio.h>
#include <stdlib.h>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include "graphics.h"

#define SIZE 20

int **initLaby(){
	int **laby = (int **)malloc(SIZE*sizeof(int *));
	for(int i = 0; i < SIZE; i++){
		laby[i] = (int *)malloc(SIZE*sizeof(int));
		for(int j = 0; j < SIZE; j++){
			laby[i][j] = 0;
		}
	}
	return laby;
}




int main(void){
	int **laby = initLaby();

	

	// Graphical interface initialisation
	if(SDL_Init(SDL_INIT_VIDEO) <0){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	int width = 800;
	int height = 860;
	SDL_Window *window;
	window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height,
	SDL_WINDOW_RESIZABLE);
	if(window == 0){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	SDL_Renderer *renderer;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == 0){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	if (TTF_Init() != 0){
		fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError()); 
	}
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=0;
	initted=IMG_Init(flags);
	if((initted&flags) != flags){
		printf("IMG_Init : Impossible d'initialiser le support des formats JPG et PNG requis.\n'");
		printf("IMG_Init : %s\n", IMG_GetError());
	}


	SDL_Event event;

	int running = 1;

	while(running){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_WINDOWEVENT:
					switch (event.window.event){
						case SDL_WINDOWEVENT_CLOSE:
							printf("Window closed.\n");
							break;
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							width = event.window.data1;
							height = event.window.data2;
							printf("Size : %d%d\n", width, height);
							break;
						default:
							showWindow(renderer);
							break;

					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					printf("Mouse button down.\n");

					break;
				case SDL_QUIT:
					printf("Quit game.\n");
					running = 0;
			}
		}
		SDL_Delay(1);
	}


	return 0;
}

