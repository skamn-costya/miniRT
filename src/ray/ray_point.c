/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/15 22:36:26 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

float pixel_bright(t_vector3 *p_normal, t_vector3 *p_light_dir)
{
    float brightness;

    brightness = ksx_vec3_dot(p_normal, p_light_dir);
    if (brightness < 0.0f)
        brightness = 0.0f;
    return brightness;
}

t_color color_bright(t_color *p_color, float brightness)
{
	t_color	color;

	color.r = (uint8_t)(p_color->r * brightness);
    color.g = (uint8_t)(p_color->g * brightness);
    color.b = (uint8_t)(p_color->b * brightness);
    return color;
}

// t_vector3 phong_shading(t_vector3 *p_point, t_triangle *p_tri, t_light *p_light, t_camera *p_camera)
// {
//     t_vector3 normal, light_dir, view_dir, reflect_dir;
//     float ambient_intensity, diffuse_intensity, specular_intensity, dot_nl, dot_rv;

//     // Интерполяция нормалей
//     normal = gradient_fill(p_point, p_tri);  // Используем линейную интерполяцию нормалей через барицентрические координаты

//     // Вектор от точки до источника света
//     light_dir = ksx_vec3_sub(&p_light->position, p_point);
//     light_dir = ksx_vec3_unit(&light_dir);  // Нормализуем

//     // Вектор от точки до камеры (наблюдателя)
//     view_dir = ksx_vec3_sub(&p_camera->position, p_point);
//     view_dir = ksx_vec3_unit(&view_dir);  // Нормализуем

//     // Отраженный вектор (для расчета спекулярной компоненты)
//     reflect_dir = ksx_vec3_reflect(&light_dir, &normal);  // Используем функцию отражения

//     // Вычисляем компоненты освещения

//     // Амбиентное освещение
//     ambient_intensity = p_light->ambient_intensity;

//     // Диффузное освещение (Lambertian reflection)
//     dot_nl = ksx_vec3_dot(&normal, &light_dir);
//     if (dot_nl < 0.0f) {
//         diffuse_intensity = 0.0f;  // Если угол между нормалью и источником света отрицательный, не освещаем
//     } else {
//         diffuse_intensity = p_light->diffuse_intensity * dot_nl;
//     }

//     // Спекулярное освещение (Phong reflection)
//     dot_rv = ksx_vec3_dot(&view_dir, &reflect_dir);
//     if (dot_rv < 0.0f) {
//         specular_intensity = 0.0f;  // Если угол между отраженным вектором и вектором наблюдения отрицательный, не вычисляем спекулярное
//     } else {
//         specular_intensity = p_light->specular_intensity * powf(dot_rv, p_light->shininess);
//     }

//     // Итоговый цвет (интенсивность освещения)
//     float intensity = ambient_intensity + diffuse_intensity + specular_intensity;

//     // Убедимся, что интенсивность не превышает 1.0
//     intensity = fminf(intensity, 1.0f);

//     // Возвращаем нормализованный вектор интенсивности
//     return ksx_vec3_set(intensity, intensity, intensity);
// }
