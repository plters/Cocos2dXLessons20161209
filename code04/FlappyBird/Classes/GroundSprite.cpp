//
//  GroundSprite.cpp
//  FlappyBird
//
//  Created by apple on 2016/11/25.
//
//

#include "GroundSprite.hpp"

bool GroundSprite::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}
GroundSprite* GroundSprite::create(const std::string &fileName){
    GroundSprite* ground =  new GroundSprite();
    if(ground && ground->initWithFile(fileName))
    {
        ground->autorelease();
        return ground;
    }
    CC_SAFE_DELETE(ground);
    return nullptr;
}
