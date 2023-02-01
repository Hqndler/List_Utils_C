#include "list_int.h"

static int	list_new_elem(t_list **new, int elem)
{
	(*new) = malloc(sizeof(t_list));
	if (*new == NULL)
		return (0);
	(*new)->value = elem;
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

int	addtop(t_list **list, int elem)
{
	t_list	*new;

	if (!list_new_elem(&new, elem))
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

int	append(t_list **list, int elem)
{
	t_list	*new;

	if (!list_new_elem(&new, elem))
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

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	current = *list;
	while (current->next != *list)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	*list = NULL;
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	printf("[");
	while (list && tmp->next != list)
	{
		printf("%d, ", tmp->value);
		tmp = tmp->next;
	}
	if (list)
		printf("%d", tmp->value);
	printf("]\n");
}

int	get_max(t_list *pile)
{
	int		max;
	t_list	*tmp;

	tmp = pile->next;
	max = pile->value;
	while (tmp != pile && tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp-> next;
	}
	return (max);
}

int	get_index(t_list *pile, int elem)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = pile;
	while (tmp->next != pile)
	{
		if (tmp->value == elem)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_min(t_list *pile)
{
	int		min;
	t_list	*tmp;

	tmp = pile->next;
	min = pile->value;
	while (tmp != pile && tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp-> next;
	}
	return (min);
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

int	insert(t_list **list, int elem, int index)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	if (!list_new_elem(&new, elem))
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

int	main(int argc, char **argv)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (++i < argc)
		append(&head, atoi(argv[i]));
	print_list(head);
	insert(&head, 20, 20);
	print_list(head);
	free_list(&head);
}