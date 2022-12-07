#include <stdio.h>

void imprimir(int vetor[], int n);
void arranjar(int vetor[], int n);
int inserir(int vetor[], int n, int max, int novo);
void subir(int vetor[],int i);
int remover(int vetor[], int n);
void descer(int vetor[], int i, int n);




int main()
{
	int vetor1[]= {0, 63, 33, 94, 47, 82, 80, 53, 61};
	int vetor2[]= {0, 94, 59, 77, 38, 27, 65, 69, 32};
	int n1=8, n2=8, max=15, novo=50;

	printf("vetor 1 original:");
	imprimir(vetor1, n1);

	arranjar(vetor1, n1);
	printf("\nvetor 1 arrumado: ");
	imprimir(vetor1, n1);

	n1 = inserir(vetor1, n1, max, novo);
	printf("\nvetor 1 apos insercao de %d: ", novo);
	imprimir(vetor1, n1);

	n1 = remover(vetor1, n1);
	printf("\nvetor 1 apos remocao: ");
	imprimir(vetor1, n1);



	printf("\n\n\n\n\nvetor 2 original:");
	imprimir(vetor2, n2);

	arranjar(vetor2, n2);
	printf("\nvetor 2 arrumado: ");
	imprimir(vetor2, n2);

	n2 = inserir(vetor2, n2, max, novo);
	printf("\nvetor 2 apos insercao de %d: ", novo);
	imprimir(vetor2, n2);

	n2 = remover(vetor2, n2);
	printf("\nvetor 2 apos remocao: ");
	imprimir(vetor2, n2);



	return 0;
}


void imprimir(int vetor[], int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		printf("%d ", vetor[i]);
	}
}


void arranjar(int vetor[], int n)
{
	int i, aux, cont;
	while(cont != 0) //Esse contador serve para que ele faça o procedimento de verificação a quantidade de vezes nescessarias ate que o vetor seja um HEAP
	{
		cont=0;// O contador sempre zera depois que ocorre a troca por todos os elementos
		for(i=1; i<=n/2; i++)
		{
			if(2*i<=n)
			{
				if(vetor[i]<vetor[2*i])
				{
					aux = vetor[i];
					vetor[i] = vetor[2*i];
					vetor[2*i] = aux;
					cont++;// sempre que acontecer alguma troca o contador é somado
				}
			}
			if(2*i+1<=n)
			{
				if(vetor[i]<vetor[2*i+1])
				{
					aux = vetor[i];
					vetor[i] = vetor[2*i+1];
					vetor[2*i+1] = aux;
					cont++;// sempre que acontecer alguma troca o contador é somado
				}
			}
		}
	}
}


int inserir(int vetor[], int n, int max, int novo)
{
	int i;
	if(n<max)
	{
		n++;
		vetor[n]=novo;
		i=n;
		subir(vetor, i);
	}
	else
	{
		printf("\n\nLista binaria de altura 4 cheia!\n\n");
	}

	return n;
}


void subir(int vetor[], int i )
{
	int aux, j;
	j=i/2;

	if(j>=1)
	{
		if(vetor[i]>vetor[j])
		{
			aux=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]= aux;

			subir(vetor, j);
		}
	}


}

int remover(int vetor[], int n)
{
	if(n!=0)
	{
		vetor[1] = vetor[n];
		n--;
		descer(vetor,1,n);
	}
	else
	{
		printf("\n\nLista Vazia!\n\n");
	}

	return n;
}

void descer(int vetor[], int i, int n)
{
	int j, aux;
	j=2*i;

	if(j<=n)
	{
		if(j<n)
		{
			if(vetor[j+1]>vetor[j])
			{
				j=j+1;
			}
		}
		if(vetor[j]>vetor[i])
		{
			aux=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=aux;
			descer(vetor,j,n);
		}
	}
}

