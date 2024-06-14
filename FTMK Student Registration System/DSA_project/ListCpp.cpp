#include "List.h"
#include <iostream>
#include<iomanip>
#include<string>


using namespace std;



List::List() // class constractor
{
	noItem = 0;// initial the noItem to 0
	pHead = 0; //intial pHead pointer to 0
}


List::~List() {} //class deconstractor 


int List::NumberOfItem() //Function to check the number of item in the list
{
	return noItem;
}


void List::InsertToFront() //Add methode to get the data from user works when first record added
{
	string item1, item2, item4; //variables to stor data from user
	int item3;
	int seriesNo;
	Node* pNew = new Node;
	cout << "\nEnter student Name  : ";
	getline(cin, item1);
	cout << "Enter student ID      : ";
	getline(cin, item2);
	cout << "Enter student age     : ";
	cin >> item3;
	cout << "Enter student grade   : ";
	cin >> item4;
	noItem++;// increment noItem
	//here is the node budy 
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pHead;
	pHead = pNew;
}//insert function to get data from user works when one or more students exist in the list

void List::InsertToFrontInput(int seriesNo, string item1, string item2, int item3, string item4) //Insert To FrontInput function to input data to the file
{
	Node* pNew = new Node;
	noItem++;
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pHead;
	pHead = pNew;
}

void List::deleteFront() //Delete function to delet front
{
	pHead = pHead->link;//increment pHead pointer to remove front
	pCurr = pHead;
	noItem--;
	for (int i = 1; i <= noItem; i++)
	{
		pCurr->studentData.id = i;
		pPrev = pCurr;
		pCurr = pCurr->link;
	}

}



void List::InsertToMiddle()
{
	string item1, item2, item4;
	int item3;
	int seriesNo;
	Node* pNew = new Node;
	cout << "\nEnter student name  : ";
	getline(cin, item1);
	cout << "Enter ID             : ";
	getline(cin, item2);
	cout << "Enter student age     : ";
	cin >> item3;
	cout << "Enter student grade   : ";
	cin >> item4;
	if (noItem == 1)
		pCurr = pHead;
	noItem++;

	//node here will be works if one sttudent or more esist in the list
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pCurr->link;
	pCurr->link = pNew;
	pCurr = pNew;
}

void List::InsertToMiddleInput(int seriesNo, string item1, string item2, int item3, string item4) // function to input data to the file

{
	Node* pNew = new Node;
	if (noItem == 1)
		pCurr = pHead;
	noItem++;
	seriesNo = noItem;
	pNew->studentData.name = item1;
	pNew->studentData.id = item2;
	pNew->studentData.age = item3;
	pNew->studentData.grade = item4;
	pNew->studentData.bil = seriesNo;
	pNew->link = pCurr->link;
	pCurr->link = pNew;
	pCurr = pNew;
}




void List::deleteMiddle() //Delete function to delete after the front and above
{
	pPrev->link = pCurr->link;
	noItem--;
	pCurr = pHead;
	for (int i = 1; i <= noItem; i++)
	{
		pCurr->studentData.id = i;
		pPrev = pCurr;
		pCurr = pCurr->link;
	}
}

//Remove searched item function return true if item found and false if item not found
bool List::removeSearch(string target1, int& loc)
{
	if (noItem == 0)
		cout << "THERE IS NO DETAIL, LIST IS EMPTY." << endl;
	else
	{
		pCurr = pHead;
		loc = 0;
		while (pCurr->studentData.id != target1 && pCurr->link != 0)
		{
			pPrev = pCurr;
			pCurr = pCurr->link;
			loc++;
		}
		if (pCurr->studentData.id == target1)
			return true;
		else
			return false;
	}
}

//insertion sort function
void List::sortBy_ID()
{
	pCurr = pHead;//to point the first node
	pPrev = pHead;
	pCurr = pCurr->link;
	while (pCurr != NULL)//move until pCurr is Null
	{
		pPrev = pHead;
		while (pPrev != pCurr)
		{
			if (pPrev->studentData.id > pCurr->studentData.id)
			{
				string temp1, temp2, temp3;
				int temp4;
				// swaping process
				temp1 = pCurr->studentData.name;
				temp2 = pCurr->studentData.id;
				temp4 = pCurr->studentData.age;
				temp3 = pCurr->studentData.grade;

				pCurr->studentData.name = pPrev->studentData.name;
				pCurr->studentData.id = pPrev->studentData.id;
				pCurr->studentData.age = pPrev->studentData.age;
				pCurr->studentData.grade = pPrev->studentData.grade;

				pPrev->studentData.name = temp1;
				pPrev->studentData.id = temp2;
				pPrev->studentData.age = temp4;
				pPrev->studentData.grade = temp3;

			}
			else
			{
				pPrev = pPrev->link;
			}
		}
		pCurr = pCurr->link;
	}
}

