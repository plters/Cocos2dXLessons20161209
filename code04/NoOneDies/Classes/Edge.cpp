//
//  Edge.cpp
//  NoOneDies
//
//  Created by apple on 2016/12/2.
//
//

#include "Edge.hpp"



bool Edge::init(){
    
    Node::init();
    
    Size visisbleSize = Director::getInstance()->getVisibleSize();
    setPhysicsBody(PhysicsBody::createEdgeBox(visisbleSize));
    setContentSize(visisbleSize);
    
    return true;
}
