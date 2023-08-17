/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:17:34 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/17 16:19:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	test_routine(const char *str)
{
	char *ptr;
	printf("%sTESTED STRING: \"%s\"%s\n", YELLOW, str, NO_COLOR);
	ptr = strdup(str);
	printf("%sstrdup    = \"%s\"%s\n", BLUE, ptr, NO_COLOR);
	free(ptr);
	ptr = ft_strdup(str);
	printf("%sft_strdup = \"%s\"%s\n", CYAN, ptr, NO_COLOR);
	free(ptr);
}

void	test_strdup(void)
{
	printf("%s###########################\n####    STRDUP TEST    ####\n###########################%s\n", PURPLE, NO_COLOR);
	test_routine("");
	test_routine("Hello World!");
	test_routine("Ceci est un test");
	test_routine("Ceci est un test avec des chiffres 1234567890");
}