/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:17:19 by hmthimun          #+#    #+#             */
/*   Updated: 2017/12/09 14:19:31 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

bool ft_atoi_base(char *str, unsigned int *result)
{
      int   base, digit;
      bool  fail;
            
      base = 10;                                      // assume decimal
      fail = false;

      *result = 0;                                    // start at zero

      if (*str)                                       // do nothing if it's a null string
      {
            if (*str == '0')                          // figure out the base
            {
                  str++;                                          // skip the zero

                  if (toupper(*str) == 'X')
                  {
                        base = 16;                          // leading 0x (or 0X), it's hex
                        str++;                                    // skip the x
                  }
                  else if (toupper(*str) == 'B')
                  {
                        base = 2;                           // leading 0b (or 0B), it's binary
                        str++;                                    // skip the b
                  }
                  else
                        base = 8;                           // leading 0, assume octal
            }

            while (*str && !fail)
            {
                  digit = toupper(*str++);      // force all upper case for hex digits
                  digit = (digit >= 'A') ? digit - 'A' + 0x0a : digit - '0';  // convert to 0-9, A-F (or try to)

                  if (digit >= 0 && digit < base)                 // make sure digit can be represented in this base
                        *result = *result * base + digit;   // shift up one order of magnitude, add in this digit
                  else
                        fail = true;                        // bad character, fail
            }
      }

      return(!fail);
}

int	main(int argc, char **argv)
{

	return (0);
}