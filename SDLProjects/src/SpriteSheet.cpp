#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
    texName = "assets/buttontest.png";

    spriteSheet.push_back({ 0,  0,  150,100 }); //top left
    spriteSheet.push_back({ 150,0,  150,100 }); //top right
    spriteSheet.push_back({ 0,  100,150,240 }); //bottom left
    spriteSheet.push_back({ 150,100,150,240 }); //bottom right

    //Set top left sprite
    spriteSheet[0].x = 0;
    spriteSheet[0].y = 0;
    spriteSheet[0].w = 100;
    spriteSheet[0].h = 100;

    //Set top right sprite
    spriteSheet[1].x = 100;
    spriteSheet[1].y = 0;
    spriteSheet[1].w = 100;
    spriteSheet[1].h = 100;

    //Set bottom left sprite
    spriteSheet[2].x = 0;
    spriteSheet[2].y = 100;
    spriteSheet[2].w = 100;
    spriteSheet[2].h = 100;

    //Set bottom right sprite
    spriteSheet[3].x = 100;
    spriteSheet[3].y = 100;
    spriteSheet[3].w = 100;
    spriteSheet[3].h = 100;
}

SpriteSheet::~SpriteSheet()
{
}

std::vector<SDL_Rect> SpriteSheet::getSprites()
{
    return spriteSheet;
}

const char* SpriteSheet::getTextureName()
{
    return texName;
}
