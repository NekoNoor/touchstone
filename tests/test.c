/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vvissche@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 20:51:14 by nschat         #+#    #+#                */
/*   Updated: 2019/12/03 19:27:46 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "touchstone.h"
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	ts_assert(0);
	ts_assert(1);
	ts_assert_eq(ft_atoi("123"), atoi("123"));
	ts_assert_eq(ft_atoi("123"), atoi("124"));
	ts_assert_str_eq("string", "string");
	ts_assert_str_eq("string", "bring");
}
