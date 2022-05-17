//-----------------------------------------------------------------------------------
//Author:   Lauren Smith
//Date:     January 24th 2022
//Course:   Programming II, Spring 2022 
//Project:  Homework 1
//-----------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std; 

//Employee structure to create an employee object 
struct Employee 
{
    string  firstName;
    string	lastName;
    int		SSN;
    string	department;
    string	role;
    double	salary;
}; 

struct Node 
{
    Employee e; 
    Node* next; 
}; 


//function fill_DB returns nothing and accepts a pointer to an Employee object 
//the function hard codes all the data for each Employee object in the p array
void fill_DB(Node* head)
{
    //hard codes all the data for Employee 1 in the p Employee array
    Node* temp=head;
    head=head->next;

    (temp->e).SSN=135251234; 
    (temp->e).lastName="Smith"; 
    (temp->e).firstName="Sophia"; 
    (temp->e).department="DevOps"; 
    (temp->e).role="Developer"; 
    (temp->e).salary=70000.00; 
    temp=head;
    head=head->next;
    //hard codes all the data for Employee 2 in the p Employee array
    (temp->e).SSN=135675462; 
    (temp->e).lastName="Johnaon"; 
    (temp->e).firstName="Jacob"; 
    (temp->e).department="SecOps"; 
    (temp->e).role="Pentester"; 
    (temp->e).salary=130000.00; 
    
    temp=head;
    head=head->next;
    //hard codes all the data for Employee 3 in the p Employee array
    (temp->e).SSN=135239877; 
    (temp->e).lastName="William"; 
    (temp->e).firstName="Emma"; 
    (temp->e).department="DevOps"; 
    (temp->e).role="DBExpert"; 
    (temp->e).salary=100000.00; 
}

//function get_avg_salary returns a double of the average of employee salaries 
//and accepts a pointer to an Employee object 
double get_avg_salary(Node *head)
{
    double avg_sal=0; 
    //loops through all employees in the set 
    Node *temp=head; 
    while(head!=nullptr)
    {
        temp=head; 
        head=head->next; 
        avg_sal+=(temp->e).salary; 
    }
    //divides the value of avg_sal by 3 to find the average since there's 3 employees
    avg_sal/=3; 
    //returns the average salary
    return avg_sal; 
}

Node* create_SLL(int s) 
{
    Node* head=new Node; //NULL
    head->next=nullptr; 
           for(int i=1; i<s; i++)
            {
                Node* q=new Node; 
                //sets the value of next for that variable as the address of p
                q->next=head;
                //sets head=q since it's the newest node
                head=q;     
            }
            return head; 
}

void delete_SLL(Node* head)
{
    Node* temp=head; 
    while(head != nullptr)
    {
        temp=head; 
        head=head->next; 
        delete temp; 
    }
}

void display(Node* head)
{
    //prints the line and Employee DB header to the console 
    cout << string(41, '-') << " Employee DB " << string(41, '-') << endl;
    string ssn; 
    double av=get_avg_salary(head); 
    //loops to print each employees values to the console
    Node* temp=head;   
    while(head!=nullptr)
    {
        temp=head; 
        head=head->next; 
        //adds hyphens to the SSN number using the to_string function on the 
        //employees SSN 
        ssn=to_string((temp->e).SSN);
        //makes the hyphenated version of the SSN by using the substring function
        //to add hyphens in the correct locations  
        ssn=ssn.substr(0,3)+"-"+ssn.substr(3,2)+"-"+ssn.substr(5,4); 
        //prints out the hypenated ssn 
        cout << ssn;
        //prints the required gap at a specified width before next value
        cout << setw(4) << setfill(' ') << " "; 
        //prints and correctly formats the employee last name 
        cout << left << setw(7) <<setfill(' ') << (temp->e).lastName;
        //below lines follow the same pattern as above with differing spacing 
        //as required for each value   
        cout << setw(3) << setfill(' ') << " ";
        cout << left << setw(6) <<setfill(' ') << (temp->e).firstName;
        cout << setw(9) << setfill(' ') << " ";
        cout << left << setw(6)<<setfill(' ') << (temp->e).department; 
        cout << setw(11) << setfill(' ') << " ";
        cout << left << setw(9)<<setfill(' ') << (temp->e).role;
        cout << setw(20) << setfill(' ') << " ";
        //prints the salary with the correct width and formatting with the decimal
        cout << showpoint<< setprecision(2) <<fixed << right << setw(9)<<setfill(' ') << (temp->e).salary;
        //uses endline to space the data values and the avg salary 
        cout << endl;
    }
    cout << string(95, '-') << endl;
    cout << "avg salary = "; 
    //calls the get_avg_salary function and passes it the value of the p array 
    //prints value function returns with correct formatting 
    cout <<  showpoint<< setprecision(2) <<fixed << right << av;
}

int main()
{ 
    Node* a=create_SLL(3);
    fill_DB(a);
    display(a);
    delete_SLL(a);           
    return 0;
}





