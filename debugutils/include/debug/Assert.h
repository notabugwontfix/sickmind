#pragma once

#include "Trace.h"

#include <cstdlib>
#include <ostream>

#if defined(__has_builtin)
#if __has_builtin(__builtin_debugtrap)
#define DEBUG_BREAK() __builtin_debugtrap()
#endif
#endif
#if !defined(DEBUG_BREAK)
#if _WIN32
#define DEBUG_BREAK() __debugbreak()
#elif __has_include(<signal.h>)
#include <signal.h>
#define DEBUG_BREAK() raise(SIGTRAP)
#else
#define DEBUG_BREAK()
#endif
#endif

#ifdef NDEBUG
#define DEBUG_ABORT()
#else
#define DEBUG_ABORT()                                                          \
  do {                                                                         \
    DEBUG_BREAK();                                                             \
    abort();                                                                   \
  } while (false)
#endif

#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      debug::trace(debug::TraceError)                                          \
          << "Assertion (" << #condition << ") failed at " << __FILE__ << "("  \
          << __LINE__ << "): " << message;                                     \
      DEBUG_ABORT();                                                           \
    }                                                                          \
  } while (false)
