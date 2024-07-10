/**
 * @file SL_PriorityQueue.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief Implementation of Priority Queue using Linked Sorted List
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 *
 *
 * @copyright Copyright (c) 2024
 *
 */


#include "SL_PriorityQueue.h"

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
    slistPtr = new LinkedSortedList<ItemType>();
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue &pq)
{
    slistPtr = new LinkedSortedList<ItemType>(*pq.slistPtr);
}

template <class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
    delete slistPtr;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
    return slistPtr->isEmpty();
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType &newEntry)
{
    slistPtr->insertSorted(newEntry);
    return true;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
    return slistPtr->remove(1); // The highest-priority item is at the front of the sorted list
}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peek() const noexcept(false)
{
    if (isEmpty())
        throw PrecondViolatedExcep("peekFront() called with empty queue");
    return slistPtr->getEntry(1);
}
