#include "HelloWorldScene.h"
#include "Rect.hpp"
#include "SRect.hpp"
#include "Circle.hpp"
#include "SCircle.hpp"
#include "Poly.hpp"
#include "SPoly.hpp"
#include "Line.hpp"
#include "Points.hpp"
USING_NS_CC;


class Shape:public Node {
    
    
public:
 
    virtual bool init(){
        return true;
    }
    
    CREATE_FUNC(Shape);
    
};


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
    auto r = shape::Rect::create();
    r->setPosition(50,50);
    addChild(r);
    
    auto sr = shape::SRect::create();
    sr->setPosition(200,50);
    addChild(sr);
    
    
    auto c = shape::Circle::create();
    c->setPosition(400,100);
    addChild(c);
    
    auto sc = shape::SCircle::create();
    sc->setPosition(550, 100);
    addChild(sc);
    
    
    auto p = shape::Poly::create();
    p->setPosition(Point(100,300));
    addChild(p);
    
    auto sp = shape::SPoly::create();
    sp->setPosition(Point(300,300));
    addChild(sp);
    
    auto l = shape::Line::create();
    l->setPosition(450,300);
    addChild(l);
    
    auto ps = shape::Points::create();
    ps->setPosition(600,300);
    addChild(ps);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
