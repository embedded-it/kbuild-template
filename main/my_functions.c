/*
 * Copyright (C) 2016 by Ole Reinhardt <ole.reinhardt@embedded-it.de>
 *
 * All rights reserved.
 *
 * For additional licensing information see COPYING.myapp
 */

#include <generated/autoconf.h>
#include <stdio.h>
#include <logmsg.h>

/*
 * This is just a sample function, called by main()
 */
void my_sample_function(void)
{
    printf("Depending on your configuration, several log messages will be printed now:\n\n");

	logmsg(LOG_INFO, "This is a LOG_INFO log message.\n");
	logmsg(LOG_WARN, "This is a LOG_WARN log message.\n");
	logmsg(LOG_ERROR, "This is a LOG_ERROR log message.\n");
	logmsg(LOG_DEBUG, "This is a LOG_DEBUG log message.\n");
}
