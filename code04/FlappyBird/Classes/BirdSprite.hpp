//
//  BirdSprite.hpp
//  FlappyBird
//
//  Created by apple on 2016/11/24.
//
//

#ifndef BirdSprite_hpp
#define BirdSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;


class BirdSprite:public extension::PhysicsSprite{
public:
    virtual bool init();
    static BirdSprite* create(const std::string &fileName);
    CREATE_FUNC(BirdSprite);
    
};

#endif /* BirdSprite_hpp */
