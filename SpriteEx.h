/*******************************************************************************
    SpriteEx.h

    Version : 1.00
    Author and Copyright : 131e55 (Twitter : @131e55)
*******************************************************************************/

#ifndef __131E55_SPRITEEX__
#define __131E55_SPRITEEX__

#include "cocos2d.h"

class SpriteEx : public cocos2d::Sprite
{
public:
    // const std::string filename : 画像ファイル名
    // int divNumX : 横のフレーム分割数
    // int divNumY : 縦のフレーム分割数
    static SpriteEx* createSprite(const std::string filename, int divNumX, int divNumY);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SpriteEx);

    // 横幅の取得. 返る値は getContentSize().width と同じ
    // getContentSize() を経由せず直接取得したいときに便利
    float getWidth();
    
    // 縦幅の取得. 返る値は getContentSize().height と同じ
    // getContentSize() を経由せず直接取得したいときに便利
    float getHeight();

    // フレームを設定する
    void setFrame(int frame_id);

    // Sprite の範囲を取得する
    cocos2d::Rect getRect();

    // Sprite に触れているかをチェックする
    bool isTouch(cocos2d::Point point);

    // アンチエイリアスの設定
    // bool b : true ならアンチエイリアスを有効にする
    //          false ならアンチエイリアスを無効にする
    void antiAlias(bool b);

private:
    // 横のフレーム分割数
    int _divNumX;

    // 縦のフレーム分割数
    int _divNumY;

    // フレームサイズ
    cocos2d::Size _frameSize;

    // フレーム分割数
    int _totalFrameNum;

    // 初期化
    void _initialize(const std::string filename, int divNumX, int divNumY);
};

#endif // __131E55_SPRITEEX__
