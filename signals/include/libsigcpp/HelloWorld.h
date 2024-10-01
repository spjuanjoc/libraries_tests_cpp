/**
 * @brief
 *
 * @author  spjuanjoc
 * @date    2024-04-17
 */
#ifndef SIGCPP_HELLOWORLD_H
#define SIGCPP_HELLOWORLD_H

#include <fmt/core.h>

#include <string>

#include <sigc++/sigc++.h>

namespace sigcpp
{

static void
onPrint(const std::string& message)
{
  fmt::println("{}", message);
}

static void
runSigcpp()
{
  sigc::signal<void(const std::string&)> signal_print;

  signal_print.connect(sigc::ptr_fun(&onPrint));

  signal_print.emit("hello sigc++-3\n");
}

}  // namespace sigcpp

#endif  // SIGCPP_HELLOWORLD_H
