#include"Grid.h"


Grid *Grid::_instance = NULL;

Grid *Grid::GetInstance()
{
	if (_instance == NULL)
		_instance = new Grid();
	return _instance;
}

Grid::Grid()
{

}

// Set duong dan cua grid 
void Grid::SetGridPath(LPCSTR gridPath)
{
	this->gridPath = gridPath;
	LoadGrid();

	fstream ObjMtrx("Resources/Object/ObjectMatrix.txt", ios::out);
	//luu no vao file txt
	for (int i = 0; i < MAX_GRID_ROW; i++)
	{
		for (int j = 0; j < MAX_GRID_COLUMN; j++)
		{
			
			int data;
			ObjMtrx << i << " " << j << " ";
			for (int z = 0; z < cells[i][j].size(); z++)
			{
				ObjMtrx << cells[i][j].at(z)->GetID() << " ";
			}
			ObjMtrx <<-1<< "\n";
		}
	}
}

void Grid::Clear()
{
	for (int i = 0; i < MAX_GRID_ROW; i++)
	{
		for (int j = 0; j < MAX_GRID_COLUMN; j++)
		{
			cells[i][j].clear();
		}
	}

	fstream ObjMtrx("Resources/Object/ObjectMatrix.txt", ios::out);
	ObjMtrx.clear();
	ObjMtrx.close();
}


//doc cac thong tin cua object 
void Grid::LoadGrid()
{
	//id trong texture,huong,chieu dai,chieu cao,toa do x, toa do y, trang thai ban dau
	int id, type, direction, width, height, n, state;
	float x, y;

	ifstream file(gridPath, ios::in);
	file >> n;

	for (int i = 0; i < n; i++)
	{
		file >> id >> type >> direction >> width >> height >> x >> y >> state;
		LoadObjectIntoGrid(id, type, direction, width, height, x, y,state);
	}
}


void Grid::LoadObjectIntoGrid(int id, int type, int direction, int width, int height, float x, float y,int state)
{
	//xac dinh left, top, rigth, bottom cua no thuoc cell nao
	int left_cell = (int)(x / GRID_CELL_WIDTH);
	int top_cell = (int)(y / GRID_CELL_HEIGHT);
	int right_cell = (int)((x + width) / GRID_CELL_WIDTH);
	int bottom_cell = (int)((y + height) / GRID_CELL_HEIGHT);

	GameObject *obj = NewObject(id, type, direction, width, height, x, y,state);
	if (obj == NULL)
		return;

	obj->SetID(id);

	//add object vao cell ma no dang thuoc ve
	for ( int i = top_cell; i <= bottom_cell; i++)
	{
		for (int j = left_cell; j <= right_cell; j++)
		{
			cells[i][j].push_back(obj);//add object vao cell
		}
	}

}


GameObject *Grid::NewObject(int id, int type, int direction, int width, int height, float x, float y,int state)
{
	switch (type)
	{
	case BRICK:
		return new Brick(x, y, width, height);
		break;
	case ARROW:
		return new Arrow(x, y,width,height, state);
		break;
	case BOB:
		return new Bob(x, y, width, height, state);
		break;
	case MOVINGBRICK:
		return new MovingBrick(x, y, width, height, state);
		break;
	case WALL:
		return new Wall(x, y, width, height);
		break;
	case ROPE:
		return new Rope(x, y, width, height);
		break;
	case APPLEITEM:
		return new AppleItem(x, y, width, height);
		break;
	case REDJEWEL:
		return new RedJewel(x, y, width, height);
		break;
	case GENIE:
		return new Genie(x, y, width, height);
		break;
	case HEART:
		return new Heart(x, y, width, height);
		break;
	case RESTARTPOINT:
		return new RestartPoint(id,x, y, width, height);
		break;
	case BAT:
		return new Bat(x, y, direction);
		break;
	case GUARD:
		return new Guard(x, y, direction);
		break;
	case SKELETON:
		return new Skeleton(x, y, state);
		break;
	case MONKEY:
		return new Monkey(x, y, direction);
		break;
	}
}


void Grid::ListObject(vector<GameObject*> &listObj)
{
	vector <int> listID;
	Camera *camera = Camera::GetInstance();
	RECT r = camera->GetBound();

	int left_cell = (int)(r.left / GRID_CELL_WIDTH);
	int right_cell = (int)(r.right / GRID_CELL_WIDTH);
	int top_cell = (int)(r.top / GRID_CELL_HEIGHT);
	int bottom_cell = (int)(r.bottom / GRID_CELL_HEIGHT);
	//lay ds cac object ra xem no con nam trong vung camera hay khong

	listObj.clear();

	//can 1 DS cac object dang nam trong vung camera
	unordered_map<int, GameObject*> mapObj;

	for (int i = top_cell; i <= bottom_cell; i++)//Theo Hang
	{
		for (int j = left_cell; j <= right_cell; j++)//Theo cot
		{
			/*listID.clear();
			ReadMatrixGrid(i, j, listID);*/
			for (int k = 0; k < cells[i][j].size(); k++)
			{
				mapObj[cells[i][j].at(k)->GetID()] = cells[i][j].at(k);//them vao neu chua co trong mapObject
				//mapObj[listID.at(k)]= cells[i][j].at(k);
			}
		}
	}


	
	int demmv = 0, dembob = 0;
	for (auto& x : mapObj)
	{
		/*if (x.second->GetType() == Type::MOVINGBRICK&&isResetMV)
		{
			x.second->Reset();
		}
		if (x.second->GetType() == Type::MOVINGBRICK)
			dembob++;
		if (x.second->GetType() == Type::BOB&&isResetBob)
		{
			x.second->Reset();
		}
		if (x.second->GetType() == Type::MOVINGBRICK)
			demmv++;*/
		listObj.push_back(x.second);
	}

	if (demmv == 0)//k co movingbrick
		isResetMV = true;
	else
		isResetMV = false;

	if (dembob == 0)//k co bob
		isResetBob = true;
	else
		isResetBob = false;

}

void Grid::ReadMatrixGrid(int row,int column,vector<int> &IdObj)
{
	ifstream file;
	file.open("Resources/Object/ObjectMatrix.txt");
	int tmp;
	int i = 0;
	while (i <= 15)
	{
		file >> tmp;
		if (tmp == row)
		{
			file >> tmp;
			if (tmp == column)
			{
				while (tmp != -1)
				{
					file >> tmp;
					if (tmp != -1)
						IdObj.push_back(tmp);
				}
				break;
			}
			else
			{
				while (tmp != -1)
				{
					file >> tmp;
				}
				i++;
			}
		}
		else
		{
			while (tmp != -1)
			{
				file >> tmp;
			}
			i++;
		}
	}
	file.close();
}

void Grid::FindObjInMatrix(int &i, int &j)
{

}
Grid::~Grid()
{

}