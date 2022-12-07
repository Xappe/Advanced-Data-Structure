void verificar_laço(lista *arquivo)
{
	int x, j, cont=0;


		fscanf(arquivo, "%d %d", &n, &m);
		while(!feof(arquivo))
		{
			fscanf(arquivo, "%d", &x);
			if(x >= 1)
			{
				cont++;
			}

			for(j=0, j< n*n, j+n)
			{
				fscanf(arquivo, "%d", &m);
			}
		}

		
		if(cont > 0)
		{
			printf("Este grafo contem laço(s).");
		}
		else
		{
			printf("Este grafo não contem laços!");
		}
}	



