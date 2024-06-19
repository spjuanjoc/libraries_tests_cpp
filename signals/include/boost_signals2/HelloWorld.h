/**
 * @brief Defines a hello world for Boost.Signals2.
 *
 * @author  spjuanjoc
 * @date    2024-04-21
 */


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
  boost::signals2::signal<void(const std::string&)> signal_print;

  auto slot1 = signal_print.connect(
    [](const auto& name)
    {
      onPrint(name);
    });

  auto slot2 = signal_print.connect(&onPrint);

  signal_print("Hello signals2");

  slot1.disconnect();
  slot2.disconnect();
}

}  // namespace Signals2
