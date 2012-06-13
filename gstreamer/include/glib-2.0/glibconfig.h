/* glibconfig.h
 *
 * This is a generated file.  Please modify 'configure.ac'
 */

#ifndef __G_LIBCONFIG_H__
#define __G_LIBCONFIG_H__

#include <glib/gmacros.h>

#include <limits.h>
#include <float.h>

G_BEGIN_DECLS

#define G_MINFLOAT	FLT_MIN
#define G_MAXFLOAT	FLT_MAX
#define G_MINDOUBLE	DBL_MIN
#define G_MAXDOUBLE	DBL_MAX
#define G_MINSHORT	SHRT_MIN
#define G_MAXSHORT	SHRT_MAX
#define G_MAXUSHORT	USHRT_MAX
#define G_MININT	INT_MIN
#define G_MAXINT	INT_MAX
#define G_MAXUINT	UINT_MAX
#define G_MINLONG	LONG_MIN
#define G_MAXLONG	LONG_MAX
#define G_MAXULONG	ULONG_MAX

typedef signed char gint8;
typedef unsigned char guint8;
typedef signed short gint16;
typedef unsigned short guint16;
#define G_GINT16_MODIFIER "h"
#define G_GINT16_FORMAT "hi"
#define G_GUINT16_FORMAT "hu"
typedef signed int gint32;
typedef unsigned int guint32;
#define G_GINT32_MODIFIER ""
#define G_GINT32_FORMAT "i"
#define G_GUINT32_FORMAT "u"
#define G_HAVE_GINT64 1          /* deprecated, always true */

#ifndef _MSC_VER
G_GNUC_EXTENSION typedef signed long long gint64;
G_GNUC_EXTENSION typedef unsigned long long guint64;
#else /* _MSC_VER */
typedef signed __int64 gint64;
typedef unsigned __int64 guint64;
#endif /* _MSC_VER */

#ifndef _MSC_VER
#define G_GINT64_CONSTANT(val)	(G_GNUC_EXTENSION (val##LL))
#else /* _MSC_VER */
#define G_GINT64_CONSTANT(val)	(val##i64)
#endif /* _MSC_VER */
#ifndef _MSC_VER
#define G_GUINT64_CONSTANT(val)	(G_GNUC_EXTENSION (val##ULL))
#else /* _MSC_VER */
#define G_GUINT64_CONSTANT(val)	(val##Ui64)
#endif /* _MSC_VER */
#define G_GINT64_MODIFIER "I64"
#define G_GINT64_FORMAT "I64i"
#define G_GUINT64_FORMAT "I64u"

#if defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64)

#define GLIB_SIZEOF_VOID_P 8
#define GLIB_SIZEOF_LONG   4
#define GLIB_SIZEOF_SIZE_T 8

typedef signed long long gssize;
typedef unsigned long long gsize;
#define G_GSIZE_MODIFIER "I64"
#define G_GSSIZE_FORMAT "I64d"
#define G_GSIZE_FORMAT "I64u"

#define G_MAXSIZE	G_MAXUINT64
#define G_MINSSIZE	G_MININT64
#define G_MAXSSIZE	G_MAXINT64

#else

#define GLIB_SIZEOF_VOID_P 4
#define GLIB_SIZEOF_LONG   4
#define GLIB_SIZEOF_SIZE_T 4

typedef signed int gssize;
typedef unsigned int gsize;
#define G_GSIZE_MODIFIER ""
#define G_GSSIZE_FORMAT "i"
#define G_GSIZE_FORMAT "u"

#define G_MAXSIZE	G_MAXUINT
#define G_MINSSIZE	G_MININT
#define G_MAXSSIZE	G_MAXINT

#endif

typedef gint64 goffset;
#define G_MINOFFSET	G_MININT64
#define G_MAXOFFSET	G_MAXINT64

#define G_GOFFSET_MODIFIER      G_GINT64_MODIFIER
#define G_GOFFSET_FORMAT        G_GINT64_FORMAT
#define G_GOFFSET_CONSTANT(val) G_GINT64_CONSTANT(val)


