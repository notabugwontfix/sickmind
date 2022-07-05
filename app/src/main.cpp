#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <debug/Log.h>

#include <iostream>

auto app(int /*argc*/, char ** /*argv*/) -> int;

auto main(int argc, char **argv) -> int {
  doctest::Context doctest_context;
  doctest_context.applyCommandLine(argc, argv);

  const auto doctest_result = doctest_context.run();

  if (doctest_context.shouldExit()) {
    return doctest_result;
  }

  return doctest_result + app(argc, argv);
}

auto app(int /*argc*/, char ** /*argv*/) -> int {
  debug::Log(debug::Log::Level::Info) << "Hello, World!" << std::endl;
  return EXIT_SUCCESS;
}
