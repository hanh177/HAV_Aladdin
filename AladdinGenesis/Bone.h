#pragma once
#include "Weapon.h"

class Bone :public Weapon
{
	int dem = 0;
	int state;
public:
	Bone(float x, float y,float vx, float vy, int state);
	void LoadResources();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	void CollisWithAladin();
	void CollisWithObj(vector<LPGAMEOBJECT> *coObjects);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void ModifyPositionFitSkeleton();
	void SetState(int x);
	~Bone();
};

