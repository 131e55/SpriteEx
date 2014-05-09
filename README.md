SpriteEx
========
cocos2d-x v3.0 の Sprite を個人用に拡張したものです.  
SpriteEx.h をインクルードして利用します.

Reference 
---------
* [SpriteEx* createSprite(const std::string filename, int divNumX, int divNumY)](#method1)
* [void setFrame(int frame_id)](#method2)
* [float getWidth()](#method3)
* [float getHeight()](#method4)
* [cocos2d::Rect getRect()](#method5)
* [bool isTouch(cocos2d::Point point)](#method6)
* [antiAlias](#method7)

### <a name="method1"> createSprite </a>
```
// const std::string filename : 画像ファイル名
// int divNumX : 横のフレーム分割数
// int divNumY : 縦のフレーム分割数
SpriteEx* createSprite(const std::string filename, int divNumX, int divNumY)
```

1 つの画像ファイルを指定された数に分割し, 分割された 1 つのフレームを表示させます.  
キャラクターやボタンなど, 1 つの画像ファイルに同じサイズの画像がまとまったものでないと使えません.

例1. 画像を分割する必要がない場合
```
auto spriteex = SpriteEx::createSprite("hello1.png", 1, 1);
layer->addChild(spriteex);
```

例2. 画像を横 3 つ, 縦 2 つの計 6 つに分割する
```
auto spriteex = SpriteEx::createSprite("hello6.png", 3, 2);
layer->addChild(spriteex);
```

### <a name="method2"> setFrame </a>
```
void setFrame(int frame_id)
```

どのフレームを表示させるかを設定します.  
フレーム番号を指定しますが, フレーム番号は次の例のように決められます.

例1. フレーム番号の割り当て (横 1 つ, 縦 4 つの計 4 つに分割されていた場合)
```
[1]
[2]
[3]
[4]
```

例2. フレーム番号の割り当て (横 6 つ, 縦 1 つの計 6 つに分割されていた場合)
```
[1][2][3][4][5][6]
```

例3. フレーム番号の割り当て (横 4 つ, 縦 3 つの計 12 つに分割されていた場合)
```
[ 1][ 2][ 3][ 4]
[ 5][ 6][ 7][ 8]
[ 9][10][11][12]
```

### <a name="method3"> getWidth </a>
```
float getWidth()
```

1 つのフレームの横幅を取得します.  
spriteex->getContentSize().width でも取得できます.  

例1. 600px * 300px の画像ファイルを横 3 つ, 縦 2 の計 6 つに分割した場合
```
auto spriteex = SpriteEx::createSprite("hello6.png", 3, 2);
float width = spriteex->getWidth();  // width = 200 
```

### <a name="method4"> getHeight </a>
```
float getHeight()
```

1 つのフレームの縦幅を取得します.  
spriteex->getContentSize().height でも取得できます.  

例1. 600px * 300px の画像ファイルを横 3 つ, 縦 2 の計 6 つに分割した場合
```
auto spriteex = SpriteEx::createSprite("hello6.png", 3, 2);
float height = spriteex->getHeight();  // height = 150
```

### <a name="method5"> getRect </a>
```
cocos2d::Rect getRect()
```

フレームが位置している範囲を取得します.  
Rect については cocos2d-x のリファレンスで確認してください.  
[cocos2d-x Rect](http://www.cocos2d-x.org/reference/native-cpp/V3.0/d4/d8a/classcocos2d_1_1_rect.html)

### <a name="method6"> isTouch </a>
```
bool isTouch(cocos2d::Point point)
```

与えた座標がフレームに触れているかを取得します.  
Point については cocos2d-x のリファレンスで確認してください.  
[cocos2d-x Point](http://www.cocos2d-x.org/reference/native-cpp/V3.0/d6/dd7/classcocos2d_1_1_point.html)

例1. フレームに触れていない場合
```
// hello4.png は 100px * 100px とし, 横 2 つ, 縦 2 つの計 4 つに分割する
auto spriteex = SpriteEx::createSprite("hello4.png", 2, 2);
spriteex->setPosition(200, 200);
bool b = spriteex->isTouch(Point(0, 0));    // b = false
```

例2. フレームに触れている場合
```
// hello4.png は 100px * 100px とし, 横 2 つ, 縦 2 つの計 4 つに分割する
auto spriteex = SpriteEx::createSprite("hello4.png", 2, 2);
spriteex->setPosition(200, 200);
bool b = spriteex->isTouch(Point(200, 200));    // b = true
```

### <a name="method7"> antiAlias </a>
```
void antiAlias(bool b)
```

アンチエイリアスを有効にするかどうかを設定できます.  
デフォルトでは有効になっています.  

例1. アンチエイリアスを無効にする
```
auto spriteex = SpriteEx::createSprite("hello8.png", 2, 4);
spriteex->antiAlias(false);
```

例2. アンチエイリアスを有効にする
```
auto spriteex = SpriteEx::createSprite("hello8.png", 2, 4);
spriteex->antiAlias(true);
```