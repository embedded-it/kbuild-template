/*
 * Copyright (C) 2016 by Ole Reinhardt <ole.reinhardt@embedded-it.de>
 *
 * All rights reserved.
 *
 * For additional licensing information see COPYING.myapp
 */

#include <generated/autoconf.h>
#include <stdio.h>
#include <my_functions.h>

void debug_of_logging(void);

int main(void)
{
	printf("KBuild template sample application... Start!\n\n");

    printf("You have configured\n");
#ifdef CONFIG_FOO
    printf("\t- Foo\n");
#ifdef CONFIG_BAR
    printf("\t- Bar\n");
#endif
#else
    printf("\t- Neither Foo nor Bar\n");
#endif
    printf("\n");

	my_sample_function();

    printf("\nKBuild template sample application... Done!\n");

	return 0;
}
