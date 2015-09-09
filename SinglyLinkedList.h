#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include<iostream>

using namespace std;

/**
 * Linked list node
 */
struct ListNode
{
    int nValue;
    ListNode* pNextNode;
};

/*
 * Linked list class.
 */
class LinkedList
{
public:

    LinkedList();
    ~LinkedList();
    void Insert( const int nNumber_i, const int nPosition_i = 1 );
    void DeletePosNode( const int nPosition_i );
    bool DeleteValueNode( const int nNumber_i );
    void DeleteAll();
    void PrintList();

private:

    LinkedList( LinkedList& CopyList_i );
    LinkedList& operator=( LinkedList& CopyList_ );
    ListNode* MakeNode( int nNumber_i );

private:

    ListNode* m_pBaseNode;
};

#endif // _LINKED_LIST_H_