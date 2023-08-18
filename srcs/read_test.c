/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:17:29 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/18 15:42:40 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	test_routine(int fd, int len)
{
	char *ptr;
	int ret;
	
	ptr = malloc(sizeof(char) * (len + 1));
	
	printf("%sTESTED FD: %d%s\n", YELLOW, fd, NO_COLOR);
	bzero(ptr, len + 1);
	ret = read(fd, ptr, len);
	if (ret != -1)
		printf("%sread    => \"%s\" ret = %d%s\n", BLUE, ptr, ret, NO_COLOR);
	else
		printf("%sread    => %serrno = %d%s\n", BLUE, RED, errno, NO_COLOR);

	errno = 0;
	bzero(ptr, len + 1);
	ret = ft_read(fd, ptr, len);
	if (ret != -1)
		printf("%sft_read => \"%s\" ret = %d%s\n", CYAN, ptr, ret, NO_COLOR);
	else
		printf("%sread    => %serrno = %d%s\n", BLUE, RED, errno, NO_COLOR);
	free(ptr);
}

void	test_read(void)
{
	int fd = open("Makefile", O_RDONLY);
	printf("%s###########################\n####     READ TEST     ####\n###########################%s\n", PURPLE, NO_COLOR);
	printf("%sFD %d : Makefile%s\n",GREEN, fd, NO_COLOR);
	test_routine(fd,0);
	test_routine(fd,5);
	test_routine(fd,24);
	test_routine(fd + 4, 10);
	close(fd);
}