bool List::searchStudentBy_ID(string target, int& loc) //search function 

{
	bool found = false;
	if (noItem == 0)
		cout << "THERE IS NO INFORMATION FOUND" << endl;
	else
	{
		pCurr = pHead;
		loc = 0;
		while (pCurr->studentData.id != target && pCurr->link != NULL)
		{
			pCurr = pCurr->link;
			loc++;
		}
		if (pCurr->studentData.id == target)
			found = true;
	}
	return found;

}

void List::printSearch(int location) //to display searched item in the list

{
	pCurr = pHead;
	int loc = 0;
	while (loc != location && pCurr->link != 0)
	{
		pPrev = pCurr;
		pCurr = pCurr->link;
		loc++;
	}
	cout << left << setw(20) << pCurr->studentData.name;
	cout << left << setw(20) << pCurr->studentData.id;
	cout << left << setw(20) << pCurr->studentData.age;
	cout << left << setw(20) << pCurr->studentData.grade;
}

void List::displayData() //Display all records function in the list

{
	pCurr = pHead;
	while (pCurr != 0)
	{
		cout << "  " << pCurr->studentData.bil << "     ";
		cout << left << setw(20) << pCurr->studentData.name;
		cout << left << setw(20) << pCurr->studentData.id;
		cout << left << setw(20) << pCurr->studentData.age;
		cout << left << setw(20) << pCurr->studentData.grade;
		pCurr = pCurr->link;
		cout << endl;
	}
}
//traverse function
bool List::Traverse()
{
	pCurr = pHead;
	while (pCurr->link != NULL)
	{
		pPrev = pCurr;
		pCurr = pCurr->link;
	}
	if (pCurr->link == NULL)
		return true;
	else
		return false;
}



//display the data from file

void List::clearList() // to delete all items in the list

{
	pCurr;
	while (pHead != NULL)
	{
		pCurr = pHead;
		pHead = pHead->link;
		delete pCurr;
	}
	pTail = NULL;
	noItem = 0;
}

void  List::update()
{
	if (pHead == NULL)
	{
		char ch;
		cout << "\n\t\tLink is empty !:" << endl;
		cout << "\n\t\tAdd a new record\n\tPress J or K:" << endl;
		cin >> ch;
		if (ch == 'J' || ch == 'j')
		{
			InsertToFront();
			return;
		}
		else
		{
			//exit)(1);


		}

	}
	else

	{
		string id;

		cout << "\n\tEnter the ID after which you want to add a new record:" << endl;
		cin >> id;

		Node* pCurr = pHead;


		while (pCurr != NULL)
		{
			if (pCurr->studentData.id == id)
			{


				cout << "\n\t\tEnter the student Full name :" << endl;
				cin >> pCurr->studentData.name;

				cout << "\n\tEnter the student ID:" << endl;
				cin >> pCurr->studentData.id;

				cout << "\n\t\t Enter the age :" << endl;
				cin >> pCurr->studentData.age;


				cout << "\n\t\t Enter the grad of student :" << endl;
				cin >> pCurr->studentData.grade;


			}
			pCurr = pCurr->link;
		}

		cout << "\n\tRecord has been Updated Successfully " << endl;
		cout << "\n\t **********THANK YOU ********* " << endl;
	}
}







///////////////////////////////////////////////////////////////// MAIN FUNCTION ////////////////////////////////////////////////////////////


