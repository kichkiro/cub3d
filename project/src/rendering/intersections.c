/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:38:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/11 22:56:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	intersec_sphere(t_ray *ray, t_sphere *sp, t_intersec **isec)
{
	t_hit	hit;

	hit.x = v_sub_vec(ray->origin, (*sp->origin));
	hit.a = v_dot_product(ray->direction, ray->direction);
	hit.hb = v_dot_product(hit.x, ray->direction);
	hit.c = v_dot_product(hit.x, hit.x) - (sp->diameter / 2 * sp->diameter / 2);
	hit.dis = hit.hb * hit.hb - (hit.a * hit.c);
	if (hit.dis < 0)
		return (false);
	hit.sdis = sqrt(hit.dis);
	hit.t = (-hit.hb - hit.sdis) / (hit.a);
	hit.t2 = (-hit.hb + hit.sdis) / (hit.a);
	if (hit.t > hit.t2)
		hit.t = hit.t2;
	if (hit.t < 0)
	{
		hit.t = hit.t2;
		if (hit.t < 0)
			return (false);
	}
	if (hit.t > (*isec)->nearest || hit.t < (*isec)->min || hit.t > (*isec)->max)
		return (false);
	(*isec)->has_intersec = true;
	(*isec)->nearest = hit.t;
	(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	(*isec)->color = (*sp->rgb);
	(*isec)->normal = v_unit(v_sub_vec((*isec)->point, (*sp->origin)));
	return (true);
}

static bool	intersec_plane(t_ray *ray, t_plane *pl, t_intersec **isec)
{
	double	t;
	double	denom;
	t_v3	v;

	denom = v_dot_product(*pl->direction, ray->direction);
	if (fabs(denom) > EPSILON)
	{
		v = v_sub_vec((*pl->origin), ray->origin);
		t = v_dot_product(v, (*pl->direction)) / denom;
		if (t > EPSILON && t < (*isec)->nearest)
		{
			(*isec)->has_intersec = true;
			(*isec)->nearest = t;
			(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, t));
			(*isec)->normal = (*pl->direction);
			(*isec)->color = (*pl->rgb);
			return (true);
		}
	}
	return (false);
}

static bool	intersec_cylinder_disc(t_cylinder *cy, t_ray *ray, t_intersec **isec, t_plane *pl)
{
	t_hit	hit;

	hit.dv = v_dot_product(ray->direction, *cy->direction);
	hit.t = v_dot_product(v_sub_vec(*pl->origin, ray->origin), *cy->direction) / hit.dv;
	if (hit.dv == 0.0)
		return (false);
	hit.p = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	if (hit.t > (*isec)->min && hit.t < (*isec)->max && hit.t < (*isec)->nearest
		&& sqrtf(v_dot_product(v_sub_vec(hit.p, *pl->origin), 
		v_sub_vec(hit.p, *pl->origin))) <= cy->diameter / 2)
	{
		(*isec)->has_intersec = true;
		(*isec)->nearest = hit.t;
		(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
		(*isec)->color = (*cy->rgb);
		(*isec)->normal = v_unit(*cy->direction);
		return (true);
	}
	return (false);
}

static bool	intersec_cylinder_body(t_ray *ray, t_cylinder *cy, t_intersec **isec)
{
	t_hit	hit;

	hit.x = v_sub_vec(ray->origin, *cy->origin);
	hit.dv = v_dot_product(ray->direction, *cy->direction);
	hit.xv = v_dot_product(hit.x, *cy->direction);
	hit.a = pow(v_module(ray->direction), 2) - pow(hit.dv, 2);
	hit.hb = v_dot_product(hit.x, ray->direction) - (hit.dv * hit.xv);
	hit.c = pow(v_module(hit.x), 2) - pow(cy->diameter / 2, 2) - pow(hit.xv, 2);
	hit.dis = (hit.hb * hit.hb) - (hit.a * hit.c);
	if (hit.dis < 0.0 || hit.a == 0)
		return (false);
	hit.t = (-hit.hb - sqrt(hit.dis)) / hit.a;
	hit.p = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	hit.diff = v_sub_vec(*cy->origin, hit.p);
	if (hit.t > (*isec)->nearest || hit.t < (*isec)->min || hit.t > (*isec)->max)
		return (false);
	if (hit.t < (*isec)->nearest && fabs(v_dot_product(hit.diff, *cy->direction)) <= (cy->height / 2))
	{
		(*isec)->has_intersec = true;
		(*isec)->nearest = hit.t;
		(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
		(*isec)->color = (*cy->rgb);
		hit.dtop = v_dot_product(hit.diff, *cy->direction);
		hit.pcent = v_add_vec(*cy->origin, v_mult(*cy->direction, -hit.dtop));
		(*isec)->normal = v_unit(v_sub_vec((*isec)->point, hit.pcent));
		return (true);
	}
	return (false);
}

static bool	intersec_cylinder(t_ray *ray, t_cylinder *cy, t_intersec **isec)
{
	t_plane	pl1;
	t_plane	pl2;

	pl1.origin = v_pointer(v_add_vec(*cy->origin, v_mult(*cy->direction, (cy->height / 2))));
	pl1.rgb = cy->rgb;
	pl1.direction = cy->direction;
	pl2.origin = v_pointer(v_sub_vec(*cy->origin, v_mult(*cy->direction, (cy->height / 2))));
	pl2.rgb = cy->rgb;
	pl2.direction = v_pointer(v_mult(*cy->direction, -1));
	if (intersec_cylinder_body(ray, cy, isec) ||
		intersec_cylinder_disc(cy, ray, isec, &pl1) || 
		intersec_cylinder_disc(cy, ray, isec, &pl2))
		return (true);
	else
		return (false);
}

static void	intersec_init(t_intersec **isec)
{
	(*isec)->has_intersec = false;
	(*isec)->nearest = INFINITY;
	(*isec)->color = (t_rgb){0, 0, 0};
	(*isec)->min = EPSILON;
	(*isec)->max = INFINITY;
}

void	intersections(t_scene *scene, t_ray ray, t_intersec *isec)
{
	t_scene_set_to_head(&scene);
	intersec_init(&isec);
	while (scene)
	{
		if (scene->type == SPHERE)
			intersec_sphere(&ray, (t_sphere *)scene->data, &isec);
		else if (scene->type == PLANE)
			intersec_plane(&ray, (t_plane *)scene->data, &isec);
		else if (scene->type == CYLINDER)
			intersec_cylinder(&ray, (t_cylinder *)scene->data, &isec);
		scene = scene->next;
	}
}
