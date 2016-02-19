#ifndef __BULLETS_SCENE_H__
#define __BULLETS_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Bullets : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Bullets);
	//void update(float dt);
private:
	Node *_ModelBulletsLeft;
	Node *_ModelBulletsRight;
};

#endif