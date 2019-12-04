/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ts_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vvissche <vvissche@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 21:08:40 by nschat         #+#    #+#                */
/*   Updated: 2019/12/04 15:59:44 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "touchstone.h"
#include "libft.h"

size_t	g_num_pass = 0;
size_t	g_num_fail = 0;

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

void		ts_result(char *file, unsigned line, size_t expr, char *result)
{
	if (expr)
	{
		ts_putstr(PASS_MESSAGE);
		g_num_pass++;
	}
	else
	{
		ts_putstr(FAIL_MESSAGE);
		g_num_fail++;
	}
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	if (expr)
		ts_putstr(" is non-zero\n");
	else
		ts_putstr(" is zero\n");
}

void	ts_result_eq(char *file, unsigned line, size_t expr, char *result, char *expected)
{
	if (expr)
	{
		ts_putstr(PASS_MESSAGE);
		g_num_pass++;
	}
	else
	{
		ts_putstr(FAIL_MESSAGE);
		g_num_fail++;
	}
	ts_putstr(file);
	ts_putstr(LINE_DIVIDER);
	ts_putulong(line);
	ts_putstr(ARROW_DIVIDER);
	ts_putstr(result);
	if (expr)
		ts_putstr(" == ");
	else
		ts_putstr(" != ");
	ts_putstr(expected);
	ts_putstr("\n");
}

void	ts_finish()
{
	ts_putstr(DONE_MESSAGE);
	ts_putstr("\x1B[0mTested: \x1B[93m");
	ts_putulong(g_num_fail + g_num_pass);
	ts_putstr("\x1B[0m | Passing: \x1B[92m");
	ts_putulong(g_num_pass);
	ts_putstr("\x1B[0m | Failing: \x1B[91m");
	ts_putulong(g_num_fail);
	ts_putstr("\x1B[0m\n");
}
