//
//  Points.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef Points_hpp
#define Points_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

namespace shape {
    
    class Points:public Node{
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

        
        public:
        CREATE_FUNC(Points);
    };
}
#endif /* Points_hpp */
