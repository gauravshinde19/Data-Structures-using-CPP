// Program for Singly Circular LinkedList

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyCircularLL
{
private:
    PNODE First;
    PNODE Last;
    int iCount;

public:
    SinglyCircularLL();

    void Display();
    int Count();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

SinglyCircularLL::SinglyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCircularLL::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }

    cout << "-> ";
    do
    {
        cout << "| " << First->data << "| -> ";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

int SinglyCircularLL::Count()
{
    return iCount;
}

void SinglyCircularLL::InsertFirst(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;

    iCount++;
}

void SinglyCircularLL::InsertLast(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;

    iCount++;
}

void SinglyCircularLL::InsertAtPos(int No, int iPos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
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

        newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

void SinglyCircularLL::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

void SinglyCircularLL::DeleteLast()
{
    if (First == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;

        Last = temp;
        Last->next = First;
    }

    iCount--;
}

void SinglyCircularLL::DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
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
        temp1 = First;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

int main()
{
    SinglyCircularLL obj;
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
