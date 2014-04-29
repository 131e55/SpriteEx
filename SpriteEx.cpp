/*******************************************************************************
    SpriteEx.cpp

    Version : develop
    Author and Copyright : 131e55
*******************************************************************************/

#include "SpriteEx.h"

USING_NS_CC;

SpriteEx* SpriteEx::createSprite(const std::string filename)
{
    auto sprite = SpriteEx::create();
    sprite->_initialize(filename);

    return sprite;
}

// on "init" you need to initialize your instance
bool SpriteEx::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Sprite::init() )
    {
        return false;
    }

    return true;
}

void SpriteEx::_initialize(const std::string filename)
{
    this->initWithFile(filename);
}