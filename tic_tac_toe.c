#include <stdio.h>

#define MAX_DIMENSION 3


void mark(int markRow,int markColumn,char c);
void display();
int check();


//global variables
char arr[3][3];																	//the tic-tac-toe matrix
int flag[3][3];																	//for checking if a given position is occupied or not
char player1Name[10],player2Name[10];


int main()
{
	int markRow,markColumn,i,j,WIN_status=0,turn=1,moveCount=0;
	for(i=0;i<MAX_DIMENSION;i++)
		for(j=0;j<MAX_DIMENSION;j++)
			arr[i][j]=' ';

	printf("Player 1 Enter your name: ");
	scanf("%s",player1Name);
	printf("Player 2 Enter your name: ");
	scanf("%s",player2Name);
	system("cls");
	display();

	while(moveCount<9&&WIN_status==0)
	{
		if(turn==1)
			printf("\n%s your turn.",player1Name);
		else
			printf("\n%s your turn.",player2Name);
		printf("\nEnter the Row:");
		scanf("%d",&markRow);
		printf("Enter the Column:");
		scanf("%d",&markColumn);
		system("cls");
		if(turn==1)
		{
			mark(markRow,markColumn,'X');
			turn=2;
		}
		else
		{
			mark(markRow,markColumn,'O');
			turn=1;
		}
		display();
		WIN_status=check();
		moveCount++;
	}
}


//----------------------------------start of mark function.--------------------------------------------
//marks the player symbol on given position
void mark(int markRow,int markColumn,char c)
{
	arr[markRow-1][markColumn-1]=c;
}


//----------------------------------start of display function.--------------------------------------------
//displays the current status of tic-tac-toe matrix
void display()
{
	int i,j;
	for(i=0;i<MAX_DIMENSION;i++)
	{
		for(j=0;j<MAX_DIMENSION;j++)
		{
			printf(" %c ",arr[i][j]);
			if(j<2)
			printf("|");
		}
		if(i<2)
		printf("\n-----------\n");
	}
}


//----------------------------------start of check function.--------------------------------------------
//checks for win condition
int check()
{
	int a[2][3],i,j,winnerIndex=0;
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[0][i]+=arr[i][j];
			a[1][i]+=arr[j][i];
		}
		j--;
		if(a[0][i]/3==(int)arr[i][j]&&(arr[i][j]=='X'))
		{
			winnerIndex=1;
		}
		if(a[0][i]/3==(int)arr[i][j]&&(arr[i][j]=='O'))
		{
			winnerIndex=2;
		}
		if(a[1][i]/3==(int)arr[j][i]&&(arr[j][i]=='X'))
		{
			winnerIndex=1;
		}
		if(a[1][i]/3==(int)arr[j][i]&&(arr[j][i]=='O'))
		{
			winnerIndex=2;
		}
		
	}
	if(arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2]&&arr[1][1]!=' ')
	{
		if(arr[1][1]=='X')
			winnerIndex=1;
		else
			winnerIndex=2;
	}
	if(arr[0][2]==arr[1][1]&&arr[2][0]==arr[1][1]&&arr[1][1]!=' ')
	{
		if(arr[1][1]=='X')
			winnerIndex=1;
		else
			winnerIndex=2;
	}
	if(winnerIndex)
	{
		printf("\nplayer %d wins!!",winnerIndex);
		return 1;
	}
	return 0;			
}

