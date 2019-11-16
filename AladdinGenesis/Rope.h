#pragma once
#include "GameObject.h"


class Rope :public GameObject
{
private:
	float mB_Start, mB_End;

	int mWidth, mHeight;

public:
	Rope(float X, float Y, int W, int H);

	void getStartEnd(float &xStart, float &xEnd);
	void Render();

	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	~Rope();

};


