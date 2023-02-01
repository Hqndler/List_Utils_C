#ifndef LIST_STR_H
# define LIST_STR_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);

#endif