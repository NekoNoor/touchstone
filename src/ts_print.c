/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ts_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 21:08:40 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/30 23:45:31 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "touchstone.h"
#include "libft.h"

static void	ts_putstr(char *str)
{
	ft_putstr_fd(str, 1);
}

static void	ts_putulong(unsigned long n)
{
	if (n >= 10)
		ts_putulong(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

void		ts_pass(char *file, unsigned line, char *result)
{
	ts_putstr(PASS_MESSAGE);
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	ts_putstr(" is non-zero\n");
}

void	ts_fail(char *file, unsigned line, char *result)
{
	ts_putstr(FAIL_MESSAGE);
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	ts_putstr(" is zero\n");
}

void	ts_pass_eq(char *file, unsigned line, char *result, char *expected)
{
	ts_putstr(PASS_MESSAGE);
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	ts_putstr(" == ");
	ts_putstr(expected);
	ts_putstr("\n");
}

void	ts_fail_eq(char *file, unsigned line, char *result, char *expected)
{
	ts_putstr(FAIL_MESSAGE);
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	ts_putstr(" != ");
	ts_putstr(expected);
	ts_putstr("\n");
}
