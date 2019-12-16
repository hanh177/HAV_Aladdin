#include"Camera.h"


Camera *Camera::_instance = NULL;

void Camera::SetTypeMap(Type type_Map)
{
	this->mType_Map = type_Map;
	switch (this->mType_Map)
	{
	case Map1:
		this->type = Map1;
		break;
	case MapBoss:
		this->type = MapBoss;
	}
}

Camera *Camera::GetInstance()
{

	if (_instance == NULL)
		_instance = new Camera(SCREEN_WIDTH,SCREEN_HEIGHT+40);
	return _instance;
}

Camera::Camera(int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;
	mPosition = D3DXVECTOR3(SCREEN_WIDTH/2,SCREEN_HEIGHT/2, 0);
}

Camera::~Camera()
{

}

int Camera::GetWidth()
{
	return mWidth;
}

int Camera::GetHeight()
{
	return mHeight;
}

RECT Camera::GetBound()
{
	RECT bound;

	bound.left = mPosition.x - mWidth / 2;
	bound.right = bound.left + mWidth;;
	bound.top = mPosition.y - mHeight / 2;
	bound.bottom = bound.top + mHeight;

	return bound;
}

D3DXVECTOR2 Camera::GetTranform()
{
	return D3DXVECTOR2(SCREEN_WIDTH / 2 - mPosition.x,SCREEN_HEIGHT / 2 - mPosition.y);
}


void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void Camera::SetPosition(D3DXVECTOR3 pos)
{
	pos.y = (int)pos.y;
	pos.x = (int)pos.x;

	if (pos.x <= (SCREEN_WIDTH / 2))
		pos.x = SCREEN_WIDTH / 2;
	if (this->type == Map1)
	{
		if (pos.x >= 2111)
			pos.x = 2111;
		if (pos.y > 1000)
			pos.y = 1038;
		if (pos.y <= 120)
			pos.y = 120;
	}
	else
	{
		if (pos.x >= 686)
			pos.x = 686;
	}
	mPosition = pos;

	
}

D3DXVECTOR3 Camera::GetPosition()
{
	return mPosition;
}

bool Camera::isContain(RECT r1, RECT r2)
{
	if (r1.left > r2.right || r1.right < r2.left || r1.top > r2.bottom || r1.bottom < r2.top)
	{
		return false;
	}
	return true;
}

