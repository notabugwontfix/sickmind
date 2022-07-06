#include <debug/Stopwatch.h>
#include <debug/Trace.h>

namespace debug {

Stopwatch::Stopwatch(std::string name)
    : m_name{std::move(name)}, m_start{std::chrono::steady_clock::now()} {}

Stopwatch::~Stopwatch() {
  const auto now = std::chrono::steady_clock::now();

  trace(TraceInfo) << "Stopwatch " << m_name << ": "
                   << std::chrono::duration_cast<std::chrono::microseconds>(
                          now - m_start)
                          .count()
                   << " us";
}

} // namespace debug
