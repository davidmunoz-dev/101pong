/*
** 101pong.c for 101pong in /home/durand_4/Exo/mathematique/101pong/101pong
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Thu Nov  5 11:38:38 2015 loic durand
** Last update Thu Nov 12 12:08:21 2015 loic durand
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	pong(float x0, float y0, float z0, float x1, float y1, float z1, int n)
{
  float	xv;
  float	yv;
  float	zv;
  float xt;
  float yt;
  float zt;
  float a;
  float cosB;
  float	angleB;

  xv = x1 - x0;
  yv = y1 - y0;
  zv = z1 - z0;
  printf("The speed vector coordinates are :\n");
  printf("(%.2f;%.2f;%.2f)\n", xv, yv, zv);
  xt = x1 + (n * xv);
  yt = y1 + (n * yv);
  zt = z1 + (n * zv);
  printf("At time t+%d, ball coordinates will be :\n", n);
  printf("(%.2f;%.2f;%.2f)\n", xt, yt, zt);
  a = -z1 / zv;
  if (a < 0)
    printf("The ball won't reach the bat.\n");
  else
    {
      cosB = (fabs(zv) / (sqrt(pow(xv, 2) + pow(yv, 2) + pow(zv, 2))));
      angleB = 90 - ((180 * acos(cosB)) / M_PI);
      printf("The incidence angle is :\n");
      printf("%.2f degrees\n", angleB);
    }
}

int	main(int ac, char **av)
{
  int	a;
  int	b;
  int	c;
  int	d;

  a = 1;
  b = 0;
  c = 0;
  d = 0;
  if (av[7][0] == '-')
    {
      printf("n must be greater than or equal to zero.\n");
      return (84);
    }
  else if (ac == 8)
    {
      while (av[a] != '\0')
	{
	  if (av[a][b] < 45 || av[a][b] > 57 || av[a][b] == 47)
	    {
	      printf("Error in argument %d.\n", a);
	      return (84);
	    }
	  if (av[a][b] == 46)
	    c = c + 1;
	  if (av[a][b] == 45)
	    d = d + 1;
	  if (c > 1 || d > 1)
	    {
	      printf("Error in argument %d.\n", a);
	      return (84);
	    }
	  b = b + 1;
	  if (av[a][b] == '\0')
	    {
	      a = a + 1;
	      b = 0;
	      c = 0;
	      d = 0;
	    }
	}
      pong(atof(av[1]), atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6]), atoi(av[7]));
      return (0);
    }
  else if (ac < 8)
    {
      printf("Not enough arguments. You need x0 y0 z0 x1 y1 z1 n.\n");
      return (84);
    }
  else if (ac > 8)
    {
      printf("Too many arguments. You need x0 y0 z0 x1 y1 z1 n.\n");
      return (84);
    }  
}
