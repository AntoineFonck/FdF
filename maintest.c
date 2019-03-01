#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map *map;
	char **tabchar;
	int i;
	int j;

	if ((map = malloc(sizeof(t_map))) == NULL)
	{
		printf("problem with map malloc");
		return (1);
	}
	i = 0;
	if (argc != 2)
	{
		printf("not good number of arguments");
		return (1);
	}
	if ((tabchar = check_and_read(argv[1], map)) != NULL)
		printf("check and read works\n");
	else
		printf("problem with check and read\n");
	atoi_tab(tabchar, map);
	if (map->tab != NULL)
		printf("atoi tab works\n");
	else
		printf("problem with atoi tab\n");
	while (i < map->h_max)
	{
		while (j < map->w_max)
		{
			printf("printing tab[%d][%d]", i, j);
			ft_putnbr(map->tab[i][j]);
			//printf("%d ", map->tab[i][j]);
			if (map->tab[i][j] == 0)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		if (j != map->w_max)
			printf("error with j=%d and map->w_max=%d\n", j, map->w_max);
		j = 0;
		i++;
	}
	if (i != map->h_max)
		printf("error with i index=%d and map->h_max=%d\n", i, map->h_max);
	i = 0;
	while (i < map->h_max)
	{
		if (tabchar[i])
			ft_memdel((void **)&tabchar[i]);
		else
			printf("couldn't memdel tabchar[%d]\n", i);
		i++;
	}
	if (tabchar)
		ft_memdel((void **)tabchar);
	else
		printf("couldn't memdel tabchar\n");
	printf("map->w_max = %d and map->h_max = %d\n", map->w_max, map->h_max);
	//while (1) {}
	return (0);
}
