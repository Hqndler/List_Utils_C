#include "list_str.h"

static int	list_new_elem_str(t_list **new, char *elem)
{
	(*new) = malloc(sizeof(t_list));
	if (*new == NULL)
		return (0);
	(*new)->str = ft_strdup(elem);
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

static void	add_first(t_list **list, t_list *new)
{
	(*list) = new;
	(*list)->prev = *list;
	(*list)->next = *list;
}

int	list_addtop_str(t_list **list, char *elem)
{
	t_list	*new;

	if (!list_new_elem_str(&new, elem))
		return (0);
	if (!(*list))
		add_first(list, new);
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
		(*list) = new;
	}
	return (1);
}

int	list_append_str(t_list **list, char *elem)
{
	t_list	*new;

	if (!list_new_elem_str(&new, elem))
		return (0);
	if (!(*list))
		add_first(list, new);
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}

size_t	len_list(t_list *list)
{
	t_list	*tmp;
	size_t	i;

	if ((list))
	{
		tmp = list;
		i = 1;
		while (tmp->next != list)
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}

int	get_index_str(t_list *list, char *str)
{
	t_list	*tmp;
	size_t	len;

	tmp = list->prev;
	len = len_list(list) + 1;
	while (--len)
	{
		if (ft_strcmp(tmp->str, str))
			return (len);
		tmp = tmp->prev;
	}
	return (0);
}

int	insert_list_str(t_list **list, char *str, int index)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	if (!list_new_elem_str(&new, str))
		return (0);
	if (!(*list))
		add_first(list, new);
	else
	{
		i = -1;
		tmp = *list;
		if (index > (int)len_list(*list))
			index = (int)len_list(*list);
		while (++i < index)
			tmp = tmp->next;
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev->next = new;
		tmp->prev = new;
	}
	return (1);
}

void	print_list_str(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	printf("[");
	while (list && tmp->next != list)
	{
		printf("\"%s\", ", tmp->str);
		tmp = tmp->next;
	}
	if (list)
		printf("\"%s\"", tmp->str);
	printf("]\n");
}

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	current = *list;
	while (current->next != *list)
	{
		tmp = current;
		current = current->next;
		free(tmp->str);
		free(tmp);
	}
	free(current->str);
	free(current);
	*list = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (++i < argc)
		list_append_str(&list, argv[i]);
	print_list_str(list);
	printf("%ld\n", len_list(list));
	insert_list_str(&list, "insert ici", 30);
	print_list_str(list);
	free_list(&list);
}