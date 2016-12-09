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

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   
    
    schedule(schedule_selector(HelloWorld::addBall), 0.1f);
    scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt){
    
    Ball * b;
    for (auto it=balls.begin(); it!=balls.end(); it++) {
        b = *it;
        b->move();
        
        if(b->getPositionX()>visibleSize.width ||
           b->getPositionX()<0 ||
           b->getPositionY()>visibleSize.height ||
           b->getPositionY()<0){
            
            balls.eraseObject(b);
            removeChild(b);
            break;
        }
    }
    
}
void HelloWorld::addBall(float dt){
   
    auto b = Ball::create();
    addChild(b);
    
    
    b->setPosition(visibleSize/2);
    balls.pushBack(b);
    
    
    
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
