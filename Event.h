/**
 * @file Event.h
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief Event header file
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

class Event
{
public:
    char type;  // 'A' for arrival, 'D' for departure
    int time;   // Time of the event
    int length; // Transaction length for arrival events, unused for departure events

    /**
     * @brief Construct a new Event object
     * 
     * @param eventType : Type of event = defaulted to 'A' - Arrival
     * @param eventTime : Time of event = defaulted to 0
     * @param eventLength : Length of event = defaulted to 0
     */
    Event(char eventType = 'A', int eventTime = 0, int eventLength = 0)
        : type(eventType), time(eventTime), length(eventLength) {}

    /**
     * @brief Comparison operator greater than
     * 
     * @param other Other event
     * @return true if this time is greater than other time; false otherwsie
     */
    bool operator>(const Event &other) const
    {
        return time > other.time;
    }

    /**
     * @brief Comparison operator less than
     * 
     * @param other Other event
     * @return true if this time is less than other time; false otherwsie
     */
    bool operator<(const Event &other) const
    {
        return time < other.time;
    }

    /**
     * @brief Comparison operator equal to
     * 
     * @param other Other event
     * @return true if this time is equal to other time; false otherwsie
     */
    bool operator==(const Event &other) const
    {
        return time == other.time;
    }
};
