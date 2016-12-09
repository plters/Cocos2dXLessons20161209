//
//  Block.hpp
//  NoOneDies
//
//  Created by apple on 2016/12/6.
//
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Block:public Sprite {
    
    
public:
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(Block);
};


#endif /* Block_hpp */
