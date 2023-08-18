/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:17:24 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/18 15:38:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static void	test_routine(const char *str)
{
	int ret;
	int len = 10;
	
	if (str)
		len = strlen(str);
	
	printf("%sTESTED STRING: \"%s\"%s\n", YELLOW, str, NO_COLOR);
	printf("%swrite    =>\n", BLUE);
	ret = write(1, str, len);
	if (ret != -1)
		printf("\nret = %d%s\n", ret, NO_COLOR);
	else
		printf("%serrno = %d%s\n", RED, errno, NO_COLOR);
	
	errno = 0;
	printf("%sft_write =>\n", CYAN);
	ret = ft_write(1, str, len);
	if (ret != -1)
		printf("\nret = %d%s\n", ret, NO_COLOR);
	else
		printf("%serrno = %d%s\n", RED, errno, NO_COLOR);
}

void	test_write(void)
{
	printf("%s###########################\n####    WRITE TEST     ####\n###########################%s\n", PURPLE, NO_COLOR);
	test_routine("");
	test_routine("Hello World!");
	test_routine("Ceci est un test");
	test_routine("Ceci est un test avec des chiffres 1234567890");
	test_routine(NULL);
}