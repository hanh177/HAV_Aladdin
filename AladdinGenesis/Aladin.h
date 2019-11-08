#pragma once
#include "GameObject.h"
#include "Camera.h"
#include <vector>
#include "Brick.h"
#include <iostream>
#include <fstream>
#include "MovingBrick.h"
#include "Keyboard.h"

using namespace std;



#define ALADIN_WALKING_SPEED 0.12f
#define ALADIN_GRAVITY 0.001f
#define ALADIN_JUMPPING_SPEED 0.385f
#define ALADIN_PARKING_SPEED 0.03f

#define ALADIN_ANI_IDLE1 0//dung yen
#define ALADIN_ANI_IDLE2 1//quay trai phai
#define ALADIN_ANI_IDLE3 2//dung yen tung tao
#define ALADIN_ANI_IDLE4 3 //chi tung tao 
#define ALADIN_ANI_IDLE5 4
#define ALADIN_ANI_RUNNING 5
#define ALADIN_ANI_FACEUP 6
#define ALADIN_ANI_JUMPPING 7
#define ALADIN_ANI_JUMPPING2 8
#define ALADIN_ANI_PARKING 9
#define ALADIN_ANI_ATTACKING1 10
#define ALADIN_ANI_SIT 11
#define ALADIN_ANI_ATTACKING2 12
#define ALADIN_ANI_ATTACKING3 13





#define ALADIN_IDLE_STATE 0
#define ALADIN_WALKING_RIGHT_STATE 100
#define ALADIN_WALKING_LEFT_STATE 200
#define ALADIN_FACEUP_STATE 300
#define ALADIN_JUMPPING_STATE 400
#define ALADIN_PARKING_STATE 500
#define ALADIN_SIT_STATE 600
#define ALADIN_ATTACKING_STATE 700

#define ALADIN_IDLE1_TIME 2000
#define ALADIN_IDLE2_TIME 5000
#define ALADIN_IDLE3_TIME 500
#define ALADIN_IDLE4_TIME 1000
#define ALADIN_IDLE5_TIME 1000
#define ALADIN_RUNNING1_TIME 1000
#define ALADIN_MIN_RUNNING_TIME 1000


class Aladin :public GameObject
{

	static Aladin * _instance;
	bool mCollisionWithBrick, isJumping = false, isAttacking = false;
	DWORD running1_Time;
	DWORD time;
	int currentIdle = -1;
	bool isCounting, isIdleDoing, isJumpping, isSet = true, isSit, isRunning;
	int mCurrentState = 0;
	int toX, toY;
	
public:
	Aladin();
	void LoadResources();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject);
	void SetState(int state);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CollisionWithBrick(vector<LPGAMEOBJECT> *coObject);
	void ClearState(int lastState);
	void StartCountingTime(int);
	void StartCountingTime(DWORD &time)
	{
		time = GetTickCount();
	}
	static Aladin *GetInstance();
	~Aladin();
};

