/* src/include/pcp/config.h.  Generated from config.h.in by configure.  */
/*
 * Copyright (c) 2012-2013 Red Hat.
 * Copyright (c) 2003 Moser, Inc.  All Rights Reserved.
 * Copyright (c) 2000-2004,2008 Silicon Graphics, Inc.  All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef _PCP_CONFIG_H
#define _PCP_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

/*
 * The type of timestamps in struct stat: either HAVE_STAT_TIMESPEC,
 * HAVE_STAT_TIMESPEC_T, HAVE_STAT_TIMESTRUC or HAVE_STAT_TIME_T
 */
/* #undef HAVE_STAT_TIMESPEC_T */
/* #undef HAVE_STAT_TIMESTRUC */
#define HAVE_STAT_TIMESPEC 1
/* #undef HAVE_STAT_TIME_T */

/* HAVE_ST_MTIME if stat.st_mtime has a ``spec'' on the end */
/* #undef HAVE_ST_MTIME_WITH_SPEC */

/* HAVE_ST_MTIME if stat.st_mtime has an ``e'' on the end */
/* #undef HAVE_ST_MTIME_WITH_E */

/* if your compiler supports LL sufix on 64 bit int constants */
#define HAVE_CONST_LONGLONG 1

/*
 * HAVE_UNDERBAR_ENVIRON if extern char **_environ is defined
 * (else extern char **environ will be used)
 */
/* #undef HAVE_UNDERBAR_ENVIRON */

/*
 * If the pointer-to-function arguments to scandir()
 * are (*scanfn)(const struct dirent *dep)
 * Otherwise ``const'' will be omitted.
 */
#define HAVE_CONST_DIRENT 1

/*
 * If the dirent structure contains a directory offset field.
 */
/* #undef HAVE_DIRENT_D_OFF */

/*
 * If getopt() needs $POSIXLY_CORRECT set in the environment to work
 * correctly, specifically to not treat -x as an option when foo is
 * invoked with the arguments "arg -x"
 */
#define HAVE_GETOPT_NEEDS_POSIXLY_CORRECT 1

/* Defined if printf %p -> 0x prefix for value */
#define HAVE_PRINTF_P_PFX 1
#ifdef HAVE_PRINTF_P_PFX
#define PRINTF_P_PFX ""
#else
#define PRINTF_P_PFX "0x"
#endif

/* Defined if bit fields are allocated left-to-right within a word */
/* #undef HAVE_BITFIELDS_LTOR */

/* if compiler can cast __uint64_t to double */
#define HAVE_CAST_U64_DOUBLE 1

/* long and pointer must be either 32 bit or 64 bit */
#define HAVE_64BIT_LONG 1
/* #undef HAVE_32BIT_LONG */
/* #undef HAVE_32BIT_PTR */
#define HAVE_64BIT_PTR 1

/* Define if header file is available */
#define HAVE_FCNTL_H 1
#define HAVE_LIMITS_H 1
#define HAVE_MALLOC_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYSLOG_H 1
#define HAVE_UNISTD_H 1
#define HAVE_STDDEF_H 1
#define HAVE_SCHED_H 1
#define HAVE_DLFCN_H 1
/* #undef HAVE_DL_H */
/* #undef HAVE_IEEEFP_H */
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TIMEB_H 1
#define HAVE_SYS_TIMES_H 1
#define HAVE_SYS_SYSINFO_H 1
/* #undef HAVE_SYS_SYSTEMINFO_H */
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_SYS_PRCTL_H 1
#define HAVE_ENDIAN_H 1
/* #undef HAVE_STANDARDS_H */
/* #undef HAVE_SYS_BYTEORDER_H */
#define HAVE_PTHREAD_H 1
#define HAVE_GETOPT_H 1
#define HAVE_VALUES_H 1
#define HAVE_LIBGEN_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_MMAN_H 1
#define HAVE_SYS_UN_H 1
#define HAVE_STDINT_H 1
#define HAVE_PWD_H 1
#define HAVE_GRP_H 1
#define HAVE_REGEX_H 1
#define HAVE_TERMIO_H 1
#define HAVE_TERMIOS_H 1
#define HAVE_SYS_TERMIOS_H 1
#define HAVE_SYS_IOCTL_H 1
#define HAVE_SYS_WAIT_H 1
/* #undef HAVE_WINDOWS_H */
/* #undef HAVE_WINSOCK2_H */
/* #undef HAVE_WS2TCPIP_H */
#define HAVE_EXECINFO_H 1
/* #undef HAVE_IPTYPES_H */
#define HAVE_NETDB_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETINET_TCP_H 1
#define HAVE_ARPA_INET_H 1

