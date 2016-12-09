//
//  Block.cpp
//  NoOneDies
//
//  Created by apple on 2016/12/6.
//
//

#include "Block.hpp"


bool  Block::init(){
    Sprite::init();
    
    Size s = Size(rand()%20+5, rand()%30+10);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setPhysicsBody(PhysicsBody::createBox(s));
    setColor(Color3B(0,0,0));
    setTextureRect(Rect(0, 0, s.width, s.height));
    setContentSize(s);
    
    
    setPositionX(visibleSize.width);
    scheduleUpdate();
    
    
    getPhysicsBody()->setDynamic(false);
    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}

void Block::update(float dt){
    this->setPositionX(getPositionX()-4);
    if(getPositionX()<0){
        unscheduleUpdate();
        removeFromParent();
        
    }
}


