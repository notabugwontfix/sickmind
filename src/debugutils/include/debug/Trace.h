#pragma once

#include <iostream>

namespace debug {

enum class TraceLevel : int {
  None,
  Fatal,
  Error,
  Warn,
  Info,
  Debug,
  All,
};

inline constexpr auto TraceNone = TraceLevel::None;
inline constexpr auto TraceFatal = TraceLevel::Fatal;
inline constexpr auto TraceError = TraceLevel::Error;
inline constexpr auto TraceWarn = TraceLevel::Warn;
inline constexpr auto TraceInfo = TraceLevel::Info;
inline constexpr auto TraceDebug = TraceLevel::Debug;
inline constexpr auto TraceAll = TraceLevel::All;

class Trace {
public:
  explicit Trace(TraceLevel level, TraceLevel max_level, std::ostream &output);
  ~Trace();

  Trace(const Trace &) = delete;
  auto operator=(const Trace &) -> Trace & = delete;
  Trace(Trace &&) = delete;
  auto operator=(Trace &&) -> Trace & = delete;

  template <typename T> auto operator<<(T &&value) -> Trace & { // NOLINT
    if (check_level()) {
      m_output << value; // NOLINT
    }

    return *this;
  }

private:
  const TraceLevel m_level;
  const TraceLevel m_max_level;
  std::ostream &m_output;

  [[nodiscard]] auto check_level() const -> bool;
  [[nodiscard]] auto level_prefix() const -> std::string;
};

class TraceDefaults {
public:
  static void set_max_level(TraceLevel max_level) { s_max_level = max_level; }
  static void set_output(std::ostream &output) { s_output = &output; }

  [[nodiscard]] static inline auto trace(TraceLevel level) -> Trace {
    return Trace{level, s_max_level, *s_output};
  }

private:
  // NOLINTBEGIN
  static inline auto s_max_level = TraceLevel::Info;
  static inline auto *s_output = &std::cout;
  // NOLINTEND
};

[[nodiscard]] inline auto trace(TraceLevel level) -> Trace {
  return TraceDefaults::trace(level);
}

} // namespace debug