/* #undef HAVE_SYS_ENDIAN_H */
/* #undef HAVE_SYS_MACHINE_H */
/* #undef HAVE_MACHINE_ENDIAN_H */

#define HAVE_AI_ADDRCONFIG 1

#if defined(HAVE_MALLOC_H)
#include <malloc.h>
#endif
#if defined(HAVE_STDDEF_H)
#include <stddef.h>
#endif
#if defined(HAVE_SYSLOG_H)
#include <syslog.h>
#endif
#if defined(HAVE_WINDOWS_H)
#include <windows.h>
#endif
#if defined(HAVE_WINSOCK2_H)
#include <winsock2.h>
#endif
#if defined(HAVE_WS2TCPIP_H)
#include <ws2tcpip.h>
#endif
#if defined(HAVE_SYS_TIMEB_H)
#include <sys/timeb.h>
#endif

/* HAVE_NETWORK_BYTEORDER for big endian systems (not Intel) */
#if defined(HAVE_ENDIAN_H)
#include <endian.h>
#elif defined(HAVE_SYS_ENDIAN_H)
#include <sys/endian.h>
#elif defined(HAVE_MACHINE_ENDIAN_H)
#include <machine/endian.h>
#endif
#if defined(HAVE_ENDIAN_H) || defined(HAVE_SYS_ENDIAN_H) || defined(HAVE_MACHINE_ENDIAN_H)
#if defined(BYTE_ORDER) && BYTE_ORDER == BIG_ENDIAN
#define HAVE_NETWORK_BYTEORDER
#endif
#endif

#if defined(HAVE_SYS_BYTEORDER_H)
#include <sys/byteorder.h>
#if defined(_BIG_ENDIAN)
#define HAVE_NETWORK_BYTEORDER
#endif
#endif

#if defined(HAVE_SYS_MACHINE_H)
#include <sys/machine.h>
#if defined(BYTE_ORDER) && BYTE_ORDER == BIG_ENDIAN
#define HAVE_NETWORK_BYTEORDER
#endif
#endif

/* define which libraries are available */
#define HAVE_SECURE_SOCKETS 1
#define HAVE_STATIC_PROBES 1
/* #undef HAVE_LIBREGEX */
#define HAVE_READLINE 1

/* define which libc functions are available */
#define HAVE_WAIT3 1

#define HAVE_MKTIME 1
#define HAVE_UNSETENV 1

#define HAVE_SELECT 1
#define HAVE_SOCKET 1
#define HAVE_GETHOSTNAME 1
/* #undef HAVE_GETPEERUCRED */
/* #undef HAVE_GETPEEREID */

#define HAVE_UNAME 1
#define HAVE_SYSLOG 1
#define HAVE___CLONE 1
#define HAVE_PIPE2 1
#define HAVE_FCNTL 1

#define HAVE_PRCTL 1
#define HAVE_SETLINEBUF 1
#define HAVE_WAITPID 1
#define HAVE_ATEXIT 1
#define HAVE_KILL 1

#define HAVE_CHOWN 1
#define HAVE_GETCWD 1
#define HAVE_SCANDIR 1
#define HAVE_MKSTEMP 1

#define HAVE_GETGRENT 1
#define HAVE_GETGRENT_R 1
#define HAVE_GETGRNAM 1
#define HAVE_GETGRNAM_R 1
#define HAVE_GETGRGID 1
#define HAVE_GETGRGID_R 1
#define HAVE_GETPWENT 1
#define HAVE_GETPWENT_R 1
#define HAVE_GETPWNAM 1
#define HAVE_GETPWNAM_R 1
#define HAVE_GETPWUID 1
#define HAVE_GETPWUID_R 1

#define HAVE_BRK 1
#define HAVE_SBRK 1
#define HAVE_POSIX_MEMALIGN 1
#define HAVE_MEMALIGN 1
#define HAVE_VALLOC 1

#define HAVE_NANOSLEEP 1
/* #undef HAVE_USLEEP */

