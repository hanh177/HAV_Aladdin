#include "SceneIntro.h"
#include"Sound.h"


SceneIntro::SceneIntro()
{
	this->State = SCENEINTRO;//ID cua introScene

	LoadResources();
}


SceneIntro::~SceneIntro()
{
}

void SceneIntro::KeyState(BYTE * state)
{
}

void SceneIntro::OnKeyDown(int KeyCode)
{
	if (animations[0]->GetCurrentFrame() == 17)
		this->isPressedKey = true;
}

void SceneIntro::OnKeyUp(int KeyCode)
{
}

void SceneIntro::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	this->animations.push_back(ani);
}

void SceneIntro::LoadResources()
{
	ifstream file;
	int id, left, top, right, bottom, n;
	CTexture * texture = CTexture::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(Type::GAME_INTRO);
	LPDIRECT3DTEXTURE9 tex2 = texture->Get(Type::ALADIN2);
	LPDIRECT3DTEXTURE9 tex3 = texture->Get(Type::BIRDINTRO);

	// di chuyen bt
	file.open("Resources/Object/GameIntro.txt");
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
	ani->Add(20018);
	animations->Add(200, ani);
	AddAnimation(200);//1

	ani = new CAnimation(100);
	sprites->Add(20020, 9, 12, 252, 102, tex2);
	ani->Add(20020);
	animations->Add(300, ani);
	AddAnimation(300);//1

	ani = new CAnimation(100);
	sprites->Add(20021, 139,78,220,148, tex3);
	ani->Add(20021);
	animations->Add(400, ani);
	AddAnimation(400);//1

	Sound::GetInstance()->Play(eSound::sound_Skeleton);
}

void SceneIntro::Update(DWORD dt)
{
	if (isPressedKey)
		SceneManager::GetInstance()->SetScene(new SceneGame(1));
	if (animations[0]->GetCurrentFrame() == 17)
	{
		state = 1;
		isRenderBird = true;
	}
	if (isRenderBird) y+= 10;
}

void SceneIntro::Render()
{
	CSprites::GetInstance()->Add(BACKGROUNDINTRO, 0, 0, 320, 256, CTexture::GetInstance()->Get(BACKGROUNDINTRO));
	CSprites::GetInstance()->Get(BACKGROUNDINTRO)->Draw(160, 75, 0, D3DXVECTOR2(0, 0), 0);
	animations[state]->Render(290, 130, 1, 1,D3DXVECTOR2(0,0),2);
	animations[2]->Render(240, 130, 1, 1, D3DXVECTOR2(0, 0), 2);
	if(isRenderBird)
		animations[3]->Render(x, y, 1, 1, D3DXVECTOR2(0, 0), 2);
	/*if (isDrawStartFont)
	{
		mFont->Draw(75, 120, "PUSH ANYWHERE TO START");
	}*/
}
