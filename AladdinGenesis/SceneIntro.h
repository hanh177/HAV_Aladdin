#pragma once
#include "Scene.h"
#include"SceneManager.h"
#include"SceneGame.h"
#include"Font.h"
#include"Sprite.h"
#include"Texture.h"
#include"GameObject.h"
#include "Camera.h"
class SceneIntro :public Scene
{
	bool isPressedKey;
	DWORD TimeBling;

	DWORD TimeBetweenBling;
	Font *mFont;
	bool isDrawStartFont;
	vector<LPANIMATION> animations;
public:
	SceneIntro();
	~SceneIntro();
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	void AddAnimation(int aniId);
	void LoadResources();
	void Update(DWORD dt);
	void Render();
};


