//
//  MoveBall.hpp
//  MoveBall
//
//  Created by apple on 2016/12/9.
//
//

#ifndef MoveBall_hpp
#define MoveBall_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Ball.hpp"

USING_NS_CC;

class MoveBalls:public LayerColor {
    
    
public:
    virtual bool init();
    CREATE_FUNC(MoveBalls);
    static Scene * createScene();
    
    virtual void update(float dt);
    
private:
    cocos2d::Vector<Ball*> balls;
//    Ball *ball;
    void addBall(float x,float y);
   
};



#endif /* MoveBall_hpp */
