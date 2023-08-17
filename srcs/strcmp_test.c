/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:52:23 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/17 15:24:39 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	test_routine(const char *str1, const char *str2)
{
	printf("%sTESTED STRING: \"%s\" <=> \"%s\"%s\n", YELLOW, str1, str2, NO_COLOR);
	printf("%sstrcmp    = %d %s\n", BLUE, strcmp(str1, str2), NO_COLOR);
	printf("%sft_strcmp = %d %s\n", CYAN, ft_strcmp(str1, str2), NO_COLOR);
}

void	test_strcmp(void)
{
	printf("%s###########################\n####    STRCMP TEST    ####\n###########################%s\n", PURPLE, NO_COLOR);
	test_routine("", "");
	test_routine("Hello Worldi!", "Hello World!");
	test_routine("Cec1i est un test", "Ceci est un test");
	test_routine("Ceci est un test avec des chiffres 1234567890", "Ceci est un test avec des chifffres 1234567890");
}