#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

namespace MS
{
size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string &record)
    : nOrders(0), order(nullptr)
{
    Utilities extract;
    size_t pos = 0;
    bool more = true;
    int tokenCount = 0;
    std::vector<std::string> itemNames;

    // while more is true, check the current record for tokens.
    while (more) {
        try {
            // extract the next token and trim its whitespace.
            std::string token = extract.nextToken(record, pos, more);
            if (!token.empty()) {
                switch (tokenCount) {
                    case 0: {
                        name = token; // set name if 1st token
                        break;
                    }
                    case 1: {
                        product = token; // set product name if 2nd token
                        break;
                    }
                    default: {
                        if (token[0] != '\0') itemNames.push_back(token); // get list of items
                    }
                }
            }
            // if field_width is less than iteration's field width, set it to that field width
            if (field_width < extract.getFieldWidth()) field_width = extract.getFieldWidth();
            tokenCount++;
        }
        catch (const char *error) {
            std::cout << error << std::endl;
            break;
        }
    }
    // allocate space for item names within order
    order = new CustomerItem[itemNames.size()];
    nOrders = (unsigned int) itemNames.size();
    for (unsigned int i = 0; i < itemNames.size(); i++) {
        order[i] = CustomerItem(itemNames[i]);
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder &rhs)
{
    throw std::string("*** move failed! ***");
}

CustomerOrder::CustomerOrder(CustomerOrder &&rhs) noexcept
{
    *this = std::move(rhs);
}

CustomerOrder &CustomerOrder::operator=(CustomerOrder &&rhs) noexcept
{
    if (this != &rhs) {
        name = rhs.name;
        product = rhs.product;
        nOrders = rhs.nOrders;
        order = rhs.order;
        rhs.name = "";
        rhs.product = "";
        rhs.nOrders = 0;
        rhs.order = nullptr;
    }
    return *this;
}

CustomerOrder::~CustomerOrder()
{
    delete[] order;
}

unsigned int CustomerOrder::noOrders() const
{
    return nOrders;
}

const std::string &CustomerOrder::operator[](unsigned int index) const
{
    // check index to see if it's out of bounds of order
    return index > nOrders ? order[index].getName() : throw "*** ERROR: index out of bounds ***";
}

void CustomerOrder::fill(Item &item)
{
    for (int i = 0; i < nOrders; ++i) {
        // compare name of current item to passed item's name, and fill it if it matches
        if (order[i].getName() == item.getName()) {
            order[i].fill(item++.getCode());
        }
    }
}

void CustomerOrder::remove(Item &item)
{
    for (int i = 0; i < nOrders; ++i) {
        if (order[i].getName() == item.getName()) {
            if (order[i].isFilled()) {
                for (int j = i; j < nOrders; ++j) {
                    order[j] = order[j + 1];
                }
                nOrders--;
                order[nOrders].clear();
            }
        }
    }
}

bool CustomerOrder::empty() const
{
    return name.empty() && product.empty() && nOrders == 0;
}

void CustomerOrder::display(std::ostream &os) const
{
    if (!empty()) {
        os << std::setw(field_width) << std::setfill(' ') << std::left << name << " :  " << product << std::endl;
        for (int i = 0; i < nOrders; ++i) {
            order[i].display(os);
        }
    }
}
}