#define HAVE_SIGNAL 1
#define HAVE_SIGHOLD 1
#define HAVE_SIGRELSE 1
#define HAVE_TCGETATTR 1
#define GWINSZ_IN_SYS_IOCTL 1

/* #undef HAVE_REGEX */
/* #undef HAVE_REGCMP */
#define HAVE_REGEXEC 1
#define HAVE_REGCOMP 1

#define HAVE_STRTOD 1
#define HAVE_STRTOL 1
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#define HAVE_STRNDUP 1

#define HAVE_DLOPEN 1
#define HAVE_FPCLASSIFY 1
/* #undef HAVE_ISNAN */
/* #undef HAVE_ISNANF */
/* #undef HAVE_FLOG10 */
#define HAVE_POW 1
#define HAVE_DIRNAME 1
#define HAVE_BASENAME 1
#define HAVE_SYSINFO 1
/* #undef HAVE_TRACE_BACK_STACK */
#define HAVE_BACKTRACE 1
/* #undef HAVE_READDIR64 */

/* if termio signals are supported */
#ifdef HAVE_TERMIOS_H
#ifdef HAVE_TCGETATTR
#define HAVE_TERMIO_SIGNALS
#endif
#endif

/* if the /proc pseudo filesystem exists */
#define HAVE_PROCFS 1

/* Infiniband API version information */
/* #undef HAVE_PORT_PERFORMANCE_QUERY_VIA */

#ifndef ULONGLONG_MAX 
#define ULONGLONG_MAX (__uint64_t)18446744073709551615ULL
#endif

#ifndef LONGLONG_MAX 
#define LONGLONG_MAX (__int64_t)9223372036854775807LL
#endif

/* some types only known by some compilers */
#define uint_t unsigned int
/* #undef __int32_t */
/* #undef __uint32_t */
/* #undef __int64_t */
/* #undef __uint64_t */

/* Check if __psint_t is set to something meaningful */
/* #undef HAVE___PSINT_T */
#ifndef HAVE___PSINT_T 
#ifdef HAVE_32BIT_PTR
typedef int __psint_t;
#elif defined HAVE_64BIT_PTR
#ifdef HAVE_64BIT_LONG
typedef long __psint_t;
#else
/* This is a very strange architecture, which has 64 bit pointers but
 * not 64 bit longs. So, I'd just punt here and assume long long is Ok */
typedef long long __psint_t;
#endif
#else
#error Unknown pointer size - not 32 and not 64
#endif
#endif

/* Check if ptrdiff_t type is available */
#define HAVE_PTRDIFF_T 1
#ifndef HAVE_PTRDIFF_T
#define ptrdiff_t	long
#endif

/*
 * User and group accounts - POSIX uid_t/gid_t combo or Win32 SID
 */
#define HAVE_UID_T 1
#define HAVE_GID_T 1
/* #undef HAVE_SID */
#if defined(HAVE_UID_T) && defined(HAVE_GID_T)
typedef uid_t	__pmUserID;
typedef gid_t	__pmGroupID;
#elif defined(HAVE_SID)
typedef SID	__pmUserID;
typedef SID	__pmGroupID;
#else
bozo! unclear how to represent users and groups for this platform
#endif

/*
 * socklen_t is not always defined, so use __pmSockLen abstraction
 */
#define HAVE_SOCKLEN_T 1
#ifdef HAVE_SOCKLEN_T
#include <sys/types.h>
#include <sys/socket.h>
typedef socklen_t __pmSockLen;
#else
typedef int __pmSockLen;
#endif

/*
 * MAXNAMELEN hides in may places and may have alias names ...
 */
#ifndef MAXNAMELEN
#include <stdio.h>
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#if !defined(MAXNAMELEN) && defined(FILENAME_MAX)
/* posix version of the bsd MAXNAMELEN macro */
#define MAXNAMELEN FILENAME_MAX
#endif
#endif
#ifndef MAXNAMELEN
bozo! need to find where MAXNAMELEN is defined for this platform
#endif

/*
 * MAXPATHLEN hides in many places and may have alias names ...
 */
#ifndef MAXPATHLEN
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#if !defined(MAXPATHLEN) && defined(PATH_MAX)
/* posix version of the bsd MAXPATHLEN macro */
#define MAXPATHLEN PATH_MAX
#endif
#endif
#ifndef MAXPATHLEN
bozo! need to find where MAXPATHLEN is defined for this platform
#endif

