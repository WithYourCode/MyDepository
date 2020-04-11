#include "TankMap.h"
#include "Configure.h"

char *TankMap::m_map = new char[CELL_NUMBER*CELL_NUMBER];//104x104

TankMap::TankMap()
{

}


TankMap::~TankMap()
{
	if (m_map != nullptr)
	{
		delete[] m_map;
		m_map = nullptr;
	}
}

void TankMap::InitMap()
{
	for (int i = 0; i < CELL_NUMBER * CELL_NUMBER; i++)
	{
		m_map[i] = 0;
	}
}

void TankMap::SetMap(int x, int y, char value)
{
	m_map[y*CELL_NUMBER + x] = value;
}

char TankMap::GetMap(int x, int y)
{
	return m_map[y*CELL_NUMBER + x];
}

void TankMap::SetWall26(int x, int y)
{
	SetMap(x, y, 'W');
	SetMap(x + 2, y, 'V');
	SetMap(x, y + 2, 'V');
	SetMap(x + 2, y + 2, 'W');
}

void TankMap::SetWall13(int x, int y)
{
	SetWall26(x, y);
	SetWall26(x + 4, y);
	SetWall26(x, y + 4);
	SetWall26(x + 4, y + 4);
}

void TankMap::test()
{
	SetBase();

	SetMap(100, 100, 'W');
	SetMap(99, 100, 'I');
}

void TankMap::SetBigCell(int x, int y, char value)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			SetMap(x + j, y + i, value);
		}
	}
}

void TankMap::SetBase()
{
	SetWall26(22 * 2, 46 * 2);
	SetWall26(2 * 22, 48 * 2);
	SetWall26(22 * 2, 50 * 2);

	SetWall26(28 * 2, 46 * 2);
	SetWall26(28 * 2, 48 * 2);
	SetWall26(28 * 2, 50 * 2);

	SetWall26(24 * 2, 46 * 2);
	SetWall26(26 * 2, 46 * 2);

	SetMap(24 * 2, 48 * 2, 'B');
}

