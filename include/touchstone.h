/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   touchstone.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vvissche <vvissche@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 14:22:53 by nschat         #+#    #+#                */
/*   Updated: 2019/12/04 15:57:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOUCHSTONE_H
# define TOUCHSTONE_H

# include <string.h>

# define FAIL_MESSAGE "\x1B[97m[\x1B[91mFAIL\x1B[97m]\x1B[0m \x1B[93m"
# define PASS_MESSAGE "\x1B[97m[\x1B[92mPASS\x1B[97m]\x1B[0m \x1B[93m"
# define LINE_DIVIDER "\x1B[97m:\x1B[96m"
# define DONE_MESSAGE "\x1B[97m[\x1B[93mDONE\x1B[97m]\x1B[0m \x1B[93m"
# define ARROW_DIVIDER "\x1B[97m -> \x1B[94m"

# define ts_assert(result) \
	ts_result(__FILE__, __LINE__, (size_t)result, #result)

# define ts_assert_eq(result, expected) \
	ts_result_eq(__FILE__, __LINE__, (result == expected), #result, #expected)

# define ts_assert_str_eq(result, expected) \
	ts_result_eq(__FILE__, __LINE__, strcmp(result, expected) == 0, #result, #expected)

void	ts_result(char *file, unsigned line, size_t expr, char *result);
void	ts_result_eq(char *file, unsigned line, size_t expr, char *result, char *expected);
void	ts_finish();

#endif