/*
 * MAXHOSTNAMELEN hides in many places and may also have aliases ...
 */
#ifndef MAXHOSTNAMELEN
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#endif
#ifndef MAXHOSTNAMELEN
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#endif
#ifndef MAXHOSTNAMELEN
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#endif
#ifndef MAXHOSTNAMELEN
#ifdef HAVE_IPTYPES_H
#include <iptypes.h>
#define MAXHOSTNAMELEN MAX_HOSTNAME_LEN
#endif
#endif
#ifndef MAXHOSTNAMELEN
bozo! need to find where MAXHOSTNAMELEN is defined for this platform
#endif

#ifndef HAVE_FLOG10
#if !defined(flog10)
#define flog10(x) (float)log10((double)x)
#endif
#endif

#if !defined(WORD_BIT)
#define WORD_BIT 32
#endif

#define RETSIGTYPE void
#ifndef RETSIGTYPE
#define RETSIGTYPE void
#endif

/* #undef HAVE_SIGPF */
#ifndef HAVE_SIGPF
/* The return type of signal() */
typedef void (*SIG_PF) (int);
#endif

#define HAVE_SA_SIGINFO 1
#define HAVE_SIGPIPE 1
#define HAVE_SIGHUP 1

#define HAVE_WAIT_INCLUDES_SIGNAL 1
#ifndef HAVE_WAIT_INCLUDES_SIGNAL
#include <signal.h>
#endif

/* #undef HAVE_PR_TERMCHILD */
#define HAVE_PR_SET_PDEATHSIG 1

#ifdef HAVE_LIBGEN_H
#include <libgen.h>
#endif

/* thread support options */
#define HAVE_PTHREAD_MUTEX_T 1
#define HAVE_PTHREAD_BARRIER_T 1
#define HAVE___THREAD 1

#define HAVE_FNDELAY 1
#if !defined(HAVE_FNDELAY)
/* Only Solaris is known to need this so far */
#ifndef FNDELAY
#define FNDELAY O_NDELAY
#endif
#endif

/* #undef HAVE_ALTZONE */
#define HAVE_STRFTIME_z 1
#define HAVE_STRERROR_R_PTR 1

#define HAVE_STRUCT_TIMESPEC 1
#define HAVE_STRUCT_SOCKADDR_UN 1
#define HAVE_STRUCT_UCRED 1

#ifndef HAVE_VALLOC
#define valloc(x) malloc(x)
#endif

/* Determine if we are on a Linux box */
#define IS_LINUX 1

/* Determine if we are on a Solaris box */
/* #undef IS_SOLARIS */

/* Determine if we are on an AIX box */
/* #undef IS_AIX */

/* Determine if we are on a FreeBSD box */
/* #undef IS_FREEBSD */

/* Determine if we are on a NetBSD box */
/* #undef IS_NETBSD */

/* Determine if we are on a Mac OS X box */
/* #undef IS_DARWIN */
#ifdef IS_DARWIN
#define DLOPEN_NO_WARN
#define st_atim st_atimespec    /* workaround */
#define st_mtim st_mtimespec    /* workaround */
#define st_ctim st_ctimespec    /* workaround */
#endif

/* Determine if we are on Windows with MinGW compiler */
/* #undef IS_MINGW */
#ifdef IS_MINGW

#ifdef PCP_VERSION		/* used to reduce namespace pollution */
#define EINPROGRESS	WSAEINPROGRESS
#define ENETDOWN	WSAENETDOWN
#define ENETUNREACH	WSAENETUNREACH
#define ECONNRESET	WSAECONNRESET
#define ETIMEDOUT	WSAETIMEDOUT
#define ECONNREFUSED	WSAECONNREFUSED
#define EHOSTDOWN	WSAEHOSTDOWN
#define EHOSTUNREACH	WSAEHOSTUNREACH
#define EOPNOTSUPP	WSAEOPNOTSUPP
#define EADDRINUSE	WSAEADDRINUSE
#define EPROTO		WSAEPROTONOSUPPORT
#define EMSGSIZE	WSAEMSGSIZE
#define ENODATA		WSANO_DATA
extern const char *wsastrerror(int);

#define HAVE_PIPE1
#define HAVE_MKDIR2
#define HAVE_RENAME2
#define HAVE_DLOPEN 1
#define HAVE_FNDELAY 1

