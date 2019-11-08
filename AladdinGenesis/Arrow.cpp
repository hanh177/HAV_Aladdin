#include "Arrow.h"

Arrow::Arrow(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	LoadResources();
}

void Arrow::LoadResources()
{
	ifstream file;
	int id, left, top, right, bottom, n;
	CTexture *texture = CTexture::GetInstance();
	CSprites *sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texArrow = texture->Get(Type::Map_Object);
	
	LPANIMATION ani;
	sprites->Add(10001,982,381,1031,416, texArrow);

	ani = new CAnimation(120);
	ani->Add(10001);
	animations->Add(100, ani);
	AddAnimation(100);//0

	//2
	file.open("Resources/Object/Arrow.txt");
	file >> n;//18
	ani = new CAnimation(25);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(id, left, top, right, bottom, texArrow);
		ani->Add(id);

	}
	animations->Add(200, ani);
	AddAnimation(200);//1
}

void Arrow::Render()
{
	int ani_ID;
	int loop;
	
	switch (mState)
	{
	case 1:
		if (animations[1]->GetCurrentFrame() == 12)
		{
			t = 0;
			mState = 0;
			isCounting = true;
		}

		ani_ID = 1;
		loop = 1;
		break;

	case 0:
		if (isCounting)
		{
			if(t==0)
				StartCountingTime(t);
		}
		if (t!=0)
		{
			if (GetTickCount() - t >= ARROW_IDLE)
				isCounting = false;
		}
		ani_ID = 0;
		loop = 0;
		break;
	}
	animations[ani_ID]->Render(this->x + 24.5, this->y + 17.5, loop, this->nx, Camera::GetInstance()->GetTranform());

	if (DISPLAY_BOX == 1)
	{
		RenderBoundingBox(this->width / 2, this->height / 2);
	}
}

void Arrow::Update(DWORD dt)
{
	float AlaX, AlaY;
	Aladin::GetInstance()->GetPosition(AlaX, AlaY);
	if (abs(AlaX - this->x) <= ARROW_ACTIVATE)
	{
		if (!isCounting)
			mState = 1;
		else
			mState = 0;
	}
	else
		mState = 0;


}

void Arrow::StartCountingTime(DWORD & t)
{
	t = GetTickCount();
}

void Arrow::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (mState!=0)
	{
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	else
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
Arrow::~Arrow()
{

}
