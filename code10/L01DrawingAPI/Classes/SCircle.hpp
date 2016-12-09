//
//  SCircle.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef SCircle_hpp
#define SCircle_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;

namespace shape {

    class SCircle:public Node{
        
    public:
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        CREATE_FUNC(SCircle);
    };
    
}



#endif /* SCircle_hpp */
