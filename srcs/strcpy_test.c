/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:58:52 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/17 13:59:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	test_routine(const char *str)
{
	char *dest = malloc(sizeof(char) * (strlen(str) + 1));
	
	printf("%sTESTED STRING: \"%s\"%s\n", YELLOW, str, NO_COLOR);
	bzero(dest, strlen(str) + 1);
	printf("%sstrcpy    -> ret = %p dest = |%s| src = |%s|%s\n", BLUE, strcpy(dest, str), dest, str, NO_COLOR);
	bzero(dest, strlen(str) + 1);
	printf("%sft_strcpy -> ret = %p dest = |%s| src = |%s|%s\n", CYAN, ft_strcpy(dest, str), dest, str, NO_COLOR);
}

void	test_strcpy(void)
{
	printf("%s###########################\n####    STRLCPY TEST    ####\n###########################%s\n", PURPLE, NO_COLOR);
	test_routine("");
	test_routine("Hello World!");
	test_routine("Ceci est un test");
	test_routine("Ceci est un test avec des chiffres 1234567890");
}