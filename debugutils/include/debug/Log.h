#pragma once

#include <iostream>
#include <string>

namespace debug {

class Log {
public:
  enum class Level : int {
    None,

    Fatal,
    Error,
    Warn,
    Info,
    Debug,
    Trace,

    All,
  };

  using endl_type = decltype(std::endl<char, std::char_traits<char>>);

  static inline auto s_level = Level::Info;
  static inline auto &s_output = std::cout;

  Log(Level level);

  auto operator<<(endl_type endl) -> Log &;

  template <typename T> auto operator<<(const T &value) -> Log & {
    if (check_log_level()) {
      s_output << value;
    }

    return *this;
  }

private:
  const Level m_level;

  auto check_log_level() const -> bool;
  auto log_level_prefix() const -> std::string;
};

} // namespace debug
