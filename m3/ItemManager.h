#ifndef MS_ITEMMANAGER_H
#define MS_ITEMMANAGER_H

#include <iostream>
#include <vector>
#include "Item.h"

namespace MS
{

class Item;

class ItemManager: public std::vector<Item>
{
public:

    /*!
     * const - inserts into os descriptions of each item stored in the base class
     * container.  The bool parameter specifies whether a full description of the
     * item should be inserted.
     * */
    void display(std::ostream &os, bool displayFullDescription = false);
};
}


#endif // MS_ITEMMANAGER_H
