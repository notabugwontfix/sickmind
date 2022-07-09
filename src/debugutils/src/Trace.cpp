#include <debug/Trace.h>

#include <doctest/doctest.h>

#include <sstream>

namespace debug {

Trace::Trace(TraceLevel level, TraceLevel max_level, // NOLINT
             std::ostream &output)
    : m_level{level}, m_max_level{max_level}, m_output{output} {

  if (check_level()) {
    m_output << level_prefix() << ": ";
  }
}

Trace::~Trace() {
  if (check_level()) {
    m_output << std::endl;
  }
}

auto Trace::check_level() const -> bool { return m_level <= m_max_level; }

auto Trace::level_prefix() const -> std::string {
  switch (m_level) {
  case TraceLevel::Fatal: {
    return "[FATAL]";
  } break;
  case TraceLevel::Error: {
    return "[ERROR]";
  } break;
  case TraceLevel::Warn: {
    return "[WARN]";
  } break;
  case TraceLevel::Info: {
    return "[INFO]";
  } break;
  case TraceLevel::Debug: {
    return "[DEBUG]";
  } break;
  default: {
    return "[UNKNOWN]";
  }
  }
}

} // namespace debug

// NOLINTBEGIN

SCENARIO("trace level check") {
  std::stringstream ss;

  GIVEN("max trace level = None") {
    constexpr auto trace_max_level = debug::TraceNone;

    WHEN("trace Fatal") {
      debug::Trace{debug::TraceFatal, trace_max_level, ss} << "message";

      THEN("trace is empty") { CHECK(ss.str().empty()); }
    }
  }

  GIVEN("max trace level = All") {
    constexpr auto trace_max_level = debug::TraceAll;

    WHEN("trace Debug") {
      debug::Trace{debug::TraceDebug, trace_max_level, ss} << "message";

      THEN("trace has DEBUG prefix") {
        CHECK(ss.str() == "[DEBUG]: message\n");
      }
    }
  }

  GIVEN("max trace level = Error") {
    constexpr auto trace_max_level = debug::TraceError;

    WHEN("trace Error") {
      debug::Trace{debug::TraceError, trace_max_level, ss} << "message";

      THEN("trace has ERROR prefix") {
        CHECK(ss.str() == "[ERROR]: message\n");
      }
    }

    WHEN("trace Fatal") {
      debug::Trace{debug::TraceFatal, trace_max_level, ss} << "message";

      THEN("trace has FATAL prefix") {
        CHECK(ss.str() == "[FATAL]: message\n");
      }
    }

    WHEN("trace Warn") {
      debug::Trace{debug::TraceWarn, trace_max_level, ss} << "message";

      THEN("trace is empty") { CHECK(ss.str().empty()); }
    }
  }
}

SCENARIO("default trace level") {
  std::stringstream ss;
  debug::TraceDefaults::set_output(ss);

  GIVEN("default trace level = Info") {
    WHEN("trace Info") {
      debug::trace(debug::TraceInfo) << "message";

      THEN("trace has INFO prefix") { CHECK(ss.str() == "[INFO]: message\n"); }
    }

    WHEN("trace Warn") {
      debug::trace(debug::TraceWarn) << "message";

      THEN("trace has WARN prefix") { CHECK(ss.str() == "[WARN]: message\n"); }
    }

    WHEN("trace Debug") {
      debug::trace(debug::TraceDebug) << "message";

      THEN("trace is empty") { CHECK(ss.str().empty()); }
    }
  }
}

TEST_CASE("trace level prefix") {
  std::stringstream ss;
  constexpr auto trace_max_level = debug::TraceAll;

  SUBCASE("trace Fatal") {
    debug::Trace{debug::TraceFatal, trace_max_level, ss} << "message";
    CHECK(ss.str() == "[FATAL]: message\n");
  }

  SUBCASE("trace Error") {
    debug::Trace{debug::TraceError, trace_max_level, ss} << "message";
    CHECK(ss.str() == "[ERROR]: message\n");
  }

  SUBCASE("trace Warn") {
    debug::Trace{debug::TraceWarn, trace_max_level, ss} << "message";
    CHECK(ss.str() == "[WARN]: message\n");
  }

  SUBCASE("trace Info") {
    debug::Trace{debug::TraceInfo, trace_max_level, ss} << "message";
    CHECK(ss.str() == "[INFO]: message\n");
  }

  SUBCASE("trace Debug") {
    debug::Trace{debug::TraceDebug, trace_max_level, ss} << "message";
    CHECK(ss.str() == "[DEBUG]: message\n");
  }
}

TEST_CASE("trace new line") {
  std::stringstream ss;

  debug::Trace{debug::TraceFatal, debug::TraceAll, ss} << "message";
  CHECK(ss.str() == "[FATAL]: message\n");
}

TEST_CASE("trace level underlying value") {
  CHECK(static_cast<debug::TraceLevel>(0) == debug::TraceNone);
  CHECK(static_cast<debug::TraceLevel>(1) == debug::TraceFatal);
  CHECK(static_cast<debug::TraceLevel>(2) == debug::TraceError);
  CHECK(static_cast<debug::TraceLevel>(3) == debug::TraceWarn);
  CHECK(static_cast<debug::TraceLevel>(4) == debug::TraceInfo);
  CHECK(static_cast<debug::TraceLevel>(5) == debug::TraceDebug);
  CHECK(static_cast<debug::TraceLevel>(6) == debug::TraceAll);
}

// NOLINTEND
