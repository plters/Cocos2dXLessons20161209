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
    
    
    auto listener = EventListenerKeyboard::create();
    
//    listener->onKeyPressed = [](EventKeyboard::KeyCode code,Event *e){
//        log("%d",code);
//        
//        switch (code) {
//            case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
//                log("Space key pressed");
//                break;
//                
//            default:
//                break;
//        }
//        
//    };
    
    listener->onKeyReleased = [](EventKeyboard::KeyCode code,Event *e){
      
        switch (code) {
            case EventKeyboard::KeyCode::KEY_BACK:
                Director::getInstance()->end();
                break;
                
            default:
                break;
        }
        
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
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
