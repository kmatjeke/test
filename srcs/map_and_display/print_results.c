#include "lem_in.h"

static unsigned char	show_result(int ants, int temp[], int room[], int ant_index)
{
	int			index;

	while (room[ant_index] != -1)	
	{
		if (!temp[room[ant_index]])	
			ant_index = room[ant_index];
		else
		{
			index = temp[room[ant_index]] - 1;
			temp[ant_index] = ((unsigned int)ant_index == create_struct()->count - 1) ? temp[ant_index] + 1 
															: temp[room[ant_index]]; 		
			temp[room[ant_index]] = (room[ant_index] == 0) ? temp[room[ant_index]] - 1 : 0;		
			ft_putstr("L");	
			ft_putnbr(ants - index);	
			ft_putchar('-');	
			ft_putstr(ft_find_name(*room_fetch(), ant_index)->content);	
			ft_putchar(' ');
			
			return (show_result(ants, temp, room, room[ant_index])); 
		}
	}
	return (0);
}

unsigned char	print_results(int ants, int temp[])
{
	t_list		*move; 

	if (temp[create_struct()->count - 1] == ants)	
		return (1);		
	move = *get_result();	
	while (move)
	{
		show_result(ants, temp, move->content, create_struct()->count - 1);	
		move = move->next; 
	}
	ft_putchar('\n');
	return (print_results(ants, temp));	
}