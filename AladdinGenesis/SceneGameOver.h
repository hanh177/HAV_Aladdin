#pragma once
#include "Scene.h"
#include"SceneManager.h"
#include"SceneGame.h"
#include"Font.h"
#include"Sprite.h"
#include"Texture.h"
#include"GameObject.h"
#include "Camera.h"


class SceneGameOver :public Scene
{

	float x = 0, y = 0;
	Font *mFont;
	vector<LPANIMATION> animations;
	bool isRender;
public:
	SceneGameOver();
	~SceneGameOver();
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	void AddAnimation(int aniId);
	void LoadResources();
	void Update(DWORD dt);
	void Render();
};
