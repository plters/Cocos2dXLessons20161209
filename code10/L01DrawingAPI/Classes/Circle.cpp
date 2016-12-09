//
//  Circle.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "Circle.hpp"


namespace shape {
    
    bool Circle::init(){
        
        return true;
    }
    void Circle::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
        DrawPrimitives::drawCircle(Point(0,0), 50, M_PI*2, 50, true);
    }
}
