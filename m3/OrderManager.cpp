//
// Created by Dominic Nunes on 2018-04-17.
//

#include <vector>
#include "OrderManager.h"
namespace MS
{


CustomerOrder &&OrderManager::extract()
{
    return std::move(back());
}

void OrderManager::validate(const ItemManager &itemManager, std::ostream &os)
{
//    std::find_if(begin(), end(), [itemManager](const Item &iM) -> bool
//    { return itemManager == iM; });
//    if (found) {
//        os << "Found";
//    }
//    else {
//        os << "Not Found";
//    }
}

void OrderManager::display(std::ostream &os) const
{

}
}
