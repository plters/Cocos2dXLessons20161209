//
//  Poly.hpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#ifndef Poly_hpp
#define Poly_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>

using namespace cocos2d;
namespace shape {

    class Poly:public Node{
    private:
        Point ps[3];
    
    public:
        virtual bool init();
        virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
        
        CREATE_FUNC(Poly);
    };
    
}
#endif /* Poly_hpp */
