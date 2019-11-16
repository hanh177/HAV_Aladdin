#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"CGame.h"
#include"Sprite.h"
#include "Texture.h"
#include<vector>
#include "define.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "Camera.h"
#include "debug.h"

using namespace std;


#define DISPLAY_BOX 0

class GameObject;
typedef GameObject * LPGAMEOBJECT;

struct CCollisionEvent;
typedef CCollisionEvent * LPCOLLISIONEVENT;
struct CCollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CCollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};

class GameObject
{

protected:
	Type type;
	int id;

	float x, y;

	float vx, vy;

	float nx, ny;

	float dx, dy;

	DWORD dt;
	int currentState;
	int movingBrickState;
	vector<LPANIMATION> animations;

public:

	GameObject();
	void SetState(int state) { this->currentState = state; }
	void AddAnimation(int aniId);


	Type GetType();

	int GetID();
	void SetID(int id);

	void SetDirection(int Direction);
	int GetDirection();


	void SetPosition(float x, float y);
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }

	void SetSpeed(float vx, float vy);
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }
	
	void RenderBoundingBox(int, int);

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny);


	virtual void Update(DWORD);
	virtual void Render();
	virtual int GetState() { return currentState; };
	virtual float GetVx() { return vx; }
	virtual void LoadAni();
	virtual void Reset();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	
	~GameObject();
};

