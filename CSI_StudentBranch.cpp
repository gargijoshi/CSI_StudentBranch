/******************************************************************************
Problem Statement:
Department of Computer Engineering has 'CSI student branch'. Students of second, third and final year can subscribe to membership. Design a system to maintain CSI student branch membership information. Choose appropriate data structure. Write a program using C++ for following operations:
1. Add new members.
2. Compute total number of members at branch.
3. Display member information.
4. Remove member details.

*******************************************************************************/
#include <iostream>
#include<string>

using namespace std;

class node{             //Create class node
    int rollNo, year;
    string name;
    node *next;
    public:
    //Constructor
        node(){
            rollNo = 0;
            year = 0;
            name = "";
            next = NULL;
        }
        friend class list;
};      //end of class node

class list{     //Friend class list
    node *start, *temp, *prev, *newNode;
    public:
    //Function declaration
        void createMember();
        void countMembers();
        void displayMembers();
        void removeMembers();
        void searchMember();
        list(){
            start=NULL;
        }
};      //end of class list

//Function definition

//Time Complexity: O(n)
void list::createMember(){  //Inserts record in the list
    int flag=0;
    node *temp1;
    newNode = new node;
    cout<<"Enter year, name: ";
    cin>>newNode->year>>newNode->name;
    newNode->next = NULL;
    do{                     //Check for duplicate Roll no's
        flag = 0;
        cout<<"Enter roll no: ";
        cin>>newNode->rollNo;
        temp1 = new node();
        if(temp1 == NULL);
        else{
            temp1 = start;
            while(temp1 != NULL){
                if(temp1->rollNo == newNode->rollNo){
                    cout<<"Roll No already exists.";
                    flag = 1;
                    break;
                }
                temp1 = temp1->next;
            }
        }
    }while(flag == 1);
    if(start==NULL){                //When list is empty, add 1st record 
        start = newNode;
    }
    else{                           //Adds records at the end.
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newNode;
        temp = newNode;
    }
    temp = start;
}

void list::displayMembers(){        //Displays the members/records
    if(start == NULL){
        cout<<"List is empty";
    }
    else{
        temp=start;
        cout<<"\nRoll No\t\tName\t\tYear\n--------------------------------------------------------------\n";
        while(temp->next!=NULL){
            cout<<temp->rollNo<<"\t\t "<<temp->name<<"\t\t "<<temp->year;
            temp=temp->next;
            cout<<"\n";
        }
        cout<<temp->rollNo<<"\t\t "<<temp->name<<"\t\t "<<temp->year;
    }
}

//Time Complexity: O(n)
void list::searchMember(){              //Searches whether particular record is present or not
    int rno, flag=0;
    cout<<"Enter roll no: ";
    cin>>rno;
    temp = start;
    while(temp != NULL){
        if(temp->rollNo == rno){
            flag = 1;
            break;
        }
        else{
            temp = temp->next;
        }        //temp = temp->next;
    }
    if(flag==1)
        cout<<"Record is present";
    else
        cout<<"Record is not present";
}

//Time Complexity: O(n)
void list::removeMembers(){     //Deletes particular record
    int rno, flag=0;
    node *prev;
    if(start==NULL)
       cout<<"\nLinked list doesnot exist";
    else{
        cout<<"Enter the details of record to delete: \nRoll No: ";
        cin>>rno;
        temp = start;
        prev = temp;
        while(temp != NULL){
            if(temp->rollNo == rno){
                if(temp == start){
                    start = temp->next;
                }
                flag=1;
                cout<<"Deleting record...";
                prev->next = temp->next;
                delete(temp);
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        if(flag==0)
            cout<<"Record is not present";
        else
            cout<<"Record deleted successfully!";
        cout<<temp->rollNo<<" "<<temp->name<<" "<<temp->year<<"\n";
        delete(temp);
    }
       
}

//Time Complexity: O(n)
void list::countMembers(){          //Counts total number of records
    int cnt=0;
    if(start==NULL)
        cout<<"\nLinked list doesnot exist";
    else{
        temp=start;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        cout<<"\nTotal records : "<<cnt;
    }
}

int main()
{
    int ch;
    list l1;
    do{
        cout<<"\n1: Add Member\n2: Search Member\n3: Remove Member\n4: View Members\n5: Count Members\n6:Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch){                 //Invokes the function based on user's choice
            case 1:char op;
                    do{
                    l1.createMember();
                    cout<<"Do you want to add member?: Y/N ";
                    cin>>op;
            }while(op!='N' && op!='n');
                    break;
            case 2: l1.searchMember();    break;
            case 3: l1.removeMembers();    break;
            case 4: l1.displayMembers();   break;
            case 5: l1.countMembers(); break;
            default: cout<<"\nError.....Please check your choice ";
        }
    }while(ch!=6);
    return 0;
}

/*******************************************************************************
 Output:

1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 1
Enter year, name: 2 Gargi 
Enter roll no: 2378
Do you want to add member?: Y/N Y
Enter year, name: 2 Sanya
Enter roll no: 2379
Do you want to add member?: Y/N Y
Enter year, name: 2 Tanishka 
Enter roll no: 2380
Do you want to add member?: Y/N N

1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 4

Roll No		Name		Year
------------------------------------------------------------
2378		 Gargi		 2
2379		 Sanya		 2
2380		 Tanishka		 2
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 2
Enter roll no: 2378
Record is present
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 2
Enter roll no: 23
Record is not present
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 5

Total records : 3
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 3
Enter the details of record to delete: 
Roll No: 2380
Deleting record...Record deleted successfully!
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 4

Roll No		Name		Year
--------------------------------------------------------------
2378		 Gargi		 2
2379		 Sanya		 2
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 5

Total records : 2
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 
--------------------------------------------------------------------------------

2. Applying Roll no constraint:

1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 1
Enter year, name: 2 Gargi
Enter roll no: 2378
Do you want to add member?: Y/N Y
Enter year, name: 2 Sanya
Enter roll no: 2378
Roll No already exists.Enter roll no: 2379
Do you want to add member?: Y/N N

1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 4

Roll No		Name		Year
-------------------------------------------------------------
2378		 Gargi		 2
2379		 Sanya		 2
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 5

Total records : 2
1: Add Member
2: Search Member
3: Remove Member
4: View Members
5: Count Members
6:Exit
Enter your choice : 6

Error.....Please check your choice 

*******************************************************************************/
