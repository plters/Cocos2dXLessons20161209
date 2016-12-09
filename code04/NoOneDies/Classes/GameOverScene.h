//
//  GameOverScene.h
//  NoOneDies
//
//  Created by apple on 2016/12/6.
//
//

#ifndef GameOverScene_h
#define GameOverScene_h

#include <stdio.h>
#include <cocos2d.h>

using namespace cocos2d;

class GameOver:public LayerColor {
private:
    Size visibleSize;
public:
    virtual bool init(){
        LayerColor::initWithColor(Color4B::WHITE);
        
        
        visibleSize = Director::getInstance()->getVisibleSize();
        
        auto label = Label::create();
        label->setString("GameOver");
        label->setSystemFontSize(40);
        label->setColor(Color3B::BLACK);
        addChild(label);
        label->setPosition(visibleSize.width/2,visibleSize.height/2);
        
        return true;
    };
    CREATE_FUNC(GameOver);
    
    static Scene* createScene(){
        auto s = Scene::create();
        auto l = GameOver::create();
        s->addChild(l);
        return s;
    }
};


#endif /* GameOverScene_h */
