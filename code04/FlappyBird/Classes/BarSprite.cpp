//
//  BarSprite.cpp
//  FlappyBird
//
//  Created by apple on 2016/11/25.
//
//

#include "BarSprite.hpp"

bool BarSprite::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}
BarSprite* BarSprite::create(const std::string &fileName){
    BarSprite* bar =  new BarSprite();
    if(bar && bar->initWithFile(fileName))
    {
        bar->autorelease();
        return bar;
    }
    CC_SAFE_DELETE(bar);
    return nullptr;
}
