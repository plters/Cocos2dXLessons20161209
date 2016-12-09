#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "BirdSprite.hpp"
#include "GroundSprite.hpp"
#include "BarSprite.hpp"
#define RATIO 170.0f


class HelloWorld : public cocos2d::Layer,public b2ContactListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    virtual void update(float dt);
   
    CREATE_FUNC(HelloWorld);
    
     virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
     virtual void BeginContact(b2Contact* contact);
private:
    Size screenSize;
    b2World* world;
    BirdSprite* bird;
    Sprite * barContainer;
    
    
    void initWorld();
    void addGround();
    void addBird();
    void addBar(float dt);
    void addBarContainer();
    
    void startGame(float dt);
    void stopGame();
    
};

#endif // __HELLOWORLD_SCENE_H__
