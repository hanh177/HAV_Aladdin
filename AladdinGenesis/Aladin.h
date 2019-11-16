#pragma once
#include "GameObject.h"
#include "Camera.h"
#include <vector>
#include "Brick.h"
#include <iostream>
#include <fstream>
#include "MovingBrick.h"
#include "Keyboard.h"
#include "Wall.h"
#include "Rope.h"
#include"debug.h"

using namespace std;



#define ALADIN_WALKING_SPEED 0.11f
#define ALADIN_GRAVITY 0.0012f
#define ALADIN_JUMPPING_SPEED 0.416f
#define ALADIN_STOP_SPEED 0.03f

#define ALADIN_ANI_IDLE1 0//dung yen
#define ALADIN_ANI_IDLE2 1//quay trai phai
#define ALADIN_ANI_IDLE3 2//dung yen tung tao
#define ALADIN_ANI_IDLE4 3 //chi tung tao 
#define ALADIN_ANI_IDLE5 4
#define ALADIN_ANI_RUNNING 5
#define ALADIN_ANI_FACEUP 6
#define ALADIN_ANI_JUMPPING 7
#define ALADIN_ANI_JUMPPING2 8
#define ALADIN_ANI_STOP 9
#define ALADIN_ANI_ATTACKING1 10
#define ALADIN_ANI_SIT 11
#define ALADIN_ANI_ATTACKING2 12
#define ALADIN_ANI_ATTACKING3 13
#define ALADIN_ANI_ATTACKING4 14
#define ALADIN_ANI_ATTACKAPPLE 15
#define ALADIN_ANI_ATTACKAPPLE2 16
#define ALADIN_ANI_ATTACKAPPLE3 17
#define ALADIN_ANI_ATTACKING5 18
#define ALADIN_ANI_PUSHING 19 
#define ALADIN_ANI_CLIMBING 20
#define ALADIN_ANI_CLIMBING_IDLE 21



#define ALADIN_IDLE_STATE 0
#define ALADIN_WALKING_RIGHT_STATE 100
#define ALADIN_WALKING_LEFT_STATE 200
#define ALADIN_FACEUP_STATE 300
#define ALADIN_JUMPPING_STATE 400
#define ALADIN_STOP_STATE 500
#define ALADIN_SIT_STATE 600
#define ALADIN_ATTACKING_STATE 700
#define ALADIN_ATTACKAPPLE_STATE 800

#define ALADIN_IDLE1_TIME 50
#define ALADIN_IDLE2_TIME 50
#define ALADIN_RUNNING1_TIME 1000
#define ALADIN_MIN_RUNNING_TIME 1000


class Aladin :public GameObject
{
	float ropeX, ropeY, X, DY;
	static Aladin * _instance;
	bool isCollisWithBrick, isCollisWithWall, isCollisWithRope, isClimbing;
	int dem = 0, currentState = 1, index, climbing = -1;
	//dem: biến đếm số lần update của cùng 1 trạng thái, currentState:biến nhận dạng trạng thái hiện tại
	//index: dùng để biểu thị cho trạng thái đc ưu tiên khi có 2 trạng thái đồng thời xảy ra ví dụ đang chạy thì tấn công.
	//sẽ rõ khi nhìn sang hàm chuyển trạng thái.
	DWORD timeRun;//biến để ghi lại tg chạy của aladin phục vụ cho việc set state stop
	bool isBusy, isSit = false, isResetFrame = true, isFaceUp, isPushing;
	//biến nhận diện nếu đang trạng thái đứng yên và không làm gì thì nó bằng false khi đó ta set trạng thái về trạng thái ban đầu
	int toX, toY;
	
public:
	Aladin();
	void LoadResources();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject);
	void SetState(int state);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CollisionWithBrick(vector<LPGAMEOBJECT> *coObject);
	void CollisionWithWall(vector<LPGAMEOBJECT> *coObject);
	void CollisionWithRope(vector<LPGAMEOBJECT> *coObject);

	int GetClimbing() { return this->climbing; }
	void SetClimbing(int x) { this->climbing = x; }
	void SetDY(float d) { this->DY = d; }

	float GetDx()//lấy giá trị biến đổi về tọa độ x để kiểm tra xem nó có đang chạy hya k
		//nếu nó khác 0 thì nó đang di chuyển theo phương ox. Ta có: dx=vx*dt(quãng đường bằng v * t)
	{
		return this->dx;
	}
	void SetTimeRun(DWORD t)//cài đặt thời gian chạy của aladin
	{
		timeRun = t;
	}
	void ResetFrame(int x)//set về frame đầu tiên của animation x
	{
		animations[x]->SetCurrentFrame();
	}

	int GetFrame(int x)//lấy frame hiện tại của animation x
	{
		return animations[x]->GetCurrentFrame();
	}

	bool getisPushing()//lấy trạng thái có pushing hay k
	{
		return isPushing;
	}
	DWORD GetTimeRun() { return timeRun; }
	static Aladin *GetInstance();
	~Aladin();
};

