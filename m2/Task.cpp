#include <iomanip>
#include "Task.h"
#include "Utilities.h"

namespace MS
{
size_t Task::field_width; // size of task name required for display method formatting

Task::Task(const std::string &record)
{
    slots = "1";
    pNextTask[passed] = nullptr;
    pNextTask[redirect] = nullptr;

    Utilities extract;

    size_t pos = 0;
    bool more = true;

    // while more is true, check the current record for tokens.
    for (int tokenCount = 0; more; tokenCount++) {
        try {
            // extract the next token and trim its whitespace.
            std::string token = extract.trimToken(extract.nextToken(record, pos, more));
            // if token is not empty, assign it to the correct variable.
            if (!token.empty()) {
                switch (tokenCount) {
                    case 0: {
                        name = token; // set task name if 1st token
                        break;
                    }
                    case 1: {
                        slots = token; // set slots number if 2nd token
                        break;
                    }
                    case 2: {
                        nextTask[passed] = token; // set 'Continue' task name if 3rd token
                        break;
                    }
                    case 3: {
                        nextTask[redirect] = token; // set 'Redirect' task name if 4th token
                        break;
                    }
                    default: { break; }
                }
            }
            // if field width is greater than maximum field width so far, increase
            // static field_width.
            if (field_width < extract.getFieldWidth()) {
                field_width = extract.getFieldWidth();
            }
        }
        catch (const char *error) {
            std::cout << error << std::endl;
            break;
        }
    }
}

bool Task::validate(const Task &task)
{
    if (task.name == nextTask[passed]) {
        // if task name is equal to the first next task, assign first pNextTask to this task.
        pNextTask[passed] = &task;
    }

    else if (task.name == nextTask[redirect]) {
        // if task name is equal to the second next task, assign second pNextTask to this task.
        pNextTask[redirect] = &task;
    }
    return (nextTask[passed].empty() || pNextTask[passed])
        && (nextTask[redirect].empty() || pNextTask[redirect]);
}

const std::string &Task::getName() const
{
    return name;
}

unsigned int Task::getSlots() const
{
    return static_cast<unsigned int>(std::stoi(slots));
}

const Task *Task::getNextTask(Task::Quality quality) const
{
    int value = 0;
    if (pNextTask[0] == nullptr) {
        throw std::string("*** Validate [" + nextTask[passed] + "]  @  [" + name + "] ***");
    }

    switch (quality) {
        case redirect:value = passed;
            break;
        case passed:value = redirect;
            break;
    }
    return pNextTask[value];
}

void Task::display(std::ostream &os) const
{
    // display task name and number of slots
    os << "Task Name    : " << std::left << std::setw(field_width + 3)
       << "[" + name + "]"
       << "[" + slots + "]" << std::endl;

    // if 'Continue' next task is not empty...
    if (!nextTask[passed].empty()) {
        os << " Continue to : " << std::left << std::setw(field_width + 2) <<
           "[" + nextTask[passed] + "]";
        // display error if 'Continue' next task pointer is not set.
        if (pNextTask[passed] == nullptr) os << " *** to be validated ***";
        os << std::endl;
    }

    // if 'Redirect' next task is not empty...
    if (!nextTask[redirect].empty()) {
        os << " Redirect to : " << std::left << std::setw(field_width + 2) <<
           "[" + nextTask[redirect] + "]";
        // display error if 'Redirect' next task pointer is not set.
        if (pNextTask[redirect] == nullptr) os << " *** to be validated ***";
        os << std::endl;
    }
}

size_t Task::getFieldWidth()
{
    return field_width;
}

bool operator==(const Task &task_a, const Task &task_b)
{
    return task_a.getName() == task_b.getName();
}
}
