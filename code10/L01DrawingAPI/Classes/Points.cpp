//
//  Points.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "Points.hpp"

namespace shape {
    bool Points::init(){
        return true;
    }
    
    void Points::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
        
        
        for (int y=0; y<50; y++) {
            for (int x=0; x<50; x++) {
                DrawPrimitives::setDrawColor4B(rand()%256, rand()%256, rand()%256, 255);
                DrawPrimitives::drawPoint(Point(x,y));
            }
        }
    }
    
}
