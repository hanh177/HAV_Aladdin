#pragma once
#include "GameObject.h"
#include <fstream>
#include"define.h"
#include"Brick.h"
#include "Camera.h"
#include"Arrow.h"
#include "Bob.h"
#include "MovingBrick.h"
#include"Wall.h"

#define GRID_CELL_HEIGHT 280
#define GRID_CELL_WIDTH (SCREEN_WIDTH/2.0f)

#define MAX_GRID_ROW 5
#define MAX_GRID_COLUMN 15
class Grid
{
	LPCSTR gridPath;
	vector<GameObject*> cells[MAX_GRID_ROW][MAX_GRID_COLUMN];
	static Grid *_instance;

public:
	Grid();
	void Clear();
	void SetGridPath(LPCSTR gridPath);
	void LoadGrid();
	void LoadObjectIntoGrid(int id, int type, int direction, int width, int height, float x, float y);
	GameObject *NewObject(int id, int type, int direction, int width, int height, float x, float y);

	void ListObject(vector<GameObject *> &listObj);//tra ve list object dang thuoc trong camera
	static Grid *GetInstance();
	~Grid();


};