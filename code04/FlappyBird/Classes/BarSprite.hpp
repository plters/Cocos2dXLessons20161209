//
//  BarSprite.hpp
//  FlappyBird
//
//  Created by apple on 2016/11/25.
//
//

#ifndef BarSprite_hpp
#define BarSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class BarSprite:public cocos2d::extension::PhysicsSprite{
    
public:
    virtual bool init();
    static BarSprite* create(const std::string &fileName);
    CREATE_FUNC(BarSprite);
};
#endif /* BarSprite_hpp */
