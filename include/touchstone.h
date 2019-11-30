/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   touchstone.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 14:22:53 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/30 23:33:08 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOUCHSTONE_H
# define TOUCHSTONE_H

# define FAIL_MESSAGE "\x1B[97m[\x1B[91mFAIL\x1B[97m]\x1B[0m \x1B[93m"
# define PASS_MESSAGE "\x1B[97m[\x1B[92mPASS\x1B[97m]\x1B[0m \x1B[93m"
# define LINE_DIVIDER "\x1B[97m:\x1B[96m"
# define ARROW_DIVIDER "\x1B[97m -> \x1B[94m"

# define ts_assert(result) \
	(result) ? \
	pass(#result) : \
	fail(#result)
# define pass(result) \
	ts_pass(__FILE__, __LINE__, #result)
# define fail(result) \
	ts_fail(__FILE__, __LINE__, #result)

# define ts_assert_eq(result, expected) \
	(result == expected) ? \
	pass_eq(result, expected) : \
	fail_eq(result, expected)
# define pass_eq(result, expected) \
	ts_pass_eq(__FILE__, __LINE__, #result, #expected)
# define fail_eq(result, expected) \
	ts_fail_eq(__FILE__, __LINE__, #result, #expected)

void	ts_pass(char *file, unsigned line, char *result);
void	ts_fail(char *file, unsigned line, char *result);
void	ts_pass_eq(char *file, unsigned line, char *result, char *expected);
void	ts_fail_eq(char *file, unsigned line, char *result, char *expected);

#endif
