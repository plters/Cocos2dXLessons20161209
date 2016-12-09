//
//  BirdSprite.cpp
//  FlappyBird
//
//  Created by apple on 2016/11/24.
//
//

#include "BirdSprite.hpp"


bool BirdSprite::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

BirdSprite* BirdSprite::create(const std::string &fileName){
    BirdSprite* bird =  new BirdSprite();
    if(bird && bird->initWithFile(fileName))
    {
        bird->autorelease();
        return bird;
    }
    CC_SAFE_DELETE(bird);
    return nullptr;
}
