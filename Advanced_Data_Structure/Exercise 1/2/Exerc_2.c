#include<stdio.h>
#include<stdlib.h>

struct tipo_lista
{
    int vertice;
    struct tipo_lista *proximo;
}typedef lista;

void criar_lista(int n_vertice);
void preencher_lista(lista *lista_adj, int n_vertice, int n1, int n2);
lista* procurar_NULL(lista *lista_adj);
int* criar_matriz(int n,int m);
void imprimir_matriz(int **matriz, int n, int m);
void imprimir_lista(lista **lista_adj, int n_vertice );


int main()
{
	FILE *arquivo;
	int n_vertice, n_aresta, n1, n2, i, j;
	lista *lista_adj;
	int *matriz_inc, *matriz_adj

	arquivo = fopne("Grafo.txt","r");	
	if(arquivo != NULL)
	{
		fscanf(arquivo,"%d %d", &n_vertice, &n_aresta);

		lista_adj = criar_lista(n_vertice);

		while(!feof(arquivo))
		{
			fscanf(arquivo,"%d %d", &n1, &n2);
	        preencher_lista(lista_adj, n_vertice, n1, n2);
		}

		rewind(arquivo);
	    fscanf(arquivo,"%d",&n_vertice);
	    fscanf(arquivo,"%d",&n_aresta);

	    matriz_adj = criar_matriz(n_vertice, n_vertice);
	    
	    while(!feof(arquivo))
	    {
	    	fscanf(arquivo, "%d", &n1);
	    	fscanf(arquivo, "%d", &n2);
	    	matriz_adj[n1-1][n1-2] = 1;
	    	matriz_adj[n1-2][n1-1] = 1; 
	    }


	    rewind(arquivo);
	    fscanf(arquivo,"%d",&n_vertice);
	    fscanf(arquivo,"%d",&n_aresta);


	    matriz_inc = criar_matriz(n_vertice, n_aresta);                                    
		while(!feof(arquivo))
		{
	        fscanf(arquivo, "%d", &n1);
	        fscanf(arquivo, "%d", &n2);
	        for(i = 0; i < n_vertice; i++) 
			{
				if(i == (n1-1) || i == (n2-1))                  
	            { 
					matriz_inc[i][j]= 1;
				}
	        }
	        j++;
	    }


	    printf("Lista de Adjacência do grafo \n\n");
	    imprimir_lista(lista_adj, n_vertice);
	    printf("Matriz de Adjacência do grafo  \n\n");
	    imprimir_matriz(matriz_adj, n_vertice, n_vertice);
	    printf("Matriz de Incidência do grafo \n\n");
	    imprimir_matriz(matriz_inc, n_vertice, n_aresta);
	    printf("\n\n");

	}

	else
	{
		printf("Erro na abertura do arquivo!\n\n");
	}

	fclose(arquivo);

	return 0;
}



void criar_lista(int n_vertice)
{
	lista *aux;
	int i;
	aux =(lista*)malloc(n_vertice * sizeof(lista));
	for(i=0; i<n_vertice; i++)
	{
		aux[i] = (lista*)malloc(sizeof(lista));
		aux[i] -> vertice = i+1;
		aux[i] -> proximo = NULL;
	}
	return aux;
}


void preencher_lista(lista *lista_adj, int n_vertice, int n1, int n2)
{
    int i;
    lista *aux1;
	for (i = 0; i < n_vertice; i++)
	{ 
        if(> vertice == n1)
		{
            aux1 = procurar_NULL(lista_adj[i]);
            aux1 -> proximo = (lista*)malloc(sizeof(lista));
            aux1 -> proximo -> vertice = n2;
            aux1 -> proximo -> proximo = NULL;
        }
        else 
		{
			if(lista_adj[i] -> vertice == n2)
			{
            	aux1 = procurar_NULL(lista_adj[i]);
            	aux1 -> proximo = (lista*)malloc(sizeof(lista));
            	aux1 -> proximo -> vertice = n1;
            	aux1 -> proximo -> proximo = NULL;
			}
        }
    }
}


lista* procurar_NULL(lista *lista_adj)
{
    lista *aux;
    aux = lista_adj;
    while(aux -> proximo != NULL)
	{
        aux = aux -> proximo;
    }
    return aux;
}


int* criar_matriz(int n,int m)
{
	int i, j;
	int *matriz = (int)malloc(n * sizeof(int));

	for(i=0; i<n; i++)
	{
		matriz[i] = (int*) malloc(m * sizeof(int));
		for(j=0; j<m; j++)
		{
			matriz[i][j] = 0;
		}
	}
	return matriz;
}


void imprimir_lista(lista **lista_adj, int n_vertice )
{
    int i;
    lista *aux;
    for(i = 0; i < n_vertice; i++)
	{
        aux=lista_adj[i] -> proximo;
        printf("%d ->", lista_adj[i] -> vertice);
        while(aux != NULL)
		{
            if(aux -> proximo != NULL)
			{
                printf("%d->",aux -> vertice);
            }
            else
			{
                printf("%d",aux -> vertice);
            }
            aux = aux -> proximo;
        }
        printf("\n");
    }
    printf ("\n");
}


void imprimir_matriz(int **matriz, int n, int m)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
   		{
   			printf ("%d \t", matriz[i][j]);
   		}
   		printf ("\n\n");
   	}
   	printf ("\n");
}