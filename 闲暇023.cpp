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
	printf("********************��w��s��a��d��ÿһ�β�����Ҫ��һ�λس���******************************");
	Sleep(2000);
	system("cls");
	start();                         //������� 
	while(1)                         //��Ϸ���� 
	{
		char ch[2];
		printf("***************************************************************������");
		scanf("%s",&ch);printf("���Ķ����ǣ�%c\n",ch[0]);
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
				printf("                   *****�������*****\n");
				printf("                   ********************\n"); 
				Sleep(2000);
		}
		//printf("������������������������������������������������������������������������");
		int result = text(1);
		if(result)
		{
			int box[16] = {0};
			int num = finder(box);       //���ؿո��Ӹ��� 
			if(num == 0)
			{
				break;
			}
			int boxn = rand()%num;       //�����ѡ�ո��� 
			int k = box[boxn];           //�������е�����ֵ��K 
			int new24 = (rand()%2+1)*2;  //�������2��4
			game[k/4][k%4] = new24;  //�������������������ĺ�����
		}
		system("cls");
		ouput(); 
		
	}
	printf("You lose already!\n");
	return 0;
} 

//�������� 

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

//�ƶ����� 

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

//�������� 

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//С������ 

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
//��ͷ���� 
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
	printf("                                                           ��Ϸ�÷֣�\n");
	printf("����������������������������������������������������������������������������\n");
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

//���Һ��� 

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
				k++;                       //��¼�ո����� 
			}
		}
	}
	return k;
}

//������� 
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
	printf("                                                           ��Ϸ�÷֣�%d\n"
	                                                                            , score);
	printf("����������������������������������������������������������������������������\n");
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
