#include <debug/Log.h>

#include <iostream>

namespace debug {

Log::Log(Level level) : m_level{level} {
  if (check_log_level()) {
    s_output << log_level_prefix() << ": ";
  }
}

auto Log::operator<<(endl_type endl) -> Log & {
  if (check_log_level()) {
    s_output << endl;
  }

  return *this;
}

auto Log::check_log_level() const -> bool { return m_level <= s_level; }

auto Log::log_level_prefix() const -> std::string {
  switch (m_level) {
  case Level::Fatal: {
    return "[FATAL]";
  } break;
  case Level::Error: {
    return "[ERROR]";
  } break;
  case Level::Warn: {
    return "[WARN]";
  } break;
  case Level::Info: {
    return "[INFO]";
  } break;
  case Level::Debug: {
    return "[DEBUG]";
  } break;
  case Level::Trace: {
    return "[TRACE]";
  } break;
  default: {
    return "[UNKNOWN]";
  }
  }
}

} // namespace debug