void TankMap::Stage1()
{
	SetBase();

	SetWall26(8, 8);
	SetWall26(12, 8);
	SetWall26(24, 8);
	SetWall26(28, 8);
	SetWall26(40, 8);
	SetWall26(44, 8);
	SetWall26(56, 8);
	SetWall26(60, 8);
	SetWall26(72, 8);
	SetWall26(76, 8);
	SetWall26(88, 8);
	SetWall26(92, 8);
	SetWall26(8, 12);
	SetWall26(12, 12);
	SetWall26(24, 12);
	SetWall26(28, 12);
	SetWall26(40, 12);
	SetWall26(44, 12);
	SetWall26(56, 12);
	SetWall26(60, 12);
	SetWall26(72, 12);
	SetWall26(76, 12);
	SetWall26(88, 12);
	SetWall26(92, 12);
	SetWall26(8, 16);
	SetWall26(12, 16);
	SetWall26(24, 16);
	SetWall26(28, 16);
	SetWall26(40, 16);
	SetWall26(44, 16);
	SetWall26(56, 16);
	SetWall26(60, 16);
	SetWall26(72, 16);
	SetWall26(76, 16);
	SetWall26(88, 16);
	SetWall26(92, 16);
	SetWall26(8, 20);
	SetWall26(12, 20);
	SetWall26(24, 20);
	SetWall26(28, 20);
	SetWall26(40, 20);
	SetWall26(44, 20);
	SetWall26(56, 20);
	SetWall26(60, 20);
	SetWall26(72, 20);
	SetWall26(76, 20);
	SetWall26(88, 20);
	SetWall26(92, 20);
	SetWall26(8, 24);
	SetWall26(12, 24);
	SetWall26(24, 24);
	SetWall26(28, 24);
	SetWall26(40, 24);
	SetWall26(44, 24);
	SetMap(48, 24, 'I');
	SetMap(52, 24, 'I');
	SetWall26(56, 24);
	SetWall26(60, 24);
	SetWall26(72, 24);
	SetWall26(76, 24);
	SetWall26(88, 24);
	SetWall26(92, 24);
	SetWall26(8, 28);
	SetWall26(12, 28);
	SetWall26(24, 28);
	SetWall26(28, 28);
	SetWall26(40, 28);
	SetWall26(44, 28);
	SetMap(48, 28, 'I');
	SetMap(52, 28, 'I');
	SetWall26(56, 28);
	SetWall26(60, 28);
	SetWall26(72, 28);
	SetWall26(76, 28);
	SetWall26(88, 28);
	SetWall26(92, 28);
	SetWall26(8, 32);
	SetWall26(12, 32);
	SetWall26(24, 32);
	SetWall26(28, 32);
	SetWall26(40, 32);
	SetWall26(44, 32);
	SetWall26(56, 32);
	SetWall26(60, 32);
	SetWall26(72, 32);
	SetWall26(76, 32);
	SetWall26(88, 32);
	SetWall26(92, 32);
	SetWall26(8, 36);
	SetWall26(12, 36);
	SetWall26(24, 36);
	SetWall26(28, 36);
	SetWall26(72, 36);
	SetWall26(76, 36);
	SetWall26(88, 36);
	SetWall26(92, 36);
	SetWall26(8, 40);
	SetWall26(12, 40);
	SetWall26(24, 40);
	SetWall26(28, 40);
	SetWall26(72, 40);
	SetWall26(76, 40);
	SetWall26(88, 40);
	SetWall26(92, 40);
	SetWall26(40, 44);
	SetWall26(44, 44);
	SetWall26(56, 44);
	SetWall26(60, 44);
	SetWall26(40, 48);
	SetWall26(44, 48);
	SetWall26(56, 48);
	SetWall26(60, 48);
	SetWall26(0, 52);
	SetWall26(4, 52);
	SetWall26(16, 52);
	SetWall26(20, 52);
	SetWall26(24, 52);
	SetWall26(28, 52);
	SetWall26(72, 52);
	SetWall26(76, 52);
	SetWall26(80, 52);
	SetWall26(84, 52);
	SetWall26(96, 52);
	SetWall26(100, 52);
	SetMap(0, 56, 'I');
	SetMap(4, 56, 'I');
	SetWall26(16, 56);
	SetWall26(20, 56);
	SetWall26(24, 56);
	SetWall26(28, 56);
	SetWall26(72, 56);
	SetWall26(76, 56);
	SetWall26(80, 56);
	SetWall26(84, 56);
	SetMap(96, 56, 'I');
	SetMap(100, 56, 'I');
	SetWall26(40, 60);
	SetWall26(44, 60);
	SetWall26(56, 60);
	SetWall26(60, 60);
	SetWall26(40, 64);
	SetWall26(44, 64);
	SetWall26(48, 64);
	SetWall26(52, 64);
	SetWall26(56, 64);
	SetWall26(60, 64);
	SetWall26(8, 68);
	SetWall26(12, 68);
	SetWall26(24, 68);
	SetWall26(28, 68);
	SetWall26(40, 68);
	SetWall26(44, 68);
	SetWall26(48, 68);
	SetWall26(52, 68);
	SetWall26(56, 68);
	SetWall26(60, 68);
	SetWall26(72, 68);
	SetWall26(76, 68);
	SetWall26(88, 68);
	SetWall26(92, 68);
	SetWall26(8, 72);
	SetWall26(12, 72);
	SetWall26(24, 72);
	SetWall26(28, 72);
	SetWall26(40, 72);
	SetWall26(44, 72);
	SetWall26(56, 72);
	SetWall26(60, 72);
	SetWall26(72, 72);
	SetWall26(76, 72);
	SetWall26(88, 72);
	SetWall26(92, 72);
	SetWall26(8, 76);
	SetWall26(12, 76);
	SetWall26(24, 76);
	SetWall26(28, 76);
	SetWall26(40, 76);
	SetWall26(44, 76);
	SetWall26(56, 76);
	SetWall26(60, 76);
	SetWall26(72, 76);
	SetWall26(76, 76);
	SetWall26(88, 76);
	SetWall26(92, 76);
	SetWall26(8, 80);
	SetWall26(12, 80);
	SetWall26(24, 80);
	SetWall26(28, 80);
	SetWall26(40, 80);
	SetWall26(44, 80);
	SetWall26(56, 80);
	SetWall26(60, 80);
	SetWall26(72, 80);
	SetWall26(76, 80);
	SetWall26(88, 80);
	SetWall26(92, 80);
	SetWall26(8, 84);
	SetWall26(12, 84);
	SetWall26(24, 84);
	SetWall26(28, 84);
	SetWall26(72, 84);
	SetWall26(76, 84);
	SetWall26(88, 84);
	SetWall26(92, 84);
	SetWall26(8, 88);
	SetWall26(12, 88);
	SetWall26(24, 88);
	SetWall26(28, 88);
	SetWall26(72, 88);
	SetWall26(76, 88);
	SetWall26(88, 88);
	SetWall26(92, 88);
	SetWall26(8, 92);
	SetWall26(12, 92);
	SetWall26(24, 92);
	SetWall26(28, 92);
	SetWall26(72, 92);
	SetWall26(76, 92);
	SetWall26(88, 92);
	SetWall26(92, 92);
}

