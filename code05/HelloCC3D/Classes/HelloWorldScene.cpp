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

    
//    auto s = Sprite3D::create("tortoise.c3b", "tortoise1.png");
    auto s = Sprite3D::create("myobj.c3b");
    s->setScale(10);
    s->setPosition(visibleSize/2);
    addChild(s);
    
    s->runAction(RepeatForever::create(RotateBy::create(1, Vec3(45, 45, 0))));
    
//    auto anim = Animate3D::create(Animation3D::create("tortoise.c3b"),0,1.93);
//    s->runAction(RepeatForever::create(anim));
//    
    auto l = DirectionLight::create(Vec3(0,0,-1000), Color3B(255,255,255));
    
    addChild(l);
    
    
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
