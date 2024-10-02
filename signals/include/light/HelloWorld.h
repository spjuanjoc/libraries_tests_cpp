/**
 * @brief Defines a hello world for signals-light.
 *
 * @author  spjuanjoc
 * @date    2024-04-24
 */

#ifndef LIGHT_HELLOWORLD_H
#define LIGHT_HELLOWORLD_H

#include <fmt/core.h>

#include <string>

#include <signals_light/signal.hpp>

namespace SignalsLight
{
static void
onPrint(const std::string& message)
{
  fmt::println("{}", message);
}

static void
runSignalsLight()
{
  sl::Signal<void(const std::string&)> printTextSignal;

  const auto slot1 = printTextSignal.connect([](const auto& name) { onPrint(name); });

  printTextSignal.connect(&onPrint);

  printTextSignal("Hello signals-light");

  fmt::println("Slots count: {}", printTextSignal.slot_count());

  printTextSignal.disconnect(slot1);

  fmt::println("Slots count: {}", printTextSignal.slot_count());
}

}  // namespace SignalsLight

#endif  // LIGHT_HELLOWORLD_H
