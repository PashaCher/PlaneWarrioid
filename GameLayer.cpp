#include "GameLayer.h"
#include "Player.h"

USING_NS_CC;

Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_player = Player::create();
	addChild(_player, 1);

	xScroll = 0.0f;
	speed = -60.0f;

	_bg = Sprite::create("bg.jpg");
	addChild(_bg, 0);
	Texture2D::TexParams texRepeat = { GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE, GL_REPEAT }; // нужно для того чтобы нормально скроллился фон
	_bg->getTexture()->setTexParameters(texRepeat);
	setRotation3D(Vec3(-30.0, 0.0f, 0.0f));
	_bg->setScale(1.6);
	_bg->setPosition(0.0f, 400.0f);
	_bg->setGlobalZOrder(-1);

	this->scheduleUpdate();
	return true;
}

void GameLayer::update(float dt)
{
	xScroll += speed*dt;
	_bg->setTextureRect(Rect(0, ((int)xScroll) % 2048, 512, 1200));
}