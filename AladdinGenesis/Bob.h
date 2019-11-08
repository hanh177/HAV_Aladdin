#pragma once
#include "GameObject.h"
#include "Aladin.h"
#include"Texture.h"
#include"Sprite.h"
#include "define.h"
#include"Camera.h"
#include <fstream>

using namespace std;





class Bob: public GameObject
{

	int mState = 0;
	DWORD t = 0;
	int isCollis;
	int width, height;
public:
	Bob(float x, float y, int width, int height);
	void LoadResources();
	void Render();
	void Update(DWORD dt);
	void StartCountingTime(DWORD &t);
	void GetBoundingBox(float & left, float & top, float & right, float & bottom);
	~Bob();
};

