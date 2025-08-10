
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"

TYPE *char_new(char c)
{
	char *elem = malloc(sizeof(char));
	*elem = c;
	return elem;
}
char char_val(TYPE *e)
{
	return *((char *)e);
}

TYPE *sint32_new(SINT32 i)
{
	SINT32 *elem = malloc(sizeof(SINT32));
	*elem = i;
	return elem;
}

SINT32 sint32_val(TYPE *e)
{
	return *((SINT32 *)e);
}

TYPE *string_new(char *s)
{
	char *newstr = malloc(sizeof(s));
	strcpy(newstr, s);
	return newstr;
}
char *string_ptr(TYPE *e)
{
	return (char *)e;
}
