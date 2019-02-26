#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char **tab;
	int i;
	int j;

	i = 0;
	if (argc != 2)
		return (1);
	j = count_nb_lines(argv[1]);
	tab = check_and_read(argv[1]);
	while (i < j)
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < j)
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)tab);
	return (0);
}
