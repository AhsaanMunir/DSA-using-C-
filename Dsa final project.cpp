#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;

class medicineType	//main class
{
public:

    void take_order();    //to  take the customer order
    void delete_order();  //to delete the customer order
    void modify();        //to modify the customer order
	void order_list();    //to display the order_list
	void daily_summary(); //to display daily sale
	void exit();         //function to exit system
	medicineType();     //constuctor

};

 medicineType::medicineType ()
{

}		//default constructor 


struct node //constract node
{
	int Customer_number;
	string customerName;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Panadol","Sunny D(500mg)","Eno","Maticbol tablet","Risex (30mg)","Maticbol injection",
	"Acyfile Coufgh serup","spino (50mg)","lectogin 1","declorin injection"};
	double Medicine[10] = {7.00,650.00,10.00,13.00,30.00,130.00,119.00,12.00,700.00,125.00};
	double total;

//use file handing to add the file in the system (wrtie function use for the enterance of data)

	node *prev;
	node *next;
	node *link; 

}
*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()	// Main function
{

	medicineType medicine;   //declare class object
	int menu;
	do
	{
		cout<<"\t\t\t   DR.Saeed Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Bill and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		
//if we use file handing then we delte the total number of med from the stocks quantity by using append fuction

		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();	//function use to add the medicine
				break;
			}	
		
		case 2:
			{
				medicine.delete_order();	//function use to delete the medicine
				break;
			}	
			
		case 3:
			{
				medicine.modify();	//function use to  modify the medicine 
				break;
			}
		

		case 4:
			{
				medicine.order_list();	//function use to place the  order
				break;
			}	
		case 5:
			{
				medicine.daily_summary();	//function use to display the daily routine
				break;
			}	
        case 6:
			{
				medicine.exit();	//function use to  exit the program
				break;
			}

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
		
	}while(menu!=6);	
	return 0;
}


void medicineType::take_order()		//function to take away the order
{
	system("cls");                //clear sreen to avoid garbag value
	int i;

	cout <<"\nAvaliable Stock\n";
	node *temp;
	temp=new node;

				cout <<"******************************************************************************************************\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"  \t\tDRUGS NAME"<<"           \t\tDRUGS PRICE(Rs)"<<endl;
				cout <<"******************************************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Panadol             "<<"		7.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Sunny D(500mg)      "<<"		650.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Eno                 "<<"		10.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maticbol tablet     "<<"		13.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Risex (30mg)        "<<"	 	30.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maticbol injection  "<<" 		130.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acyfile Coufgh serup"<<"		119.00 Rs "<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    spino (50mg)        "<<"		12.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    lectogin 1          "<<"		700.00 Rs"<<endl;
                cout<<"_________________________________________________________________________________"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    declorin injection  "<<"      125.00 Rs"<<endl;
                cout<<" "<<endl;
    
	temp = new node;
	cout << "Order Number: ";
    cin >> temp->Customer_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "How many Medicine would you like to order:   " ;cin >> temp->x;
	cout<< endl;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		cout << "Please enter your selection : ";cin>> temp->menu2[i];cout<<endl;
        cout<< "Medicine Name:             " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want:         ";cin >> temp->quantity[i];cout<<endl;
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout<<"The Amount you Need to Pay for this is medicine is:        "<<temp->amount[i]<<"Rs"<<endl;                    
	}
	cout<<endl;
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Get the Reciept and Pay The Bill To Counter"<<endl;
    cout<<"==========================================================================="<<endl;

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
}
}


void medicineType::order_list()		//Function use to display Customer Number
{
	int i, num, num2,Sub=0;	
	bool found;			//variable use to search the Customer Bill 
	system("cls");   //clear sreen to avoid garbag value
	node *temp;

	temp=start_ptr;
	found = false;     //intilize false because of garbage value
	
	cout<<" Enter the Customer Number To Print The Bill\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\t\tOrder Details\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //If their is no order of the day
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->Customer_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Customer Number : "<<temp->Customer_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "===============================================================================" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" Rs"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Amount Given by the Customer : ";
        cin >> num;
        Sub=num-temp->total;
        cout<<endl;
        cout<<"Amount you need to Return The Customer is: "<<Sub<<endl;
		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}	


void medicineType::delete_order()	//function use to delete the whole order
{
    int i,num,count=0;
	system("cls");
    cout<<"Enter the order number you want to delete: ";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cout<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->Customer_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Bill is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->Customer_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"The Bill is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}



void medicineType::modify()		//function use  to modify the  order
{
 system("cls");
 int i, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Customer Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->Customer_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Order Number: ";
    cin >> temp->Customer_number;
	cout<< "Customer Name: ";
	cin>> temp->customerName;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "How many New Medicine would you like to Change:";
	cin >> temp->x;
	cout<<endl;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
	}
	else{
		cout <<"******************************************************************************************************\n";
		cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"  \t\tDRUGS NAME"<<"           \t\tDRUGS PRICE(Rs)"<<endl;
		cout <<"******************************************************************************************************\n";
		cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Panadol             "<<"		7.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Sunny D(500mg)      "<<"		650.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Eno                 "<<"		10.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maticbol tablet     "<<"		13.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Risex (30mg)        "<<"	 	30.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maticbol injection  "<<" 		130.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acyfile Coufgh serup"<<"		119.00 Rs "<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    spino (50mg)        "<<"		12.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    lectogin 1          "<<"		700.00 Rs"<<endl;
        cout<<"_________________________________________________________________________________"<<endl;
        cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    declorin injection  "<<"           125.00 Rs"<<endl;
        cout<<" "<<endl;
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection Number which you want to add: ";
		cin>> temp->menu2[i];
		cout<<endl;
        cout<< "New Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" Rs"<<endl;
	}
	temp = temp->next;
	
	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->Customer_number != sid)
 	{
 	cout<<"Invalid Customer Number...!"<<endl;
    }
 }
}
}
}	



void medicineType::daily_summary()		//Function to display the Daily Summary
{
	int i;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid Customer Number
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all Customer
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<" Number : "<<temp->Customer_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;
				
				cout<<"____________________________________________________________________________"<<endl;
			
				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "==========================================================================" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RM"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}


void medicineType::exit() //Function use to exit the program
{
	cout<<"\nYou choose to exit.\n"<<endl;
    cout << "==========================================================================" << endl;
    cout<<"                       THANK YOU                                            "<<endl;
    cout << "==========================================================================" << endl;
}
