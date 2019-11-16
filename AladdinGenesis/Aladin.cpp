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
	ani = new CAnimation(45);
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
	ani = new CAnimation(75);
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
	ani = new CAnimation(25);
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
	ani = new CAnimation(25);
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

	//chay va nhay nem tao
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

	//climbing
	file.open("Resources/Aladin/Climbing.txt");
	file >> n;
	ani = new CAnimation(100);
	for (int i = 0; i < n; i++)
	{
		file >> id >> left >> top >> right >> bottom;
		sprites->Add(20000 + id, left, top, right, bottom, texAladin);
		ani->Add(20000 + id);

	}
	animations->Add(2100, ani);
	AddAnimation(2100);//20
	file.close();

	//climbing_Idle
	ani = new CAnimation(50);
	sprites->Add(20188, 11, 1362, 40, 1448, texAladin);
	ani->Add(20188);
	animations->Add(2200, ani);
	AddAnimation(2200);//21

}

void Aladin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	if (climbing<0)
	{
		GameObject::Update(dt);
		
	}
	vy += ALADIN_GRAVITY * dt;

	if (climbing>=0)
	{
		vy = 0;
		dy = 0;
		if (climbing == 1)
			dy = -10;
	}
	CollisionWithWall(coObject);
	CollisionWithRope(coObject);
	CollisionWithBrick(coObject);

	if (vx < 0 && x <8 ) x = 8;
	Camera::GetInstance()->SetPosition(x,y+50);
	if (climbing == 1)
		DebugOut(L"1", NULL);
}

void Aladin::Render()
{
	
	int formSize = 1;
	int toX = 0;
	int ani_ID = 0;
	int loop=1;//0 là k lap
	if (vx == 0)
	{
		switch (currentState)
		{
		case 1://trang thai idle1
			isBusy = true;
			dem++;
			ani_ID = ALADIN_ANI_IDLE1;
			loop = 0;
			if (dem >= ALADIN_IDLE1_TIME)
			{
				currentState = 2;
				dem = 0;
				animations[2]->SetCurrentFrame();
			}
			break;
		case 2:
			isBusy = true;
			dem++;
			ani_ID = ALADIN_ANI_IDLE2;
			loop = 1;
			if (dem >= ALADIN_IDLE2_TIME)
			{
				currentState = 3;
				dem = 0;
				animations[3]->SetCurrentFrame();
			}
			break;
		case 3:
			isBusy = true;
			ani_ID = ALADIN_ANI_IDLE3;
			loop = 1;
			if (animations[ALADIN_ANI_IDLE3]->GetCurrentFrame() == 4)
				currentState = 4;
			break;
		case 4:
			isBusy = true;
			ani_ID = ALADIN_ANI_IDLE4;
			loop = 1;
			if (animations[ani_ID]->GetCurrentFrame() == 9)
				currentState = 4 + rand() % (2);
			break;
		case 5:
			isBusy = true;
			ani_ID = ALADIN_ANI_IDLE5;
			loop = 1;
			if (animations[ani_ID]->GetCurrentFrame() == 16)
				currentState = 4 + rand() % (2);
			break;

		case 6://ngửa mặt
			isBusy = false;
			ani_ID = ALADIN_ANI_FACEUP;
			break;

		case 7://ngồi xuống
			isBusy = false;
			ani_ID = ALADIN_ANI_SIT;
			break;

		case 9://đứng tấn công
			ani_ID = ALADIN_ANI_ATTACKING1;
			if (GetFrame(ani_ID) == 4)
			{
				isBusy = false;
				isResetFrame = true;
			}
			break;

		case 10://ngồi tấn công
			ani_ID = ALADIN_ANI_ATTACKING2;
			if (GetFrame(ani_ID) == 6)
			{
				index = 0;
				isResetFrame = true;
				isBusy = false;
			}
			break;

		case 11://đứng ném táo
			ani_ID = ALADIN_ANI_ATTACKAPPLE;
			if (GetFrame(ani_ID) ==5 )
			{
				isBusy = false;//khong ban lam gi ca co the dung yen 
				isResetFrame = true;
			}
			break;

		case 12://ngồi ném táo
			if (GetFrame(ALADIN_ANI_ATTACKAPPLE2) == 3)
			{
				index = 0;
				isResetFrame = true;
			}
			ani_ID = ALADIN_ANI_ATTACKAPPLE2;
			loop = 0;
			break;
			
		case 15://ngửa mặt và tấn công
			ani_ID = ALADIN_ANI_ATTACKING5;
			if (GetFrame(ani_ID) == 19)//lấy frame hiện tại của nó đem đi so sánh để xem nó đã kết thúc 1 vòng lặp animation hay chưa
			{
				index = 0;
				isResetFrame = true;
			}
			break;
		}

	}
	else//aladin đang di chuyển theo phương x
	{
		switch (currentState)
		{
		case 16:
			isBusy = false;
			ani_ID = ALADIN_ANI_RUNNING;
			if (isCollisWithWall)
			{
				ani_ID = ALADIN_ANI_PUSHING;
				formSize = 2;
				isPushing = true;
			}
			formSize = 2;
			break;

		case 17://chạy và tấn công
			ani_ID = ALADIN_ANI_ATTACKING3;
			if (GetFrame(ani_ID) == 5)
			{
				isResetFrame = true;
				index = 0;
			}
			break;
			
		case 18://chạy và ném táo
			ani_ID = ALADIN_ANI_ATTACKAPPLE;
			if (GetFrame(ani_ID) == 5)
			{
				isResetFrame = true;
				index = 0;
			}
			break;

		case 20://dung lai
			ani_ID = ALADIN_ANI_STOP;
			if (GetFrame(ani_ID) == 5)
				isResetFrame = true;
			break;

		default:
			isBusy = false;
			ani_ID = ALADIN_ANI_RUNNING;
			formSize = 2;
			break;
		}
	}

	if (!isCollisWithBrick)
	{
		switch (currentState)
		{
		case 8://nhay len binh thuong
			ani_ID = ALADIN_ANI_JUMPPING;
			if (GetFrame(ani_ID) == 8)
				isBusy = false;
			break;

		case 13://nhay tai cho va tan cong
			ani_ID = ALADIN_ANI_ATTACKING3;
			if (GetFrame(ani_ID) == 5)
			{
				isBusy = false;
				isResetFrame = true;
			}
			break;

		case 14://nhảy tại chỗ và ném táo
			ani_ID = ALADIN_ANI_ATTACKAPPLE3;
			if (GetFrame(ani_ID) == 4)
			{
				isResetFrame = true;
				index = 0;
			}
			break;

		case 19://vừa chạy vừa nhảy
			ani_ID = ALADIN_ANI_JUMPPING2;
			loop = 1;
			if (GetFrame(ani_ID) == 5)
				index = 0;
			break;

		case 17://chạy và tấn công(có trạng thái 17 ở đây là vì nó có thể vừa chạy vừa nhảy và tấn công,
			//khi này vx và vy nó đang khác 0 nên k cần quan tâm nó có phải trạng thái chạy hoặc nhảy hay k
			//vì khi rơi vào trạng thái này thì nó đang di chuyển cả theo Ox và Oy
			ani_ID = ALADIN_ANI_ATTACKING3;
			if (GetFrame(ani_ID) == 5)
			{
				isResetFrame = true;
				index = 0;
			}
			break;

		case 21:
			ani_ID = ALADIN_ANI_CLIMBING_IDLE;
			loop = 0;
			break;

		default:
			
  			ani_ID = ALADIN_ANI_JUMPPING;
			index = 0;
			break;
		}

		
	}
	
	if (this->nx == -1)
			toX = 40;
	if (formSize == 2)
	{
		if (nx == 1)
			toX = 40;
		else
			toX = 0;
	}
	if(!isClimbing)
		animations[ani_ID]->Render(x + toX, y + 52, loop, this->nx, Camera::GetInstance()->GetTranform(), formSize);
	else
		animations[ani_ID]->Render(x + toX+X, y + 52, loop, this->nx, Camera::GetInstance()->GetTranform(), formSize);
	if (DISPLAY_BOX == 1)
	{
		RenderBoundingBox(22, 26);
	}
	
}


