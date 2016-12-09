//
//  GroundSprite.hpp
//  FlappyBird
//
//  Created by apple on 2016/11/25.
//
//

#ifndef GroundSprite_hpp
#define GroundSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class GroundSprite:public cocos2d::extension::PhysicsSprite{
    
public:
    virtual bool init();
    static GroundSprite* create(const std::string &fileName);
    CREATE_FUNC(GroundSprite);
};
#endif /* GroundSprite_hpp */
