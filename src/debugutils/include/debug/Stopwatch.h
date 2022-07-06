#pragma once

#include <chrono>
#include <string>

namespace debug {

class Stopwatch {
public:
  explicit Stopwatch(std::string name);
  ~Stopwatch();

private:
  std::string m_name;
  std::chrono::time_point<std::chrono::steady_clock> m_start;
};

} // namespace debug
