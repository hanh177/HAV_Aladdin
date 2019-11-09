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
}


//doc cac thong tin cua object 
void Grid::LoadGrid()
{
	for (int i = 0; i < MAX_GRID_ROW;i++)
	{
		for (int j = 0; j < MAX_GRID_COLUMN;j++)
		{
			cells[i][j].clear();
		}
	}

	//id trong texture,kieu object,diem bat dau,diem ket thuc,huong di
	int id, type, direction, width, height, n;
	float x, y;

	ifstream file(gridPath, ios::in);
	file >> n;

	for (int i = 0; i < n; i++)
	{
		file >> id >> type >> direction >> width >> height >> x >> y;
		LoadObjectIntoGrid(id, type, direction, width, height, x, y);
	}
}


void Grid::LoadObjectIntoGrid(int id, int type, int direction, int width, int height, float x, float y)
{
	//xac dinh left, top, rigth, bottom cua no thuoc cell nao
	int left_cell = (int)(x / GRID_CELL_WIDTH);
	int top_cell = (int)(y / GRID_CELL_HEIGHT);
	int right_cell = (int)((x + width) / GRID_CELL_WIDTH);
	int bottom_cell = (int)((y + height) / GRID_CELL_HEIGHT);

	GameObject *obj = NewObject(id, type, direction, width, height, x, y);
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


GameObject *Grid::NewObject(int id, int type, int direction, int width, int height, float x, float y)
{
	switch (type)
	{
	case BRICK:
		return new Brick(x, y, width, height);
		break;
	case ARROW:
		return new Arrow(x, y,width,height);
		break;
	case BOB:
		return new Bob(x, y, width, height);
		break;
	case MOVINGBRICK:
		return new MovingBrick(x, y, width, height);
		break;
	case WALL:
		return new Wall(x, y, width, height);
		break;
	}
}


void Grid::ListObject(vector<GameObject*> &listObj)
{
	Camera *camera = Camera::GetInstance();
	//Kiem tra cell ma camera dang nam trong
	int left_cell = (int)((camera->GetPosition().x- camera->GetWidth()/2) / GRID_CELL_WIDTH);
	int right_cell = (int)((camera->GetPosition().x + camera->GetWidth()/2-1) / GRID_CELL_WIDTH);

	int top_cell = (int)((camera->GetPosition().y - camera->GetHeight() / 2)/ GRID_CELL_HEIGHT);	
	int bottom_cell = (int)((camera->GetPosition().y + camera->GetHeight()/2-1) / GRID_CELL_HEIGHT);

	//lay ds cac object ra xem no con nam trong vung camera hay khong

	vector<GameObject *> listObjNow;//DS cac object hien tai
	listObjNow = listObj;

	listObj.clear();

	//can 1 DS id cac object dang nam trong vung camera
	unordered_map<int, GameObject*> mapObj;

	for (auto x : listObjNow)
	{
		RECT gObj;
		float gLeft, gTop, gRight, gBottom;
		x->GetBoundingBox(gLeft, gTop, gRight, gBottom);
		gObj.left = gLeft;
		gObj.top = gTop;
		gObj.right = gRight;
		gObj.bottom = gBottom;
		if (camera->isContain(camera->GetBound(), gObj))// Neu nam trong vung camera
		{
			mapObj[x->GetID()] = x;//cho no vao trong ds co vi tri tai id cua no 
		}
	}

	for (int i = top_cell; i <= bottom_cell; i++)//Theo Hang
	{
		for (int j = left_cell; j <= right_cell; j++)//Theo cot
			for (int k = 0; k < cells[i][j].size(); k++)
			{
				if (mapObj.find(cells[i][j].at(k)->GetID()) == mapObj.end()) // Kiem tra da them vao mapObject hay chua
					mapObj[cells[i][j].at(k)->GetID()] = cells[i][j].at(k);
				
			}
	}

	for (auto& x : mapObj)
	{
		listObj.push_back(x.second);
	}

}

Grid::~Grid()
{

}