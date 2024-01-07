#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const char* spriteSheetName, int x, int y, int w, int h)
{
    sheetName = spriteSheetName;

    spriteSheet.push_back({ 0,  0,  0, 0 }); //top left
    spriteSheet.push_back({ 0,  0,  0, 0 }); //top right
    spriteSheet.push_back({ 0,  0,  0, 0 }); //bottom left
    spriteSheet.push_back({ 0,  0,  0, 0 }); //bottom right

    //Set top left sprite
    spriteSheet[0].x = x;
    spriteSheet[0].y = 0;
    spriteSheet[0].w = w;
    spriteSheet[0].h = h;

    //Set top right sprite
    spriteSheet[1].x = 0;
    spriteSheet[1].y = 0;
    spriteSheet[1].w = w;
    spriteSheet[1].h = h;

    //Set bottom left sprite
    spriteSheet[2].x = 0;
    spriteSheet[2].y = y;
    spriteSheet[2].w = w;
    spriteSheet[2].h = h;

    //Set bottom right sprite
    spriteSheet[3].x = x;
    spriteSheet[3].y = y;
    spriteSheet[3].w = w;
    spriteSheet[3].h = h;
}

SpriteSheet::~SpriteSheet(){
}

//To be converted this to get select sprites along a row/column x amount of times at a height & width
//This will support different sprite sheets being defined
//The sprite sheet sdl_rect vector could then be defined in the renderableobject.cpp class making this class redundant eventually
std::vector<SDL_Rect>* SpriteSheet::getSprites()
{
    return &spriteSheet;
}

const char* SpriteSheet::getTextureName()   
{
    return sheetName;
}
