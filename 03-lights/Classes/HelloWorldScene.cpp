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
    auto sprite1 = Sprite3D::create("models/orc_jump.c3t");
    this->addChild(sprite1);
    sprite1->setScale(10);
    sprite1->setNormalizedPosition(Vec2(0.33,0.4));
    sprite1->setRotation3D(Vec3(0,180,0));

    auto sprite2 = Sprite3D::create("models/orc_jump.c3t");
    this->addChild(sprite2);
    sprite2->setScale(10);
    sprite2->setNormalizedPosition(Vec2(0.66,0.4));
    sprite2->setRotation3D(Vec3(0,180,0));


    auto s = Director::getInstance()->getWinSize();


//    auto light1 = PointLight::create(Vec3(s.width * 0.2f, s.height * 0.8f, 100.0f), Color3B(200, 200, 200), 10000.0f);
//    addChild(light1);

//    light1->setColor(Color3B::RED);
//    light1->setColor(Color3B::BLUE);
//    light1->setColor(Color3B::GREEN);

//    auto tintto1 = TintTo::create(4, Color3B::RED);
//    auto tintto2 = TintTo::create(4, Color3B::BLUE);
//    auto tintto3 = TintTo::create(4, Color3B::GREEN);
//    auto tintto4 = TintTo::create(4, Color3B::WHITE);
//    auto seq = Sequence::create(tintto1,tintto2, tintto3, tintto4, nullptr);
//    light1->runAction(RepeatForever::create(seq));


//    auto light2 = AmbientLight::create(Color3B(100, 100, 100));
//    addChild(light2);

//    auto directionalLight = DirectionLight::create(Vec3(-1.0f, -1.0f, 0.0f), Color3B(200, 200, 200));
//    addChild(directionalLight);

//    auto spotLight = SpotLight::create(Vec3(1, 0, 0), Vec3(s.width * 0.2f, s.height * 0.8f, 0), Color3B::WHITE, 0.2, 5.5, 10000.0f);
//    addChild(spotLight);

    return true;
}
