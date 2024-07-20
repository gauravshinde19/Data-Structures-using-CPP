// Program for Doubly Linear LinkedList

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyLL
{
private:
    PNODE First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

DoublyLL::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
    PNODE temp = First;

    if (First == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }
    cout << "<=> ";
    while (temp != NULL)
    {
        cout << "| " << temp->data << "| <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    iCount++;
}

void DoublyLL::InsertLast(int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

void DoublyLL::DeleteFirst()
{
    PNODE temp = NULL;

    if (First == NULL)
    {
        cout << "Element cannot be deleted as LinkedList is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
    }

    iCount--;
}

void DoublyLL::DeleteLast()
{
    PNODE temp = NULL;

    if (First == NULL)
    {
        cout << "Element cannot be deleted as LinkedList is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

void DoublyLL::InsertAtPos(int No, int iPos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

void DoublyLL::DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    // PNODE temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }

    iCount--;
}

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after InsertFirst : " << iRet << endl << endl;

    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after InsertLast : " << iRet << endl << endl;

    obj.InsertAtPos(101, 4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after InsertAtPos : " << iRet << endl << endl;

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after DeleteFirst : " << iRet << endl << endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after DeleteLast : " << iRet << endl << endl;

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements after DeleteAtPos : " << iRet << endl << endl;

    return 0;
}
