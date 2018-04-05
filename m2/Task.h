/*! ********************************************************
 * OOP345: Milestone 1
 * \file Task.h
 * \class Task
 * \version Version 1.0
 * \date 2018-03-25
 * \author Dominic Nunes - 016-183-121
***********************************************************/

#ifndef MS_TASK_H
#define MS_TASK_H

#include <iostream>
#include <string>

/*! OOP345 Project namespace */
namespace MS
{
/*!
 * \brief A text file identifies the tasks that make up the assembly line.
 * Each record within this file identifies one task, the number of product
 * slots that the task handles and any follow-on tasks.  A valid input
 * record includes up to 4 fields:
 *
 * 1. the name of the task
 * 2. the number of product slots available in the task
 * 3. the name of the next task upon successful completion
 * 4. the name of the next task if the inspector decides to redirect the product
 *
 * The name of the task (1) is required.  The third field specifies the default
 * next task.  The fourth field is optional.  If it is omitted, the third field
 * is optional.  If it is omitted, the second field is optional and defaults
 * to 1.
 * */
class Task
{
    std::string name;          // name of the task
    std::string slots;         // number of slots
    std::string nextTask[2];   // names of the next tasks
    const Task *pNextTask[2];  // addresses of the next tasks
    static size_t field_width; // current maximum field width

public:

    /*!
     * \enum 0 = passed, 1 = redirect
     * */
    enum Quality
    {
        passed,
        redirect
    };

    /*!
     * Upon instantiation, a Task object receives a reference to an unmodifiable
     * std::string. This string contains a single record that has been retrieved
     * from the task file specified by the user.
     *
     * The constructor initializes the number of product slots to a default value of
     * 1 and the pointers to the next tasks to safe addresses.  The constructor then
     * uses a Utilities object to extract each token from the record (see below).
     * Once the constructor has extracted all of the tokens from the record, it
     * retrieves the maximum field width needed by the extracted tokens.  If that
     * field width is greater than field_width, the constructor resets this class
     * variable to the value retrieved.  (The display member function uses this
     * field width to align the output across all of the records retrieved from
     * the task file.)
     *
     * \param record is a reference to a string of tokens
     * */
    explicit Task(const std::string &record);

    /*!
     * validates the next task(s), stored upon instantiation, by matching the
     * name of each next task to task (referenced in this function's parameter).
     * This function checks the name of each non-empty next task against task and,
     * if the names match, stores the address of task in the pointer to that
     * particular next task.  This function then checks if the pointer to each
     * non-empty next task has been resolved.  If so, this function returns true.
     * This function always returns true if both next task names are empty.
     *
     * \param task is a reference to a Task to be validated
     *
     * \returns true if both next tasks names are empty
     * */
    bool validate(const Task &task);

    /*!
     * \returns the name of the task
     * */
    const std::string &getName() const;

    /*!
     * \returns the number of product slots in the task (converted from a string
     * to an unsigned integer)
     * */
    unsigned int getSlots() const;

    /*!
     * returns the address of the next task associated with the parameter received.
     * This function reports an exception if the address (pNextTask) for a non-empty
     * next task name corresponding to quality has not been resolved (as described
     * in the validate() function).  The form of the exception is
     * *** Validate [...] @ [...] ***.
     *
     * \param quality is a Quality enum
     *
     * \returns a pointer to the next task
     * */
    const Task *getNextTask(Quality quality) const;

    /*!
     * inserts into os a full description of the task as shown in the sample
     * output listed below
     *
     * if the task has been validated - uses the
     * pointer(s) to the next task(s)
     *
     * if the task has not been validated - uses the name(s) of the next task(s)
     * and appends a note that validation is still required
     *
     * \param os is a reference to an ostream object
     * */
    void display(std::ostream &os) const;

    /*!
     * \returns the field width currently stored for all objects in this class
     * */
    static size_t getFieldWidth();
};

/*!
 * \param task_a is a reference to the first Task to be compared
 * \param task_b is a reference to the second Task to be compared
 *
 * \returns true if the tasks referenced in its parameters (task_a and task_b)
 * have the same name
 * */
bool operator==(const Task &task_a, const Task &task_b);
}

#endif // MS_TASK_H