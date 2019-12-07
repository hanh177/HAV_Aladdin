#include "SceneIntro.h"



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
}

void SceneIntro::Update(DWORD dt)
{
	if (isPressedKey)
	{
		if(animations[0]->GetCurrentFrame()==17)
			SceneManager::GetInstance()->SetScene(new SceneGame(1));
	}
}

void SceneIntro::Render()
{
	animations[0]->Render(180, 130, 1, 1,D3DXVECTOR2(0,0),2);
	/*if (isDrawStartFont)
	{
		mFont->Draw(75, 120, "PUSH ANYWHERE TO START");
	}*/
}
