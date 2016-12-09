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

    /*
    auto icon=Sprite::create("CloseSelected.png");
    addChild(icon);
    
    icon->setPosition(visibleSize/2);
    auto size=icon->getContentSize();
    CCLOG("SIZE: %f %f",size.width,size.height);
    
    auto scheduler = Director::getInstance()->getScheduler();
    
    scheduler->schedule([icon,size](float f){
          CCLOG("SIZE: %f %f",size.width,size.height);
    }, this, 1, false, "test");
     */
    //icon->retain();
    /*
    Vector<Label*> vec;
    auto label1=Label::create();
    auto label2=Label::create();
    
    label1->setString("Label 1");
    label2->setString("Label 2");
    label1->setSystemFontSize(50);
    label2->setSystemFontSize(50);
    
    vec.pushBack(label1);
    vec.pushBack(label2);
    
    int i=0;
    for(auto label:vec){
        i++;
        label->setPosition(Vec2(visibleSize.width/2,i*200));
        addChild(label);
    }
    */
    //错误方法
    /*
    Vector<int> vec2;
    vec2.pushBack(1);
    vec2.pushBack(2);
     */
    /*
    Map<std::string,Label*> map;
    auto label1=Label::create();
    auto label2=Label::create();
    
    label1->setString("Label 1");
    label2->setString("Label 2");
    label1->setSystemFontSize(50);
    label2->setSystemFontSize(50);
    
    label1->setPosition(Vec2(visibleSize.width/2,200));
    label2->setPosition(Vec2(visibleSize.width/2,300));
    
    map.insert("label1",label1);
    map.insert("label2",label2);
    
    addChild(map.at("label2"));
     */
    
    Value value1=Value("abc");
    Value value2=Value(123);
    Value value3=Value(true);
    
    CCLOG("%s %d %s",value1.asString().c_str(),value2.asInt(),value3.asBool()==true?"True":"False");
    CCLOG("%s %s %s",value1.asString().c_str(),value2.asString().c_str(),value3.asString().c_str());
    
    Value value4=Value::Null;
    value4=value1;
    value4=value2;
    value4=value3;
    
    CCLOG("%s %s",value4.getType()==Value::Type::BOOLEAN?"True":"False",value4.asString().c_str());
    
    
    ValueVector vector;
    vector.push_back(Value("hello"));
    vector.push_back(value1);
    vector.push_back(value2);
    for(auto v:vector){
        CCLOG("Vector %s",v.asString().c_str());
    }
    
    ValueMap map;
    map["a"]=value2;
    map["b"]=value1;
    for(auto m:map){
        CCLOG("%s = %s",m.first.c_str(),m.second.asString().c_str());
    }
    
    
    
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
