/**
 * @brief Defines a hello world for Boost.Signals2.
 *
 * @author  spjuanjoc
 * @date    2024-04-21
 */

#ifndef SIGNALS2_HELLOWORLD_H
#define SIGNALS2_HELLOWORLD_H

#include <fmt/core.h>

#include <string>

#include <boost/signals2.hpp>

namespace Signals2
{

static void
onPrint(const std::string& message)
{
  fmt::println("{}", message);
}

static void
runSignals2()
{
  boost::signals2::signal<void(const std::string&)> printTextSignal;

  const auto slot1 = printTextSignal.connect([](const auto& name) { onPrint(name); });
  const auto slot2 = printTextSignal.connect(&onPrint);

  printTextSignal("Hello signals2");

  slot1.disconnect();
  slot2.disconnect();
}

}  // namespace Signals2

#endif  // SIGNALS2_HELLOWORLD_H
