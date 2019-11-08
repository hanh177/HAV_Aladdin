#include "MovingBrick.h"

MovingBrick::MovingBrick(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->type = Type::MOVINGBRICK;
	LoadResources();
}

void MovingBrick::LoadResources()
{

	ifstream file, file2;
	int id, left, top, right, bottom, n;
	CTexture *texture = CTexture::GetInstance();
	CSprites *sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texMBrick = texture->Get(Type::Map_Object);

	LPANIMATION ani;


	

	file.open("Resources/Object/MovingBrick.txt");
	file >> n;
	ani = new CAnimation(175);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(10000 + id, left, top, right, bottom, texMBrick);
		ani->Add(10000 + id);

	}
	animations->Add(100, ani);
	AddAnimation(100);//0

	file2.open("Resources/Object/MovingBrick2.txt");
	file2 >> n;
	ani = new CAnimation(175);
	for (int i = 0; i < n; i++)
	{
		file2 >> id >> left >> top >> right >> bottom;
		sprites->Add(10000 + id, left, top, right, bottom, texMBrick);
		ani->Add(10000 + id);

	}
	animations->Add(200, ani);
	AddAnimation(200);//1


	//thut vao trong
	sprites->Add(10054, 996, 618, 1038, 642, texMBrick);
	ani = new CAnimation(150);
	ani->Add(10054);
	animations->Add(300, ani);
	AddAnimation(300);//2

	//thut ra ngoai
	sprites->Add(10055, 1276, 618, 1318, 642, texMBrick);
	ani = new CAnimation(150);
	ani->Add(10055);
	animations->Add(400, ani);
	AddAnimation(400);//3
}

void MovingBrick::Render()
{
	int ani_ID;
	int loop;
	switch (mState)
	{
	case 0://di ra
		ani_ID = 0;
		loop = 1;
		break;

	case 1://di vao
		ani_ID = 1;
		loop = 1;
		break;

	case 2://dung yen thut vao trong
		ani_ID = 2;
		loop = 0;
		break;
	case 3:
		ani_ID = 3;
		loop = 0;
		break;
	}

	animations[ani_ID]->Render(this->x + 21, this->y + 12, loop, this->nx, Camera::GetInstance()->GetTranform());
	if (DISPLAY_BOX == 0)
	{
		RenderBoundingBox(this->width / 2, this->height / 2);
	}
}

void MovingBrick::Update(DWORD dt)
{
	switch (mState)
	{
	case 0://di ra
		if (animations[0]->GetCurrentFrame() == 4)
		{
			isCounting = true;
			mState = 3;
		}
		break;
	case 1://di vao
		if (animations[1]->GetCurrentFrame() == 4)
		{
			isCounting = true;
			mState = 2;
		}
		break;


	case 2://dung yen thut vao trong
		if (isCounting == true)
		{
			isCounting = false;
			t = 0;
			StartCountingTime(t);
		}
		if (t != 0)
			if (GetTickCount() - t >= MOVINGBRICK_IDLE_TIME)
				mState = 0;
		break;

	case 3:
		if (isCounting == true)
		{
			isCounting = false;
			t = 0;
			StartCountingTime(t);
		}
		if (t != 0)
			if (GetTickCount() - t >= MOVINGBRICK_IDLE_TIME)
				mState = 1;
		break;
	}
}

void MovingBrick::StartCountingTime(DWORD & t)
{
	t = GetTickCount();
}

void MovingBrick::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (mState == 3)
	{
		left = x;
		top = y;;
		right = left + width/2+10;
		bottom = top + height;
	}
	else
		left = top = right = bottom = 0;
}

MovingBrick::~MovingBrick()
{
}
