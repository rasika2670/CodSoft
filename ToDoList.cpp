#include<iostream>
using namespace std ;

struct Node
{
    string data ;
    bool status;
    Node* next ;
};

class ToDoList
{
    public:
    Node* root;
    ToDoList();
    void AddTask(string data);
    void ViewTask();
    void MarkRead(int index);
    void remove(int index);
    ~ToDoList();
};

ToDoList::ToDoList()
{
    root = nullptr ;
}

ToDoList::~ToDoList()
{
    while (root != nullptr)
    {
        Node* temp = root ;
        root = root->next ;
        delete temp ;
    }
}

void ToDoList::AddTask(string data){

    Node* newNode = new Node ;
    newNode->data = data ;
    newNode->status = false ;
    newNode->next = nullptr ;

    if (root == nullptr)
    {
        root = newNode ;
        return;
    }
    Node* temp = root ;
    while (temp->next != nullptr)
    {
        temp=temp->next;
    }
    temp->next = newNode;   
}

void ToDoList::ViewTask()
{
    if (root == nullptr)
    {
        cout << "List is Empty!"<<endl;
        return;
    }

    Node* temp = root ;
    int index = 1 ;
    
    while (temp != nullptr)
    {
        cout << index << ". " << temp->data << " - ";
        if (temp->status == false)
        {
            cout << "Pending" << endl;
        }
        else
        {
            cout << "Completed" << endl;
        }
        index++;
        temp = temp->next;
    }
}

void ToDoList::MarkRead(int index)
{
    int cur = 1 ;
    if (root == nullptr)
    {
        cout << "List is Empty" << endl ;
        return ;
    }

    Node* temp = root ;

    while (temp != nullptr)
    {
        if (cur == index)
        {
            temp->status = true ;
            cout << "Task no. " << cur << " marked as completed." << endl;
            return;
        }
        cur++ ;
        temp = temp->next;
    }
    cout << "Invalid index!"<<endl;
}

void ToDoList::remove(int index)
{
    if (root == nullptr)
    {
        cout << "List is Empty" << endl ;
        return ;
    }

    Node* temp = root ;
    Node* prev = nullptr;
    int cur = 1 ;

    while (temp != nullptr)
    {
        if (cur == index)
        {
            if (prev == nullptr)
            {
                root = temp->next ;
            }
            else
            {
                prev->next = temp->next ;
            }
            
            temp->next = nullptr ;
            cout << "Task no. " << cur << " removed successfully!" << endl ;
            delete temp ;
            return;
        }
        cur++ ;
        prev = temp ;
        temp = temp->next;
    }
    cout << "Invalid index!"<<endl;   
}

int main()
{
    ToDoList task;
    int ch , index;
    string data;
    do
    {
        cout << "\nMENU" << endl;
        cout << "1.Add task\n2.View Tasks\n3.Mark as completed\n4.Remove Task\n5.Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
            case 1:
            cout << "\nEnter your Task : "<<endl;
            cin >> data ;
            task.AddTask(data);
            break ;

            case 2:
            cout << "\nYour tasks are : "<<endl;
            task.ViewTask();
            break ;

            case 3:
            cout << "Enter index of the task : ";
            cin >> index;
            task.MarkRead(index);
            break ;

            case 4:
            cout << "Enter index of the task : ";
            cin>>index;
            task.remove(index);
            break ;

            case 5:
            cout << "Exiting the program!"<<endl;
            break ;

            default :
            cout << "Invalid Input!"<<endl;
            break ;
        }
    } while (ch!=5);
    
    return 0;
}