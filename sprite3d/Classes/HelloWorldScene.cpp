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

    //
    // "c3b": means "cocos 3d binary" format:
    //        optimized for production
    // "c3t": means "cocos 3d text" format
    //        optimized for development (version control friendly)
    // "obj": is the Wavefront file format
    //        c3b / c3t are better formats
    //
    // "tools/fbx_conv" converts FBX file format to c3b/c3t
    //
    auto sprite = Sprite3D::create("models/orc.c3b");
    this->addChild(sprite);

    sprite->setNormalizedPosition(Vec2(0.5, 0.5));

    sprite->setScale(10);

    // Actions on Sprite3D
    sprite->setRotation3D(Vec3(0,180,0));

    return true;
}
