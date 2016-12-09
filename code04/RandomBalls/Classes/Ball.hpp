//
//  Ball.hpp
//  RandomBalls
//
//  Created by apple on 2016/12/9.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class Ball:public Sprite {
    
    
public:
    virtual bool init();
    CREATE_FUNC(Ball);
    virtual void update(float dt);
    
private:
    float speedX,speedY;
    Size visibleSize;
};

#endif /* Ball_hpp */
