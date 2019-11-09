#include"Aladin.h"


Aladin *Aladin::_instance = NULL;

Aladin *Aladin::GetInstance()
{
	if (_instance == NULL)
		_instance = new Aladin();
	return _instance;
}

Aladin::Aladin()
{
	GameObject::GameObject();
	
	LoadResources();
}

void Aladin::LoadResources()
{
	ifstream file;
	int id,left, top, right, bottom, n;
	CTexture *texture = CTexture::GetInstance();
	CSprites *sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texAladin = texture->Get(Type::ALADIN);
	LPDIRECT3DTEXTURE9 texAladin2 = texture->Get(Type::ALADIN2);

	LPANIMATION ani;
	//standing state
	//sprites->Add(20000, 20,61,66, 147, texAladin);
	sprites->Add(20000, 3,9,40,59, texAladin);

	ani = new CAnimation(100);
	ani->Add(20000);
	animations->Add(100, ani);
	AddAnimation(100);//0

	////IDLE2(quay ngang trai phai)
	file.open("Resources/Aladin/Idle2.txt");
	file >> n;//18
	ani = new CAnimation(115);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000+id, left, top, right, bottom, texAladin2);
		ani->Add(20000+id);
		
	}
	animations->Add(200, ani);
	AddAnimation(200);//1
	file.close();

	//dung yen tung tao
	file.open("Resources/Aladin/Idle3.txt");
	file >> n;//7
	ani = new CAnimation(100);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(300, ani);
	AddAnimation(300);//2
	file.close();

	//chi tung tao
	file.open("Resources/Aladin/Idle4.txt");
	file >> n;//7
	ani = new CAnimation(100);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(400, ani);
	AddAnimation(400);//3
	file.close();

	//Idle5
	file.open("Resources/Aladin/Idle5.txt");
	file >> n;
	ani = new CAnimation(100);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(500, ani);
	AddAnimation(500);//4
	file.close();

	//Running1
	file.open("Resources/Aladin/Running.txt");
	file >> n;
	ani = new CAnimation(46);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(600, ani);
	AddAnimation(600);//5
	file.close();

	//ngua mat
	ani = new CAnimation(100);
	sprites->Add(20071, 111, 491, 160, 549, texAladin);
	ani->Add(20071);
	animations->Add(700, ani);
	AddAnimation(700);//6

	//jumpping
	file.open("Resources/Aladin/Jumpping1.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(800, ani);
	AddAnimation(800);//7
	file.close();

	//jumpping2
	file.open("Resources/Aladin/Jumpping2.txt");
	file >> n;
	ani = new CAnimation(125);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(900, ani);
	AddAnimation(900);//8
	file.close();

	//Parking
	file.open("Resources/Aladin/Parking.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1000, ani);
	AddAnimation(1000);//9
	file.close();

	//attacking1: dung chem
	file.open("Resources/Aladin/Attacking1.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1100, ani);
	AddAnimation(1100);//10
	file.close();

	//cui dau
	ani = new CAnimation(50);
	sprites->Add(20116, 378, 516, 431, 551, texAladin);
	ani->Add(20116);
	animations->Add(1200, ani);
	AddAnimation(1200);//11

	//attacking2: ngoi chem
	file.open("Resources/Aladin/Attacking2.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1300, ani);
	AddAnimation(1300);//12
	file.close();

	//attacking3: vua di vua chem
	file.open("Resources/Aladin/Attacking3.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin2);
		ani->Add(20000 + id);

	}
	animations->Add(1400, ani);
	AddAnimation(1400);//13
	file.close();

	//attacking4: vua nhay vua chem
	file.open("Resources/Aladin/Attacking4.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1500, ani);
	AddAnimation(1500);//14
	file.close();


	file.open("Resources/Aladin/AttackApple.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1600, ani);
	AddAnimation(1600);//15
	file.close();

	//ngoi nem tao
	file.open("Resources/Aladin/AttackApple2.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1700, ani);
	AddAnimation(1700);//16
	file.close();

	//chay nem tao
	file.open("Resources/Aladin/AttackApple3.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1800, ani);
	AddAnimation(1800);//17
	file.close();
	

	//ngua mat tan cong
	file.open("Resources/Aladin/Attacking5.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(1900, ani);
	AddAnimation(1900);//18
	file.close();

	//Pushing
	file.open("Resources/Aladin/Pushing.txt");
	file >> n;
	ani = new CAnimation(50);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(2000, ani);
	AddAnimation(2000);//19
	file.close();
}

void Aladin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	GameObject::Update(dt);
	vy += ALADIN_GRAVITY * dt;

	CollisionWithWall(coObject);
	CollisionWithBrick(coObject);
	
	if (vx < 0 && x <8 ) x = 8;
	Camera::GetInstance()->SetPosition(x+37,y);
	
}

void Aladin::Render()
{
	int formSize = 1;
	int toHeight;
	int ani_ID;
	int loop;//0 là k lap
	
	if (vx == 0)
	{
		if (isCounting)
			StartCountingTime(time);
		switch (currentIdle)
		{

		case -1:
			/*ani_ID = ALADIN_ANI_IDLE1;
			loop = 0;
			currentIdle = 1;
			break;*/
		case 1://trang thai idle1
			ani_ID = ALADIN_ANI_IDLE1;
			loop = 0;
			if (GetTickCount() - time >= ALADIN_IDLE1_TIME)
			{
				currentIdle = 2;
				isCounting = true;
			}
			else
				isCounting = false;
			break;

		case 2:
			ani_ID = ALADIN_ANI_IDLE2;
			loop = 1;
			if (GetTickCount() - time >= ALADIN_IDLE2_TIME)
			{
				currentIdle = 3;
				isCounting = true;
			}
			else
				isCounting = false;
			break;

		case 3:
			ani_ID = ALADIN_ANI_IDLE3;
			loop = 1;
			if (GetTickCount() - time >= ALADIN_IDLE3_TIME)
			{
				currentIdle = 4;
				isCounting = true;
			}
			else
				isCounting = false;
			break;

		case 4:
			ani_ID = ALADIN_ANI_IDLE4;
			loop = 1;
			isCounting = false;
			if (animations[ani_ID]->GetCurrentFrame() == 9)
				currentIdle = 4 + rand() % (2);
			break;

		case 5:
			ani_ID = ALADIN_ANI_IDLE5;
			loop = 1;
			if (animations[ani_ID]->GetCurrentFrame() == 16)
				currentIdle = 4 + rand() % (2);
			break;
		case 6:
			ani_ID = ALADIN_ANI_FACEUP;
			loop = 0;
			isIdleDoing = false;
			break;
		case 7:
			ani_ID = ALADIN_ANI_SIT;
			isIdleDoing = false;
			loop = 0;
			break;
		case 8://dung yen tan cong
			ani_ID = ALADIN_ANI_ATTACKING1;
			if (animations[ani_ID]->GetCurrentFrame() == 4)
			{
				isIdleDoing = false;
				isSet = true;
				isAttacking = false;
			}
			loop = 1;
			break;
		case 9://ngoi tan cong
			ani_ID = ALADIN_ANI_ATTACKING2;
			if (animations[ani_ID]->GetCurrentFrame() == 6)
			{
				isIdleDoing = false;
				isSet = true;
				attacking = -1;

			}
			loop = 1;
			break;

		case 10://dung nem tao
			ani_ID = ALADIN_ANI_ATTACKAPPLE;
			if (animations[ani_ID]->GetCurrentFrame() == 5)
			{
				isIdleDoing = false;
				isSet = true;
			}
			loop = 1;
			break;
		case 11://ngoi nem tao
			ani_ID = ALADIN_ANI_ATTACKAPPLE2;
			if (animations[ani_ID]->GetCurrentFrame() == 3)
			{
				isIdleDoing = false;
				isSet = true;
				attacking = -1;
	

			}
			loop = 1;
			break;
		case 12://ngua mat va tan cong
			ani_ID = ALADIN_ANI_ATTACKING5;
			if (animations[ani_ID]->GetCurrentFrame() == 18)
			{
				isIdleDoing = false;
				attacking = -1;
				isSet = true;
			}
			loop = 1;
			break;
		}
	}
	else
	{
			currentIdle = 1;
			isCounting = true;
			switch (mCurrentState)
			{
			case 1:
				ani_ID = ALADIN_ANI_RUNNING;
				loop = 1;
				break;
			case 2:
				ani_ID = ALADIN_ANI_PARKING;
				if (animations[ani_ID]->GetCurrentFrame() == 6)
					isSet = true;
				loop = 1;
				break;
			case 3://chay tan cong
				ani_ID = ALADIN_ANI_ATTACKING3;
				if (animations[ani_ID]->GetCurrentFrame() == 4)
				{
					isIdleDoing = false;
					isSet = true;
					attacking = -1;
				}
				loop = 1;
				break;
			case 4://chay nem tao
				ani_ID = ALADIN_ANI_ATTACKAPPLE;
				if (animations[ani_ID]->GetCurrentFrame() == 5)
				{
					isIdleDoing = false;
					isSet = true;
					attacking = -1;
				}
				loop = 1;
				break;
			case 5:
				ani_ID = ALADIN_ANI_PUSHING;
				loop = 1;
				formSize = 2;
			}
	}

	if (vy != 0)
	{
		if (!mCollisionWithBrick)
		{
			loop = 1;
			if (isAttacking)
			{
				ani_ID = ALADIN_ANI_ATTACKING4;
				if (animations[ani_ID]->GetCurrentFrame() == 5)
				{
					isIdleDoing = false;
					isSet = true;
					isAttacking = false;
				}
			}
			else if (isAttacking2)
					{
						mCurrentState = 1;
						ani_ID = ALADIN_ANI_ATTACKAPPLE3;
						if (animations[ani_ID]->GetCurrentFrame() == 4)
						{
							isIdleDoing = false;
							isSet = true;
							isAttacking2 = false;
						}
					}
			else if (vx != 0)
				ani_ID = ALADIN_ANI_JUMPPING2;
			else
				ani_ID = ALADIN_ANI_JUMPPING;
		}
	}
	float toX = 0;
	if (this->nx == -1)
		toX = 37;
	if (formSize == 2)
		toX = 40;
	animations[ani_ID]->Render(x+toX, y + 52, loop, this->nx, Camera::GetInstance()->GetTranform(),formSize);
	if (DISPLAY_BOX ==1 )
	{
		RenderBoundingBox(22,26);
	}
}


void Aladin::SetState(int state)
{

	switch (state)
	{
	case ALADIN_IDLE_STATE:
		isSit =isFaceUp = false;
		vx = 0;
		mCurrentState = 1;
		if (!isIdleDoing)
		{
			if (currentIdle>5|| currentIdle ==-1)
			{
				currentIdle = 1;
				isCounting = true;
			}
		}
		break;
	case ALADIN_WALKING_LEFT_STATE:
		vx = -ALADIN_WALKING_SPEED;
		mCurrentState = 1;
		if (attacking == 3)
			mCurrentState = 3;
		else if (attacking == 4)
			mCurrentState = 4;
		this->nx = -1;
		break;
	case ALADIN_WALKING_RIGHT_STATE:
		if (!isCollisWithWall)
		{
			vx = ALADIN_WALKING_SPEED;
			mCurrentState = 1;
			if (attacking == 3)
				mCurrentState = 3;
			else if (attacking == 4)
				mCurrentState = 4;
		}
		else
		{
			mCurrentState = 5;
		}
		this->nx = 1;
		break;
	case ALADIN_FACEUP_STATE:
		vx = 0;
		isFaceUp = true;
		isIdleDoing = true;
		currentIdle = 6;
		if (attacking == 12)
			currentIdle = 12;
		break;
	case ALADIN_JUMPPING_STATE:
		if (mCollisionWithBrick == true)
		{
			animations[ALADIN_ANI_JUMPPING]->SetCurrentFrame();
			animations[ALADIN_ANI_JUMPPING2]->SetCurrentFrame();
			time = 0;
			vy = -ALADIN_JUMPPING_SPEED;
			mCollisionWithBrick = false;
			isCounting = true;
			currentIdle = 1;
		}
		break;
	case ALADIN_PARKING_STATE:
		if (!isCollisWithWall)
		{
			mCurrentState = 2;
			if (isSet)
			{
				animations[ALADIN_ANI_PARKING]->SetCurrentFrame();
				isSet = false;
			}
			vx = ALADIN_PARKING_SPEED * this->nx;
		}
		break;
	case ALADIN_SIT_STATE:
		isSit = true;
		currentIdle = 7;
		if (attacking == 9)
			currentIdle = 9;
		else if (attacking == 11)
			currentIdle = 11;
		isIdleDoing = true;
		break;
	case ALADIN_ATTACKING_STATE:
		if (vx == 0)//dung yen
		{
			if (isSit)//dang ngoi
			{
				currentIdle = 9;//ngoi tan cong
				attacking = 9;
				isSit = false;
			}
			else if (isFaceUp)
			{
				currentIdle = 12;//ngua mat va tan cong
				isFaceUp = false;
				attacking = 12;
			}
			else
				currentIdle = 8;//dung yen tan cong
		}
		else //di chuyen theo phuong x
		{
				mCurrentState = 3;//chay va tan cong
				attacking = 3;
		}
		if (vy != 0)
			isAttacking = true;
		if (isSet)
		{
			animations[ALADIN_ANI_ATTACKING1]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKING2]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKING3]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKING4]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKING5]->SetCurrentFrame();
			isSet = false;
		}
		isIdleDoing = true;//trang thai dang dung va lam j do
		break;

	case ALADIN_ATTACKAPPLE_STATE:
		if (vx == 0)//dung yen
		{
			if (isSit)//dang ngoi
			{
				currentIdle = 11;//ngoi nem tao
				attacking = 11;
				isSit = false;
			}
			else
				currentIdle = 10;//dung yen nem tao
		}
		else //di chuyen theo phuong x
		{
			mCurrentState = 4;//chay va nem tao
			attacking = 4;
		}
		if (vy != 0)
			isAttacking2 = true;
		isIdleDoing = true;
		if (isSet)
		{
			animations[ALADIN_ANI_ATTACKAPPLE]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKAPPLE2]->SetCurrentFrame();
			animations[ALADIN_ANI_ATTACKAPPLE3]->SetCurrentFrame();
			isSet = false;
		}
		break;
	}
}


Aladin::~Aladin()
{

}

void Aladin::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;

	right = left + 44;
	bottom = top+52 ;
}

void Aladin::CollisionWithBrick(vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == Type::BRICK|| coObject->at(i)->GetType() == Type::MOVINGBRICK)
		{
			list_Brick.push_back(coObject->at(i));
		}
	}

	CalcPotentialCollisions(&list_Brick, coEvents);

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		if (nx != 0) vx = 0;
		//xet logic va cham voi brick
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<Brick *>(e->obj))//e->obj is Brick
			{
				if (e->nx != 0)//co xay ra va cham theo phuong Ox
				{
					x += dx;
				}
				else//k xay ra va cham theo phuong Ox
				{
					x += min_tx * dx + nx * 0.4f;
				}
				if (e->ny == -1)//dang di len
				{
					y += min_ty * dy + ny * 0.4f;
					if (ny != 0)
					{
						vy = 0;
					}
					mCollisionWithBrick = true;
				}
				else// Nhay duoi len(ny==1)
				{
					y += dy;
				}
			}
			else
			{
				dynamic_cast<MovingBrick *>(e->obj);
				if (e->nx != 0)
				{
					x += dx;
				}
				else
				{
					x += min_tx * dx + nx * 0.4f;
				}
				if (e->ny == -1)
				{
					y += min_ty * dy + ny * 0.4f;
					if (ny != 0)
					{
						vy = 0;
					}
					mCollisionWithBrick = true;
				}
				else// Nhay duoi len
				{
					y += dy;
				}
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Aladin::CollisionWithWall(vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Wall;
	list_Wall.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == Type::WALL)
		{
			list_Wall.push_back(coObject->at(i));
		}
	}

	CalcPotentialCollisions(&list_Wall , coEvents);

	if (coEvents.size() != 0)//co xay ra va cham
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (e->nx == -1)
			{
				dx = 0;
				isCollisWithWall = true;
			}

		}
	}
	else
	{
		isCollisWithWall = false;
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}


void Aladin::ClearState(int lastState)
{
	
}

void Aladin::StartCountingTime(int x)
{
	
}