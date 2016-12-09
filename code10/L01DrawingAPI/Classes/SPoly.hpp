//
//  SPoly.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef SPoly_hpp
#define SPoly_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

namespace shape {
    
    class SPoly:public Node{
    private:
        Point points[5];
    public:
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        CREATE_FUNC(SPoly);
    };
}

#endif /* SPoly_hpp */
