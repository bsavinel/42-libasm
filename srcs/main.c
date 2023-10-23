/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:40:32 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/23 11:04:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_strdup();
	test_write();
	test_read();
	return (0);
}
