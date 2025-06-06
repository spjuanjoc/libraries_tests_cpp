#include <iostream>

#include <nlohmann/json.hpp>

using namespace nlohmann;

int
main()
{
  const json object = { "one", "two", "three", "four", "five" };
  json       j2     = { { "pi", 3.141 },
                        { "happy", true },
                        { "name", "Niels" },
                        { "nothing", nullptr },
                        { "answer", { { "everything", 42 } } },
                        { "list", { 1, 0, 2 } },
                        { "object", { { "currency", "USD" }, { "value", 42.99 } } } };

  std::cout << object.dump() << std::endl;
  std::cout << j2.dump() << std::endl;

  const auto ptr = j2["happy"].template get<bool>();
  std::cout << std::boolalpha << ptr << std::endl;

  const auto j3 = j2["list"];
  std::cout << j3 << std::endl;
}