void TankMap::Stage2()
{
	SetBase();

	SetMap(24, 0, 'I');
	SetMap(28, 0, 'I');
	SetMap(56, 0, 'I');
	SetMap(60, 0, 'I');
	SetMap(24, 4, 'I');
	SetMap(28, 4, 'I');
	SetMap(56, 4, 'I');
	SetMap(60, 4, 'I');
	SetWall26(8, 8);
	SetWall26(12, 8);
	SetMap(24, 8, 'I');
	SetMap(28, 8, 'I');
	SetWall26(56, 8);
	SetWall26(60, 8);
	SetWall26(72, 8);
	SetWall26(76, 8);
	SetWall26(88, 8);
	SetWall26(92, 8);
	SetWall26(8, 12);
	SetWall26(12, 12);
	SetMap(24, 12, 'I');
	SetMap(28, 12, 'I');
	SetWall26(56, 12);
	SetWall26(60, 12);
	SetWall26(72, 12);
	SetWall26(76, 12);
	SetWall26(88, 12);
	SetWall26(92, 12);
	SetWall26(8, 16);
	SetWall26(12, 16);
	SetWall26(48, 16);
	SetWall26(52, 16);
	SetWall26(56, 16);
	SetWall26(60, 16);
	SetWall26(72, 16);
	SetWall26(76, 16);
	SetMap(80, 16, 'I');
	SetMap(84, 16, 'I');
	SetWall26(88, 16);
	SetWall26(92, 16);
	SetWall26(8, 20);
	SetWall26(12, 20);
	SetWall26(48, 20);
	SetWall26(52, 20);
	SetWall26(56, 20);
	SetWall26(60, 20);
	SetWall26(72, 20);
	SetWall26(76, 20);
	SetMap(80, 20, 'I');
	SetMap(84, 20, 'I');
	SetWall26(88, 20);
	SetWall26(92, 20);
	SetWall26(24, 24);
	SetWall26(28, 24);
	SetMap(72, 24, 'I');
	SetMap(76, 24, 'I');
	SetWall26(24, 28);
	SetWall26(28, 28);
	SetMap(72, 28, 'I');
	SetMap(76, 28, 'I');
	SetMap(0, 32, 'G');
	SetMap(4, 32, 'G');
	SetWall26(24, 32);
	SetWall26(28, 32);
	SetMap(48, 32, 'I');
	SetMap(52, 32, 'I');
	SetWall26(72, 32);
	SetWall26(76, 32);
	SetMap(80, 32, 'G');
	SetMap(84, 32, 'G');
	SetWall26(88, 32);
	SetWall26(92, 32);
	SetMap(96, 32, 'I');
	SetMap(100, 32, 'I');
	SetMap(0, 36, 'G');
	SetMap(4, 36, 'G');
	SetWall26(24, 36);
	SetWall26(28, 36);
	SetMap(48, 36, 'I');
	SetMap(52, 36, 'I');
	SetWall26(72, 36);
	SetWall26(76, 36);
	SetMap(80, 36, 'G');
	SetMap(84, 36, 'G');
	SetWall26(88, 36);
	SetWall26(92, 36);
	SetMap(96, 36, 'I');
	SetMap(100, 36, 'I');
	SetMap(0, 40, 'G');
	SetMap(4, 40, 'G');
	SetMap(8, 40, 'G');
	SetMap(12, 40, 'G');
	SetWall26(40, 40);
	SetWall26(44, 40);
	SetMap(64, 40, 'I');
	SetMap(68, 40, 'I');
	SetMap(80, 40, 'G');
	SetMap(84, 40, 'G');
	SetMap(0, 44, 'G');
	SetMap(4, 44, 'G');
	SetMap(8, 44, 'G');
	SetMap(12, 44, 'G');
	SetWall26(40, 44);
	SetWall26(44, 44);
	SetMap(64, 44, 'I');
	SetMap(68, 44, 'I');
	SetMap(80, 44, 'G');
	SetMap(84, 44, 'G');
	SetWall26(8, 48);
	SetWall26(12, 48);
	SetWall26(16, 48);
	SetWall26(20, 48);
	SetWall26(24, 48);
	SetWall26(28, 48);
	SetMap(32, 48, 'G');
	SetMap(36, 48, 'G');
	SetMap(40, 48, 'G');
	SetMap(44, 48, 'G');
	SetMap(48, 48, 'G');
	SetMap(52, 48, 'G');
	SetMap(56, 48, 'I');
	SetMap(60, 48, 'I');
	SetMap(80, 48, 'G');
	SetMap(84, 48, 'G');
	SetWall26(88, 48);
	SetWall26(92, 48);
	SetWall26(8, 52);
	SetWall26(12, 52);
	SetWall26(16, 52);
	SetWall26(20, 52);
	SetWall26(24, 52);
	SetWall26(28, 52);
	SetMap(32, 52, 'G');
	SetMap(36, 52, 'G');
	SetMap(40, 52, 'G');
	SetMap(44, 52, 'G');
	SetMap(48, 52, 'G');
	SetMap(52, 52, 'G');
	SetMap(56, 52, 'I');
	SetMap(60, 52, 'I');
	SetMap(80, 52, 'G');
	SetMap(84, 52, 'G');
	SetWall26(88, 52);
	SetWall26(92, 52);
	SetMap(24, 56, 'I');
	SetMap(28, 56, 'I');
	SetMap(32, 56, 'G');
	SetMap(36, 56, 'G');
	SetWall26(40, 56);
	SetWall26(44, 56);
	SetWall26(56, 56);
	SetWall26(60, 56);
	SetWall26(72, 56);
	SetWall26(76, 56);
	SetWall26(88, 56);
	SetWall26(92, 56);
	SetMap(24, 60, 'I');
	SetMap(28, 60, 'I');
	SetMap(32, 60, 'G');
	SetMap(36, 60, 'G');
	SetWall26(40, 60);
	SetWall26(44, 60);
	SetWall26(56, 60);
	SetWall26(60, 60);
	SetWall26(72, 60);
	SetWall26(76, 60);
	SetWall26(88, 60);
	SetWall26(92, 60);
	SetMap(0, 64, 'I');
	SetMap(4, 64, 'I');
	SetWall26(8, 64);
	SetWall26(12, 64);
	SetMap(24, 64, 'I');
	SetMap(28, 64, 'I');
	SetWall26(40, 64);
	SetWall26(44, 64);
	SetWall26(56, 64);
	SetWall26(60, 64);
	SetWall26(88, 64);
	SetWall26(92, 64);
	SetMap(0, 68, 'I');
	SetMap(4, 68, 'I');
	SetWall26(8, 68);
	SetWall26(12, 68);
	SetMap(24, 68, 'I');
	SetMap(28, 68, 'I');
	SetWall26(40, 68);
	SetWall26(44, 68);
	SetWall26(56, 68);
	SetWall26(60, 68);
	SetWall26(88, 68);
	SetWall26(92, 68);
	SetWall26(8, 72);
	SetWall26(12, 72);
	SetWall26(24, 72);
	SetWall26(28, 72);
	SetWall26(40, 72);
	SetWall26(44, 72);
	SetWall26(48, 72);
	SetWall26(52, 72);
	SetWall26(56, 72);
	SetWall26(60, 72);
	SetWall26(72, 72);
	SetWall26(76, 72);
	SetMap(80, 72, 'I');
	SetMap(84, 72, 'I');
	SetWall26(88, 72);
	SetWall26(92, 72);
	SetWall26(8, 76);
	SetWall26(12, 76);
	SetWall26(24, 76);
	SetWall26(28, 76);
	SetWall26(40, 76);
	SetWall26(44, 76);
	SetWall26(48, 76);
	SetWall26(52, 76);
	SetWall26(56, 76);
	SetWall26(60, 76);
	SetWall26(72, 76);
	SetWall26(76, 76);
	SetMap(80, 76, 'I');
	SetMap(84, 76, 'I');
	SetWall26(88, 76);
	SetWall26(92, 76);
	SetWall26(8, 80);
	SetWall26(12, 80);
	SetWall26(24, 80);
	SetWall26(28, 80);
	SetWall26(40, 80);
	SetWall26(44, 80);
	SetWall26(48, 80);
	SetWall26(52, 80);
	SetWall26(56, 80);
	SetWall26(60, 80);
	SetWall26(8, 84);
	SetWall26(12, 84);
	SetWall26(24, 84);
	SetWall26(28, 84);
	SetWall26(40, 84);
	SetWall26(44, 84);
	SetWall26(48, 84);
	SetWall26(52, 84);
	SetWall26(56, 84);
	SetWall26(60, 84);
	SetWall26(8, 88);
	SetWall26(12, 88);
	SetWall26(72, 88);
	SetWall26(76, 88);
	SetWall26(88, 88);
	SetWall26(92, 88);
	SetWall26(8, 92);
	SetWall26(12, 92);
	SetWall26(72, 92);
	SetWall26(76, 92);
	SetWall26(88, 92);
	SetWall26(92, 92);
	SetWall26(8, 96);
	SetWall26(12, 96);
	SetWall26(24, 96);
	SetWall26(28, 96);
	SetWall26(72, 96);
	SetWall26(76, 96);
	SetWall26(80, 96);
	SetWall26(84, 96);
	SetWall26(88, 96);
	SetWall26(92, 96);
	SetWall26(8, 100);
	SetWall26(12, 100);
	SetWall26(24, 100);
	SetWall26(28, 100);
	SetWall26(72, 100);
	SetWall26(76, 100);
	SetWall26(80, 100);
	SetWall26(84, 100);
	SetWall26(88, 100);
	SetWall26(92, 100);
}

void TankMap::SetStage(int stage)
{
	switch (stage)
	{
	case 1:
		Stage1();
		//test();
		break;
	case 2:
		Stage2();
		break;
	default:
		break;
	}
}
