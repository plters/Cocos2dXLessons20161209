//
//  ImageScene.cpp
//  L01StartScene
//
//  Created by apple on 2016/12/1.
//
//

#include "ImageScene.hpp"


Scene* ImageScene::createScene(){
    
    Scene* scene = Scene::create();
    ImageScene * layer = ImageScene::create();
    scene->addChild(layer);
    
    return scene;
}


bool ImageScene::init(){
    
    Size size = Director::getInstance()->getVisibleSize();
    Sprite *s = Sprite::create("HelloWorld.png");
    s->setPosition(size.width/2,size.height/2);
    addChild(s);
    
    
    return true;
}
