/**
 * @file Tester.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief A program to test the Event class
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 *
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Event.h"

/**
 * @brief Test the Event Constructor
 * 
 */
void testEventConstructor()
{
    std::cout << "Testing Event Constructor...\n";
    Event e1('A', 10, 5);
    std::cout << "Expected: A, 10, 5\n";
    std::cout << "Actual: " << e1.type << ", " << e1.time << ", " << e1.length << "\n";
    std::cout << "----------------------------------\n";
}

/**
 * @brief Test the comparison operators (<, >, ==, !=)
 * 
 */
void testEventComparisonOperators()
{
    std::cout << "Testing Event Comparison Operators...\n";
    Event e1('A', 10, 5);
    Event e2('D', 15, 5);
    Event e3('A', 5, 5);

    std::cout << "Comparing e1 (10) and e2 (15)\n";
    std::cout << "Expected: e1 < e2, e2 > e1, e1 != e2\n";
    std::cout << "Actual: " << (e1 < e2) << ", " << (e2 > e1) << ", " << (e1 == e2) << "\n";

    std::cout << "Comparing e1 (10) and e3 (5)\n";
    std::cout << "Expected: e1 > e3, e3 < e1, e1 != e3\n";
    std::cout << "Actual: " << (e1 > e3) << ", " << (e3 < e1) << ", " << (e1 == e3) << "\n";

    std::cout << "Comparing e1 (10) and e1 (10)\n";
    std::cout << "Expected: e1 == e1\n";
    std::cout << "Actual: " << (e1 == e1) << "\n";
    std::cout << "----------------------------------\n";
}

int main()
{
    testEventConstructor();
    testEventComparisonOperators();
    return 0;
}
