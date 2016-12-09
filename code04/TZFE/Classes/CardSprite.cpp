//
//  CardSprite.cpp
//  TZFE
//
//  Created by apple on 2016/11/24.
//
//

#include "CardSprite.h"

USING_NS_CC;

CardSprite*  CardSprite::createCardSprite(int numbers,int width,int height,float CardSpriteX,float CardSpriteY){
     CardSprite *enemy = new(std::nothrow) CardSprite();
     if(enemy && enemy->init()){
         enemy->autorelease();
         enemy->enemyInit(numbers, width, height, CardSpriteX, CardSpriteY);
         return enemy;
     }
     CC_SAFE_DELETE(enemy);
     return nullptr;
}
bool CardSprite::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

int CardSprite::getNumber(){
    return number;
}
//设置数字
void CardSprite::setNumber(int num){
    number = num;
    
    //判断数字的大小来调整字体大小
    if(number>=0){
        labelTTFCardNumber->setSystemFontSize(100);
    }
    if(number>=16){
        labelTTFCardNumber->setSystemFontSize(90);
    }
    if(number>=128){
        labelTTFCardNumber->setSystemFontSize(60);
    }
    if(number>=1024){
        labelTTFCardNumber->setSystemFontSize(40);
    }
    
    //判断数字的大小调整颜色
    if(number==0){
        layerColorBG->setColor(cocos2d::Color3B(200,190,180));
    }
    if(number==2){
        layerColorBG->setColor(cocos2d::Color3B(240,230,220));
    }
    if(number==4){
        layerColorBG->setColor(cocos2d::Color3B(240,220,200));
    }
    if(number==8){
        layerColorBG->setColor(cocos2d::Color3B(240,180,120));
    }
    if(number==16){
        layerColorBG->setColor(cocos2d::Color3B(240,140,90));
    }
    if(number==32){
        layerColorBG->setColor(cocos2d::Color3B(240,120,90));
    }
    if(number==64){
        layerColorBG->setColor(cocos2d::Color3B(240,90,60));
    }
    if(number==128){
        layerColorBG->setColor(cocos2d::Color3B(240,90,60));
    }
    if(number==256){
        layerColorBG->setColor(cocos2d::Color3B(240,200,70));
    }
    if(number==521){
        layerColorBG->setColor(cocos2d::Color3B(240,200,70));
    }
    if(number==1024){
        layerColorBG->setColor(cocos2d::Color3B(0,130,0));
    }
    if(number==2048){
        layerColorBG->setColor(cocos2d::Color3B(0,130,0));
    }
  
    
    //更新显示的数字
    if(number>0){
        labelTTFCardNumber->setString(__String::createWithFormat("%i",number)->getCString());
    }else{
        labelTTFCardNumber->setString("");
    }
    
}
void CardSprite::enemyInit(int numbers,int width,int height,float CardSpriteX,float CardSpriteY){
    //初始化数字
    number = numbers;
    
    //加入卡片的背景颜色
    layerColorBG = cocos2d::LayerColor::create(Color4B(200,190,180,255),width-15,height-15);
    layerColorBG->setPosition(Vec2(CardSpriteX, CardSpriteY));
    
    
    //判断如果不等于0就显示,否则为空
    if(numbers > 0){
        //加入中间字体
        labelTTFCardNumber = cocos2d::Label::create(__String::createWithFormat("%i",numbers)->getCString(), "HirakakuProN-W6", 100);
        labelTTFCardNumber->setPosition(Vec2(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
        layerColorBG->addChild(labelTTFCardNumber);
        
    }else{
        //加入中间字体
        labelTTFCardNumber = cocos2d::Label::create("", "HirakakuProN-W6", 100);
        labelTTFCardNumber->setPosition(Vec2(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
        layerColorBG->addChild(labelTTFCardNumber);
    }
    this->addChild(layerColorBG);
}





