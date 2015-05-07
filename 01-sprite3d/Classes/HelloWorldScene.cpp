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
    auto sprite = Sprite3D::create("models/orc_jump.c3t");
    this->addChild(sprite);

    //
    // Setting basic properties, like a regular Node
    // In fact, Sprite3D is a subclass of Node
    //
    sprite->setNormalizedPosition(Vec2(0.5, 0.25));

    sprite->setScale(10);

    sprite->setRotation3D(Vec3(0,180,0));

    //
    // Actions on Sprite3D
    //
    auto rotateby = RotateBy::create(5, Vec3(0,360,0));
    sprite->runAction(rotateby);


    //
    // Animation
    //
    // c3b/c3t files also contain animation information
    // we extract the information from that file, and just play the animation like any regular action
    //
//    auto animation = Animation3D::create("models/orc_jump.c3t");
//    auto animate = Animate3D::create(animation);
//    sprite->runAction(animate);

    //
    // Like any action, it can be combined with other actions
    //
//    auto seq = Sequence::create(rotateby, animate, nullptr);
//    sprite->runAction(seq);

//    auto ease = EaseSineIn::create(animate);
//    sprite->runAction(ease);


    //
    // Attachment
    // You can attach other objects into objects
    //
//    auto sp = Sprite3D::create("models/axe.c3b");
//    sprite->getAttachNode("Bip001 R Hand")->addChild(sp);

    return true;
}
