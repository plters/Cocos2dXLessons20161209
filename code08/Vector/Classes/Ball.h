//
//  Ball.h
//  Vector
//
//  Created by apple on 2016/12/2.
//
//

#ifndef Ball_h
#define Ball_h

#include <cocos2d.h>

class Ball:public cocos2d::Sprite{
    
private:
    float speedX,speedY;
    
public:
    
    virtual bool init(){
        speedX = CCRANDOM_0_1()*10-5;
        speedY = CCRANDOM_0_1()*10-5;
        
        Sprite::initWithFile("ball.png");
        return true;
    }
    
    void move(){
        setPositionX(getPositionX()+speedX);
        setPositionY(getPositionY()+speedY);
    }
    CREATE_FUNC(Ball);
};


#endif /* Ball_h */
