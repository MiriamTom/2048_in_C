#include "stvorec.h"

void stvorce (SDL_Renderer *renderer, int* matica, int COLUMNS, int ROWS, int WINDOW_WIDTH){
    SDL_Texture * texture;

    int a = 0;

    if(COLUMNS>=ROWS){
        a = ((COLUMNS*ROWS) - ((COLUMNS - 1)*5)) / COLUMNS ;

    }
    else if(COLUMNS<ROWS){
        a = ((COLUMNS*ROWS)- ((ROWS - 1)*5)) / ROWS ;
    }

    int zacatek = 0 ;
    int zacatek_y = 0 ;

    int posun = WINDOW_WIDTH/COLUMNS + 8;
    
    SDL_Rect rect;
    rect.x = zacatek; //pozice x
    rect.y = zacatek_y; //pozice y
    rect.w = WINDOW_WIDTH/COLUMNS - 10; //sirka obrazku
    rect.h = WINDOW_WIDTH/COLUMNS - 10; //vyska obrazku
    

    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++ ){
            if(matica[i*COLUMNS+j]==0){
                texture = IMG_LoadTexture(renderer, "png/NULL.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 2){
                texture = IMG_LoadTexture(renderer, "png/2.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 4){
                texture = IMG_LoadTexture(renderer, "png/4.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 8){
                texture = IMG_LoadTexture(renderer, "png/8.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 16){
                texture = IMG_LoadTexture(renderer, "png/16.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 32){
                texture = IMG_LoadTexture(renderer, "png/32.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 64){
                texture = IMG_LoadTexture(renderer, "png/64.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 128){
                texture = IMG_LoadTexture(renderer, "png/128.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 256){
                texture = IMG_LoadTexture(renderer, "png/256.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 512){
                texture = IMG_LoadTexture(renderer, "png/512.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 1024){
                texture = IMG_LoadTexture(renderer, "png/1024.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            else if(matica[i*COLUMNS + j] == 2048){
                texture = IMG_LoadTexture(renderer, "png/2048.png");
                assert(texture);
                SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, 0);
            }
            rect.x += posun;
            SDL_DestroyTexture(texture);
        }
        rect.y += posun;
        rect.x = zacatek;
    }
    SDL_DestroyTexture(texture);
}