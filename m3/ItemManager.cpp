#include <ostream>
#include "ItemManager.h"

namespace MS
{
void ItemManager::display(std::ostream &os, bool displayFullDescription)
{
    for (size_t i = 0; i < std::vector<Item>::size(); i++) {
        std::vector<Item>::at(i).display(os);
    }
}
}