#ifndef _WIN64

#define GPOINTER_TO_INT(p)	((gint)   (p))
#define GPOINTER_TO_UINT(p)	((guint)  (p))

#define GINT_TO_POINTER(i)	((gpointer)  (i))
#define GUINT_TO_POINTER(u)	((gpointer)  (u))

typedef signed int gintptr;
typedef unsigned int guintptr;

#define G_GINTPTR_MODIFIER      ""
#define G_GINTPTR_FORMAT        "i"
#define G_GUINTPTR_FORMAT       "u"

#else

#define GPOINTER_TO_INT(p)	((gint)  (gint64) (p))
#define GPOINTER_TO_UINT(p)	((guint) (guint64) (p))

#define GINT_TO_POINTER(i)	((gpointer) (gint64) (i))
#define GUINT_TO_POINTER(u)	((gpointer) (guint64) (u))

#ifndef _MSC_VER
typedef signed long long gintptr;
typedef unsigned long long guintptr;
#else
typedef signed __int64 gintptr;
typedef unsigned __int64 guintptr;
#endif

#define G_GINTPTR_MODIFIER      "I64"
#define G_GINTPTR_FORMAT        "I64i"
#define G_GUINTPTR_FORMAT       "I64u"

#endif

#ifdef NeXT /* @#%@! NeXTStep */
# define g_ATEXIT(proc)	(!atexit (proc))
#else
# define g_ATEXIT(proc)	(atexit (proc))
#endif

#define g_memmove(dest,src,len) G_STMT_START { memmove ((dest), (src), (len)); } G_STMT_END

#define GLIB_MAJOR_VERSION 2
#define GLIB_MINOR_VERSION 26
#define GLIB_MICRO_VERSION 1

#define G_OS_WIN32
#define G_PLATFORM_WIN32


#ifndef _MSC_VER
#define G_VA_COPY	va_copy
#endif /* not _MSC_VER */

#ifdef	__cplusplus
#define	G_HAVE_INLINE	1
#else	/* !__cplusplus */
#ifndef _MSC_VER
#define G_HAVE_INLINE 1
#endif /* _MSC_VER */
#define G_HAVE___INLINE 1
#if !defined(_MSC_VER) && !defined(__DMC__)
#define G_HAVE___INLINE__ 1
#endif /* !_MSC_VER and !__DMC__ */
#endif	/* !__cplusplus */

#ifdef	__cplusplus
#define G_CAN_INLINE	1
#else	/* !__cplusplus */
#define G_CAN_INLINE	1
#endif

#ifndef _MSC_VER
#define G_HAVE_ISO_VARARGS 1

/* gcc-2.95.x supports both gnu style and ISO varargs, but if -ansi
 * is passed ISO vararg support is turned off, and there is no work
 * around to turn it on, so we unconditionally turn it off.
 */
#if __GNUC__ == 2 && __GNUC_MINOR__ == 95
#  undef G_HAVE_ISO_VARARGS
#endif

#define G_HAVE_GNUC_VARARGS 1
#else /* _MSC_VER */
/* varargs macros available since msvc8 (vs2005) */
#  if _MSC_VER >= 1400
#    define G_HAVE_ISO_VARARGS 1
#   endif
#endif /* not _MSC_VER */
#define G_HAVE_GROWING_STACK 0

#if defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define G_GNUC_INTERNAL __attribute__((visibility("hidden")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)
#define G_GNUC_INTERNAL __hidden
#elif defined (__GNUC__) && defined (G_HAVE_GNUC_VISIBILITY)
#define G_GNUC_INTERNAL __attribute__((visibility("hidden")))
#else
#define G_GNUC_INTERNAL
#endif

#define G_THREADS_ENABLED
#define G_THREADS_IMPL_WIN32
typedef struct _GMutex* GStaticMutex;
#define G_STATIC_MUTEX_INIT NULL
#define g_static_mutex_get_mutex(mutex) \
  (g_static_mutex_get_mutex_impl_shortcut (mutex))
