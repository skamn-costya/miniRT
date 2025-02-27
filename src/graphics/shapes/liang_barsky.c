/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liang_barsky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:13:55 by ksorokol          #+#    #+#             */
/*   Updated: 2025/02/28 00:31:07 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ksx_graphics.h"
#include <stdio.h>
#define LEFT 0
#define RIGHT 1
#define BOTTOM 2
#define TOP 3

/*
1. Добавить Z-отсечение в Лян–Барски:
Можно модифицировать алгоритм, добавив проверки для границ:

near — передняя плоскость отсечения.
far — задняя плоскость отсечения.
Добавляем в код:

c
Copy
Edit
// Добавляем границы по Z
p[4] = -dz; q[4] = z1 - z_near;  // передняя плоскость (near)
p[5] = dz;  q[5] = z_far - z1;   // задняя плоскость (far)
2. Использовать алгоритм Клайпа–Барски (Cyrus–Beck):
Этот алгоритм является обобщением Лян–Барски и работает в трёх измерениях, учитывая отсечение по всем плоскостям (включая 
𝑧
z). Однако он сложнее в реализации.

3. Отсечение в однородных координатах (Clipping in Homogeneous Coordinates):
Это наиболее эффективный метод в 3D-графике:

Выполняется после умножения на матрицу проекции.
Отрезки отсекаются в 4D-пространстве перед выполнением перспективного деления.
Проверяются условия для видимости:
−
𝑤
≤
𝑥
≤
𝑤
−w≤x≤w
−
𝑤
≤
𝑦
≤
𝑤
−w≤y≤w
0
≤
𝑧
≤
𝑤
0≤z≤w — это условие и отсечёт все объекты за камерой.
*/

uint32_t	liang_barsky(t_pixel *p_pix1, t_pixel *p_pix2,
		t_pixel *p_pix1n, t_pixel *p_pix2n)
 {
    float	pq[2][4];
	float	t_in = 0.0f, t_out = 1.0f;
    float dx = p_pix2->x - p_pix1->x;
    float dy = p_pix2->y - p_pix1->y;
    
    // pq[0][LEFT] = -dx;
	// pq[1][LEFT] = p_pix1->x + WIDTH * .5f;
    // pq[0][RIGHT] = dx;
	// pq[1][RIGHT] = WIDTH * .5f - p_pix1->x;
    // pq[0][BOTTOM] = -dy;
	// pq[1][BOTTOM] = p_pix1->y + HEIGHT * .5f;
    // pq[0][TOP] = dy;
	// pq[1][TOP] = HEIGHT * .5f - p_pix1->y;
	pq[0][LEFT] = -dx;
	pq[1][LEFT] = 0;
    pq[0][RIGHT] = dx;
	pq[1][RIGHT] = WIDTH - p_pix1->x;
    pq[0][BOTTOM] = -dy;
	pq[1][BOTTOM] = 0;
    pq[0][TOP] = dy;
	pq[1][TOP] = HEIGHT - p_pix1->y;
    for (int i = 0; i < 4; i++) {
        if (pq[0][i] == 0) {
            if (pq[1][i] < 0) return 0; // Отрезок полностью за границей
        } else {
            float t = pq[1][i] / pq[0][i];
            if (pq[0][i] < 0) {
                if (t > t_out) return 0;
                else if (t > t_in) t_in = t;
            } else {
                if (t < t_in) return 0;
                else if (t < t_out) t_out = t;
            }
        }
    }
    p_pix1n->x = p_pix1->x + t_in * dx;
	p_pix1n->y = p_pix1->y + t_in * dx;
	p_pix2n->x = p_pix2->x + t_in * dx;
	p_pix2n->y = p_pix2->y + t_in * dx;
    return 1;
}
