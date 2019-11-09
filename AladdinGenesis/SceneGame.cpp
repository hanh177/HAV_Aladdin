#include"SceneGame.h"


SceneGame::SceneGame()
{
	

}

SceneGame::SceneGame(int state)
{
	mAladin = Aladin::GetInstance();
	this->State = state;
	mCamera = Camera::GetInstance();
	mGrid = Grid::GetInstance();
	LoadResources();
	

}

SceneGame::~SceneGame()
{

}

void SceneGame::LoadResources()
{
	mGamemap1 = new GameMap(Map1, "Resources/Map/map1_matrix.txt");
	mGamemap2 = new GameMap(Map2, "Resources/Map/map2_matrix.txt");
	mGamemap3 = new GameMap(Map3, "Resources/Map/map3_matrix.txt");
	mGamemap4 = new GameMap(Map4, "Resources/Map/map4_matrix.txt");
	mGamemap5 = new GameMap(Map5, "Resources/Map/map5_matrix.txt");
	mGamemap6 = new GameMap(Map6, "Resources/Map/map6_matrix.txt");
	mGamemap7 = new GameMap(Map7, "Resources/Map/map7_matrix.txt");
	mGamemap8 = new GameMap(Map8, "Resources/Map/map8_matrix.txt");
	mGamemap9 = new GameMap(Map9, "Resources/Map/map9_matrix.txt");
	mGamemap10 = new GameMap(Map10, "Resources/Map/map10_matrix.txt");
	mMapObject = new MapObject("Resources/Map/mapObject.txt");
	mCamera->SetTypeMap(Type::Map1);
	mAladin->SetPosition(40, 1000);
	mGrid->SetGridPath("Resources/Object/Object.txt");
	
}

void SceneGame::Render()
{

	
	mGamemap1->Draw(Type::Map1);
	mGamemap2->Draw(Type::Map2);
	mGamemap3->Draw(Type::Map3);
	mGamemap4->Draw(Type::Map4);
	mGamemap5->Draw(Type::Map5);
	mGamemap6->Draw(Type::Map6);
	mGamemap7->Draw(Type::Map7);
	mGamemap8->Draw(Type::Map8);
	mGamemap9->Draw(Type::Map9);
	mGamemap10->Draw(Type::Map10);
	
	
	for (auto x : obj)
	{
		x->Render();
	}
	mAladin->Render();
	mMapObject->Draw();
}

void SceneGame::Update(DWORD dt)
{
	mGrid->ListObject(obj);
	for (auto x : obj)
	{
		x->Update(dt);
	}
	mAladin->Update(dt,&obj);
}

void SceneGame::KeyState(BYTE *state)
{
	if (CKeyHandler::GetInstance()->isKeyDown(DIK_RIGHT))
	{
		isRunning = true;
		if (mAladin->GetTimeRun() == 0)
			mAladin->SetTimeRun(GetTickCount());
		mAladin->SetState(ALADIN_WALKING_RIGHT_STATE);
	}

	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_LEFT))
	{
		if (mAladin->GetTimeRun() == 0)
			mAladin->SetTimeRun(GetTickCount());
		isRunning = true;
		mAladin->SetState(ALADIN_WALKING_LEFT_STATE);
		
	}
	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_UP))
	{
		mAladin->SetState(ALADIN_FACEUP_STATE);
		
	}
	else if (CKeyHandler::GetInstance()->isKeyDown(DIK_DOWN))
	{
		mAladin->SetState(ALADIN_SIT_STATE);

	}
	else
	{
		if (isRunning)
		{
			if (GetTickCount() - mAladin->GetTimeRun()>= ALADIN_MIN_RUNNING_TIME)
			{
				if (time == 0)
					time = GetTickCount();
				if (GetTickCount() - time < 500)
					mAladin->SetState(ALADIN_PARKING_STATE);
				else
				{
					isRunning = false;
					mAladin->SetTimeRun(0);
					mAladin->SetState(ALADIN_IDLE_STATE);
					time = 0;
				}
			}
			else
			{
				isRunning = false;
				mAladin->SetTimeRun(0);
				time = 0;
				mAladin->SetState(ALADIN_IDLE_STATE);
			}

		}
		else
		{
			mAladin->SetState(ALADIN_IDLE_STATE);
		}
	}
}

void SceneGame::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_SPACE:
		mAladin->SetState(ALADIN_JUMPPING_STATE);
		timeRun = 0;
		break;
	case DIK_A:
		mAladin->SetState(ALADIN_ATTACKING_STATE);
		break;
	case DIK_X:
		mAladin->SetState(ALADIN_ATTACKAPPLE_STATE);
		break;
	}
}

void SceneGame::OnKeyUp(int KeyCode)
{

}