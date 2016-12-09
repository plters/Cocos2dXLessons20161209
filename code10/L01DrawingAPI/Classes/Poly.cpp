//
//  Poly.cpp
//  L01DrawingAPI
//
//  Created by apple on 2016/12/5.
//
//

#include "Poly.hpp"


namespace shape {
    
    bool Poly::init(){
        ps[0] = Point(0,0);
        ps[1] = Point(100,0);
        ps[2] = Point(100,100);
        return true;
    }
    void Poly::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
        
        DrawPrimitives::drawPoly(ps, 3, true);
    }
}
