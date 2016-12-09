//
//  Rect.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "Rect.hpp"
namespace shape {

bool Rect::init(){
    
    
    return true;
}

void Rect::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
    DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
    DrawPrimitives::drawRect(Point(0,0),Point(100,100));
}

}
