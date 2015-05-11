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

bool HelloWorld::init()
{
    if (!Layer::init())
        return false;
    
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("spritesheet.plist");

    Vector<SpriteFrame*> animFrames;
    char str[100];
    for(int i = 1; i <= 16; i++)
    {
        sprintf(str, "capguy/%04d.png", i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    
    Animation *animation = Animation::createWithSpriteFrames(animFrames, 1.0f/15);
    sprite->runAction(RepeatForever::create(Animate::create(animation)));
    sprite->setPosition(Director::getInstance()->getWinSize() / 2);
    
    addChild(sprite);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
