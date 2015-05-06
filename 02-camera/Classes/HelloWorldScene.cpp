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

    // Setup the sprite
    auto sprite = Sprite3D::create("models/orc_jump.c3t");
    this->addChild(sprite);
    sprite->setScale(0.2f);
    sprite->setRotation3D(Vec3(0,180,0));
    sprite->setPosition3D(Vec3(0,0,10));

    //create a plane
    auto plane = Sprite3D::create("models/plane.c3t");
    this->addChild(plane);
    plane->setRotation3D(Vec3(90,0,0));

    return true;
}

void HelloWorld::onEnter()
{
    Layer::onEnter();

    // Setup the Camera
//    auto camera = getScene()->getDefaultCamera();
    auto camera = Camera::getDefaultCamera();
    camera->setPosition3D(Vec3(0,20,25));
    camera->setRotation3D(Vec3(-60,0,0));


//    camera->lookAt(Vec3(20,0,0));


//    auto moveBy = MoveBy::create(5, Vec3(50,0,0));
//    auto moveBack = moveBy->reverse();
//    camera->runAction(Sequence::create(moveBy, moveBack, nullptr));

//    scheduleUpdate();
}

void HelloWorld::update(float dt)
{
//    auto camera = Camera::getDefaultCamera();
//    camera->lookAt(Vec3(0,0,10));
}
