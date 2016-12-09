//
//  Hero.hpp
//  NoOneDies
//
//  Created by apple on 2016/12/6.
//
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Hero:public Sprite {
    
    
public:
    virtual bool init();
    CREATE_FUNC(Hero);
};


#endif /* Hero_hpp */
