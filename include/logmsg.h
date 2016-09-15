/*
 * Copyright (C) 2016 by Ole Reinhardt <ole.reinhardt@embedded-it.de>
 *
 * All rights reserved.
 *
 * For additional licensing information see COPYING.myapp
 */

#ifndef _LOGMSG_H_
#define _LOGMSG_H_

#include <generated/autoconf.h>


#ifdef CONFIG_LOG_INFO 
#define LOG_INFO        0x0001
#else
#define LOG_INFO        0
#endif

#ifdef CONFIG_LOG_WARN 
#define LOG_WARN        0x0002
#else
#define LOG_WARN        0
#endif

#ifdef CONFIG_LOG_ERROR 
#define LOG_ERROR       0x0004
#else
#define LOG_ERROR       0
#endif

#ifdef CONFIG_LOG_DEBUG 
#define LOG_DEBUG       0x0008
#else
#define LOG_DEBUG       0
#endif

#ifdef CONFIG_LOG_ENABLE

#define LOG_ENABLE (LOG_INFO | LOG_WARN | LOG_ERROR | LOG_DEBUG)

extern void logmsg(unsigned int type, const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));

#else

#if defined(__GNUC__)
#define logmsg(type, fmt, args...) ((void)0)
#endif

#endif /* CONFIG_LOG_ENABLE */

#endif /* _LOGMSG_H_ */
