/*******************************************************************************
    SpriteEx.h

    Version : develop
    Author and Copyright : 131e55
*******************************************************************************/

#ifndef __131E55_SPRITEEX__
#define __131E55_SPRITEEX__

#include "cocos2d.h"

class SpriteEx : public cocos2d::Sprite
{
public:
    /*
    * @param {const std::string} filename 画像ファイル名
    */
    static SpriteEx* createSprite(const std::string filename);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SpriteEx);

private:
    void _initialize(const std::string filename);
};

#endif // __131E55_SPRITEEX__
