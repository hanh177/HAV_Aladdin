#include "Rope.h"




Rope::Rope(float X, float Y, int W, int H)
{
	this->x = X;
	this->y = Y;

	mWidth = W;
	mHeight = H;

	this->type = Type::ROPE;

}

void Rope::getStartEnd(float & xStart, float & xEnd)
{
	xStart = this->x;
	xEnd = this->x + mWidth;

}

void Rope::Render()
{
	if (DISPLAY_BOX == 0)
	{
		RenderBoundingBox(this->mWidth / 2, this->mHeight / 2);
	}
}

void Rope::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = left + mWidth;
	bottom = top + mHeight;
}

Rope::~Rope()
{
}
