#include "lem_in.h"

unsigned char	ft_add_path(char *str) {
	t_list *list[2];

	create_struct()->stop = 1;
	list[0] = ft_find_room(*room_fetch(), str, ft_strstr(str, "-") - str);
	list[1] = ft_find_room(*room_fetch(), ft_strstr(str, "-") + 1, 0);
	if (!(list[0] && list[1]))
		return (1);
	if (list[0]->content_size == (size_t)-1)
		list[0]->content_size = create_struct()->index;
	else if (list[1]->content_size == (size_t)-1)
		list[1]->content_size = create_struct()->index;
    (*get_path())[list[0]->content_size][list[1]->content_size] = 1;
	(*get_path())[list[1]->content_size][list[0]->content_size] = (*get_path())[list[0]->content_size][list[1]->content_size];
	return (0);
}

unsigned char	ft_remove_path(int block[])
{
	int		remove;

	remove = create_struct()->count - 1;
	while (block[remove] != -1)
	{
		(*get_path())[remove][block[remove]] = 0;
		(*get_path())[block[remove]][remove] = 0;
		remove = block[remove];
	}
	return (1);
}

int			***get_path(void)
{
	static int		**path = NULL;  
	unsigned int	i;

	if (start != 1 || end != 1) {
	    ft_putstr("\nError\n");
	    exit(0);
	}

	if (path == NULL)
	{
		path = (int**)ft_memalloc(sizeof(int*) * create_struct()->count);
		i = 0;
		while (i < create_struct()->count)
			path[i++] = (int*)ft_memalloc(sizeof(int) * create_struct()->count); 
	}
	return (&path);
}