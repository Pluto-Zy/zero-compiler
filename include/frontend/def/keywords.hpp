/**
 * @file keywords.hpp
 * This file defines all the keywords in the language. Each keyword must be
 * wrapped by the `ZEROC_KEYWORD` macro. It could be included multiple times to
 * generate appropriate code.
 */

#ifndef ZEROC_KEYWORD
#  define ZEROC_KEYWORD(spelling)
#endif

// C99 6.4.1 Keywords
// clang-format off
ZEROC_KEYWORD(auto)
ZEROC_KEYWORD(break)
ZEROC_KEYWORD(case)
ZEROC_KEYWORD(char)
ZEROC_KEYWORD(const)
ZEROC_KEYWORD(continue)
ZEROC_KEYWORD(default)
ZEROC_KEYWORD(do)
ZEROC_KEYWORD(double)
ZEROC_KEYWORD(else)
ZEROC_KEYWORD(enum)
ZEROC_KEYWORD(extern)
ZEROC_KEYWORD(float)
ZEROC_KEYWORD(for)
ZEROC_KEYWORD(goto)
ZEROC_KEYWORD(if)
ZEROC_KEYWORD(inline)
ZEROC_KEYWORD(int)
ZEROC_KEYWORD(long)
ZEROC_KEYWORD(register)
ZEROC_KEYWORD(restrict)
ZEROC_KEYWORD(return)
ZEROC_KEYWORD(short)
ZEROC_KEYWORD(signed)
ZEROC_KEYWORD(sizeof)
ZEROC_KEYWORD(static)
ZEROC_KEYWORD(struct)
ZEROC_KEYWORD(switch)
ZEROC_KEYWORD(typedef)
ZEROC_KEYWORD(union)
ZEROC_KEYWORD(unsigned)
ZEROC_KEYWORD(void)
ZEROC_KEYWORD(volatile)
ZEROC_KEYWORD(while)
ZEROC_KEYWORD(_Bool)
ZEROC_KEYWORD(_Complex)
ZEROC_KEYWORD(_Imaginary)
// clang-format on
