/*******************************************************************************
    SpriteEx.cpp

    Version : develop.003
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

// Sprite の範囲を取得する
Rect SpriteEx::getRect()
{
    Point point = this->getPosition();
    Point anchor = this->getAnchorPoint();
    Size size = this->getContentSize();

    return Rect(
        point.x - (size.width * anchor.x),
        point.y - (size.height * anchor.y),
        size.width,
        size.height);
}

// Sprite に触れているかをチェックする
bool SpriteEx::isTouch(Point point)
{
    return this->getRect().containsPoint(point);
}

// アンチエイリアスの設定
// bool b : true ならアンチエイリアスを有効にする
//          false ならアンチエイリアスを無効にする
void SpriteEx::antiAlias(bool b)
{
    if (b == true) {
        this->getTexture()->setAntiAliasTexParameters();
    }
    else {
        this->getTexture()->setAliasTexParameters();
    }
}