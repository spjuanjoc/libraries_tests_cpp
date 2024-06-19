/**
 * @brief Defines a button click example for Boost.Signals2.
 *
 * @author  spjuanjoc
 * @date    2024-04-21
 */

#ifndef SIGNALS2_SIGNALCLICK_H
#define SIGNALS2_SIGNALCLICK_H

#include <iostream>

#include <boost/signals2/signal.hpp>

namespace Signals2
{


//[ passing_slots_defs_code_snippet
// a pretend GUI button
class Button
{
  typedef boost::signals2::signal<void(int x, int y)> OnClick;

public:
  using OnClickSlotType = OnClick::slot_type;

  // forward slots through Button interface to its private signal
  boost::signals2::connection doOnClick(const OnClickSlotType& slot);

  // simulate user clicking on GUI button at coordinates 52, 38
  void simulateClick();

private:
  OnClick onClick;
};

boost::signals2::connection
Button::doOnClick(const OnClickSlotType& slot)
{
  return onClick.connect(slot);
}

void
Button::simulateClick()
{
  onClick(52, 38);
}

void
printCoordinates(long x, long y)
{
  fmt::println("({},{})", x, y);
}
//]

}  // namespace Signals2

#endif  //SIGNALS2_SIGNALCLICK_H
