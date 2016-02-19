#include "Bullets.h"

USING_NS_CC;

Scene* Bullets::createScene()
{
	auto scene = Scene::create();
	auto layer = Bullets::create();
	scene->addChild(layer);
	return scene;
}

bool Bullets::init()
{
	if (!Layer::init())
	{
		return false;
	}
	_ModelBulletsLeft = Sprite::create("bullet_player.png");
	_ModelBulletsLeft->setScale(0.3);
	_ModelBulletsLeft->setPosition(117.0f, 100.0f);
	addChild(_ModelBulletsLeft, 1);

	_ModelBulletsRight = Sprite::create("bullet_player.png");
	_ModelBulletsRight->setScale(0.3);
	_ModelBulletsRight->setPosition(193.0f, 100.0f);
	addChild(_ModelBulletsRight, 2);

	return true;
}