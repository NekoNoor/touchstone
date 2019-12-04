/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ts_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vvissche <vvissche@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 21:08:40 by nschat         #+#    #+#                */
/*   Updated: 2019/12/04 15:26:18 by vvissche      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TS_SETUP
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
	num_pass++;
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
	num_fail++;
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
	num_pass++;
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
	num_fail++;
}

void	ts_finish()
{
	ts_putstr(DONE_MESSAGE);
	ts_putstr("\x1B[0;39mTested ");
	ts_putulong(num_fail + num_pass);
	ts_putstr(" | Passing: \x1B[0;32m");
	ts_putulong(num_pass);
	ts_putstr("\x1B[0;39m | Failing: \x1B[31m");
	ts_putulong(num_fail);
	ts_putstr("\x1B[39m\n");
}

void	ts_setup()
{
	num_pass = 0;
	num_fail = 0;
}
