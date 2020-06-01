
#include "lem_in.h"

int				main(void)
{
	int				*temp;
	unsigned char	error_handler;

	error_handler = get_map_info();
	if (error_handler == 1)
	{
		ft_putstr_fd("\nError\n", 2);
		return (2);
	}
	temp = (int*)ft_memalloc(sizeof(int) * create_struct()->count);
	temp[0] = create_struct()->ants;	
	if ( ft_check_room(*room_fetch())|| create_struct()->ants <= 0)
	{
		ft_putstr_fd("\nError\n", 2);
		return (2);
	}
	if (solve_map(create_struct()->ants, -1, -1, 0))
	{
		ft_putstr_fd("\nError\n", 2);
		return (2); 
	}
	ft_putchar('\n');	
	(void)print_results(create_struct()->ants, temp);	
	free(temp);	
	temp = NULL;	
	return (0);	
}
