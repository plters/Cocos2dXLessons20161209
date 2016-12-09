//
//  SPoly.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "SPoly.hpp"


namespace shape {
    
    bool SPoly::init(){
        points[0] = Point(0,0);
        points[1] = Point(100,0);
        points[2] = Point(100,100);
        points[3] = Point(50,50);
        points[4] = Point(0,100);
        
        
        return true;
    }
    
    void SPoly::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
        DrawPrimitives::drawSolidPoly(points, 5, Color4F(1,1,0,1));
    }
}
