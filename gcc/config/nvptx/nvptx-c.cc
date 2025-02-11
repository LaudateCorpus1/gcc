/* Subroutines for the C front end on the NVPTX architecture.
 * Copyright (C) 2021-2022 Free Software Foundation, Inc.
 *
 * This file is part of GCC.
 *
 * GCC is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3, or (at your
 * option) any later version.
 *
 * GCC is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GCC; see the file COPYING3.  If not see
 * <http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "c-family/c-common.h"
#include "memmodel.h"
#include "tm_p.h"
#include "c-family/c-pragma.h"

/* Function to tell the preprocessor about the defines for the target.  */
void
nvptx_cpu_cpp_builtins (void)
{
  cpp_assert (parse_in, "machine=nvptx");
  cpp_assert (parse_in, "cpu=nvptx");
  cpp_define (parse_in, "__nvptx__");
  if (TARGET_SOFT_STACK)
    cpp_define (parse_in, "__nvptx_softstack__");
  if (TARGET_UNIFORM_SIMT)
    cpp_define (parse_in,"__nvptx_unisimt__");
  if (TARGET_SM80)
    cpp_define (parse_in, "__PTX_SM__=800");
  else if (TARGET_SM75)
    cpp_define (parse_in, "__PTX_SM__=750");
  else if (TARGET_SM70)
    cpp_define (parse_in, "__PTX_SM__=700");
  else if (TARGET_SM53)
    cpp_define (parse_in, "__PTX_SM__=530");
  else if (TARGET_SM35)
    cpp_define (parse_in, "__PTX_SM__=350");
  else
    cpp_define (parse_in,"__PTX_SM__=300");
}

