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
  sl::Signal<void(const std::string&)> signal_print;

  const auto slot1 = signal_print.connect(
    [](const auto& name)
    {
      onPrint(name);
    });

  signal_print.connect(&onPrint);

  signal_print("Hello signals-light");

  fmt::println("Slots count: {}", signal_print.slot_count());

  signal_print.disconnect(slot1);

  fmt::println("Slots count: {}", signal_print.slot_count());
}

}  // namespace SignalsLight

#endif  // LIGHT_HELLOWORLD_H
