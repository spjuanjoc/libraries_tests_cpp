#include <fmt/base.h>
#include <scn/scan.h>

int
main()
{
  const auto an_int = scn::scan<int>("123", "{}");

  const auto a_double = scn::scan<double>("3.14", "{}");

  const auto ints           = scn::scan<int, int>("0 1 2", "{} {}");
  const auto [int_a, int_b] = ints->values();

  const auto a_string = scn::scan<std::string>("hello world", "{}");
  // str == "hello"

  fmt::print(
    "int: {}, double: {}, multi: ({},{}), string: {}",
    an_int->value(),
    a_double->value(),
    int_a,
    int_b,
    a_string->value());

  return 0;
}
