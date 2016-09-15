/*
 * Copyright (C) 2016 by Ole Reinhardt <ole.reinhardt@embedded-it.de>
 *
 * All rights reserved.
 *
 * For additional licensing information see COPYING.myapp
 */

#include <generated/autoconf.h> /* Must be first. */
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <logmsg.h>

/*!
 * \brief Output a normal log message.
 *
 * \param type Severity of this message.
 * \param fmt  Format string containing conversion specifications of the
 *             following list of parameters.
 */
#if CONFIG_LOG_ENABLE || !defined(__GNUC__)
void logmsg(unsigned int type, const char *fmt, ...)
{
#if CONFIG_LOG_ENABLE
    va_list ap;

    va_start(ap, fmt);

    if (type & LOG_ENABLE) {
#ifdef CONFIG_LOG_TIMESTAMP
        time_t timestamp = time(NULL);
        struct tm now;
        localtime_r(&timestamp, &now);
        printf("%04d.%02d.%02d-%02d:%02d:%02d ",
                     now.tm_year + 1900, now.tm_mon + 1, now.tm_mday,
                     now.tm_hour, now.tm_min, now.tm_sec);
#endif
        vprintf(fmt, ap);
    }
    va_end(ap);
    fflush(stdout);
#endif
}
#endif


/*@}*/
