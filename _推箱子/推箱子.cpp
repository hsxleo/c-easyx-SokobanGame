
////////////////////////////////////////////////////////////
//游戏中用0表示空地，1表示人物，2表示箱子，3表示目的地，6表示围墙
//
//画素材的x1和y1都是反的，因为x表示行,但是画出来x表示列，y同
////////////////////////////////////////////////////////////

#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#pragma comment(lib,"Winmm.lib")  //添加的背景音乐*******************************

int map[5][9][9] = {										//定义三维地图数组
	
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

int x, y;							//人物坐标
int loop;							//定义全局变量控制是否重新开始
IMAGE img[10];                     	//定义IMAGE对象数组来保存图片


/*******************函数声明*******************/
void drawBlank(int x1, int y1);	            //画空地
void drawDest(int x1, int y1);				//画目的地
void drawWall(int x1, int y1);	            //画围墙

void drawBlankDoraemon(int x1, int y1);     //画空地上的人物
void drawDestDoraemon(int x1, int y1);	    //画目的地上的人物
void drawWinDoraemon(int x1, int y1);		//画胜利的人物

void drawBlankBox(int x1, int y1);	        //画空地上的箱子
void drawDestBox(int x1, int y1);			//画在目的地上的箱子
void drawMap(int a[][15]);					//把地图所有全画出来

void move(int a[][15], int x1, int y1);		//移动
void find(int a[][15]);						//找人物坐标
int  isWin(int a[][15]);					//判断游戏是否结束
int  playGame(int a[][15]);					//游戏过程
void gameLevel();							//游戏关卡

void beginMenu();							//开始菜单
void overMenu();							//结束菜单


//画空地
void drawBlank(int x1, int y1)
{
	putimage(y1, x1, &img[0]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画人物
void drawBlankDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[1]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画箱子
void drawBlankBox(int x1, int y1)
{
	putimage(y1, x1, &img[2]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画目的地
void drawDest(int x1, int y1)
{
	putimage(y1, x1, &img[3]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画在目的地上的人物
void drawDestDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[4]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画在目的地上的箱子
void drawDestBox(int x1, int y1)
{
	putimage(y1, x1, &img[5]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画围墙
void drawWall(int x1, int y1)
{
	putimage(y1, x1, &img[6]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画胜利的人物
void drawWinDoraemon(int x1, int y1)
{
	putimage(y1, x1, &img[7]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//把数组里的全画出来
void drawMap(int a[][9])
{
	for (int x1 = 0; x1 < 9; x1++)
		for (int y1 = 0; y1 < 9; y1++)
			putimage(60 * y1, 60 * x1, &img[a[x1][y1]]);
}

//移动
void move(int a[][9], int x1, int y1)
{
	if (a[x + x1][y + y1] == 0 || a[x + x1][y + y1] == 3)
	{
		a[x][y]--;
		a[x + x1][y + y1]++;
		for (int i = 0; i < 60; i++)     //移动贴图过程
		{
			BeginBatchDraw();  
			drawBlank(60 * x + i * x1, 60 * y + i * y1);				//擦掉
			drawBlankDoraemon(60 * x + (i + 1) * x1, 60 * y + (i + 1) * y1);
			Sleep(1);												//为了降低CPU且保存流畅
			EndBatchDraw();
		}
		if (a[x][y] == 3)    //人物从目的地上离开
			drawDest(60 * x, 60 * y);
		x += x1;
		y += y1;
		if (a[x][y] == 4)     //人物到目的地上
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
			drawBlank(60 * (x + x1) + i * x1, 60 * (y + y1) + i * y1);	        //擦掉
			drawBlankBox(60 * (x + x1) + (i + 1) * x1, 60 * (y + y1) + (i + 1) * y1);
			drawBlank(60 * x + i * x1, 60 * y + i * y1);						//擦掉
			drawBlankDoraemon(60 * x + (i + 1) * x1, 60 * y + (i + 1) * y1);
			Sleep(1);				//为了降低CPU且保存流畅
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

//想x,y找人物坐标
void find(int a[][9])
{
	//循环遍历数组找到人物坐标
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

//判断游戏是否结束
int isWin(int a[][9])
{
	//循环地图看看还有没有在空地上的箱子
	for (int x1 = 0; x1 < 9; x1++)
	{
		for (int y1 = 0; y1 < 9; y1++)
		{
			if (a[x1][y1] == 2)
			{
				return 0;	//如果还有箱子返回假
			}
		}

	}
	
	return 1;		//如果没有箱子返回真										
}

//游戏过程
int playGame(int a[][9])
{
	loop = 0;
	drawMap(a);     //画出每一关的布局
	find(a);		//通过find函数寻找人物的x, y坐标
	do
	{
		switch (_getch())										//获取键盘
		{
		case 'w':
		case 'W':
			move(a, -1, 0);		//上移
			break;				 
		case 'a':
		case 'A':
			move(a, 0, -1);		//左移 
			break;				
		case 'd':
		case 'D':
			move(a, 0, 1);		//右移
			break;				 
		case 's':
		case 'S':
			move(a, 1, 0);		//下移
			break;				 
		case 'r':
		case 'R':
		case ' ':
			loop = 1;			//重新开始当前关 
			return 0;				
		case  27:
			exit(0);			//结束游戏 
			break;					
		case 0xE0:						//如果是方向键 
			switch (_getch())								//再次获取键盘 
			{
			case 72:
				move(a, -1, 0);	//上移
				break;          
			case 75:
				move(a, 0, -1);	//左移
				break;          
			case 77:
				move(a, 0, 1); 	//右移
				break;          
			case 80:
				move(a, 1, 0);  //下移
				break;           
			}
		}
	} while (!isWin(a));								//通过isWin函数判断是否通过
	drawWinDoraemon(60 * x, 60 * y);				//画一个胜利的人物
	_getch();                                       //暂停等待用户按键  进入下一关
	return 0;
}

//游戏关卡
void gameLevel()
{
	int b[9][9];				//设置当前地图数组 
	for (int i = 0; i < 5; i++)
	{
		do
		{
			loop = 0;				//loop置为0
			for (int x1 = 0; x1 < 9; x1++)
			{
				for (int y1 = 0; y1 < 9; y1++)
				{
					b[x1][y1] = map[i][x1][y1];			//对当前地图数组分别赋值 
				}
			}	
			playGame(b);
		} while (loop);					//如果loop被置为1则重新开始
	}
	overMenu();  //结束菜单
}

//开始菜单
void beginMenu()
{
	//初始化画布
	initgraph(540, 540);
	//菜单背景
	putimage(0, 0, &img[8]);

	//字体格式
	settextstyle(30, 0, "华文新魏");//设置字体样式，高为30
	setbkmode(TRANSPARENT);     //文字背景透明
	settextcolor(WHITE);    //设置当前文字的颜色	
	//输出界面汉字
	outtextxy(40, 500, "开始游戏");//利用函数在指定位置输出字符串
	outtextxy(390, 500, "退出游戏");

	//鼠标交互
	MOUSEMSG m;
	while (1)
	{
		//获取鼠标位置
		m = GetMouseMsg();

		//判断鼠标位置
		settextcolor(RED);     //鼠标点击时的颜色
		if (m.x >= 40 && m.x <= 160 && m.y >= 500 && m.y <= 530)
		{
			outtextxy(40, 500, "开始游戏");
			//鼠标左击  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				gameLevel();
			}
		}
		else if (m.x >= 390 && m.x <= 510 && m.y >= 500 && m.y <= 530)
		{
			outtextxy(390, 500, "退出游戏");
			//鼠标左击  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else       //文字颜色还原（鼠标点文字以外的地方）
		{
			settextcolor(WHITE);    //设置当前文字的颜色	
			outtextxy(40, 500, "开始游戏");
			outtextxy(390, 500, "退出游戏");
		}
	}
}

//结束菜单
void overMenu()
{
	//初始化画布
	initgraph(540, 540);
	//菜单背景
	putimage(0, 0, &img[9]);

	//三个箱子
	putimage(130, 60, &img[3]);
	putimage(230, 60, &img[3]);
	putimage(330, 60, &img[3]);
	//文字提示
	settextstyle(30, 0, "华文新魏");//设置字体样式，高为30
	setbkmode(TRANSPARENT);     //文字背景透明
	settextcolor(BLACK);    //设置当前文字的颜色	

	//左边箱子的钥匙
	int i;
	for (i = -60; i <= 130; i += 5)
	{
		BeginBatchDraw();  //双缓冲绘图
		putimage(i, 120, &img[2]);
		Sleep(100);
		putimage(i - 60, 120, &img[0]);  //覆盖一下走过的路径
		EndBatchDraw();
	}

	//右边箱子的钥匙
	for (i = 540; i >= 330; i -= 5)
	{
		BeginBatchDraw();  //双缓冲绘图
		putimage(i, 120, &img[2]);
		Sleep(100);
		putimage(i + 60, 120, &img[0]);  //覆盖一下走过的路径
		EndBatchDraw();
	}

	//中间箱子的钥匙
	for (i = 540; i >= 120; i -= 10)
	{
		BeginBatchDraw();  //双缓冲绘图
		putimage(230, i, &img[2]);
		Sleep(60);
		putimage(230, i + 60, &img[0]);  //覆盖一下走过的路径
		EndBatchDraw();
	}


	outtextxy(150, 230, "下面,来打开箱子");
	//点击钥匙打开宝箱
	MOUSEMSG m;
	int key[3] = { 1,1,1 };  //钥匙  1为有  0为没有
	int key_flg = 0;
	while (1)
	{
		//获取鼠标位置
		m = GetMouseMsg();

		//左边的钥匙
		if (m.x >= 130 && m.x <= 190 && m.y >= 120 && m.y <= 180)
		{
			//鼠标点击
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[0] = 0;
				//擦除左边钥匙
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(130, i, &img[0]);
				}
				//覆盖左边箱子
				putimage(130, 60, &img[5]);
			}
		}
		//中间的钥匙
		else if (m.x >= 230 && m.x <= 290 && m.y >= 120 && m.y <= 180)
		{
			//鼠标点击
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[1] = 0;
				//擦除中间钥匙
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(230, i, &img[0]);
				}
				//覆盖中间箱子
				putimage(230, 60, &img[5]);
			}
		}
		//右边的钥匙
		else if (m.x >= 330 && m.x <= 390 && m.y >= 120 && m.y <= 180)
		{
			//鼠标点击
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				key[2] = 0;
				//擦除右边钥匙
				for (i = 160; i >= 120; i -= 5)
				{
					Sleep(100);
					putimage(330, i, &img[0]);
				}
				//覆盖右边箱子
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

	//覆盖文字
	putimage(150, 200, &img[0]);
	putimage(200, 200, &img[0]);
	putimage(250, 200, &img[0]);
	putimage(300, 200, &img[0]);
	outtextxy(165, 200, "成功获得宝藏");

	outtextxy(100, 350, "重新开始");
	outtextxy(300, 350, "退出游戏");

	//鼠标交互
	while (1)
	{
		//获取鼠标位置
		m = GetMouseMsg();

		//判断鼠标位置
		settextcolor(RED);     //鼠标点击时的颜色
		if (m.x >= 100 && m.x <= 220 && m.y >= 350 && m.y <= 380)
		{
			outtextxy(100, 350, "重新开始");
			//鼠标左击  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				gameLevel();
			}
		}
		else if (m.x >= 300 && m.x <= 420 && m.y >= 350 && m.y <= 380)
		{
			outtextxy(300, 350, "退出游戏");
			//鼠标左击  
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else       //文字颜色还原（鼠标点文字以外的地方）
		{
			settextcolor(WHITE);
			outtextxy(100, 350, "重新开始");
			outtextxy(300, 350, "退出游戏");
		}
	}
}

//主函数
int main()
{
	//播放音乐
	mciSendString("open music.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
	//加载图片资源
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

	//开始菜单
	beginMenu();
	return 0;
}