void main()
{
	List mylist;
	string target, name, id, grade, target1;
	int age, bil, location, choice;
	char backOption, choice1;

	system("cls");
	system("color F1");
	//Sleep(500);


	ifstream infile;
	infile.open("info.txt"); //file name
	while (infile >> bil >> name >> id >> age >> grade)
	{
		if (mylist.NumberOfItem() == 0)
			mylist.InsertToFrontInput(bil, name, id, age, grade);
		else
			mylist.InsertToMiddleInput(bil, name, id, age, grade);
	}
	infile.close();


	do
	{      ///////////////////////////////////////////////////////////////// MAIN MENU PAGE ////////////////////////////////////////////////////////////

		cout << "\n\n\t\t" << " FTMK STUDENTS REGISTRATION SYSTEM " << endl;

		cout << "\n\t\t++++++++++++++++++++++++++++\n\t\t1. INSERT STUDENT\n\t\t2. DISPLAY RECORDS"


			"\n\t\t3. SORT BY STUDENT ID \n\t\t4. SEARCH BY STUDENT ID \n\t\t5. DELETE STUDENT\n\t\t"

			"6. UPDATE \n\t\t7. CLEAR LIST \n\t\t 8. EXIT\n\t\t++++++++++++++++++++++++++++\n\n";

		cout << "\t\t^PLEASE ENTER YOUR OPTION : ";


		cin >> choice;
		cin.ignore();
		cout << endl;
		system("cls");

		switch (choice)
		{
		case 1: // Add function call
			cout << "\n\t+++++ INSERT STUDENT +++++\n";

			if (mylist.NumberOfItem() == 0)
			{
				mylist.InsertToFront();
				cout << "\n ADD MORE..? (Y=yes, N=no) : ";
				cin >> choice1;
				cin.ignore();
				if ((choice1 == 'Y') || (choice1 == 'y'))
				{
					do
					{
						mylist.InsertToMiddle();
						cout << "\nAdd some more? (Y=yes, N=no) : ";
						cin >> choice1;
						cin.ignore();
					} while ((choice1 == 'Y') || (choice1 == 'y'));
				}
				else
					break;
			}
			else
				if (mylist.Traverse() == true)
				{
					do
					{
						mylist.InsertToMiddle();
						cout << "\nAdd more? (Y=yes, N=no) : ";
						cin >> choice1;
						cin.ignore();
					} while ((choice1 == 'Y') || (choice1 == 'y'));
				}
			cout << "\n STUDENT SUCCESSFULLY ADDED!\n";
			break;



		case 2: //Display function call

			cout << "\n\t+++++ STUDENT DETAILS +++++\n\n";


			cout << left << setw(8) << "==========" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;
			cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20) << "ID "
				<< left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
			cout << left << setw(8) << "=====" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;


			mylist.displayData();
			cout << endl << "TOTAL : " << mylist.NumberOfItem() << endl;
			break;


		case 3: //insertion sort function call
			system("cls");
			cout << "\n +++++ STUDENT SORTED BY ID +++++\n\n";
			mylist.sortBy_ID();


			cout << left << setw(8) << "=====" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;
			cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20) << "ID "
				<< left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
			cout << left << setw(8) << "=====" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;


			mylist.displayData();
			cout << endl << "Total : " << mylist.NumberOfItem() << endl;
			break;


		case 4: //Search function call
			cout << "\n+++++ SEARCH BY SUDENT ID +++++" << "\n\n ENTER SUDENT ID. : ";
			getline(cin, target);
			cout << endl;


			cout << left << setw(20) << "==========" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << endl;
			cout << left << setw(20) << "Name" << left << setw(20) << "ID" << left << setw(20)
				<< "Age" << left << setw(20) << "Grade" << endl;
			cout << left << setw(20) << "==========" << left << setw(20) << "==========" << left << setw(20)
				<< "==========" << left << setw(20) << "==========" << endl;


			if (mylist.searchStudentBy_ID(target, location) == true) {
				mylist.printSearch(location);
				cout << endl;
			}

			else
				cout << "/n STUDENT IS NOT FOUND\n\n";
			break;


		case 5:  //Delet function call
			do
			{
				system("cls");
				cout << "\n\t\t\t+++++ DELETE STUDENT +++++\n\n";
				cout << left << setw(8) << "=====" << left << setw(20) << "==========" << left << setw(20)
					<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;
				cout << left << setw(8) << " No. " << left << setw(20) << "Name " << left << setw(20)
					<< "ID " << left << setw(20) << "Age " << left << setw(20) << "Grade " << endl;
				cout << left << setw(8) << "=====" << left << setw(20) << "==========" << left << setw(20)
					<< "==========" << left << setw(20) << "==========" << left << setw(20) << "==========" << endl;


				mylist.displayData();
				cout << "\nENTER STUDENT ID TO DELETE. : \n";
				cin >> target1;

				if (mylist.removeSearch(target1, location) == true)
				{
					if (location == 0)
					{
						mylist.deleteFront();
					}
					else
					{
						mylist.deleteMiddle();
					}
					cout << "\STUDENT SUCCESSFULLY DELETED.\n";
				}
				else
					cout << "\nYOU ENTERED WRONG ID.\n";

				cout << "\nDelete more? (Y=yes, N=no) : ";
				cin >> choice1;
				cin.ignore();
			} while ((choice1 == 'Y') || (choice1 == 'y'));
			break;

		case 6: //Update list function
			mylist.update();
			cout << "\n\t... TO UPDATE ...\n\n";
			break;

		case 7: //clear list function
			mylist.clearList();
			cout << "\n\t... LIST IS EMPTY NOW ...\n\n";
			break;


		case 8: //Exit function

			cout << "######################### THANKS #########################\n\n\n";
			exit(EXIT_FAILURE);
			break;

		default:
			cout << "\n\tINVALID INPUT";
		}


		cout << "\nBACK TO MAIN MENU? (Y=yes, N=no) : ";
		cin >> backOption;
		system("cls");
	} while ((backOption == 'Y') || (backOption == 'y'));//end of do while loop 
	{

		cout << "\n. . . EXITING SYSTEM . . .\n\n";
	}
} ///////////////////////////////////////////////////////////////// END OF MAIN FUNCTION ////////////////////////////////////////////////////////////

