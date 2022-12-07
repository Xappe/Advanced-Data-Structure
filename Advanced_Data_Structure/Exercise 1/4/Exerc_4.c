
void verificar_grau(int *matriz, int n, int m)
{
	int i, j, soma_grau = 0;
	for (i =0 ; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (matriz[i][j] == 1)
			{
				soma = soma + 1;
			}
		}
		printf("O vértice %d tem grau %d \n", i + 1, soma_grau);
	}
}





