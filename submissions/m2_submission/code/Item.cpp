#include <vector>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

namespace MS
{

size_t Item::field_width = 0;

Item::Item(const std::string &record)
    : description("no detailed description"), code(1)
{
    size_t pos = 0;
    bool more = true;
    Utilities extract;

    try {
        name = extract.nextToken(record, pos, more);
        if (field_width < extract.getFieldWidth()) {
            field_width = extract.getFieldWidth();
        }

        if (more) { filler = extract.nextToken(record, pos, more); }
        if (more) { remover = extract.nextToken(record, pos, more); }
        if (more) { code = static_cast<unsigned int>(stoi(extract.nextToken(record, pos, more))); }
        if (more) { description = extract.nextToken(record, pos, more); }
    }
    catch (const char *error) {
    }

    // if description empty, give default value.
    if (description[0] == '\0') description = "no detailed description";
}

bool Item::empty() const
{
    return name.empty();
}

Item &Item::operator++(int)
{
    Item *temp = new Item();
    *temp = *this;
    code++;
    return *temp;
}

unsigned int Item::getCode() const
{
    return code;
}

const std::string &Item::getName() const
{
    return name;
}

const std::string &Item::getFiller() const
{
    return filler;
}

const std::string &Item::getRemover() const
{
    return remover;
}

void Item::display(std::ostream &os, bool more) const
{
    os << std::setfill(' ');
    os << std::setw(field_width + 1) << std::left << name << "[" << std::right << std::setw(CODE_WIDTH)
       << std::setfill('0')
       << code << "] From " <<
       std::setw(field_width) << std::left << std::setfill(' ') << filler << " To " << remover << std::endl <<
       std::setw(field_width + CODE_WIDTH + 4) << std::right << ": " << description << std::endl;

}
}
