#ifndef MS_TASKMANAGER_H
#define MS_TASKMANAGER_H

#include <iostream>
#include <vector>
#include "Task.h"

namespace MS
{

class Task;
class ItemManager;

class TaskManager: public std::vector<Task>
{
public:
    /*!
     * validates each task against all of the other tasks in the base class
     * container.  This function inserts a message into os if not all tasks have
     * been validated.
     * */
    void validate(std::ostream &os);

    /*!
     * checks that the tasks assigned to handle each item managed by itemManager
     * are tasks in the base class container.  If a task is not in the container,
     * then this function inserts a message into os that that task is not
     * available.
     * Hint: use std::find_if() with a lambda expression
     * */
    void validate(const ItemManager &itemManager, std::ostream &os);

    /*!
     * inserts into the referenced ostream object descriptions of the tasks stored
     * in tasks
     * */
    void display(std::ostream &os) const;
};
}

#endif // MS_TASKMANAGER_H
