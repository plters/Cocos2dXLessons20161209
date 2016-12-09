//
//  CardSprite.hpp
//  TZFE
//
//  Created by apple on 2016/11/24.
//
//

#ifndef CardSprite_h
#define CardSprite_h

#include <stdio.h>
#include "cocos2d.h"

class CardSprite:public cocos2d::Sprite {
    
public:
    static  CardSprite *createCardSprite(int number,int width,int height,float CardSpriteX,float CardSpriteY);
    virtual bool init();
    CREATE_FUNC(CardSprite);
    //获取数字
    int getNumber();
    //设置数字
    void setNumber(int num);
    
private:
    //显示在界面
    int number;
    void enemyInit(int number,int width,int height,float CardSpriteX,float CardSpriteY);
    
    //定义显示数字的控件
    cocos2d::Label   *labelTTFCardNumber;
    
    //显示的背景
    cocos2d::LayerColor *layerColorBG;
    
};

#endif /* CardSprite_hpp */
