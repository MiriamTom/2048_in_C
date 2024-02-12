#include <SDL2/SDL.h>  // Vložení hlavního hlavičkového souboru SDL
#include <stdbool.h>
#include <SDL2/SDL_ttf.h> // tff formaty
#include <assert.h>
#include <SDL2/SDL_image.h>
#include <time.h>

int COLUMNS;
int ROWS;

#include "pohyb.h"
#include "stvorec.h"
#include "operacie.h"

int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 800;




// gcc 2048_3.c pohyb.c stvorec.c operacie.c -fsanitize=address -lSDL2 -lSDL2_image -lSDL2_ttf -o ./main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{   
    SDL_Init(SDL_INIT_VIDEO);   
    srand(time(NULL));
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow(
        "2048",  
        100,                
        100,                
        WINDOW_WIDTH,                
        WINDOW_HEIGHT,                
        SDL_WINDOW_SHOWN    
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    SDL_Event e;
        bool quit = false;
        

    SDL_Surface * sscore; 
    SDL_Texture * stexture;

    char pole_score[99];
    int texW = 70;
    int texH = 70;
    TTF_Font * font = TTF_OpenFont("Amatic-Bold.ttf", 70);
    assert(font);
    SDL_Color color = { 255, 0, 0 };
    SDL_Color cierna = { 0, 0, 0 };
    int SCORE = 0;
/////////////////////////////////////////
    SDL_Surface * svysledok; 
    SDL_Texture * tvysledok;
    char vysledok[99];
////////////////////////////////////////////////////////////////////////
    
    bool choose = false;
    //1//
    SDL_Rect rect1;
    rect1.x = 0;
    rect1.y = 0;
    rect1.w = rect1.h = 50;
    SDL_Surface * slevel1; 
    SDL_Texture * tlevel1;
    char level1[10]; 
    //2//
    SDL_Rect rect2;
    rect2.x = 0;
    rect2.y = 50;
    rect2.w = rect2.h = 50;
    SDL_Surface * slevel2; 
    SDL_Texture * tlevel2;
    char level2[10]; 
    //3//
    SDL_Rect rect3;
    rect3.x = 0;
    rect3.y = 100;
    rect3.w = rect3.h = 50;
    SDL_Surface * slevel3; 
    SDL_Texture * tlevel3;
    char level3[10]; 

    SDL_Event c;
    SDL_Point  mys;
    
    while (!choose){
        SDL_SetRenderDrawColor(renderer, 151,239, 198, 255); 
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&c)){
            
            if (c.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mys.x,&mys.y);
                if (SDL_PointInRect(&mys,&rect1)){
                COLUMNS = 4;
                ROWS = 4;
                choose=true;
                }
                if (SDL_PointInRect(&mys,&rect2)){
                COLUMNS = 8;
                ROWS = 8;
                choose=true;
                }
                if (SDL_PointInRect(&mys,&rect3)){
                COLUMNS = 20;
                ROWS = 20;
                choose=true;
                }
            }

        }
        //1
        sprintf(level1, "4x4");
        slevel1 = TTF_RenderText_Solid(font, level1, cierna);
        tlevel1 = SDL_CreateTextureFromSurface(renderer, slevel1);
        SDL_QueryTexture(tlevel1, NULL, NULL, &texW, &texH);
        SDL_RenderCopy(renderer, tlevel1, NULL, &rect1);
         
        SDL_FreeSurface(slevel1);
        SDL_DestroyTexture(tlevel1);   
        //2
        sprintf(level2, "8x8");
        slevel2 = TTF_RenderText_Solid(font, level2, cierna);
        tlevel2 = SDL_CreateTextureFromSurface(renderer, slevel2);
        SDL_QueryTexture(tlevel2, NULL, NULL, &texW, &texH);
        SDL_RenderCopy(renderer, tlevel2, NULL, &rect2);
         
        SDL_FreeSurface(slevel2);
        SDL_DestroyTexture(tlevel2); 
        //3
        sprintf(level3, "20x20");
        slevel3 = TTF_RenderText_Solid(font, level3, cierna);
        tlevel3 = SDL_CreateTextureFromSurface(renderer, slevel3);
        SDL_QueryTexture(tlevel3, NULL, NULL, &texW, &texH);
        SDL_RenderCopy(renderer, tlevel3, NULL, &rect3);
         
        SDL_FreeSurface(slevel3);
        SDL_DestroyTexture(tlevel3); 

        SDL_RenderPresent(renderer);
    }

    int* matica = vytvor_maticu(COLUMNS, ROWS);
    

    for(int i = 0; i < COLUMNS * ROWS ; i++)
    {
        matica[i] = 0;
    }

   nahodne_cislo(matica, COLUMNS, ROWS);
 //  nahodne_cislo(matica, COLUMNS, ROWS);
    
