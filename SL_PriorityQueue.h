/** ADT priority queue: ADT sorted list implementation.
 @file SL_PriorityQueue.h */
#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE
#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"
template <class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    LinkedSortedList<ItemType> *slistPtr; // Pointer to sorted list of
                                          // items in the priority queue
public:
    /**
     * @brief Construct a new sl priorityqueue object
     *
     */
    SL_PriorityQueue();

    /**
     * @brief Construct a new sl priorityqueue object using a copy
     *
     * @param pq
     */
    SL_PriorityQueue(const SL_PriorityQueue &pq);

    /**
     * @brief Destroy the sl priorityqueue object
     *
     */
    ~SL_PriorityQueue();

    /**
     * @brief Checks if the PriorityQueueu is empty
     *
     * @return true if empty; false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Adds a new entry into the Priority queue
     *
     * @param newEntry : Entry to add
     * @return true is successfully added; false otherwise
     */
    bool add(const ItemType &newEntry);

    /**
     * @brief Removes an entry from the Priority Queue [from the front]
     *
     * @return true if removed; false otherwise
     */
    bool remove();

    /**
     *  @throw PrecondViolatedExcep if priority queue is empty. */
    ItemType peek() const noexcept(false);
}; // end SL_PriorityQueue

#include "SL_PriorityQueue.cpp"
#endif