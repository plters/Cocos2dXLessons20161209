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
    
    screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    initWorld();
    addBird();
    addBarContainer();
    addGround();
    setTouchEnabled(true);
   
    scheduleOnce(schedule_selector(HelloWorld::startGame), 3);
    
    return true;
}


void HelloWorld::update(float dt){
    world->Step(dt, 8, 3);
    Sprite *s;
    for(b2Body *b = world->GetBodyList();b!=NULL;b=b->GetNext()){
        if(b->GetPosition().x<-3){
            
            s = (Sprite*)b->GetUserData();
            if(s!=NULL){
                s->removeFromParent();
                
                CCLOG("Remove");
            }
            
            world->DestroyBody(b);
            
            
        }
    }
    
}

void HelloWorld::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event){
    bird->getB2Body()->SetLinearVelocity(b2Vec2(0,5));
    
}
void HelloWorld::initWorld(){
    world = new b2World(b2Vec2(0, -7));
    world->SetContactListener(this);
    
}

void HelloWorld::BeginContact(b2Contact* contact){
    if(contact->GetFixtureA()->GetBody()->GetUserData()==bird ||
       contact->GetFixtureB()->GetBody()->GetUserData()==bird){
        stopGame();
        MessageBox("游戏失败", "游戏失败");
    }
}

void HelloWorld::startGame(float dt){
    scheduleUpdate();
    schedule(schedule_selector(HelloWorld::addBar), 1);
}
void HelloWorld::stopGame(){
    unscheduleUpdate();
    unschedule(schedule_selector(HelloWorld::addBar));
}

void HelloWorld::addBar(float dt){
    
    float offset = -rand()%5;
    
    //up bar
    BarSprite * down_bar = BarSprite::create("down_bar.png");
    Size down_bar_size = down_bar->getContentSize();
    b2BodyDef down_bar_body_def;
    down_bar_body_def.type = b2_kinematicBody;
    
   
    down_bar_body_def.position = b2Vec2(screenSize.width/RATIO+4,down_bar_size.height/2/RATIO+offset-1);
    down_bar_body_def.linearVelocity=b2Vec2(-5,0);
    b2Body * down_bar_body = world->CreateBody(&down_bar_body_def);
    
    
    b2PolygonShape down_bar_shape;
    down_bar_shape.SetAsBox(down_bar_size.width/2/RATIO, down_bar_size.height/2/RATIO);

    b2FixtureDef down_bar_fixture_def;
    down_bar_fixture_def.shape = &down_bar_shape;
    down_bar_body->CreateFixture(&down_bar_fixture_def);
    down_bar_body->SetUserData(down_bar);

    down_bar->setB2Body(down_bar_body);
    down_bar->setPTMRatio(RATIO);
    
    barContainer->addChild(down_bar);
    
    //up bar
    BarSprite * up_bar = BarSprite::create("up_bar.png");
    Size up_bar_size = up_bar->getContentSize();
    b2BodyDef up_bar_body_def;
    up_bar_body_def.type = b2_kinematicBody;
    
    
    up_bar_body_def.position = b2Vec2(screenSize.width/RATIO+4,down_bar_size.height/RATIO+offset+3.5+up_bar_size.height/2/RATIO);
    up_bar_body_def.linearVelocity=b2Vec2(-5,0);
    b2Body * up_bar_body = world->CreateBody(&up_bar_body_def);
    up_bar_body->SetUserData(up_bar);
    
    b2PolygonShape up_bar_shape;
    up_bar_shape.SetAsBox(up_bar_size.width/2/RATIO, up_bar_size.height/2/RATIO);
    
    b2FixtureDef up_bar_fixture_def;
    up_bar_fixture_def.shape = &up_bar_shape;
    up_bar_body->CreateFixture(&up_bar_fixture_def);

    up_bar->setB2Body(up_bar_body);
    up_bar->setPTMRatio(RATIO);
    
    barContainer->addChild(up_bar);
    
}


void HelloWorld::addGround(){
    
    GroundSprite *ground = GroundSprite::create("ground.png");
    
    Size size = ground->getContentSize();
    b2BodyDef bDef;
    bDef.type =  b2_staticBody;
    bDef.position = b2Vec2(size.width/2/RATIO,size.height/2/RATIO);
    b2Body * groundBody = world->CreateBody(&bDef);
    
    b2PolygonShape groundShape;
    groundShape.SetAsBox(size.width/2/RATIO, size.height/2/RATIO);
    
    b2FixtureDef groundFixtureDef;
    groundFixtureDef.density = 1;
    groundFixtureDef.friction = 0.3;
    groundFixtureDef.shape = &groundShape;
    groundBody->CreateFixture(&groundFixtureDef);
    groundBody->SetUserData(ground);
    
    addChild(ground);
    
    ground->setB2Body(groundBody);
    ground->setPTMRatio(RATIO);
    
    
}

void HelloWorld::addBird(){
    bird = BirdSprite::create("bird.png");
    Size size = bird->getContentSize();
    
    b2BodyDef bodyDef;
    bodyDef.position.Set(screenSize.width/2/RATIO,screenSize.height/2/RATIO);
    bodyDef.type = b2_dynamicBody;
    

    b2PolygonShape birdShape;
    birdShape.SetAsBox(size.width/2/RATIO, size.height/2/RATIO);
    
    b2Body* birdBody =  world->CreateBody(&bodyDef);
    
    b2FixtureDef birdFixtureDef;
    birdFixtureDef.shape = &birdShape;
    birdFixtureDef.density = 0.5f;
    birdFixtureDef.friction =  0.1;
    birdBody->CreateFixture(&birdFixtureDef);
    birdBody->SetUserData(bird);
    
    addChild(bird);
    
    bird->setPTMRatio(RATIO);
    bird->setB2Body(birdBody);
    
}
void HelloWorld::addBarContainer(){
    
    barContainer = Sprite::create();
    addChild(barContainer);
}


