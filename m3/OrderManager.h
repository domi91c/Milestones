#ifndef MS_ORDERMANAGER_H
#define MS_ORDERMANAGER_H


#include <iostream>
#include <vector>
#include "CustomerOrder.h"
#include "ItemManager.h"

namespace MS
{
class OrderManager: public std::vector<CustomerOrder>
{
public:

    /*!
     * moves a customerOrder from the back of the base class container
     * */
    CustomerOrder &&extract();

    /*!
     * checks that the items requested in the customer orders are available,
     * inserting a message into os for any item that is not available.
     * Hint: use std::find_if()
     * */
    void validate(const ItemManager &itemManager, std::ostream &os);

    /*!
     * inserts into os descriptions of each customer order in the base class
     * container
     * */
    void display(std::ostream &os) const;
};
}

#endif // MS_ORDERMANAGER_H
