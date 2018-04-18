#include <iomanip>
#include "CustomerItem.h"
#include "Item.h"

namespace MS
{
CustomerItem::CustomerItem(const std::string &_name)
    : name(_name),
      filled(false),
      code(0)
{
}

bool CustomerItem::asksFor(const Item &item) const
{
    return (name == item.getName());
}

bool CustomerItem::isFilled() const
{
    return filled;
}

void CustomerItem::fill(const unsigned int _code)
{
    code = _code;
    filled = true;
}

void CustomerItem::clear()
{
    code = 0;
    filled = false;
}

const std::string &CustomerItem::getName() const
{
    return name;
}

void CustomerItem::display(std::ostream &os) const
{
    os << (filled ? " + " : " - ")
       << "[" << std::setw(5) << std::setfill('0') << std::right << code << "] "
       << name << std::endl;
}
}
