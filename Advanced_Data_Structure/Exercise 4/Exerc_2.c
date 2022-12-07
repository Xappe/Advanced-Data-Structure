#include <stdio.h>

int metodo_da_divisao(int chave, int tamanho);
int metodo_da_multiplicacao(int chave, int tamanho);
void metodo_da_dobra(int r_dobra[], int tamanho, int vetor[]);

int main()
{
	int tamanho, r_divisao, r_multiplicacao, r_dobra[2], chave;
	int vetor[] = {9, 5, 1, 6, 8, 4, 3, 5};


	tamanho = 8, chave= 95168435;


	r_divisao = metodo_da_divisao(chave, tamanho);
	printf("\nDivisao  %d", r_divisao);

	r_multiplicacao = metodo_da_multiplicacao(chave, tamanho);
	printf("\nMultiplicacao  %d", r_multiplicacao);

	metodo_da_dobra(r_dobra, tamanho, vetor);


	printf("\nDobra  %d %d", r_dobra[0], r_dobra[1]);

	return 0;
}


int metodo_da_divisao(int chave, int tamanho)
{
	int resultado;

	resultado = chave % tamanho;

	return resultado;
}


int metodo_da_multiplicacao(int chave, int tamanho)
{
	int resultado;
	double c = 0.724;
	double aux;

	aux = chave * c;

	resultado=aux; //variavel resultado utilizada para adquirir parte inteira de aux

	aux = aux - resultado;

	resultado = tamanho * aux;

	return resultado;
}

void metodo_da_dobra(int r_dobra[], int tamanho, int vetor[])
{
	int i;
	int aux[tamanho/2];

	if(tamanho>4)
    {
        for(i=0; i<tamanho/2; i++)
        {
            aux[i] = (vetor[i] + vetor[tamanho-1-i])%10;
        }
         metodo_da_dobra(r_dobra, tamanho/2, aux);
    }
    else
    {

        r_dobra[1] = (vetor[0] + vetor[3])%10;
        r_dobra[0] = (vetor[1] + vetor[2])%10;
    }
}
