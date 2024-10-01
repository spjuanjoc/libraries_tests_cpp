#include "boost_signals2/HelloWorld.h"
#include "boost_signals2/SignalClick.h"
#include "libsigcpp/HelloWorld.h"
#include "libsigcpp/MemberMethod.h"
#include "light/HelloWorld.h"

int
main()
{
  sigcpp::runSigcpp();

  ObservablePrinter                  printer;
  std::shared_ptr<ObservablePrinter> printer2;

  auto slot = printer.signalPrinted().connect(
    [&](int value)
    {
      fmt::println("Slot connected. Value printed: {}", value);
    });

  printer.print(10);
  PrintObserver  observer(printer);
  PrintObserver2 observer2;
  Observer3      observer3;

  auto connection1 = printer.signalPrinted().connect(sigc::mem_fun(observer3, &Observer3::onPrint));  // for a non-static member
  auto connection2 = printer.signalPrinted().connect(&Observer3::onPrint2);                           // for a static member

  observer.subscribe();
  observer2.subscribe();
  printer.print(10);
  printer.print(20);
  observer2.print(30);
  slot.disconnect();

  Signals2::runSignals2();

  Signals2::Button button;

  button.doOnClick(&Signals2::printCoordinates);

  button.simulateClick();

  SignalsLight::runSignalsLight();

  return 0;
}
