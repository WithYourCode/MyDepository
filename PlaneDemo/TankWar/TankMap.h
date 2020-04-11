#ifndef __TANKMAP_H__
#define __TANKMAP_H__

/*
0 空白   1 普通敌人
B 基地   2 速度快敌人
I 钢铁   3 子弹快敌人
W 墙壁L  4 BUFF敌人
V 墙壁R  5 护甲敌人
G 草地   6
R 河流   7
P 玩家1  8
Q 玩家2  9
*/


/*
W、V  普通红墙，占据4个单元格
I     钢铁墙，占据16个单元格

*/

/*
地图设计思想：
1、将地图的元素信息记录在内存中，映射出整个地图的全部元素信息，通过字符串来设置
2、通过行列号，读取出每个格子的元素信息，再渲染出来
3、坦克的位置信息也需要映射在这块内存中


*/


class TankMap
{

public:
	TankMap();
	virtual ~TankMap();

	static char* m_map;		// 地图内存

	static void InitMap();  // 初始化地图

	// 设置地图的属性
	static void SetMap(int x, int y, char value);

	static char GetMap(int x, int y);

	static void SetWall26(int x, int y);

	static void SetWall13(int x, int y);

	static void test();

	// 设置坦克的位置
	static void SetBigCell(int x, int y, char value);

	static void SetBase();  //设置基地

	static void Stage1();   //第一关

	static void Stage2();   //第二关

	static void SetStage(int stage);    //设置关卡
};

#endif //__TANKMAP_H__
