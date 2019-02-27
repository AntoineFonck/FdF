#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map *map;
	char **tabchar;
	int i;
	int j;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (1);
	i = 0;
	if (argc != 2)
		return (1);
	tabchar = check_and_read(argv[1], map);
	printf("check and read works\n");
	atoi_tab(tabchar, map);
	printf("atoi tab works\n");
	while (i < map->h_max)
	{
		while (j < map->w_max)
		{
			printf("printing tab[%d][%d]", i, j);
			ft_putnbr(map->tab[i][j]);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	i = 0;
	while (i < map->h_max)
	{
		ft_memdel((void **)&tabchar[i]);
		i++;
	}
	ft_memdel((void **)tabchar);
	return (0);
}
