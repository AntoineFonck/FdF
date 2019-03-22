#include <stdio.h>
/*
unsigned long createcolor(int r, int g, int b)
{   
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
*/

/*
void	int_to_rgb(t_param **param)
{
	(*param)->red = ((*param)->color >> 16) & 255;
	(*param)->green = ((*param)->color >> 8) & 255;
	(*param)->blue = (*param)->color & 255;
}
*/

int	rgb_to_int(unsigned int red, unsigned int green, unsigned int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}
/*
int main()
{
	printf("%d", rgb_to_int(255, 255, 255));
}
*/
