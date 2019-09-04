/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:53 by agelloz           #+#    #+#             */
/*   Updated: 2019/09/04 18:45:32 by agelloz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stacks(t_stack *a, t_stack *b)
{
	t_list	*curr;

	curr = a->head;
	while (curr->next)
	{
		if (*(int *)curr->content > *(int *)curr->next->content)
			return (0);
		curr = curr->next;
	}
	if (b->head)
		return (0);
	return (1);
}

int	ft_check_line(char *line)
{
	if (line[0] == '\0')
		return (0);
	else if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
			&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
			&& ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
			&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
			&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
			&& ft_strcmp(line, "rrr"))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	ft_check_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_check_line(line))
		return (0);
	//printf("Avant:%s\n", line);
	//ft_display_stacks(*a, *b);
	//ft_putchar('\n');
	(!ft_strcmp(line, "sa")) ? ft_swap(a, 0) : 0;
	(!ft_strcmp(line, "sb")) ? ft_swap(b, 0) : 0;
	(!ft_strcmp(line, "ss")) ? ft_rotate(a, 0) : 0;
	(!ft_strcmp(line, "ss")) ? ft_rotate(b, 0) : 0;
	(!ft_strcmp(line, "pa")) ? ft_push(b, a, 0) : 0;
	(!ft_strcmp(line, "pb")) ? ft_push(a, b, 0) : 0;
	(!ft_strcmp(line, "ra")) ? ft_rotate(a, 0) : 0;
	(!ft_strcmp(line, "rb")) ? ft_rotate(b, 0) : 0;
	(!ft_strcmp(line, "rr")) ? ft_rotate(a, 0) : 0;
	(!ft_strcmp(line, "rr")) ? ft_rotate(b, 0) : 0;
	(!ft_strcmp(line, "rra")) ? ft_reverse_rotate(a, 0) : 0;
	(!ft_strcmp(line, "rrb")) ? ft_reverse_rotate(b, 0) : 0;
	(!ft_strcmp(line, "rrr")) ? ft_reverse_rotate(a, 0) : 0;
	(!ft_strcmp(line, "rrr")) ? ft_reverse_rotate(b, 0) : 0;
	//sleep(1);
	//printf("Success:%s\n", line);
	//ft_display_stacks(*a, *b);
	//ft_putchar('\n');
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (!(a = malloc(sizeof(*a)))
			|| !(b = malloc(sizeof(*b))))
		return (0);
	a->head = NULL;
	b->head = NULL;
	line = NULL;
	if (ac < 2 || !ft_fill_a(&a, ac, av))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_check_instruction(line, &a, &b))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ft_check_stacks(a, b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_display_stacks(a, b);
	ft_delete_stacks(a, b);
	return (0);
}
