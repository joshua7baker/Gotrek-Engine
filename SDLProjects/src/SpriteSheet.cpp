#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const char* spriteSheetName)
{
    sheetName = spriteSheetName;

    spriteSheet.push_back({ 0,  0,  0, 0 }); //top left
    spriteSheet.push_back({ 0,  0,  0, 0 }); //top right
    spriteSheet.push_back({ 0,  0,  0, 0 }); //bottom left
    spriteSheet.push_back({ 0,  0,  0, 0 }); //bottom right

    //Set top left sprite
    spriteSheet[0].x = 150;
    spriteSheet[0].y = 0;
    spriteSheet[0].w = 150;
    spriteSheet[0].h = 100;

    //Set top right sprite
    spriteSheet[1].x = 0;
    spriteSheet[1].y = 0;
    spriteSheet[1].w = 150;
    spriteSheet[1].h = 100;

    //Set bottom left sprite
    spriteSheet[2].x = 0;
    spriteSheet[2].y = 100;
    spriteSheet[2].w = 150;
    spriteSheet[2].h = 100;

    //Set bottom right sprite
    spriteSheet[3].x = 100;
    spriteSheet[3].y = 100;
    spriteSheet[3].w = 150;
    spriteSheet[3].h = 100;
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
