/**
 * @file LinkedSortedList.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief Implementation of Link-based Sorted list
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 *
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "LinkedSortedList.h"

template <class ItemType>
void LinkedSortedList<ItemType>::clear()
{
    // Clears out the list using remove() function
    while (!isEmpty())
        remove(1);
}

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
    // Constructor (default)
}

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType> &aList)
{
    // Copy constructor
    headPtr = copyChain(aList.headPtr);
    itemCount = aList.itemCount;
}

template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const noexcept(false)
{
    // Throw exception if position is invalid
    if (position < 1 || position > getLength())
        throw PrecondViolatedExcep("getEntry() called with an invalid position.");

    return getNodeAt(position)->getItem(); // USe getNodeAt to get the node at position p
}

template <class ItemType>
Node<ItemType> *LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    if (position < 1 || position > getLength())
        return nullptr;

    // Go through the list until we reach position
    Node<ItemType> *curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    // Return the pointer
    return curPtr;
}

template <typename ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();   // Clear out the list
}

template <class ItemType>
Node<ItemType> *LinkedSortedList<ItemType>::
    copyChain(const Node<ItemType> *origChainPtr)
{
    Node<ItemType> *copiedChainPtr;
    if (origChainPtr == nullptr)
    {
        copiedChainPtr = nullptr;
        itemCount = 0;
    }
    else
    {
        // Build new chain from given one
        Node<ItemType> *copiedChainPtr =
            new Node<ItemType>(origChainPtr->getItem());
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
        itemCount++;
    } // end if
    return copiedChainPtr;
} // end copyChain

template <class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType &newEntry)
{
    Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType> *prevPtr = getNodeBefore(newEntry);
    if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else // Add after node before
    {
        Node<ItemType> *aftPtr = prevPtr->getNext();
        newNodePtr->setNext(aftPtr);
        prevPtr->setNext(newNodePtr);
    } // end if
    itemCount++;
} // end insertSorted

template <class ItemType>
Node<ItemType> *LinkedSortedList<ItemType>::
    getNodeBefore(const ItemType &anEntry) const
{
    Node<ItemType> *curPtr = headPtr;
    Node<ItemType> *prevPtr = nullptr;
    while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
    {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    } // end while
    return prevPtr;
} // end getNodeBefore

template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
    return itemCount;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType> *curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            Node<ItemType> *prevPtr = getNodeAt(position - 1);
            // Point to node to delete
            curPtr = prevPtr->getNext();
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        } // end if
          // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--; // Decrease count of entries
    }                // end if
    return ableToRemove;
} // end removegh
