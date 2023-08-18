/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:20:56 by bsavinel          #+#    #+#             */
/*   Updated: 2023/08/18 17:04:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include <stdio.h>

void	test_atoi_base(void)
{
	printf("%s#################################\n#####    ATOI BASE TEST     #####\n#################################%s\n", PURPLE, NO_COLOR);
	printf("ret = %d\n", ft_atoi_base("chiffre", "base"));
}