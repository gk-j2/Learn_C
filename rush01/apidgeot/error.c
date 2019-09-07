int		error(char	sudoku[9][9])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 8 && i >= 0)
	{	
		while (j <= 8 && j >= 0)
		{
			if (sudoku[i][j] < '1' || sudoku[i][j] > '9')
			{
				printf("Ошибка! Один из символов в строке не удовлетворяет условию задачи!\n");
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (sudoku);
}

int		error2(char *sudoku)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i <= 9)
	{
		if (sudoku[i][j] == '\0')
			return (0);
		i++;
	}
	printf("Ошибка! Количество символов в строке больше 9!\n"); 
	return (0);
}
