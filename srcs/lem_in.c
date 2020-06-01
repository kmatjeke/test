
#include "lem_in.h"

int				main(void)
{
	int				*temp;
	unsigned char	error_handler;		//variable will act as errorhandler for getting map information

	error_handler = get_map_info();	//function which gets data from the map files.
	if (error_handler == 1)
	{
		ft_putstr_fd("\nError\n", 2);
		return (-1);
	}
	temp = (int*)ft_memalloc(sizeof(int) * create_struct()->count);		//allocating the variable *temp memory.
	temp[0] = create_struct()->ants;							//assigning the first index of integer array *temp, the value of the number of ants.
	if ( ft_check_room(*room_fetch())|| create_struct()->ants <= 0) //if the number of ants are lower than 0, or if the is no start or end room.
	{
		ft_putstr_fd("\nError\n", 2);					//print error.
		return (-1);
	}
	if (solve_map(create_struct()->ants, -1, -1, 0))	//runs the function solve_map(which solves the map and removes unused paths)and if the function determines that the map is unsolvable.
	{
		ft_putstr_fd("\nError\n", 2);	//print error
		return (-1); 
	}
	ft_putchar('\n');	
	(void)print_results(create_struct()->ants, temp);		//runs print_results which actually prints the solution of the map.
	free(temp);					//frees memory to avoid memory leaks
	temp = NULL;				//resseting the variable temp to null.
	return (0);	
}
