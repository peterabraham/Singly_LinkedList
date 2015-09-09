#include "SinglyLinkedList.h"

/**
 * Linked List Constructor
 */
LinkedList::LinkedList() : m_pBaseNode( NULL )
{
}


/**
 * Linked List Destructor
 */
LinkedList::~LinkedList()
{
    DeleteAll();
}


/**
 * Function to create a new node.
 */
void LinkedList::Insert( const int nNumber_i, const int nPosition_i )
{
    ListNode* pNewNode = MakeNode( nNumber_i );
    ListNode* pNodeP = NULL;
    ListNode* pNodeQ = NULL;
    int nPos = 1;

    pNodeP = m_pBaseNode;
    if( nPosition_i == 1 )
    {
        pNewNode->pNextNode = pNodeP;
        m_pBaseNode = pNewNode;
    }
    else
    {
        while(( pNodeP != NULL ) && ( nPos < nPosition_i ))
        {
            pNodeQ = pNodeP;
            pNodeP = pNodeP->pNextNode;
            nPos++;
        }
        pNewNode->pNextNode = pNodeP;
        pNodeQ->pNextNode = pNewNode;
    }
}


/**
 * Function to delete a node from input position.
 */
void LinkedList::DeletePosNode( const int nPosition_i )
{
    ListNode* pNodeP = NULL;
    ListNode* pNodeQ = NULL;
    int nPos = 1;

    if( NULL == m_pBaseNode )
    {
        cout << "Linked list is empty!!!..." << endl;
        return;
    }
    pNodeP = m_pBaseNode;
    if( 1 == nPosition_i )
    {
        m_pBaseNode = pNodeP->pNextNode;
        delete pNodeP;
        pNodeP = NULL;
    }
    else
    {
        while(( pNodeP != NULL ) && ( nPos < nPosition_i ))
        {
            pNodeQ = pNodeP;
            pNodeP = pNodeP->pNextNode;
            nPos++;
        }
        if( NULL == pNodeP )
        {
            cout << "Position Does not exist!!!..." << endl;
        }
        else
        {
            pNodeQ->pNextNode = pNodeP->pNextNode;
            delete pNodeP;
            pNodeP = NULL;
        }
    }
}


bool LinkedList::DeleteValueNode( const int nNumber_i )
{
    if( NULL == m_pBaseNode )
    {
        cout << "Linked list is empty!!!..." << endl;
        return false;
    }

    ListNode* pTempNode = m_pBaseNode;
    ListNode* pPrevNode = NULL;

    while( NULL != pTempNode )
    {
        if( pTempNode->nValue == nNumber_i )
        {
            if( NULL == pPrevNode )
            {
                m_pBaseNode = pTempNode->pNextNode;
            }
            else
            {
                pPrevNode->pNextNode = pTempNode->pNextNode;
            }
            delete pTempNode;
            pTempNode = NULL;
            return true;
        }
        pPrevNode = pTempNode;
        pTempNode = pTempNode->pNextNode;
    }
    cout << "Item not found!!!..." << endl;
    return true;
}


/**
 * Function to delete all nodes.
 */
void LinkedList::DeleteAll()
{
    if( NULL == m_pBaseNode )
    {
        cout << "Linked list is already empty!!!..." << endl;
        return;
    }

    ListNode* pTempNode = m_pBaseNode;
    ListNode* pDeleteNode = NULL;
    while( NULL != pTempNode )
    {
        pDeleteNode = pTempNode;
        pTempNode = pTempNode->pNextNode;
        delete pDeleteNode;
        pDeleteNode = NULL;
    }
    m_pBaseNode = NULL;
}


/**
 * Function to print the list values.
 */
void LinkedList::PrintList()
{
    if( NULL == m_pBaseNode )
    {
        cout << "Linked list is empty!!!..." << endl;
        return;
    }

    int nPos = 1;
    ListNode* pTempNode = m_pBaseNode;
    while( NULL != pTempNode )
    {
        cout << "Element " << nPos << " = " << pTempNode->nValue << endl;
        pTempNode = pTempNode->pNextNode;
        nPos++;
    }
}


/**
 * Function to create a new node.
 */
ListNode* LinkedList::MakeNode( int nNumber_i )
{
    ListNode* NewNode = new ListNode();
    NewNode->nValue = nNumber_i;
    NewNode->pNextNode = NULL;

    return NewNode;
}


/**
 * main function to demonstrate Linked List
 **/
int main(int argc, char **argv )
{
    LinkedList* list = new LinkedList();
    for( int nIndex = 0; nIndex < 10; ++nIndex )
    {
        list->Insert( nIndex * 2 );
    }

    cout << "\n\n*********************" << endl;
    cout << "Complete List" << endl;
    list->PrintList();

    cout << "\n\n*********************" << endl;
    cout << "Delete from Position 3" << endl;
    list->DeletePosNode( 3 );
    list->PrintList();

    cout << "\n\n*********************" << endl;
    cout << "Insert 7 to position 5" << endl;
    list->Insert( 7, 5 );
    list->PrintList();

    cout << "\n\n*********************" << endl;
    cout << "Delete the value 8" << endl;
    list->DeleteValueNode( 8 );
    list->PrintList();

    cout << "\n\n*********************" << endl;
    cout << "Delete All elements" << endl;
    list->DeleteAll();
    list->PrintList();

    return 0;
}