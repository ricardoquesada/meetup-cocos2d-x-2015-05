#include "HelloWorldScene.h"

#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

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

    FileUtils::getInstance()->addSearchPath("particles/materials");
    FileUtils::getInstance()->addSearchPath("particles/scripts");
    FileUtils::getInstance()->addSearchPath("models");


    // Particles are created with Particle Universe editor

    auto particle = PUParticleSystem3D::create("blackHole.pu", "pu_mediapack_01.material");
//    auto particle = PUParticleSystem3D::create("explosionSystem.pu");
//    auto particle = PUParticleSystem3D::create("hypno.pu", "pu_mediapack_01.material");


    this->addChild(particle);
    particle->setNormalizedPosition(Vec2(0.5,0.5));
    particle->setScale(20);
    particle->startParticleSystem();

    return true;
}
