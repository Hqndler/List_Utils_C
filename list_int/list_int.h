#ifndef LIST_INT_H
# define LIST_INT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

#endif