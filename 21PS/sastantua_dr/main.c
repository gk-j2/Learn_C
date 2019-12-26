#include <stdio.h>
#include <unistd.h>
void ft_putchar(char c){write(1, &c, 1);}





void ft_pir(int size, int delta)
{
	int cur_lev = size;
	int i;
	int j;
	int k;
	int spaces;

	spaces = 0;
	i = k = j =0;
	while (cur_lev > 0)
	{
		while (i < cur_lev+2)
		{
			while (j < spaces){
				ft_putchar(' ');j++;}
			ft_putchar('/');
			while (k < delta - 2){
				ft_putchar('*');k++;}
			ft_putchar('\\');
			delta -= 1;
			spaces += 1;
			i++;
		}
		cur_lev--;
		delta = delta - 2*((i-1)%2+(i-1)/2+3+i);
	}
}
void  sastantua(int size)
{
	int delta = 0;
	int i = 1;
	int hight = 3;
	while (i <= size)
	{
		if (i == 1) delta = 7;
		else
		{
			delta = delta + 2*((i-1)%2+(i-1)/2+hight+i);
		}
		i+=1;
	}
	ft_pir(size, delta);
}



int main()
{
	int size;
	size = 5;
	sastantua(size);
	return (0);
}
