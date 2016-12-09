#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CardSprite.h"
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
    //加入手势识别的事件
    virtual bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);
    //上下左右
    bool doLeft();
    bool doRight();
    bool doUp();
    bool doDown();
    //自动卡片生成
    void autoCreateCardNumber();
    //游戏是否还能进行下去
    void doCheckGameOver();
private:
    //点击的元素
    int firstX,firstY,endX,endY;
    //定义一个二维数组
    CardSprite * cardArr[4][4];
    
    //创建卡片
    void createCardSprite(cocos2d::Size size);
    
    //整体游戏分数
    int score;
    //显示分数的空控件
    cocos2d::Label* labelCardNumber;
    
};

#endif // __HELLOWORLD_SCENE_H__
