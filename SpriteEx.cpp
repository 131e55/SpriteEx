/*******************************************************************************
    SpriteEx.cpp

    Version : develop.001
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

// 横幅の取得. 返る値は getContentSize().width と同じ
// getContentSize() を経由せず直接取得したいときに便利
float SpriteEx::getWidth()
{
    return this->getContentSize().width;
}

// 縦幅の取得. 返る値は getContentSize().height と同じ
// getContentSize() を経由せず直接取得したいときに便利
float SpriteEx::getHeight()
{
    return this->getContentSize().height;
}