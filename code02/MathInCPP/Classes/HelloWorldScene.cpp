#include "HelloWorldScene.h"

USING_NS_CC;

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
void callback(DrawNode *dot,DrawNode *rect){
    
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
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    /*
    //正方形
    auto rect = DrawNode::create();
    
    Vec2 vec2s[] = {Vec2(0,0),Vec2(200,0),Vec2(200,200),Vec2(0,200)};
    Vec2 *edges = vec2s;
    
    rect->drawPolygon(edges, 4, Color4F(0,0,0,1.0), 1.0, Color4F(0,1.0,0,1.0));
    rect->setPosition(visibleSize.width/2,visibleSize.height/2);
    //rect->drawTriangle(Vec2(0,0), Vec2(100,0),  Vec2(50,80),  Color4F(1.0,0,0,1.0));
   
    
    //点
    auto dot=DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    
    addChild(rect);
    rect->addChild(dot);
    dot->setPosition(Vec2(10,10));//本地空间
    
    rect->setContentSize(Size(300,300));
    rect->setAnchorPoint(Vec2(0.5,0.5));
    
    auto scheduler =  Director::getInstance()->getScheduler();
    scheduler->schedule([dot,rect](float f){
        rect->setRotation(rect->getRotation()+1);
        auto p = dot->convertToWorldSpace(Vec2(0,0));
        CCLOG("%f,%f",p.x,p.y);
    }, rect, 0.01, false, "Test");
    */
    
    /*
    _angle = 0;
    auto dot=DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    
     
     
     
    */

    _direction.set(random(),random());
    _direction.normalize(); //标准化
    
    auto dot=DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    
    
    auto scheduler =  Director::getInstance()->getScheduler();
    scheduler->schedule([dot,this,visibleSize](float f){
       auto p = dot->getPosition();
       if(p.x<0||p.x>visibleSize.width){
            _direction.x*=-1;
        }else if(p.y<0||p.y>visibleSize.height)
        {
            _direction.y*=-1;
        }
       dot->setPosition(p+_direction*10);
        
    }, dot  , 0.001, false, "Test");
    
    
    
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
