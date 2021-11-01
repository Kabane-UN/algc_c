#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void tip(int a)
{
	printf("Usage: frame <height> <width> <text>\n");
	exit(0);
}
void err(int a)
{
	printf("Error\n");
	exit(0);
}
int main(int argc, char **argv)
{
	signal(SIGINT, tip);
	if (argc!=4)
	{
		raise(SIGINT);
	}
	signal(SIGINT, err);
    int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int l = (int)strlen(argv[3]);
	if ((l>(b-2))||((a==2)&&l!=0)||(a<2))
	{
		raise(SIGINT);
	}
	for (int i = 0; i < a;i++)
	{
		if (i == 0 || i == a-1)
		{
			for (int j = 0; j < b; j++)
			{
				printf("*");
			}
			printf("\n");
		} else if ((a%2==0 && i==a/2-1)||(a%2!=0 && i==a/2))
		{
			printf("*");
			for (int j = 0; j < (b-2-l)/2; j++)
			{
				printf(" ");
			}
			for (int j = 0; j < l; j++)
			{
				printf("%c", argv[3][j]);
			}
			for (int j = 0; j < (b-2-l)-(b-2-l)/2; j++)
			{
				printf(" ");
			}
			printf("*\n");
		} else
		{
			printf("*");
			for (int j = 0; j < b-2; j++)
			{
				printf(" ");
			}
			printf("*\n");
		}
	}
	return 0;
}
