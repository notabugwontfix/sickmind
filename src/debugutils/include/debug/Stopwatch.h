#pragma once

#include <chrono>
#include <string>

namespace debug {

class Stopwatch {
public:
  explicit Stopwatch(std::string name);
  ~Stopwatch();

  Stopwatch(const Stopwatch &) = delete;
  auto operator=(const Stopwatch &) -> Stopwatch & = delete;
  Stopwatch(Stopwatch &&) = delete;
  auto operator=(Stopwatch &&) -> Stopwatch & = delete;

private:
  std::string m_name;
  std::chrono::time_point<std::chrono::steady_clock> m_start;
};

} // namespace debug
