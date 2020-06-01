
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
#include <limits.h>

int start;
int end;

typedef struct		s_struct
{
	unsigned char	end;
	unsigned char	start;
	unsigned char	stop;
	unsigned int	count;
	unsigned int	index;
	int				dist;
	int				ants;
}					t_struct;

t_struct			*create_struct(void);
t_list				**room_fetch(void);
t_list				*ft_find_room(t_list *room, char *name, unsigned char alt);
t_list				*ft_find_name(t_list *room, size_t index);
unsigned char		ft_check_room(t_list *list);
unsigned char		create_room(char *str);

t_list				**get_result(void);
int					***get_path(void);
unsigned char		ft_remove_path(int parent[]);
unsigned char		ft_add_path(char *str);

int					ft_isnums(const char *str);
unsigned char		get_map_info(void);
int					solve_map(int ants, unsigned int c, unsigned int v, int u);
unsigned char		print_results(int ants, int temp[]);
#endif
