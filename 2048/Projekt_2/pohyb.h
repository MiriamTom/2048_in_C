#pragma once

#include <SDL2/SDL.h>  // Vložení hlavního hlavičkového souboru SDL
#include <stdbool.h>
#include <SDL2/SDL_ttf.h> // tff formaty
#include <assert.h>
#include <SDL2/SDL_image.h>
#include <time.h>

int position();

void hore();
void hore_sucet();

void dole() ;
void dole_sucet();

void vpravo();
void vpravo_sucet();

void vlavo();
void vlavo_sucet();
