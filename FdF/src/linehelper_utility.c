/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehelper_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:20:10 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/29 22:20:11 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1)
{
	lh->dx = abs(c1->x - c0->x);
	if (c0->x < c1->x)
		lh->sx = 1;
	else
		lh->sx = -1;
	lh->dy = -abs(c1->y - c0->y);
	if (c0->y < c1->y)
		lh->sy = 1;
	else
		lh->sy = -1;
	lh->err = lh->dx + lh->dy;
	lh->x = c0->x;
	lh->y = c0->y;
}

/* 

//https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
//https://www.ques10.com/p/48681/bresenhams-line-algorithm-1/
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=
ndb796&logNo=221115220322

Some versions use Bresenham's principles of integer incremental error 
to perform all octant line draws, balancing the positive and negative error 
between the x and y coordinates.[2] 
Take note that the order is not necessarily guaranteed; 
in other words, the line may be drawn 
from (x0, y0) to (x1, y1) or from (x1, y1) to (x0, y0).  
*/

/* 
1) Take the absolute value of dx and dy in the case that x1/y1 are
	smaller than x0/y0
2) If c0->x < c1->x then we are moving right so the amount we add to lh->sx is +1
   If c1->x > c0->x then we are moving left so the amount we add to lh->sx is -1

3) If c0->y < c1->y then we are moving down so the amount we add to lh->sy is +1
   If c0->y > c1->y then we are heading up so the amount we add to lh->sy is -1

4) If dx > dy then we have a flatter line so make dx the driving axis.

5) If dy > dx then we have a steeper line so make dy the driving axis.
 
Note: you might think 3) is mistaken in directions but recall that in our
graphics coordinate system 0,0 is the top left and 0, WIN_H is the bottom left.
 
*/

/* 
void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1)
{
	lh->dx = abs(c1->x - c0->x);
	printf("c1->x , c0->x %d\t%d\n", c1->x , c0->x);
	printf("lh->sx %d\n", lh->sx);
	if (c0->x < c1->x)
	// printf("lh->dx%d\n", lh->dx);
	// printf("lh->sx%d\n", lh->sx);
		lh->sx = 1;
	else
		lh->sx = -1;
	
	lh->dy = -abs(c1->y - c0->y);
		// printf("c0->y%d\n", c0->y);
	// printf("c1->y%d\n", c1->y);
	if (c0->y < c1->y)
		lh->sy = 1;
	else
		lh->sy = -1;
	printf("c1->x , c1->y %d\t%d\n", c1->x , c1->y);
	printf("lh->dx%d\n", lh->dx);
	printf("lh->dy : %d\n", lh->dy);
	printf("lh->err%d\n", lh->err);
	lh->x = c0->x;
	printf("lh->x%d\n", lh->x);
	lh->y = c0->y;
	printf("lh->y%d\n", lh->y);
} 
*/