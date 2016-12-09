//
//  Rect.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef Rect_hpp
#define Rect_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;


namespace  shape{
    
class Rect:public Node{
public:
    virtual bool init();
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

    CREATE_FUNC(Rect);
};

}
#endif /* Rect_hpp */