/* This represents a system thread as used by the implementation. An
 * alien implementaion, as loaded by g_thread_init can only count on
 * "sizeof (gpointer)" bytes to store their info. We however need more
 * for some of our native implementations. */
typedef union _GSystemThread GSystemThread;
union _GSystemThread
{
#ifndef _WIN64
  char   data[4];
#else
  char   data[8];
#endif
  double dummy_double;
  void  *dummy_pointer;
  long   dummy_long;
};

#define G_ATOMIC_OP_MEMORY_BARRIER_NEEDED 1

#define GINT16_TO_LE(val)	((gint16) (val))
#define GUINT16_TO_LE(val)	((guint16) (val))
#define GINT16_TO_BE(val)	((gint16) GUINT16_SWAP_LE_BE (val))
#define GUINT16_TO_BE(val)	(GUINT16_SWAP_LE_BE (val))
#define GINT32_TO_LE(val)	((gint32) (val))
#define GUINT32_TO_LE(val)	((guint32) (val))
#define GINT32_TO_BE(val)	((gint32) GUINT32_SWAP_LE_BE (val))
#define GUINT32_TO_BE(val)	(GUINT32_SWAP_LE_BE (val))
#define GINT64_TO_LE(val)	((gint64) (val))
#define GUINT64_TO_LE(val)	((guint64) (val))
#define GINT64_TO_BE(val)	((gint64) GUINT64_SWAP_LE_BE (val))
#define GUINT64_TO_BE(val)	(GUINT64_SWAP_LE_BE (val))
#define GLONG_TO_LE(val)	((glong) GINT32_TO_LE (val))
#define GULONG_TO_LE(val)	((gulong) GUINT32_TO_LE (val))
#define GLONG_TO_BE(val)	((glong) GINT32_TO_BE (val))
#define GULONG_TO_BE(val)	((gulong) GUINT32_TO_BE (val))
#define GINT_TO_LE(val)		((gint) GINT32_TO_LE (val))
#define GUINT_TO_LE(val)	((guint) GUINT32_TO_LE (val))
#define GINT_TO_BE(val)		((gint) GINT32_TO_BE (val))
#define GUINT_TO_BE(val)	((guint) GUINT32_TO_BE (val))
#define GSIZE_TO_LE(val)	((gsize) GUINT32_TO_LE (val))
#define GSSIZE_TO_LE(val)	((gssize) GINT32_TO_LE (val))
#define GSIZE_TO_BE(val)	((gsize) GUINT32_TO_BE (val))
#define GSSIZE_TO_BE(val)	((gssize) GINT32_TO_BE (val))
#define G_BYTE_ORDER G_LITTLE_ENDIAN

#define GLIB_SYSDEF_POLLIN =1
#define GLIB_SYSDEF_POLLOUT =4
#define GLIB_SYSDEF_POLLPRI =2
#define GLIB_SYSDEF_POLLHUP =16
#define GLIB_SYSDEF_POLLERR =8
#define GLIB_SYSDEF_POLLNVAL =32

#define G_MODULE_SUFFIX "dll"

/* A GPid is an abstraction for a process "handle". It is *not* an
 * abstraction for a process identifier in general. GPid is used in
 * GLib only for descendant processes spawned with the g_spawn*
 * functions. On POSIX there is no "process handle" concept as such,
 * but on Windows a GPid is a handle to a process, a kind of pointer,
 * not a process identifier.
 */
typedef void * GPid;

#define GLIB_SYSDEF_AF_UNIX 1
#define GLIB_SYSDEF_AF_INET 2
#define GLIB_SYSDEF_AF_INET6 23

#define GLIB_SYSDEF_MSG_OOB 1
#define GLIB_SYSDEF_MSG_PEEK 2
#define GLIB_SYSDEF_MSG_DONTROUTE 4

G_END_DECLS

#endif /* GLIBCONFIG_H */
