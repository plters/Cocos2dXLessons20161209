//
//  SCircle.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "SCircle.hpp"


namespace shape {
    bool SCircle::init(){
        return true;
    }
    
    void  SCircle::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
        DrawPrimitives::setDrawColor4B(0, 255, 0, 255);
        DrawPrimitives::drawSolidCircle(Point(0,0), 50, M_PI*2, 50);
    }
}
