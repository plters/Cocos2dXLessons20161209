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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::create();
    label->setString("Hello Cocos2d-x");
    addChild(label);
    label->setPosition(visibleSize/2);
    
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchBeganHandler, this);
    
//    listener->onTouchBegan = [](cocos2d::Touch *,cocos2d::Event* ){
//        
//        log("clicked");
//        return false;
//    };
    
    
 //Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto listener = EventListenerCustom::create("MyEvent",[](EventCustom* e){
//        log("event executed");
        log("event executed, and data is %s",(char*)(e->getUserData()));
    });
    
    
    Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithFixedPriority(listener, 1);
    
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("MyEvent");
    
    EventCustom e("MyEvent");
    
    e.setUserData((void*)"Hello Cocos2d-x");
    
    Director::getInstance()->getEventDispatcher()->dispatchEvent(&e);
    
   
    
    return true;
}

bool HelloWorld::touchBeganHandler(cocos2d::Touch *, cocos2d::Event *){
    
    log("touch began");
    
    return false;
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
