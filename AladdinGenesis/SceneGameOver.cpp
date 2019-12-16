#include "SceneGameOver.h"
#include "Sound.h"
SceneGameOver::SceneGameOver()
{
	LoadResources();
}

SceneGameOver::~SceneGameOver()
{
}

void SceneGameOver::KeyState(BYTE * state)
{
}

void SceneGameOver::OnKeyDown(int KeyCode)
{
}

void SceneGameOver::OnKeyUp(int KeyCode)
{
}

void SceneGameOver::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	this->animations.push_back(ani);
}

void SceneGameOver::LoadResources()
{

	ifstream file;
	int id, left, top, right, bottom, n;
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(Type::ALADIN);
	LPDIRECT3DTEXTURE9 tex2 = texture->Get(Type::ALADIN2);

	// di chuyen bt
	file.open("Resources/Aladin/Win.txt");
	file >> n;
	LPANIMATION ani;
	ani = new CAnimation(100);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, tex);
		ani->Add(20000 + id);

	}
	animations->Add(100, ani);
	AddAnimation(100);//1
	file.close();

	ani = new CAnimation(100);
	sprites->Add(20020, 513, 2851, 745, 2986, tex2);
	ani->Add(20020);
	animations->Add(200, ani);
	AddAnimation(200);//1
}

void SceneGameOver::Update(DWORD dt)
{
	Sound::GetInstance()->Play(eSound::sound_LevelComplete);
	x += 1;
	if (this->x >= 180)
		isRender = true;
}

void SceneGameOver::Render()
{
	animations[0]->Render(x, y, 1, -1, D3DXVECTOR2(0, 0), 2);
	if (isRender)
		animations[1]->Render(260, 150, 0, 1, D3DXVECTOR2(0, 0), 2);
}