#define MAP_FAILED	NULL
#define O_NDELAY	0
#define SIGHUP		(NSIG+1)
#define SIGUSR1		(NSIG+2)
#define SIGBUS		(NSIG+3)
#define S_IRGRP		0
#define S_IROTH		0
#define S_IRWXG		0
#define S_IRWXO		0
#define S_ISVTX		0

#define fcntl(f, cmd, ...) 0
#define mkdir2(path, mode) mkdir(path)
#define rename2(a, b) (unlink(b), rename(a,b))
#define realpath(path, pp) strcpy(pp, path)
#define pipe1(fds) _pipe(fds, 4096, O_BINARY)

extern void setlinebuf(FILE *);
extern char *index(const char *, int);
extern char *rindex(const char *, int);
extern long int lrand48(void);
extern void srand48(long int);

#ifdef HAVE_STRUCT_TIMESPEC
/*
 * This is a bit odd ... but for MinGW, struct timespec is not in
 * <time.h> but _is_ in <pthread.h> ... the structure (sec, nanosec)
 * is what we want, so include <pthread.h>
 */
#include <pthread.h>
#endif

extern int nanosleep(const struct timespec *, struct timespec *);
extern unsigned int sleep(unsigned int);

enum { RTLD_NOW, RTLD_LAZY };
extern void *dlopen(const char *, int);
extern char *dlerror(void);
extern void *dlsym(void *, const char *);
extern int dlclose(void *);

extern void openlog(const char *, int, int);
extern void syslog(int, const char *, ...);
extern void closelog(void);
#endif
enum { LOG_EMERG, LOG_ALERT, LOG_CRIT, LOG_ERR,
       LOG_WARNING, LOG_NOTICE, LOG_INFO, LOG_DEBUG,
       LOG_PID, LOG_CONS, LOG_DAEMON };

#ifdef LIBPCP_INTERNAL
#define INTERN __declspec(dllexport)
#define EXTERN
#else
#define INTERN
#define EXTERN __declspec(dllimport)
#endif

#define setoserror(n)	(errno = (n))	/* not SetLastError() */
#define oserror()	errno		/* not GetLastError() */
#define neterror()	WSAGetLastError()
#define hosterror()	WSAGetLastError()
#define osstrerror()		strerror(GetLastError())
#define osstrerror_r(buf, len)	pmErrStr_r(-GetLastError(), buf, len)
#define netstrerror()		strerror(WSAGetLastError())
#define netstrerror_r(buf, len)	pmErrStr_r(-WSAGetLastError(), buf, len)
#define hoststrerror()	strerror(WSAGetLastError())

#else /*!MINGW*/
#define INTERN
#define EXTERN extern

#define setoserror(n)	(errno = (n))
#define oserror()	errno
#define neterror()	errno
#define hosterror()	h_errno
#define osstrerror()		strerror(errno)
#define osstrerror_r(buf, len)	pmErrStr_r(-errno, buf, len)
#define netstrerror()		strerror(errno)
#define netstrerror_r(buf, len)	pmErrStr_r(-errno, buf, len)
#define hoststrerror()	hstrerror(h_errno)
#endif

#ifndef O_CLOEXEC
#define O_CLOEXEC	0
#endif

#ifndef FD_CLOEXEC
#define FD_CLOEXEC	0
#endif

/*
 * run-time environment that is in libc for most platforms, but for some
 * we need to provide our own implementation
 */
#ifndef HAVE_DIRNAME
extern char *dirname(char *);
#endif
#ifndef HAVE_BASENAME
extern char *basename(char *);
#endif
#ifndef HAVE_STRNDUP
extern char *strndup(const char *, size_t n);
#endif

#ifdef HAVE_CONST_DIRENT
#define const_dirent const struct dirent
#else
#define const_dirent struct dirent
#endif

#ifndef HAVE_SCANDIR
struct dirent;
extern int scandir(const char *, struct dirent ***,
                   int(*filter)(const_dirent *),
                   int(*compare)(const_dirent **, const_dirent **));
extern int alphasort(const_dirent **, const_dirent **);
#endif

#ifndef HAVE_MKDIR2
#define mkdir2(path,mode) mkdir(path,mode)
#endif

#ifndef HAVE_RENAME2
#define rename2(path,target) rename(path,target)
#endif

#ifndef HAVE_PIPE1
#define pipe1(fds) pipe(fds)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _PCP_CONFIG_H */
