/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:40:21 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/15 18:41:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdio.h>
#include <string.h>

static void	test_routine(const char *str)
{
	printf("%sTESTED STRING: \"%s\"%s\n", YELLOW, str, NO_COLOR);
	printf("%sstrlen = %zu%s\n", BLUE, strlen(str), NO_COLOR);
	printf("%sft_strlen = %zu%s\n", CYAN, ft_strlen(str), NO_COLOR);
}

void	test_strlen(void)
{
	printf("%s###########################\n####    STRLEN TEST    ####\n###########################%s\n", PURPLE, NO_COLOR);
	test_routine("");
	test_routine("Hello World!");
	test_routine("Ceci est un test");
	test_routine("Ceci est un test avec des chiffres 1234567890");
}
