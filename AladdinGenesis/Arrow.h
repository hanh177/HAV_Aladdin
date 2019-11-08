#pragma once
#include "GameObject.h"
#include "Aladin.h"
#include"Texture.h"
#include"Sprite.h"
#include "define.h"
#include"Camera.h"
#include <fstream>

using namespace std;




#define ARROW_ACTIVATE 128
#define ARROW_IDLE 3200

class Arrow : public GameObject
{

	int mState;
	DWORD t=0;
	bool isCounting;
	int width, height;
public:
	Arrow(float x, float y,int width,int height);
	void LoadResources();
	void Render();
	void Update(DWORD dt);
	void StartCountingTime(DWORD &t);
	void GetBoundingBox(float & left, float & top, float & right, float & bottom);
	~Arrow();
};
