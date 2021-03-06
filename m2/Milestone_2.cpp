/*! ********************************************************
 * OOP345: Milestone 2
 * \file Milestone_2.cpp
 * \version Version v2.0
 * \date 15/01/2016
 * \author Chris Szalwinski
 * \mainpage OOP345 Project
 * \section introduction Introduction
 *
 * The final project simulates an assembly line, which fulfils customer orders using processors that perform tasks of adding and removing specific items according to customer specifications and quality control inspections.
 *
 *
 * The complete solution is built in four milestones followed by a test suite:
 *
 * 1. Tasks - handles each task of the assembly line
 * 2. Customer Orders - handles each customer order passing through the assembly line
 * 3. Managers - manages the tasks, customer orders and items passing through the assembly line
 * 4. Assembly Line - manages the processors that constitute the assembly line
 * 5. Test Suite - executes the assembly line simulator for realistic data
***********************************************************/

// CustomerOrder Milestone - Main Program
// Milestone_2.cpp
// Chris Szalwinski
// v1.0 - 9/11/2015
// v1.1 - 9/11/2015 - customerOrder -> customerOrders for g++ 5.2 compatability (CS)
// v1.2 - 16/11/2015 - add <cstdlib> for exit (CS)
// v2.0 - 15/01/2016

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <memory>
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"
#include "CustomerOrder.h"

using namespace MS;

template<typename T>
void loadFromFile(const char *, std::vector<T> &, std::ostream &);

int main(int argc, char **argv)
{
    // process command line arguments
    if (argc != 4) {
        std::cerr << "*** invalid number of arguments ***\n"
                  << "Usage: " << argv[0] << " customer_order_file item_file delimiter\n";
        exit(1);
    }
    std::cout << "Command Line Arguments\n----------------------\n";
    std::cout << "Customer Order File Specified = " << argv[1] << "\n";
    std::cout << "Item File Specified           = " << argv[2] << "\n";
    std::cout << "File Record Field Delimiter   = " << argv[3][0] << "\n\n";
    Utilities::setDelimiter(argv[3][0]);
    // end of command line processing

    // Load, Accept and Display the Customer Orders
    //
    std::cout << "\n*** Load and Accept the Customer Orders ***\n";
    std::vector<CustomerOrder> customerOrders;
    loadFromFile(argv[1], customerOrders, std::cerr);
    std::cout << "\nList of Accepted Customer Orders\n--------------------------------\n";
    for (auto &s : customerOrders)
        s.display(std::cout);

    // Load, Accept and Display the Items in Stock
    //
    std::cout << "\n*** Load and Accept the Items in Stock ***\n";
    std::vector<Item> items;
    loadFromFile(argv[2], items, std::cerr);
    std::cout << "\nList of Items in Stock\n----------------------\n";
    for (auto &i : items)
        i.display(std::cout, true);

    // Fill the Customer Orders with the Items in Stock
    //
    std::cout << "\n*** Process the Customer Orders ***\n";
    for (auto &i : items)
        for (auto &s : customerOrders)
            s.fill(i);

    // Display the Processed Customer Orders
    //
    std::cout << "\nList of Processed Customer Orders\n---------------------------------\n";
    for (auto &s : customerOrders)
        s.display(std::cout);

    // Terminate
    //
    std::cout << "\nDone!\nPress Enter Key to Exit ... ";
    char c;
    std::cin.get(c);
}

template<typename T>
void loadFromFile(const char *fileName, std::vector<T> &collection, std::ostream &os)
{
    std::ifstream file(fileName);
    if (!file) {
        os << "*** Cannot open file named " << fileName << " ***\n";
        exit(1);
    }
    while (file) {
        std::string record;
        std::getline(file, record);
        if (file) {
            try {
                std::unique_ptr<T> entry(new T(record));
                if (!entry->empty())
                    collection.push_back(std::move(*entry));
            }
            catch (const std::string &msg) {
                os << msg << std::endl;
            }
        }
    }
}

