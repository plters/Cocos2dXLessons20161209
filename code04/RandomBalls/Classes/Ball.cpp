
//
//  Ball.cpp
//  RandomBalls
//
//  Created by apple on 2016/12/9.
//
//

#include "Ball.hpp"

bool Ball::init(){
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    Sprite::initWithFile("ball.png");
    
    speedX = CCRANDOM_0_1()*10-5;
    speedY = CCRANDOM_0_1()*10-5;
    
    scheduleUpdate();
    return true;
}


void Ball::update(float dt){
    
    setPosition(getPositionX()+speedX,getPositionY()+speedY);
    
    if(getPositionX()<getContentSize().width/2){
        speedX = fabs(speedX);
        
    }
    if(getPositionX()>visibleSize.width-getContentSize().width/2){
        speedX = -fabs(speedX);
    }
    if(getPositionY()<visibleSize.height/2){
        speedY = fabs(speedY);
    }
    if(getPositionY()>visibleSize.height-getContentSize().height/2){
        speedY = -fabs(speedY);
    }
}
