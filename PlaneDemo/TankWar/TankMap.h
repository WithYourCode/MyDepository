#ifndef __TANKMAP_H__
#define __TANKMAP_H__

/*
0 �հ�   1 ��ͨ����
B ����   2 �ٶȿ����
I ����   3 �ӵ������
W ǽ��L  4 BUFF����
V ǽ��R  5 ���׵���
G �ݵ�   6
R ����   7
P ���1  8
Q ���2  9
*/


/*
W��V  ��ͨ��ǽ��ռ��4����Ԫ��
I     ����ǽ��ռ��16����Ԫ��

*/

/*
��ͼ���˼�룺
1������ͼ��Ԫ����Ϣ��¼���ڴ��У�ӳ���������ͼ��ȫ��Ԫ����Ϣ��ͨ���ַ���������
2��ͨ�����кţ���ȡ��ÿ�����ӵ�Ԫ����Ϣ������Ⱦ����
3��̹�˵�λ����ϢҲ��Ҫӳ��������ڴ���


*/


class TankMap
{

public:
	TankMap();
	virtual ~TankMap();

	static char* m_map;		// ��ͼ�ڴ�

	static void InitMap();  // ��ʼ����ͼ

	// ���õ�ͼ������
	static void SetMap(int x, int y, char value);

	static char GetMap(int x, int y);

	static void SetWall26(int x, int y);

	static void SetWall13(int x, int y);

	static void test();

	// ����̹�˵�λ��
	static void SetBigCell(int x, int y, char value);

	static void SetBase();  //���û���

	static void Stage1();   //��һ��

	static void Stage2();   //�ڶ���

	static void SetStage(int stage);    //���ùؿ�
};

#endif //__TANKMAP_H__
