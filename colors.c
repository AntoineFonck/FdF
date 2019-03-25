#include <stdio.h>
#include "fdf.h"
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

void    fill_pix(int *data, int x, int y, int z)
{
	/*
	  int color;
	  int red;
	  int green;
	  int blue;
	  red = 0;
	  green = 0;
	  blue = 0;
	  color = rgb_to_int(red, green, blue);
	  */
	if ((x + y * WIN_WIDTH) < (WIN_WIDTH * WIN_HEIGHT) && (x + y * WIN_WIDTH) > 0 && x < WIN_WIDTH && x > 0)
	{
		if (z < -5)
		{
		/*
		 red = 33;
		 blue = 229;
		 data[x + y * WIN_WIDTH] = rgb_to_int(red, green, blue);
		 */
			data[x + y * WIN_WIDTH] = 0x0000C8;
		}
		else if (z >= -5 && z <= 0)
		{
			/*
			 red = 0;
			 green = 66;
			 blue = 191;
			 data[x + y * WIN_WIDTH] = rgb_to_int(red, green, blue);
			 */
			data[x + y * WIN_WIDTH] = 0x0042BF;
		}
		else if (z > 0 && z <= 8)
			data[x + y * WIN_WIDTH] = 0x05701E;
		else if (z > 8 && z <= 16)
			data[x + y * WIN_WIDTH] = 0x659C16;
		else if (z > 16 && z <= 26)
			data[x + y * WIN_WIDTH] = 0xBFC610;
		else if (z > 26 && z <= 36)
			data[x + y * WIN_WIDTH] = 0xF7FF42;
		else if (z > 36 && z <= 50)
			data[x + y * WIN_WIDTH] = 0xC4A564;
		else if (z > 50 && z <= 70)
			data[x + y * WIN_WIDTH] = 0x986D42;
		else if (z > 70 && z <= 90)
			data[x + y * WIN_WIDTH] = 0x79472A;
		else if (z > 90 && z <= 130)
			data[x + y * WIN_WIDTH] = 0x3B271A;
		else if (z > 130 && z <= 170)
			data[x + y * WIN_WIDTH] = 0x659C16;
		else
			data[x + y * WIN_WIDTH] = 0xD9E7E8;
		/*
		 *         if (z <= 7)
		 *                     data[x + y * WIN_WIDTH] = color;
		 *                             else if (z > 7 && z < 10)
		 *                                         data[x + y * WIN_WIDTH] = color;
		 *                                                 else if (z == 10)
		 *                                                             data[x + y * WIN_WIDTH] = color;
		 *                                                                     else
		 *                                                                                 data[x + y * WIN_WIDTH] = color;
		 *                                                                                             */
		/*
		 *         while (z != 0)
		 *                 {
		 *                             z--;
		 *                                         if (blue < 256)
		 *                                                         color = rgb_to_int(red, (green -= 10), (blue -= 20));
		 *                                                                 }
		 *                                                                         data[x + y * WIN_WIDTH] = color;
		 *                                                                                 */
	}
}
