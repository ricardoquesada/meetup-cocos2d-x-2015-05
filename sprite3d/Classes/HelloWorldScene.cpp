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
    if ( !Layer::init() )
    {
        return false;
    }

    auto sprite = Sprite3D::create("models/orc.c3b");
    this->addChild(sprite);

    sprite->setNormalizedPosition(Vec2(0.5, 0.5));

    sprite->setScale(10);
    sprite->setRotation3D(Vec3(0,180,0));

    return true;
}
