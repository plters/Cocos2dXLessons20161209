//
//  Line.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

namespace shape {
    
    class Line:public Node{
        
    public:
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        CREATE_FUNC(Line);
    };
}

#endif /* Line_hpp */
