#include "lem_in.h"

static unsigned char	ft_check_command(char *str) {
    if (!ft_strcmp("##start", str)) {
        create_struct()->start = 1;
        start = 1;
    }
    else {
        if (!ft_strcmp("##end", str)) {
            create_struct()->end = 1;
            end = 1;
        }
        else
            return 0;
    }
    return !(!create_struct()->start || !create_struct()->end);
}

unsigned char			get_map_info() {
	char			*str;
	unsigned char	check;
	int				ver_rooms = 0;

	if (get_next_line(0, &str) < 1)
		return (1);
	ft_putstr(str);
	ft_putchar('\n');
	if (ft_isnums(str))
	    check = 0;
	else
	    check = 1;
	create_struct()->ants = ft_atoi(str);
	free(str);
	while (get_next_line(0, &str) >= 1) {
        ft_putstr(str);
        ft_putchar('\n');
		if (!(check || *str != '#'))
			check = ft_check_command(str);
		else if (!(check || !ft_strstr(str, "-")))
			check = ft_add_path(str);
		else if (!(check || *str == 'L'))
		{
			check = create_room(str);
			ver_rooms = 1;
		}
		else
			check = 1;
		free(str);
	}
	if (ver_rooms != 1)
	{
		check = 1;
	}
	free(str);
	return (check);
}
