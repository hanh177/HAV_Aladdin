#pragma once
#include "GameObject.h"
#include "Aladin.h"
#include"Texture.h"
#include"Sprite.h"
#include "define.h"
#include"Camera.h"
#include <fstream>

using namespace std;


#define MOVINGBRICK_IDLE_TIME 3000
#define MOVINGBRICK_IDLE_TIME 3000


class MovingBrick : public GameObject
{

	int mState = 0;
	DWORD t = 0;
	int isCollis, isCounting;
	int width, height;
	bool isStart;
	
public:
	MovingBrick(float x, float y, int width, int height);
	void LoadResources();
	void Render();
	void Update(DWORD dt);
	void StartCountingTime(DWORD &t);
	void GetBoundingBox(float & left, float & top, float & right, float & bottom);
	~MovingBrick();
};