void Aladin::SetState(int state)
{

	switch (state)
	{
	case ALADIN_IDLE_STATE:
		isSit = isFaceUp=isPushing=false;
		vx = 0;
		if (!isBusy)//không làm bất cứ hành động nào khác thì có thể nhàn rỗi và đứng yên
		{
			currentState = 1;
			dem = 0;
		}
		if (isClimbing)
		{
			currentState = 21;
			climbing = 0;
			if (ropeX > this->x)
			{
				X = ropeX - (this->x + 18);
			}
			else
			{
				X = (this->x+17)-ropeX;
			}
		}
		break;
	
	case ALADIN_FACEUP_STATE:
		isBusy = isFaceUp=true;
		climbing = -1;
		switch (index)
		{
		case 15://đang có trạng thái tấn công xảy ra, để nó hoàn thành trk
			currentState = 15;
			break;
		default:
			currentState = 6;
			break;
		}
		break;

	case ALADIN_SIT_STATE:
		isSit = true;
		switch (index)
		{
		case 10://đang có trạng thái tấn công xảy ra khi đang ngồi, ưu tiên hoàn thành tấn công trk
			currentState = 10;
			break;
		case 12://(tương tự)
			currentState = 12;
			break;
		default:
			currentState = 7;
			break;
		}
		break;

	case ALADIN_JUMPPING_STATE:
		if (isCollisWithBrick)//nếu đang va chạm với nền thì ms cho nhảy tiếp, tránh trường hợp đang nhảy thì nhấn nhảy lần 2.
		{
			vy = -ALADIN_JUMPPING_SPEED;
			if (vx == 0)
			{
				currentState = 8;
				ResetFrame(ALADIN_ANI_JUMPPING);
			}
			else
			{
				currentState = 19;//vừa chạy vừa nhảy
				index = 19;
			}
			ResetFrame(ALADIN_ANI_JUMPPING2);
			isCollisWithBrick = false;
		}
		break;
		
	case ALADIN_ATTACKING_STATE:
		if (isSit)
		{
			isSit = false;
			currentState = 10;//ngồi tấn công
			index = 10;//chỉ số cho biết nó đang ở trạng thái tấn công nào.
		}
		else if (isFaceUp)//trường hợp đang ngửa mặt và tấn công
		{
			isFaceUp = false;
			currentState = 15;
			index = 15;
		}
		else if (vx != 0)
		{
			currentState = 17;//chạy và tấn công
			index = 17;
		}
		else
		{
			currentState = 9;//đứng yên tấn công
		}
		isBusy = true;
		if (!isCollisWithBrick)
		{
			currentState = 13;//nhảy tại chỗ và tấn công
			vy = 0;
		}
		if (isResetFrame)//set về frame bắt đầu=0 để tăng độ chính xác
		{
			isResetFrame = false;
			ResetFrame(ALADIN_ANI_ATTACKING1);
			ResetFrame(ALADIN_ANI_ATTACKING2);
			ResetFrame(ALADIN_ANI_ATTACKING3);
			ResetFrame(ALADIN_ANI_ATTACKING4);
			ResetFrame(ALADIN_ANI_ATTACKING5);
		}
		break;

	case ALADIN_ATTACKAPPLE_STATE:
		if (isSit)
		{
			isSit = false;
			currentState = 12;//ngồi và ném táo(tương tự ngồi và tấn công)
			index = 12;//chỉ số biểu thị(dùng để phân biệt ngồi và ngồi tấn công khi cả 2 trạng thái đồng thời xảy ra,
			//theo đó hành động có index khác 0 thì nó đc ưu tiên hoàn thành và set tới trạng thái của nó trước)
		}
		else if (vx != 0)
		{
			currentState = 18;//chạy và ném táo
			index = 18;
		
		}
		else
			currentState = 11;

		if (!isCollisWithBrick)
		{
			currentState = 14;//nhảy tại chỗ và ném táo(tương tự currentState 13)
			vy = 0;
			if (vx != 0)
				index = 14;
		}
		if (isResetFrame)
		{
			isResetFrame = false;
			ResetFrame(ALADIN_ANI_ATTACKAPPLE);
			ResetFrame(ALADIN_ANI_ATTACKAPPLE2);
			ResetFrame(ALADIN_ANI_ATTACKAPPLE3);
		}
		break;

	case ALADIN_WALKING_RIGHT_STATE:
		vx = ALADIN_WALKING_SPEED;
		switch (index)
		{
		case 14:
			currentState = 14;
			break;
		case 17:
			currentState = 17;
			break;
		case 18:
			currentState = 18;
			break;
		case 19:
			currentState = 19;//vừa chạy vừa nhảy
			break;
		default:
			currentState = 16;
			break;
		}
		if (isCollisWithWall)
			index = 0;
		this->nx = 1;
		break;

	case ALADIN_WALKING_LEFT_STATE:
		vx = -ALADIN_WALKING_SPEED;
		switch (index)
		{
		case 14:
			currentState = 14;
			break;
		case 17:
			currentState = 17;
			break;
		case 18:
			currentState = 18;
			break;
		case 19:
			currentState = 19;
			break;
		default:
			currentState = 16;
			break;
		}
		if (isCollisWithWall)
			index = 0;
		this->nx = -1;
		break;

	case ALADIN_STOP_STATE:
		vx = this->nx*ALADIN_STOP_SPEED;
		currentState = 20;
		if (isResetFrame)
		{
			ResetFrame(ALADIN_ANI_STOP);
			isResetFrame = false;
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

		right = left + 45;
		bottom = top + 52;
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
				//DebugOut(L"Collision", NULL);
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
					isCollisWithBrick = true;
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
					isCollisWithBrick = true;
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
			//DebugOut(L"Collision", NULL);
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (e->nx == -1||e->nx==1)
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

void Aladin::CollisionWithRope(vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Rope;
	list_Rope.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == Type::ROPE)
		{
			list_Rope.push_back(coObject->at(i));
		}
	}

	CalcPotentialCollisions(&list_Rope, coEvents);

	if (coEvents.size() == 0)//co xay ra va cham
	{
		//climbing = 0;
		isClimbing = false;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			//DebugOut(L"Collision", NULL);
			LPCOLLISIONEVENT e = coEventsResult[i];
			e->obj->GetPosition(ropeX, ropeY);
			y += min_ty * dy + ny * 0.4f;
			//climbing = 1;
			isClimbing = true;
		}
	}
}


