//
//  Circle.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

namespace shape {
    
    class Circle:public Node{
        
        
    public:
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        CREATE_FUNC(Circle);
        
    };
    
    
}

#endif /* Circle_hpp */
