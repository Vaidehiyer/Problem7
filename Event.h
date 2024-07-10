#include <iostream>

class Event
{
public:
    char type;  // 'A' for arrival, 'D' for departure
    int time;   // Time of the event
    int length; // Transaction length for arrival events, unused for departure events

    Event(char eventType = 'A', int eventTime = 0, int eventLength = 0)
        : type(eventType), time(eventTime), length(eventLength) {}

    bool operator>(const Event &other) const
    {
        return time > other.time;
    }

    bool operator<(const Event &other) const
    {
        return time < other.time;
    }

    bool operator==(const Event &other) const
    {
        return time == other.time;
    }
};
