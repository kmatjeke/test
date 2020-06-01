
#include "lem_in.h"


t_list		**get_result(void)
{
	static t_list	*result = NULL;

	return (&result);
}

t_list		**room_fetch(void)
{
	static t_list	*rooms = NULL;

	return (&rooms);
}

t_struct		*create_struct(void)
{
	static t_struct	frame = {0, 0, 0, 0, 1, INT_MAX, 0};

	return (&frame);
}
