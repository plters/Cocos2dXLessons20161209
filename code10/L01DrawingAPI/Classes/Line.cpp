//
//  Line.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "Line.hpp"


namespace shape {
    
    bool Line::init(){
        
        return true;
    }
    
    void Line::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
        
        DrawPrimitives::drawLine(Point(0,0), Point(100,100));
    }
}

