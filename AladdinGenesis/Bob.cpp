#include "Bob.h"

Bob::Bob(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	LoadResources();
}

void Bob::LoadResources()
{

	ifstream file, file2;
	int id, left, top, right, bottom, n;
	CTexture *texture = CTexture::GetInstance();
	CSprites *sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texBob= texture->Get(Type::Map_Object);

	LPANIMATION ani;
	
	file.open("Resources/Object/Bob.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(10000+id, left, top, right, bottom, texBob);
		ani->Add(10000+id);

	}
	animations->Add(100, ani);
	AddAnimation(100);//0


	file2.open("Resources/Object/Bob2.txt");
	file2 >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file2 >> id >> left >> top >> right >> bottom;
		sprites->Add(10000 + id, left, top, right, bottom, texBob);
		ani->Add(10000 + id);

	}
	animations->Add(200, ani);
	AddAnimation(200);//1
}

void Bob::Render()
{
	switch (mState)
	{
	case 0:
		
		if (animations[0]->GetCurrentFrame() == 13)
			mState = 1;
		if (animations[0]->GetCurrentFrame() == 13 || animations[0]->GetCurrentFrame() == 12)
			isCollis = 1;
		else
			isCollis = 0;
		animations[0]->Render(this->x + 16, this->y + 33, 1, this->nx, Camera::GetInstance()->GetTranform());
		break;
	case 1:
		if (animations[1]->GetCurrentFrame() ==13)
			mState = 0;
		if (animations[1]->GetCurrentFrame() == 14 || animations[1]->GetCurrentFrame() == 0)
			isCollis = 1;
		else
			isCollis = 0;
			
		animations[1]->Render(this->x + 16.5, this->y + 33.5, 1, this->nx, Camera::GetInstance()->GetTranform());
		break;
	}
	if (DISPLAY_BOX == 1)
	{
		RenderBoundingBox(this->width / 2, this->height / 2);
	}
	
}

void Bob::Update(DWORD dt)
{
}

void Bob::StartCountingTime(DWORD & t)
{
}

void Bob::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	switch (isCollis)
	{
	case 0:
		left = top = right = bottom = 0;
		break;
	case 1:
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
}

Bob::~Bob()
{
}
