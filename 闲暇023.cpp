#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

void start();
int text(int a);
void swap(int a,int b);

void gameup();
void up_blank();
void upadd();

void gamedown();
void down_blank();
void downadd();

void gameleft();
void left_blank();
void leftadd();

void gameright();
void right_blank();
void rightadd();

int finder(int *p);
void ouput();

int game[4][4] = {0};
int arr[4][4] = {0};

int main()
{

	srand((unsigned)time(0));
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("********************上w下s左a右d，每一次操作都要按一次回车！******************************");
	Sleep(2000);
	system("cls");
	start();                         //最初界面 
	while(1)                         //游戏主体 
	{
		char ch[2];
		printf("***************************************************************动作：");
		scanf("%s",&ch);printf("您的动作是：%c\n",ch[0]);
		text(0);
		switch(ch[0])
		{
			case 'w':
				gameup();
				break;
			case 's':
				gamedown();
				break;
			case 'a':
				gameleft();
				break;
			case 'd':
				gameright();
				break;
			default:
				printf("                   ********************\n"); 
				printf("                   *****输入错误！*****\n");
				printf("                   ********************\n"); 
				Sleep(2000);
		}
		//printf("————————————————————————————————————");
		int result = text(1);
		if(result)
		{
			int box[16] = {0};
			int num = finder(box);       //返回空格子个数 
			if(num == 0)
			{
				break;
			}
			int boxn = rand()%num;       //随机挑选空格子 
			int k = box[boxn];           //将格子中的数赋值给K 
			int new24 = (rand()%2+1)*2;  //随机产生2或4
			game[k/4][k%4] = new24;  //将随机数放在随机产生的盒子中
		}
		system("cls");
		ouput(); 
		
	}
	printf("You lose already!\n");
	return 0;
} 

//副本函数 

int text(int a)
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			
			switch(a)
			{
				case 0:
					arr[i][j] = game[i][j];
					break;
				case 1:
					if (arr[i][j] != game[i][j])
						return 1;
					break;
			}
		}
	}
	return 0;
	
}

//移动函数 

void gameup()
{
	up_blank();
	upadd();
}
void gamedown()
{
	down_blank();
	downadd();
}
void gameleft()
{
	left_blank();
	leftadd();
}
void gameright()
{
	right_blank();
	rightadd();
}

//交换函数 

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//小函数块 

void up_blank()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 1 ; j < 4 ; j++)
		{
			int k = j;
			while( (k-1) >= 0 && game[k-1][i] == 0){
				swap(&game[k][i], &game[k-1][i]);
				k--;
			}
		}
	}
} 
 
void upadd()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			if(game[j][i] == game[j+1][i])
			{
				game[j][i] = game[j][i]+game[j+1][i];
				game[j+1][i] = 0;
				up_blank(); 
			}
		}
	} 
}
void down_blank()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 2 ; j >= 0; j--)
		{
			int k = j;
			while((k+1) <= 3 && game[k+1][i] == 0)
			{
				swap(&game[k][i], &game[k+1][i]);
				k++;
			}
		}
	}
} 
void downadd()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 3 ; j > 0 ; j--)
		{
			if(game[j][i] == game[j-1][i])
			{
				game[j][i] = game[j][i]+game[j-1][i];
				game[j-1][i] = 0;
				down_blank();
			}
		}
	}
	
}
void left_blank()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 1 ; j < 4 ;j ++){
			int k = j;
			while((k-1) >= 0 && game[i][k-1] == 0)
			{
				swap(&game[i][k-1], &game[i][k]);
				k--;
			}
		}
	}
}
void leftadd()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			if(game[i][j] == game[i][j+1])
			{
				game[i][j] = game[i][j]+game[i][j+1];
				game[i][j+1] = 0;
				left_blank(); 
			}
		}
	} 
	
}
void right_blank()
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 2; j >= 0; j--)
		{
			int k = j;
			while((k+1) < 4 && game[i][k+1] == 0){
				swap(&game[i][k], &game[i][k+1]);
				k++;
			}
		}
	}
}
void rightadd()
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		for(j = 3; j > 0; j--)
		{
			if(game[i][j] == game[i][j-1])
			{
				game[i][j] = game[i][j]+game[i][j-1];
				game[i][j-1] = 0;
				right_blank();
			}
		}
	}
	
}
//开头函数 
void start()
{
	int i, firstbox[4];
	srand((unsigned)time(0));
	for(i = 0 ; i < 4; i++)
	{
		firstbox[i] = (rand()%4);
	}
	game[firstbox[0]][firstbox[1]] = 2;
	game[firstbox[2]][firstbox[3]] = 2;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                                           游戏得分：\n");
	printf("——————————————————————————————————————\n");
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[0][0],game[0][1],game[0][2],game[0][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[1][0],game[1][1],game[1][2],game[1][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[2][0],game[2][1],game[2][2],game[2][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[3][0],game[3][1],game[3][2],game[3][3]);
	printf("                                +----+----+----+----+\n");
} 

//查找函数 

int finder(int *p)
{
	int i,j,k = 0;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(game[i][j] == 0)
			{
				*(p + k) = (i*4+j);
				k++;                       //记录空格子数 
			}
		}
	}
	return k;
}

//输出函数 
void ouput()
{
	int score = 0,i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			score += game[i][j];
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                                           游戏得分：%d\n"
	                                                                            , score);
	printf("——————————————————————————————————————\n");
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[0][0],game[0][1],game[0][2],game[0][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[1][0],game[1][1],game[1][2],game[1][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[2][0],game[2][1],game[2][2],game[2][3]);
	printf("                                +----+----+----+----+\n");
	printf("                                |%4d|%4d|%4d|%4d|\n",
	game[3][0],game[3][1],game[3][2],game[3][3]);
	printf("                                +----+----+----+----+\n");
}
