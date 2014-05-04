/*******************************************************************************
    SpriteEx.cpp

    Version : develop.009
    Author and Copyright : 131e55
*******************************************************************************/

#include "SpriteEx.h"

USING_NS_CC;

SpriteEx* SpriteEx::createSprite(const std::string filename, int divNumX, int divNumY)
{
    auto sprite = SpriteEx::create();
    sprite->_initialize(filename, divNumX, divNumY);

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

void SpriteEx::_initialize(const std::string filename, int divNumX, int divNumY)
{
    // 画像を読み込む
    this->initWithFile(filename);

    // 受け取った値を保持しておく
    _divNumX = divNumX;
    _divNumY = divNumY;

    // 分割後のフレームのサイズ (初期値はオリジナルのサイズ)
    _frameSize = this->getContentSize();

    // フレーム分割数
    _totalFrameNum = 1;

    // フレーム分割
    if (_divNumX >= 1 && _divNumY >= 1) {
        if ((int)_frameSize.width % (int)_divNumX == 0) {
            _frameSize.width /= _divNumX;
            _totalFrameNum *= _divNumX;
        } else {
            log("[SpriteEx::_initialize Error] width %% _divNumX is not 0");
        }

        if ((int)_frameSize.height % (int)_divNumY == 0) {
            _frameSize.height /= _divNumY;
            _totalFrameNum *= _divNumY;
        } else {
            log("[SpriteEx::_initialize Error] height %% _divNumY is not 0");
        }
        this->setTextureRect(Rect(0, 0, _frameSize.width, _frameSize.height));
    }
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

// フレームを設定する
void SpriteEx::setFrame(int frame_id)
{
    // オリジナルの画像のどの位置からフレームを切り抜くか
    Point target = Point(0, 0);

    // 負の id は除外
    if (frame_id >= 0) {
        // フレーム分割数より大きい id を指定されたときは周回する
        frame_id %= _totalFrameNum;

        // frame_id = 0 のときは target に変化なし
        if (frame_id > 0) {
            target.x = (frame_id % _divNumX) * _frameSize.width;
            target.y = (frame_id / _divNumX) * _frameSize.height;
        }

        // フレームを切り抜く
        this->setTextureRect(Rect(target.x, target.y, _frameSize.width, _frameSize.height));
    } else {
        log("[SpriteEx::setFrame Error] (frame >= 0) is not true");
    }
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
    if (this->getOpacity() == 0) {
        return false;
    }
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