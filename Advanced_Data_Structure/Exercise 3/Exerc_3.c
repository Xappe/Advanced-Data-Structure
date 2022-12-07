#include <stdio.h>

int soma(int h);


int main()
{
	int h, n;

	printf("Insira um numero inteiro positivo para altura h da arvore: ");
	scanf("%d", &h);

	n = soma(h) ;

	printf("\n\nO numero minimo de nos para uma arvore de altura %d e: %d", h,n);
	return 0;
}





int soma(int h)
{
    int n;
	if(h>0)
	{
	    if(h==1)
		{
			n=1;
		}
		else
		{
			n=1 +soma(h-1)+soma(h-2);
		}
	}
	else
	{
		n=0;
	}

	return n;
}