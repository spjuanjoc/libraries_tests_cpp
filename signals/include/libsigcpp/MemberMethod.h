/**
 * @brief
 *
 * @author  spjuanjoc
 * @date    2024-04-17
 */

#ifndef MEMBERMETHOD_H
#define MEMBERMETHOD_H

#include <fmt/core.h>

#include <string>

#include <sigc++/sigc++.h>

/**
 * @brief The signal emitter.
 */
class ObservablePrinter : public sigc::trackable
{
public:
  /**
   * @brief The signal type
   */
  using PrintSignal = sigc::signal<void(int)>;

  ObservablePrinter() = default;

  /**
   * @brief Emitted when the message has been printed.
   *
   * @return The signal object.
   */
  PrintSignal signalPrinted() const { return m_print_signal; };

  void print(const std::int32_t& value) const
  {
    fmt::println("Printing {}", value);
    onPrint(value);
  };

protected:
  void onPrint(const std::int32_t& value) const
  {
    m_print_signal.emit(value);
    fmt::println("Printed {}", value);
  }

private:
  PrintSignal m_print_signal;
};

/**
 * @brief Print observer with reference.
 */
class PrintObserver
{
public:
  explicit PrintObserver(ObservablePrinter& printer)
  : m_observable_printer { printer } {};

  ~PrintObserver() { m_slot.disconnect(); }

  void subscribe()
  {
    m_slot = m_observable_printer.signalPrinted().connect(
      [&](int value)
      {
        fmt::println("Observer connected. Value printed: {}", value);
      });
  }

private:
  sigc::connection   m_slot;
  ObservablePrinter& m_observable_printer;
};

/**
 * @brief Print observer with pointer.
 */
class PrintObserver2
{
public:
  explicit PrintObserver2()
  : m_printer { std::make_shared<ObservablePrinter>() } {};

  ~PrintObserver2() { m_slot.disconnect(); }

  void subscribe()
  {
    m_slot = m_printer->signalPrinted().connect(
      [&](int value)
      {
        fmt::println("Observer2 connected. Value printed: {}", value);
      });
  }

  void print(const std::int32_t& value) const
  {
    fmt::println("Print as member");
    m_printer->print(value);
  };

private:
  sigc::connection                   m_slot;
  std::shared_ptr<ObservablePrinter> m_printer;
};

class Observer3
{
public:
  void        onPrint(const std::int32_t& value) { fmt::println("Observed3 {}", value); }
  static void onPrint2(const std::int32_t& value) { fmt::println("Observed3s {}", value); }
};

#endif  // MEMBERMETHOD_H
