//
//  SRect.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "SRect.hpp"


namespace shape {

void SRect::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
    DrawPrimitives::drawSolidRect(Point(0,0), Point(100,100), Color4F(0, 0, 1, 1));
    
}
    
    
}
