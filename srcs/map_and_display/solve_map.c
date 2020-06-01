
#include "lem_in.h"
#include <limits.h>


static int		find_shortest_path(int dist[], int visited[])
{
	int				min_dist;
	int				min_index;
	unsigned int	v_index;

	min_dist = INT_MAX;
	v_index = 0; 
	while (create_struct()->count > v_index)
	{
		if (!visited[v_index] && dist[v_index] <= min_dist)
		{
			min_dist = dist[v_index];
			min_index = v_index;
		}
		v_index++;
	}
	return (min_index); 
}


static unsigned char	ft_initialise_solver(int (*dist)[], int (*visited)[], int (*source)[])
{
	unsigned int	i;

	i = 0;
	while (create_struct()->count > i)
	{
		(*dist)[i] = INT_MAX;
		(*visited)[i] = 0;
		(*source)[0] = -1;
		i++;
	}
	(*dist)[0] = 0;
	return (0);
}


int				solve_map(int ants, unsigned int x, unsigned int v_index, int short_path)
{
	int				visited[create_struct()->count];
	int				source[create_struct()->count];
	int				dist[create_struct()->count];

	(void)ft_initialise_solver(&dist, &visited, &source);
	while (++x < create_struct()->count - 1)
	{
		v_index = -1;
		short_path = find_shortest_path(dist, visited);
		visited[short_path] = 1; 
		while (++v_index < create_struct()->count)
			if (!visited[v_index] && (*get_path())[short_path][v_index] && dist[short_path] != INT_MAX
							&& dist[short_path] + (*get_path())[short_path][v_index] < dist[v_index])
			{
				source[v_index] = short_path; 
				dist[v_index] = dist[short_path] + (*get_path())[short_path][v_index]; 
			}
	}
	if (create_struct()->dist < dist[create_struct()->count - 1]
						|| dist[create_struct()->count - 1] == INT_MAX)
		return (create_struct()->dist == INT_MAX);
	create_struct()->dist = dist[create_struct()->count - 1];
	ft_lstadd(get_result(), ft_lstnew(source, sizeof(source))); 
	(void)ft_remove_path((*get_result())->content);
	return (solve_map(ants, -1, -1, 0));
}
