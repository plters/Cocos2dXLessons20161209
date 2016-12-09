//
//  SRect.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef SRect_hpp
#define SRect_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;
namespace shape {
    
    class SRect:public Node{
        
        
    public:
        virtual bool init(){
            
            return true;
        }
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        CREATE_FUNC(SRect);
    };
    
    
}

#endif /* SRect_hpp */
