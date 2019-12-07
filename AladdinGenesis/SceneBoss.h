#pragma once
#include"Scene.h"
#include"CGame.h"
#include "Aladin.h"
#include "GameMap.h"
#include "Camera.h"
#include "Keyboard.h"
#include"Grid.h"
#include"MapObject.h"
#include "Board.h"


#define ALADIN_NORMAL 1
#define ALADIN_DIE 0
#define ALADIN_OVER -1
class SceneBoss :public Scene
{

	Aladin *mAladin;
	GameMap *mMapBoss;
	Camera *mCamera;
	Grid *mGrid;
	Board *mBoard;
	bool isRunning;
	DWORD  time;


	vector<LPGAMEOBJECT> listObj;
public:
	SceneBoss();
	SceneBoss(int State);
	~SceneBoss();
	void LoadResources();
	void SetEvent(int mEvent);
	void Render();
	void Update(DWORD dt);
	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	GameObject* NewObject(int id, int type, int direction, int width, int height, float x, float y, int state);
	void AddObject(int id, int type, int direction, int width, int height, float x, float y, int state);
};


