/**
 * @file BankSimulation.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief A program that Implements the event-driven simulation of a bank that Chapter 13 described.
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
#include <fstream>
#include "Event.h"
#include "SL_PriorityQueue.h"
#include "ListQueue.h"

// Function prototypes
void processArrival(Event arrivalEvent, SL_PriorityQueue<Event> &eventQueue,
                    ListQueue<Event> &bankQueue, bool &tellerAvailable,
                    int &currentTime, int &totalWaitTime, int &customerCount);
void processDeparture(Event departureEvent, SL_PriorityQueue<Event> &eventQueue,
                      ListQueue<Event> &bankQueue, bool &tellerAvailable,
                      int &currentTime, int &totalWaitTime);
void simulate();

int main()
{
    simulate(); // Start the simulation
    return 0;
}

// Simulates the bank event-driven system
void simulate()
{
    ListQueue<Event> bankQueue;              // Queue to manage customers waiting in line
    SL_PriorityQueue<Event> eventListPQueue; // Priority queue for managing events
    bool tellerAvailable = true;             // Flag to track teller availability

    // Open input file containing arrival and transaction times
    std::ifstream inputFile("events.txt");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // Read arrival and transaction times from file and add arrival events to the priority queue
    int arrivalTime, transactionTime;
    while (inputFile >> arrivalTime >> transactionTime)
    {
        Event newArrivalEvent('A', arrivalTime, transactionTime);
        eventListPQueue.add(newArrivalEvent);
    }
    inputFile.close(); // Close the input file

    int currentTime = 0;   // Current time in the simulation
    int totalWaitTime = 0; // Total accumulated waiting time for customers
    int customerCount = 0; // Total number of customers processed

    // Process events until the event list is empty
    while (!eventListPQueue.isEmpty())
    {
        Event newEvent = eventListPQueue.peek(); // Get the next event from the priority queue
        currentTime = newEvent.time;             // Update current time to the time of the event

        // Process arrival or departure event based on event type
        if (newEvent.type == 'A')
        {
            std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
            processArrival(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime, totalWaitTime, customerCount);
        }
        else
        {
            std::cout << "Processing a departure event at time: " << currentTime << std::endl;
            processDeparture(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime, totalWaitTime);
        }
    }

    // Simulation ends, display final statistics
    std::cout << "Simulation ends." << std::endl;
    std::cout << "\nFinal Statistics:" << std::endl;
    std::cout << "  Total number of customers processed: " << customerCount << std::endl;
    if (customerCount > 0)
    {
        std::cout << "  Average amount of time spent waiting: " << static_cast<double>(totalWaitTime) / customerCount << " minutes" << std::endl;
    }
}

// Process an arrival event
void processArrival(Event arrivalEvent, SL_PriorityQueue<Event> &eventQueue,
                    ListQueue<Event> &bankQueue, bool &tellerAvailable,
                    int &currentTime, int &totalWaitTime, int &customerCount)
{
    eventQueue.remove(); // Remove the arrival event from the event queue
    customerCount++;     // Increment the count of customers processed

    // If no customers are in line and teller is available, start serving this customer immediately
    if (bankQueue.isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + arrivalEvent.length; // Calculate departure time
        Event newDepartureEvent('D', departureTime);           // Create a departure event
        eventQueue.add(newDepartureEvent);                     // Add departure event to the event queue
        tellerAvailable = false;                               // Set teller to unavailable
    }
    else
    {
        bankQueue.enqueue(arrivalEvent); // Otherwise, enqueue the customer in the bank line
    }
}

// Process a departure event
void processDeparture(Event departureEvent, SL_PriorityQueue<Event> &eventQueue,
                      ListQueue<Event> &bankQueue, bool &tellerAvailable,
                      int &currentTime, int &totalWaitTime)
{
    eventQueue.remove(); // Remove the departure event from the event queue

    // If there are customers waiting in line
    if (!bankQueue.isEmpty())
    {
        Event nextCustomer = bankQueue.peekFront();            // Get the next customer in line
        bankQueue.dequeue();                                   // Remove the customer from the line
        int waitTime = currentTime - nextCustomer.time;        // Calculate waiting time for the customer
        totalWaitTime += waitTime;                             // Accumulate total waiting time
        int departureTime = currentTime + nextCustomer.length; // Calculate departure time for the customer
        Event newDepartureEvent('D', departureTime);           // Create a new departure event
        eventQueue.add(newDepartureEvent);                     // Add departure event to the event queue
    }
    else
    {
        tellerAvailable = true; // If no customers are in line, teller becomes available
    }
}
