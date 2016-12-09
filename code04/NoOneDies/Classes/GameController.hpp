//
//  GameController.hpp
//  NoOneDies
//
//  Created by apple on 2016/12/6.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
#include "Edge.hpp"
#include "Hero.hpp"
#include "Block.hpp"

USING_NS_CC;


class GameController:public Ref {
private:
    Layer * _layer;
    float _positionY;
    Size visibleSize;
    int currentFrameIndex;
    int nextFrameCount;
    Edge * edge;
    Hero * hero;
private:
    void resetFrames();
    void addBlock();
    
public:
    void onUpdate(float dt);
    virtual bool init(Layer * layer,float positionY);
    bool hitTestPoint(Vec2 point);
    void onUserTouch();
    static GameController* create(Layer * layer,float positionY);
    
  
};


#endif /* GameController_hpp */
