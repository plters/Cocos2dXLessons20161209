//
//  ImageScene.hpp
//  L01StartScene
//
//  Created by apple on 2016/12/1.
//
//

#ifndef ImageScene_hpp
#define ImageScene_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class ImageScene:public Layer {
    
    
public:
    virtual bool init();
    
    static Scene* createScene();
    CREATE_FUNC(ImageScene);
};


#endif /* ImageScene_hpp */