///////////////////////////////////////////////////////////////////////

    while (!quit)
    {   
        SDL_SetRenderDrawColor(renderer, 151,239, 198, 255); 
        SDL_RenderClear(renderer);
        
        
        while (SDL_PollEvent(&e))
        {
           if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN){
                
                switch(e.key.keysym.sym) {

                    case SDLK_UP: {
                        vlavo_sucet(matica,COLUMNS,ROWS,&SCORE); 
                        nahodne_cislo(matica, COLUMNS, ROWS);
                        break;
                    }

                    case SDLK_LEFT: {
                        hore_sucet(matica,COLUMNS,ROWS,&SCORE); 
                        nahodne_cislo(matica, COLUMNS, ROWS);
                        break;
                    }

                    case SDLK_DOWN: {
                        vpravo_sucet(matica,COLUMNS,ROWS,&SCORE); 
                        nahodne_cislo(matica, COLUMNS, ROWS);
                        break;
                    }

                    case SDLK_RIGHT: {
                        dole_sucet(matica,COLUMNS,ROWS,&SCORE); 
                        nahodne_cislo(matica);
                        break;
                    }
                }
            }
            
        }

        

        stvorce(renderer,matica, COLUMNS, ROWS, WINDOW_WIDTH);  
        if (prehra(matica, COLUMNS, ROWS)==1){
            sprintf(vysledok, "Prehral si :(");

        svysledok = TTF_RenderText_Solid(font, vysledok, color);
        tvysledok = SDL_CreateTextureFromSurface(renderer, svysledok);
        SDL_QueryTexture(tvysledok, NULL, NULL, &texW, &texH);

        SDL_Rect dstrect = { WINDOW_WIDTH/2-texW/2, WINDOW_HEIGHT-200, texW,texH };
        SDL_RenderCopy(renderer, tvysledok, NULL, &dstrect);
         SDL_FreeSurface(svysledok);
        SDL_DestroyTexture(tvysledok);
        }
        if (vyhra(matica, COLUMNS, ROWS)==1){
            sprintf(vysledok, "Vyhral si :D");

        svysledok = TTF_RenderText_Solid(font, vysledok, color);
        tvysledok = SDL_CreateTextureFromSurface(renderer, svysledok);
        SDL_QueryTexture(tvysledok, NULL, NULL, &texW, &texH);

        SDL_Rect dstrect = { WINDOW_WIDTH/2-texW/2, WINDOW_HEIGHT-200, texW,texH };
        SDL_RenderCopy(renderer, tvysledok, NULL, &dstrect);
         SDL_FreeSurface(svysledok);
        SDL_DestroyTexture(tvysledok);
        }
        

        sprintf(pole_score, "SCORE: %d", SCORE);
        sscore = TTF_RenderText_Solid(font, pole_score, cierna);
        stexture = SDL_CreateTextureFromSurface(renderer, sscore);
        SDL_QueryTexture(stexture, NULL, NULL, &texW, &texH);

        SDL_Rect dstrect = { 50, WINDOW_HEIGHT-100, texW,texH };
        SDL_RenderCopy(renderer, stexture, NULL, &dstrect);
        
        SDL_FreeSurface(sscore);
        SDL_DestroyTexture(stexture);
        
        SDL_RenderPresent(renderer);
    }
   SDL_DestroyTexture(stexture);
    
    free(matica);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}    