#include "lem_in.h"

static unsigned char	ft_check_format(char *str) {
    int i;

    i = 1;
    if (!ft_strstr(str, " "))
		return (i);

    if (create_struct()->stop)
        return (i);

    while (*str != ' ')
		str++;
	str++;
	i++;
	if (!ft_isdigit(*str))
		return (i);
	while (ft_isdigit(*str))
		str++;
	str++;
	i++;
	if (!ft_isdigit(*str))
		return (i);
    if (!*str)
        return (i);

    while (ft_isdigit(*str))
		str++;
    str++;
	return (0);
}


unsigned char	create_room(char *str) {
	char *room;

	if (ft_check_format(str))
		return (1);
	room = ft_strsub(str, 0, ft_strstr(str, " ") - str);
	ft_lstadd(room_fetch(), ft_lstnew(room, ft_strlen(room) + 1));
	if (create_struct()->start)
        (*room_fetch())->content_size = 0;
	else
        (*room_fetch())->content_size = create_struct()->index;
	if (create_struct()->end)
        (*room_fetch())->content_size = (size_t)-1;
	else
        (*room_fetch())->content_size = (*room_fetch())->content_size;
    create_struct()->index = create_struct()->index + !(create_struct()->start || create_struct()->end);
	create_struct()->count = create_struct()->count + 1;
    if ((create_struct()->start))
        create_struct()->start = 0;
    if ((create_struct()->end))
        create_struct()->end = 0;

    free(room);
	return (0);
}