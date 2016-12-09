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

   
    auto map = TMXTiledMap::create("map.tmx");
    map->setContentSize(visibleSize);
    map->setScale(1);
    addChild(map);
    
    auto mapProperties = map->getProperties();
    auto str = mapProperties["type"].asString();
    CCLOG("map pro:%s",str.c_str());
    
    //获取图层属性
    auto sceneLayer = map->getLayer("scene");
    auto layerProperties = sceneLayer->getProperties();
    CCLOG("layer pro:%s",layerProperties["type"].asString().c_str());
    
    //获取图块属性
    auto tilePro = map->getPropertiesForGID(1).asValueMap();
    CCLOG("tile pro:%s",tilePro["type"].asString().c_str());
    
    //获取对象属性
    auto objectGroup = map->getObjectGroup("object");
    auto obj = objectGroup->getObject("player");
    CCLOG("tile pro:%s",obj["type"].asString().c_str());
    
    
    //修改指定区域的颜色
    auto colorObj = objectGroup->getObject("color");
    auto colorObjX = colorObj["x"].asInt()/32;
    auto colorObjY = colorObj["y"].asInt()/32;
    auto colorObjW = colorObj["width"].asInt()/32;
    auto colorObjH = colorObj["height"].asInt()/32;
    
    for (int x=colorObjX; x<colorObjX+colorObjW; x++) {
        for(int y=colorObjY;y<colorObjY+colorObjY;y++){
            auto sprite = sceneLayer->getTileAt(Vec2(x,map->getMapSize().height-y));
            sprite->setColor(Color3B(255,0,0));
        }
    }
    
    //家在小球
    auto player = Sprite::create("c.png");
    player->setPosition(obj["x"].asFloat(),obj["y"].asFloat());
    addChild(player);
    
    auto eventListener = EventListenerTouchOneByOne::create();
    
    eventListener->onTouchBegan=[map,sceneLayer,player](Touch* touch,Event* event){
        
        auto point = map->convertToNodeSpace(touch->getLocation());
        point.x = static_cast<int>(point.x/32);
        point.y = map->getMapSize().height-static_cast<int>(point.y/32)-1;
        
        
        auto t = sceneLayer->getTileAt(point);
//        t->setColor(Color3B(255,0,0));
        
        auto gid = sceneLayer->getTileGIDAt(point);
        auto p = map->getPropertiesForGID(gid).asValueMap();
        
        if(p["move"].isNull()!=true&&p["move"].asBool()==true) {
            
            player->setPosition(t->getPosition().x,t->getPosition().y);
        }
        
        
        
        return false;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, map);
    
    
    
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
