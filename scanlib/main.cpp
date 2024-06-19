#include <scn/scan/scan.h>
#include <fmt/core.h>

int main() {
  int an_int;
  scn::scan("123", "{}", an_int);

  double a_double;
  scn::scan("3.14", "{}", a_double);

  int int_a, int_b;
  scn::scan("0 1 2", "{} {}", int_a, int_b);

  std::string a_string;
  scn::scan("hello world", "{}", a_string);
  // str == "hello"

  fmt::print("int: {}, double: {}, multi: ({},{}), string: {}",
    an_int,
    a_double,
    int_a,
    int_b,
    a_string
    );

}
