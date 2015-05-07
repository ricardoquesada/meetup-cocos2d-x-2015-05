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

    auto sprite = Sprite3D::create("models/orc_jump.c3t");
    this->addChild(sprite);
    sprite->setScale(0.8f);
    sprite->setRotation3D(Vec3(0,180,0));
    sprite->setPosition3D(Vec3(0,0,10));

    auto plane = Sprite3D::create("models/plane.c3t");
    this->addChild(plane);
    plane->setRotation3D(Vec3(90,0,0));

    //
    // A billboard is an object that always face the camera
    //
//    auto bill = BillBoard::create("images/grossini.png");
//    bill->setScale(0.3);
//    bill->setPosition3D(Vec3(8,1,15));
//    this->addChild(bill);


    //
    // Billboard could have anything as a child, including Sprites
    // And you can create empty Billboards if you want
    //

    auto bill = BillBoard::create();
    bill->setPosition3D(Vec3(8,1,15));
    this->addChild(bill);

//    auto sp = Sprite::create("images/SpookyPeas.png");
//    sp->setScale(0.1);
//    bill->addChild(sp);

    //
    // ... including Labels
    //

//    auto lbl = Label::createWithSystemFont("Hello", "Helvetica", 18);
//    lbl->setColor(Color3B::BLACK);
//    lbl->setPosition(0,1);
//    bill->addChild(lbl);


    //
    // ... and 2D particles
    //

    auto particle = ParticleFlower::create();
    particle->setTexture(Director::getInstance()->getTextureCache()->addImage("images/stars.png"));
    particle->setPosition(0,10);
    particle->setScale(0.2);
    bill->addChild(particle);

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


    camera->lookAt(Vec3(20,0,0));


    auto moveBy = MoveBy::create(5, Vec3(50,0,0));
    auto moveBack = moveBy->reverse();
    camera->runAction( RepeatForever::create(Sequence::create(moveBy, moveBack, nullptr)));

    scheduleUpdate();
}

void HelloWorld::update(float dt)
{
    auto camera = Camera::getDefaultCamera();
    camera->lookAt(Vec3(0,0,10));
}
