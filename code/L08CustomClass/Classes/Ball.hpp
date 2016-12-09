//
//  Ball.hpp
//  L08CustomClass
//
//  Created by apple on 2016/12/1.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Ball:public Sprite{
    
public:
    virtual bool init();
    
    CREATE_FUNC(Ball);
    
//    static Ball* create(){
//        
//        Ball * b = new Ball();
//        b->init();
//        b->autorelease();
//        
//        return b;
//    }
    
};


#endif /* Ball_hpp */
