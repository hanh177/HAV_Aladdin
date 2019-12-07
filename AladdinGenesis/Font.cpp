#include "Font.h"

Font * Font::_instance = NULL;

Font::Font()
{
}


Font::~Font()
{
}

Font * Font::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Font();
	}
	return _instance;
}

void Font::Draw(float x, float y, const string & s)
{
	CTexture * texture = CTexture::GetInstance();
	LPDIRECT3DTEXTURE9 tex = texture->Get(Type::ALADIN2);
	CGame *mGame = CGame::GetInstance();
	for (UINT i = 0; i < s.size(); i++)
	{
		int number = s[i] - '0';
		switch (number)
		{
		case 0:
			Set(359, 3594, 366, 3601);
			break;
		case 1:
			Set(371, 3594, 374, 3601);
			break;
		case 2:
			Set(379, 3594, 384, 3601);
			break;
		case 3:
			Set(389, 3594, 393, 3601);
			break;
		case 4:
			Set(398, 3594, 404, 3601);
			break;
		case 5:
			Set(409, 3594, 414, 3601);
			break;
		case 6:
			Set(419, 3594, 425, 3601);
			break;
		case 7:
			Set(430, 3594, 435, 3601);
			break;
		case 8:
			Set(439, 3594, 444, 3601);
			break;
		case 9:
			Set(449, 3594, 455, 3601);
			break;

		}
		mGame->Draw(x + 20.0f + i * 8, y, tex, left, top, right, bottom, 0, D3DXVECTOR2(0, 0));

	}
}

void Font::Set(int left, int top, int right, int bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}
