#ifndef __GAMELAYER_SCENE_H__
#define __GAMELAYER_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class Player;

class GameLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLayer);
	void update(float dt);
private:
	Sprite *_bg;
	float xScroll;
	float speed;

	Player *_player;
};

#endif