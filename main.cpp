#include "libsigcpp/hello_world.h"
#include "libsigcpp/member_method.h"

int
main()
{
  runSigcpp();

  ObservablePrinter printer;
  std::shared_ptr<ObservablePrinter> printer2;

  auto slot = printer.signalPrinted().connect(
    [&](int value)
    {
      fmt::println("Slot connected. Value printed: {}", value);
    });

  PrintObserver observer(printer);
  PrintObserver2 observer2;

  observer.subscribe();
  observer2.subscribe();
  printer.print(10);
  printer.print(20);
  observer2.print(30);
  slot.disconnect();

  return 0;
}
