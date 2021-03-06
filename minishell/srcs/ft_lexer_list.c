/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 14:22:08 by etermeau          #+#    #+#             */
/*   Updated: 2015/03/13 14:22:10 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_add_lex(t_lex **list, char *word)
{
	t_lex	*new;
	t_lex	*tmp;

	new = ft_new_lex(word);
	tmp = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = (*list);
		while (tmp)
		{
			if (!(tmp->next))
				break ;
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

t_lex	*ft_new_lex(char *word)
{
	t_lex	*tmp;

	if (!(tmp = (t_lex *)malloc(sizeof(t_lex))))
		code_erreur(0, NULL);
	if (word)
		tmp->word = word;
	else
		tmp->word = NULL;
	tmp->next = NULL;
	return (tmp);
}
