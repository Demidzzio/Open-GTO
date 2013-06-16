/*
	
	About: misc utils
	Author: ziggi

*/

#if defined _utils_included
	#endinput
#endif

#define _utils_included
#pragma library utils


#define MAX_STRING	128
#define MAX_NAME	40
#define MAX_IP		16

#if !defined isnull
	#define isnull(%1) \
		((%1[0] == 0) || (%1[0] == 1 && %1[1] == 0))
#endif

#if !defined mathrandom
	#define mathrandom(%0,%1) \
		(random(%1 - %0 + 1) + %0)
#endif

stock bernstein(string[])
{
	new
		hash = -1,
		i,
		j;
	while ((j = string[i++]))
	{
		hash = hash * 33 + j;
	}
	return hash;
}
