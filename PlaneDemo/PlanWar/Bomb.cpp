#include "Bomb.h"
#include "Config.h"


Bomb::Bomb()
{
	// ��ʼ����ըͼƬ
	for (int i = 0; i < BOMB_MAX; i++)
	{
		QString str = QString(BOMB_PATH).arg(i);
		m_pixmaps.push_back(QPixmap(str));
	}

	m_X = 0;
	m_Y = 0;
	m_Free = true;
	m_index = 0;
}


Bomb::~Bomb()
{
}

void Bomb::UpdatePosition()
{
	//����״̬
	if (m_Free)
		return;

	m_Record++;
	if (m_Record < BOMB_INTERVAL)
	{
		//��¼��ը���δ����ֱ��return������Ҫ��ͼ
		return;
	}
	//���ü�¼
	m_Record = 0;

	//�л���ը����ͼƬ
	m_index++;
	//ע�������е��±��0��ʼ�������6
	//���������±����6������Ϊ0
	if (m_index > BOMB_MAX - 1)
	{
		m_index = 0;
		m_Free = true;
	}
}

void Bomb::PaintPixmap(QPainter& painter)
{
	if (m_Free == false)
	{
		painter.drawPixmap(m_X, m_Y, m_pixmaps[m_index]);
	}
}
