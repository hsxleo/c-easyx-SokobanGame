
////////////////////////////////////////////////////////////
//��Ϸ����0��ʾ�յأ�1��ʾ���2��ʾ���ӣ�3��ʾĿ�ĵأ�6��ʾΧǽ
//
//���زĵ�x1��y1���Ƿ��ģ���Ϊx��ʾ��,���ǻ�����x��ʾ�У�yͬ
////////////////////////////////////////////////////////////

#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#pragma comment(lib,"Winmm.lib")  //��ӵı�������*******************************

int map[5][9][9] = {										//������ά��ͼ����
	
					{	{0},
						{0, 0, 6, 6, 6},
						{0, 0, 6, 3, 6},
						{0, 0, 6, 0, 6, 6, 6, 6},
						{6, 6, 6, 2, 0, 2, 3, 6},
						{6, 3, 0, 2, 1, 6, 6, 6},
						{6, 6, 6, 6, 2, 6},
						{0, 0, 0, 6, 3, 6},
						{0, 0, 0, 6, 6, 6} 
					},

					{	{6, 6, 6, 6, 6},
						{6, 1, 0, 0, 6},
						{6, 0, 2, 2, 6, 0, 6, 6, 6},
						{6, 0, 2, 0, 6, 0, 6, 3, 6},
						{6, 6, 6, 0, 6, 6, 6, 3, 6},
						{0, 6, 6, 0, 0, 0, 0, 3, 6},
						{0, 6, 0, 0, 0, 6, 0, 0, 6},
						{0, 6, 0, 0, 0, 6, 6, 6, 6},
						{0, 6, 6, 6, 6, 6} 
					},

					{	{0, 6, 6, 6, 6},
						{0, 6, 1, 0, 6, 6, 6},
						{0, 6, 0, 2, 0, 0, 6},
						{6, 6, 6, 0, 6, 0, 6, 6},
						{6, 3, 6, 0, 6, 0, 0, 6},
						{6, 3, 2, 0, 0, 6, 0, 6},
						{6, 3, 0, 0, 0, 2, 0, 6},
						{6, 6, 6, 6, 6, 6, 6, 6} 
					},

					{	{0, 6, 6, 6, 6, 6, 6, 6},
						{0, 6, 0, 1, 3, 3, 3, 6},
						{0, 6, 0, 0, 0, 6, 6, 6, 6},
						{6, 6, 6, 2, 0, 0, 0, 0, 6},
						{6, 0, 0, 0, 6, 2, 6, 0, 6},
						{6, 0, 2, 0, 6, 0, 0, 0, 6},
						{6, 0, 0, 0, 6, 6, 6, 6, 6},
						{6, 6, 6, 6, 6} 
					},

					{
						{0},
						{0, 0, 6, 6, 6, 6, 0},
						{0, 6, 6, 0, 0, 6, 0},
						{0, 6, 1, 2, 0, 6, 0},
						{0, 6, 6, 2, 0, 6, 6},
						{0, 6, 6, 0, 2, 0, 6},
						{0, 6, 3, 2, 0, 0, 6},
						{0, 6, 3, 3, 5, 3, 6},
						{0, 6, 6, 6, 6, 6, 6},
					},

					
};

int x, y;							//��������
int loop;							//����ȫ�ֱ��������Ƿ����¿�ʼ
IMAGE img[10];                     	//����IMAGE��������������ͼƬ


/*******************��������*******************/
void drawBlank(int x1, int y1);	            //���յ�
void drawDest(int x1, int y1);				//��Ŀ�ĵ�
void drawWall(int x1, int y1);	            //��Χǽ

void drawBlankDoraemon(int x1, int y1);     //���յ��ϵ�����
void drawDestDoraemon(int x1, int y1);	    //��Ŀ�ĵ��ϵ�����
void drawWinDoraemon(int x1, int y1);		//��ʤ��������

void drawBlankBox(int x1, int y1);	        //���յ��ϵ�����
void drawDestBox(int x1, int y1);			//����Ŀ�ĵ��ϵ�����
void drawMap(int a[][15]);					//�ѵ�ͼ����ȫ������

void move(int a[][15], int x1, int y1);		//�ƶ�
void find(int a[][15]);						//����������
int  isWin(int a[][15]);					//�ж���Ϸ�Ƿ����
int  playGame(int a[][15]);					//��Ϸ����
void gameLevel();							//��Ϸ�ؿ�

void beginMenu();							//��ʼ�˵�
void overMenu();							//�����˵�


//���յ�
void drawBlank(int x1, int y1)
{
	putimage(y1, x1, &img[0]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//������
void drawBlankDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[1]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//������
void drawBlankBox(int x1, int y1)
{
	putimage(y1, x1, &img[2]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//��Ŀ�ĵ�
void drawDest(int x1, int y1)
{
	putimage(y1, x1, &img[3]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//����Ŀ�ĵ��ϵ�����
void drawDestDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[4]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//����Ŀ�ĵ��ϵ�����
void drawDestBox(int x1, int y1)
{
	putimage(y1, x1, &img[5]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//��Χǽ
void drawWall(int x1, int y1)
{
	putimage(y1, x1, &img[6]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//��ʤ��������
void drawWinDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[7]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//���������ȫ������
void drawMap(int a[][9])
{
	for (int x1 = 0; x1 < 9; x1++)
		for (int y1 = 0; y1 < 9; y1++)
			putimage(60 * y1, 60 * x1, &img[a[x1][y1]]);
}

//�ƶ�
void move(int a[][9], int x1, int y1)
{
	if (a[x + x1][y + y1] == 0 || a[x + x1][y + y1] == 3)
	{
		a[x][y]--;
		a[x + x1][y + y1]++;
		for (int i = 0; i < 60; i++)     //�ƶ���ͼ����
		{
			BeginBatchDraw();  
			drawBlank(60 * x + i * x1, 60 * y + i * y1);				//����
			drawBlankDoraemon(60 * x + (i + 1) * x1, 60 * y + (i + 1) * y1);
			Sleep(1);												//Ϊ�˽���CPU�ұ�������
			EndBatchDraw();
		}
		if (a[x][y] == 3)    //�����Ŀ�ĵ����뿪
			drawDest(60 * x, 60 * y);
		x += x1;
		y += y1;
		if (a[x][y] == 4)     //���ﵽĿ�ĵ���
			drawDestDoraemon(60 * x, 60 * y);
	}
	else if ((a[x + x1][y + y1] == 2 || a[x + x1][y + y1] == 5) && (a[x + 2 * x1][y + 2 * y1] == 0 || a[x + 2 * x1][y + 2 * y1] == 3))
	{
		a[x][y]--;
		a[x + x1][y + y1]--;
		a[x + 2 * x1][y + 2 * y1] += 2;
		for (int i = 0; i < 60; i++)
		{
			BeginBatchDraw();
			drawBlank(60 * (x + x1) + i * x1, 60 * (y + y1) + i * y1);	        //����
			drawBlankBox(60 * (x + x1) + (i + 1) * x1, 60 * (y + y1) + (i + 1) * y1);
			drawBlank(60 * x + i * x1, 60 * y + i * y1);						//����
			drawBlankDoraemon(60 * x + (i + 1) * x1, 60 * y + (i + 1) * y1);
			Sleep(1);				//Ϊ�˽���CPU�ұ�������
			EndBatchDraw();
		}
		if (a[x][y] == 3)
			drawDest(60 * x, 60 * y);
		x += x1;
		y += y1;
		if (a[x][y] == 4)
			drawDestDoraemon(60 * x, 60 * y);
		if (a[x + x1][y + y1] == 5)
			drawDestBox(60 * (x + x1), 60 * (y + y1));
	}
}

//��x,y����������
void find(int a[][9])
{
	//ѭ�����������ҵ���������
	for (x = 0; x < 9; x++)
	{
		for (y = 0; y < 9; y++)
		{
			if (a[x][y] == 1)
			{
				return;
			}

		}
	}
}

//�ж���Ϸ�Ƿ����
int isWin(int a[][9])
{
	//ѭ����ͼ��������û���ڿյ��ϵ�����
	for (int x1 = 0; x1 < 9; x1++)
	{
		for (int y1 = 0; y1 < 9; y1++)
		{
			if (a[x1][y1] == 2)
			{
				return 0;	//����������ӷ��ؼ�
			}
		}

	}
	
	return 1;		//���û�����ӷ�����										
}

//��Ϸ����
int playGame(int a[][9])
{
	loop = 0;
	drawMap(a);     //����ÿһ�صĲ���
	find(a);		//ͨ��find����Ѱ�������x, y����
	do
	{
		switch (_getch())										//��ȡ����
		{
		case 'w':
		case 'W':
			move(a, -1, 0);		//����
			break;				 
		case 'a':
		case 'A':
			move(a, 0, -1);		//���� 
			break;				
		case 'd':
		case 'D':
			move(a, 0, 1);		//����
			break;				 
		case 's':
		case 'S':
			move(a, 1, 0);		//����
			break;				 
		case 'r':
		case 'R':
		case ' ':
			loop = 1;			//���¿�ʼ��ǰ�� 
			return 0;				
		case  27:
			exit(0);			//������Ϸ 
			break;					
		case 0xE0:						//����Ƿ���� 
			switch (_getch())								//�ٴλ�ȡ���� 
			{
			case 72:
				move(a, -1, 0);	//����
				break;          
			case 75:
				move(a, 0, -1);	//����
				break;          
			case 77:
				move(a, 0, 1); 	//����
				break;          
			case 80:
				move(a, 1, 0);  //����
				break;           
			}
		}
	} while (!isWin(a));								//ͨ��isWin�����ж��Ƿ�ͨ��
	drawWinDoraemon(60 * x, 60 * y);				//��һ��ʤ��������
	_getch();                                       //��ͣ�ȴ��û�����  ������һ��
	return 0;
}

//��Ϸ�ؿ�
void gameLevel()
{
	int b[9][9];				//���õ�ǰ��ͼ���� 
	for (int i = 0; i < 5; i++)
	{
		do
		{
			loop = 0;				//loop��Ϊ0
			for (int x1 = 0; x1 < 9; x1++)
			{
				for (int y1 = 0; y1 < 9; y1++)
				{
					b[x1][y1] = map[i][x1][y1];			//�Ե�ǰ��ͼ����ֱ�ֵ 
				}
			}	
			playGame(b);
		} while (loop);					//���loop����Ϊ1�����¿�ʼ
	}
	overMenu();  //�����˵�
}

//��ʼ�˵�
void beginMenu()
{
	//��ʼ������
	initgraph(540, 540);
	//�˵�����
	putimage(0, 0, &img[8]);

	//�����ʽ
	settextstyle(30, 0, "������κ");//����������ʽ����Ϊ30
	setbkmode(TRANSPARENT);     //���ֱ���͸��
	settextcolor(WHITE);    //���õ�ǰ���ֵ���ɫ	
	//������溺��
	outtextxy(40, 500, "��ʼ��Ϸ");//���ú�����ָ��λ������ַ���
	outtextxy(390, 500, "�˳���Ϸ");

	//��꽻��
	MOUSEMSG m;
	while (1)
	{
		//��ȡ���λ��
		m = GetMouseMsg();

		//�ж����λ��
		settextcolor(RED);     //�����ʱ����ɫ
		if (m.x >= 40 && m.x <= 160 && m.y >= 500 && m.y <= 530)
		{
			outtextxy(40, 500, "��ʼ��Ϸ");
			//������  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				gameLevel();
			}
		}
		else if (m.x >= 390 && m.x <= 510 && m.y >= 500 && m.y <= 530)
		{
			outtextxy(390, 500, "�˳���Ϸ");
			//������  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else       //������ɫ��ԭ��������������ĵط���
		{
			settextcolor(WHITE);    //���õ�ǰ���ֵ���ɫ	
			outtextxy(40, 500, "��ʼ��Ϸ");
			outtextxy(390, 500, "�˳���Ϸ");
		}
	}
}

//�����˵�
void overMenu()
{
	//��ʼ������
	initgraph(540, 540);
	//�˵�����
	putimage(0, 0, &img[9]);

	//��������
	putimage(130, 60, &img[3]);
	putimage(230, 60, &img[3]);
	putimage(330, 60, &img[3]);
	//������ʾ
	settextstyle(30, 0, "������κ");//����������ʽ����Ϊ30
	setbkmode(TRANSPARENT);     //���ֱ���͸��
	settextcolor(BLACK);    //���õ�ǰ���ֵ���ɫ	

	//������ӵ�Կ��
	int i;
	for (i = -60; i <= 130; i += 5)
	{
		BeginBatchDraw();  //˫�����ͼ
		putimage(i, 120, &img[2]);
		Sleep(100);
		putimage(i - 60, 120, &img[0]);  //����һ���߹���·��
		EndBatchDraw();
	}

	//�ұ����ӵ�Կ��
	for (i = 540; i >= 330; i -= 5)
	{
		BeginBatchDraw();  //˫�����ͼ
		putimage(i, 120, &img[2]);
		Sleep(100);
		putimage(i + 60, 120, &img[0]);  //����һ���߹���·��
		EndBatchDraw();
	}

	//�м����ӵ�Կ��
	for (i = 540; i >= 120; i -= 10)
	{
		BeginBatchDraw();  //˫�����ͼ
		putimage(230, i, &img[2]);
		Sleep(60);
		putimage(230, i + 60, &img[0]);  //����һ���߹���·��
		EndBatchDraw();
	}


	outtextxy(150, 230, "����,��������");
	//���Կ�״򿪱���
	MOUSEMSG m;
	int key[3] = { 1,1,1 };  //Կ��  1Ϊ��  0Ϊû��
	int key_flg = 0;
	while (1)
	{
		//��ȡ���λ��
		m = GetMouseMsg();

		//��ߵ�Կ��
		if (m.x >= 130 && m.x <= 190 && m.y >= 120 && m.y <= 180)
		{
			//�����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[0] = 0;
				//�������Կ��
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(130, i, &img[0]);
				}
				//�����������
				putimage(130, 60, &img[5]);
			}
		}
		//�м��Կ��
		else if (m.x >= 230 && m.x <= 290 && m.y >= 120 && m.y <= 180)
		{
			//�����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[1] = 0;
				//�����м�Կ��
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(230, i, &img[0]);
				}
				//�����м�����
				putimage(230, 60, &img[5]);
			}
		}
		//�ұߵ�Կ��
		else if (m.x >= 330 && m.x <= 390 && m.y >= 120 && m.y <= 180)
		{
			//�����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[2] = 0;
				//�����ұ�Կ��
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(330, i, &img[0]);
				}
				//�����ұ�����
				putimage(330, 60, &img[5]);
			}
		}
		key_flg = 0;
		for (i = 0; i < 3; i++)
		{
			if (key[i] != 0)
			{
				key_flg = 1;
				break;
			}
		}
		if (key_flg == 1)
		{
			continue;
		}
		else
		{
			break;
		}

	}

	//��������
	putimage(150, 200, &img[0]);
	putimage(200, 200, &img[0]);
	putimage(250, 200, &img[0]);
	putimage(300, 200, &img[0]);
	outtextxy(165, 200, "�ɹ���ñ���");

	outtextxy(100, 350, "���¿�ʼ");
	outtextxy(300, 350, "�˳���Ϸ");

	//��꽻��
	while (1)
	{
		//��ȡ���λ��
		m = GetMouseMsg();

		//�ж����λ��
		settextcolor(RED);     //�����ʱ����ɫ
		if (m.x >= 100 && m.x <= 220 && m.y >= 350 && m.y <= 380)
		{
			outtextxy(100, 350, "���¿�ʼ");
			//������  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				gameLevel();
			}
		}
		else if (m.x >= 300 && m.x <= 420 && m.y >= 350 && m.y <= 380)
		{
			outtextxy(300, 350, "�˳���Ϸ");
			//������  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else       //������ɫ��ԭ��������������ĵط���
		{
			settextcolor(WHITE);
			outtextxy(100, 350, "���¿�ʼ");
			outtextxy(300, 350, "�˳���Ϸ");
		}
	}
}

//������
int main()
{
	//��������
	mciSendString("open music.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
	//����ͼƬ��Դ
	loadimage(&img[0], "image\\0.jpg", 60, 60);
	loadimage(&img[1], "image\\1.jpg", 60, 60);
	loadimage(&img[2], "image\\2.jpg", 60, 60);
	loadimage(&img[3], "image\\3.jpg", 60, 60);
	loadimage(&img[4], "image\\4.jpg", 60, 60);
	loadimage(&img[5], "image\\5.jpg", 60, 60);
	loadimage(&img[6], "image\\6.jpg", 60, 60);
	loadimage(&img[7], "image\\7.jpg", 60, 60);
	loadimage(&img[8], "image\\8.jpg", 540, 540);
	loadimage(&img[9], "image\\9.jpg", 540, 540);

	//��ʼ�˵�
	beginMenu();
	return 0;
}

