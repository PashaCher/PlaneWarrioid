#include "Player.h"
#include "Bullets.h"
#include "global.h"

USING_NS_CC;

Scene* Player::createScene()
{
	auto scene = Scene::create();
	auto layer = Player::create();
	scene->addChild(layer);
	return scene;
}

bool Player::init()
{
	if (!Layer::init())
	{
		return false;
	}
	_ModelPlayer = Sprite3D::create("player.c3b", "player.png");
	_ModelPlayer->setScale(6);
	_ModelPlayer->setPosition(157.0f, 100.0f);
	addChild(_ModelPlayer, 1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	schedule(schedule_selector(Player::shoot), 0.12);
	return true;
}

bool Player::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void Player::onTouchMoved(Touch *touch, Event *event)
{
	Vec2 prev = event->getCurrentTarget()->getPosition();
	Vec2 delta = touch->getDelta();
	Vec2 shiftPosition = delta + prev;

	setPosition(shiftPosition.getClampPoint(Vec2(PLAYER_LIMIT_LEFT, PLAYER_LIMIT_DOWN), Vec2(PLAYER_LIMIT_RIGHT, PLAYER_LIMIT_TOP)));
}

void Player::onTouchEnded(Touch *touch, Event *event)
{
}

void Player::shoot(float dt)
{
	auto bullet = Bullets::create();
	MoveBy *shoot = MoveBy::create(2, Vec2(0.0f, 1000.0f));
	bullet->runAction(shoot);
	addChild(bullet, 2);
}