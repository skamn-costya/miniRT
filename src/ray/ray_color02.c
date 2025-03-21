/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:25 by ksorokol          #+#    #+#             */
/*   Updated: 2025/03/19 22:03:53 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ksx_vec3_math.h"
#include "math.h"
#include <stdio.h>

#include <stdint.h>
#include <math.h>

// Структура для цвета с каналами [0, 1]
typedef struct s_color {
    float r;
    float g;
    float b;
} t_color;

// Структура для 3D-вектора
typedef struct s_vector3 {
    float x, y, z;
} t_vector3;

// Структура для источника света
typedef struct s_light {
    t_vector3 position;   // позиция света (в мировых координатах)
    uint32_t color;       // 8-битовый цвет света (0xRRGGBB)
    float brightness;     // яркость источника (0..1)
} t_light;

// Вспомогательные функции (предполагается их реализация):
// normalize, dot, subtract, add, scale, reflect

// Преобразование 8-битового цвета (0xRRGGBB) в t_color с каналами [0,1]
t_color to_normalized_color(uint32_t col) {
    t_color c;
    c.r = ((col >> 16) & 0xFF) / 255.0f;
    c.g = ((col >> 8) & 0xFF) / 255.0f;
    c.b = (col & 0xFF) / 255.0f;
    return c;
}

// Преобразование t_color с каналами [0,1] в 8-битовый цвет (0xRRGGBB)
uint32_t to_8bit_color(const t_color *c) {
    uint8_t r = (uint8_t)fminf(c->r * 255.0f, 255);
    uint8_t g = (uint8_t)fminf(c->g * 255.0f, 255);
    uint8_t b = (uint8_t)fminf(c->b * 255.0f, 255);
    return (r << 16) | (g << 8) | b;
}

// Функция для сложения двух цветов
t_color add_color(const t_color *a, const t_color *b) {
    t_color res = { a->r + b->r, a->g + b->g, a->b + b->b };
    return res;
}

// Функция для масштабирования цвета (каждый канал умножается на scalar)
t_color scale_color(const t_color *c, float scalar) {
    t_color res = { c->r * scalar, c->g * scalar, c->b * scalar };
    return res;
}

// Функция для климпинга цвета к диапазону [0,1]
t_color clamp_color(const t_color *c) {
    t_color res;
    res.r = fminf(fmaxf(c->r, 0.0f), 1.0f);
    res.g = fminf(fmaxf(c->g, 0.0f), 1.0f);
    res.b = fminf(fmaxf(c->b, 0.0f), 1.0f);
    return res;
}

// Примерная функция, вычисляющая итоговый цвет пикселя с Phong reflection.
// Параметры:
//   point: координаты точки на поверхности (в мировых координатах)
//   base_color_8bit: базовый (оригинальный) цвет объекта в 8-битном формате (0xRRGGBB)
//   normal: нормаль поверхности в точке (нормализована)
//   ambient_color_8bit: 8-битовый цвет амбиентного света (0xRRGGBB)
//   ambient_intensity: яркость амбиентного света (0..1)
//   lights: массив источников света
//   numLights: количество источников света
//   view_pos: позиция камеры (например, в мировых координатах)
uint32_t compute_final_pixel_color(const t_vector3 *point,
                                   uint32_t base_color_8bit,
                                   const t_vector3 *normal,
                                   uint32_t ambient_color_8bit,
                                   float ambient_intensity,
                                   const t_light *lights,
                                   int numLights,
                                   const t_vector3 *view_pos,
                                   float shininess)  // параметр для зеркального отражения
{
    // Преобразуем 8-битовые цвета в нормализованные [0,1]
    t_color base_color = to_normalized_color(base_color_8bit);
    t_color ambient_color = to_normalized_color(ambient_color_8bit);

    // Начинаем с амбиентного вклада:
    // Амбиентный вклад = базовый цвет * (ambient_color * ambient_intensity)
    t_color final_color = scale_color(&multiply_color(&base_color, &ambient_color), ambient_intensity);
    // Заметим, что multiply_color — функция, которая перемножает каналы двух цветов поэлементно.
    // Если её нет, можно заменить на:
    // t_color ambient_contrib = { base_color.r * ambient_color.r,
    //                             base_color.g * ambient_color.g,
    //                             base_color.b * ambient_color.b };
    // final_color = scale_color(&ambient_contrib, ambient_intensity);

    // Цикл по источникам света для добавления диффузного и зеркального (specular) вклада
    for (int i = 0; i < numLights; i++) {
        // Вычисляем направление от точки к источнику света
        t_vector3 L = subtract(&lights[i].position, point);
        L = normalize(&L);

        // Диффузное освещение (Ламбертова модель)
        float lambert = fmaxf(dot(normal, &L), 0.0f);

        // Диффузный вклад: base_color * light_color * light_brightness * lambert
        t_color light_color = to_normalized_color(lights[i].color);
        t_color diffuse = scale_color(&multiply_color(&base_color, &light_color),
                                      lights[i].brightness * lambert);

        // Вычисляем отражённый вектор R: R = L - 2 * (L dot N) * N
        t_vector3 R = ksx_vec3_reflect(&L, normal);

        // Вычисляем направление на камеру: V = normalize(view_pos - point)
        t_vector3 V = subtract(view_pos, point);
        V = normalize(&V);

        // Спекулярное освещение (модель Фонга)
        float spec_angle = fmaxf(dot(&R, &V), 0.0f);
        float spec = powf(spec_angle, shininess);  // shininess — степень блеска
        t_color specular = scale_color(&light_color, lights[i].brightness * spec);

        // Добавляем вклад данного источника к итоговому цвету:
        // Обычно спекулярная компонента не умножается на базовый цвет объекта,
        // поэтому просто суммируем diffuse и specular
        t_color contrib = add_color(&diffuse, &specular);
        final_color = add_color(&final_color, &contrib);
    }

    // Ограничиваем итоговый цвет значениями в диапазоне [0,1]
    final_color = clamp_color(&final_color);

    // Преобразуем итоговый цвет обратно в 8-битовый формат (0xRRGGBB)
    return to_8bit_color(&final_color);
}
