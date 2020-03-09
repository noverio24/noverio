
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class Details {
	
	protected :
		
		
		string name, ic, phone, email;
		
	public :
		
		Details ()
		{
			name = ic = phone = email = "";
		}
		
		void setDetails (); //ask user about his/her personal details
		void printDetails(); //print personal details

}; //end of class Details

void Details :: setDetails ()
{
	string Array [5];
	ofstream outfile("Details.txt");  //create file names Details.txt
	
	cout << "IC number : ";
	cin >> ic ;
			
	cout << "Name : " ;
	cin.ignore();
	getline (cin, name) ;
			
	cout << "Email : " ;
	getline (cin, email);
					
			
	cout << "Number Phone : ";
	cin >> phone;
	cout << endl;
	
	//put into the fille						
	outfile << "NAME " << "\t\t\t" << "IC NUMBER" << "\t\t\t" << "EMAIL" <<endl; 
	outfile << name << "\t\t" << ic << "\t\t\t" << email << endl << endl;
					
	outfile<<endl<<endl<<endl;
	outfile.close();
	
}

void Details :: printDetails ()

{
	string s;
	string array[5];
	ifstream infile("Details.txt"); //read file names Details.txt

	cout << "\n\nHere is passenger personal details :- " << endl << endl;
	cout << "===============================================================" << endl;
	cout << "User Details " ;
	
	//print the Details of passenger
	for(int i=0;i<5;i++)
		{
			getline(infile,s);
			array[i]=s;
			s=" ";
			cout<<endl;
			cout<<array[i];
		}
}

//start of class Place
class Place
 {
	private : 
	
		string arrive, depart;
		Details detail;			// composition
		
	public :
		
		string Destination ()
		{
			string Dest [5];
			ofstream outfile("Destination.txt"); 		//create outputfile named Destination.txt
			
			cout << "Depart from : ";
			cin.ignore();
			getline (cin, depart);
			cout << "Arrive at : ";
			getline (cin, arrive);
			cout << endl;
			
			//check condition for arrive and depart
			while (depart == arrive)
			{
				//cin.ignore();
				cout << "Departure and Arriving cannot be same!" << endl;
				cout << "Depart from : ";
				cin.ignore();
				getline (cin, depart);
				cout << "Arrive at : ";
				getline (cin, arrive);
				cout << endl;
			
			}
			
			//put the data into file
			outfile <<  "DEPART" << "\t\t\t" << "ARRIVING" << endl;
			outfile << depart << "\t\t\t" << arrive << endl ;
			outfile.close();
		}

		//to print the destination
		void PrintPlace ()
		{
			string d;
			string array1[5];
			
			ifstream inf ("Destination.txt");		//read the file named Destination.txt 
			
			detail.printDetails(); 						//call printTicket() in class Details by using a compostion
			
			for (int i= 0; i<5; i++)
			{
				getline (inf, d);
				array1[i] = d;
				d = " ";
				cout << endl;
				cout << array1[i];
			}
		}
};//end of class Place


//start of class Book inherted from classDetails
class Book : public Details {
	
	protected :
		
		int date, month, year;
		int d1, m1, y1;
		
	public :
		
		//ask user when they want to book
		void BookingDate ()
		{
			int Ticket[5];
			ofstream outfile ("Booking.txt"); 			//create outputfile name Booking.txt
			
			cout << "Today's Day (DD) : " ; 
			cin >> d1;
			cout << "Month (MM) : " ;
			cin >> m1 ;
			cout << "Year (YYYY) : " ;
			cin >> y1;
			cout << endl;
			
			cout << "\nWhat date do you want to book? " << endl;
			cout << "Date (DD) : ";
			cin >> date ; 
			cout << "Month (MM) : ";
			cin >> month;  
			cout << "Year (YYYY) : ";
			cin >> year;
			cout << endl;
			
			while ((year <= y1 && month <= m1 && date <= d1 ))			//check condition for year, month and date
			{
				cout << "Invalid date" << endl;
				cout << "\nWhat date do you want to book? " << endl;
				cout << "Date (DD) : ";
				cin >> date ; 
				cout << "Month (MM) : ";
				cin >> month;  
				cout << "Year (YYYY) : ";
				cin >> year;
				cout << endl;
			
			}
			
			setDetails();
			
			outfile << "DATE BOOKING : " << date << " / " << month << " / " << year << endl << endl;		//put into the file
			outfile.close();
		}
		
		//to display the data for booking date
		void PrintBook()
		{
			string b;
			string array3 [5];
			ifstream file("Booking.txt");		//read the file named Booking.txt
			
			for (int i=0; i<5; i++)
			{
				getline(file, b);
				array3[i] = b;
				b = " ";
				cout << endl;
				cout << array3[i];
			}
		}
		
		
}; //end of class Book

//start of class Ticket inherited from class Book
class Ticket : public Book {
	
	protected :
		int kelas;
		int adult;
		int child;
		int infant;
		double total1, total2, total;
		
		Place place; 		//composition
		
	public :
		
		//ask the user to choose which class they want to sit
		int askTicket ()
		{
			cout << "\nPlease choose class:- " << endl;
			cout << "1. BUSINESS CLASS" << endl;
			cout << "2. FIRST CLASS" << endl;
			cout << "3. ECONOMY CLASS" << endl;
			cout << "Your choice : ";
			cin >> kelas;
			cout << endl;
			
			if ( kelas == 1)
			{
				cout << "The Price Details" << endl;
				cout << "Adult is RM 1000.OO" << endl;
				cout << "Child is RM 500.00" << endl;
				cout << "Infant is free" << endl;
			}	
	
			else if (kelas == 2)
			{
				cout << "The Price Details" << endl;
				cout << "Adult is RM 600.00" << endl;
				cout << "Child is RM 250.00" << endl;
				cout << "Infant is free" << endl;
			}	
	
			else if (kelas == 3)
			{
				cout << "The Price Details" << endl;
				cout << "Adult is RM 300.00" << endl;
				cout << "Child is RM 150.00" << endl;
				cout << "Infant is free" << endl;
			}
	
			else 
			{
				cout << "Oppsss. You choose a wrong option" << endl;
			}
			
			return kelas;
		}
		
		//calculate all the cost for adult and child
		double totalPay ()
		{
			string arr[5];
			ofstream out("People.txt"); 		//create a file name People.txt
			
			
			if ( kelas == 1 )
			{
				
				total1 = 1000*adult;
				total2 = 500*child;
				total = total1 + total2;
				//cout << "Total : RM " << total << endl;
				out << "TOTAL : RM " << total << endl;
			}
		
			else if ( kelas == 2 )
			{
				total1 = 600*adult;
				total2 = 250*child;
				total = total1 + total2;
				//cout << "Total : RM " << total << endl;
				out << "TOTAL : RM " << total << endl;
				
				return total;
			}
		
			else 
			{
				total1 = 300*adult;
				total2 = 150*child;
				total = total1 + total2;
				out << "TOTAL : RM " << total << endl;
				
				return total;
			}
			
			out.close();					//close People.txt file	
		}
		
		//ask user how many adults, children and infants
		int askPeople ()
		{
			int Peep[5];
			ofstream ofile ("People.txt");//create output file named People.txt
			
			cout << endl;
			cout << "How many people? " << endl;
			cout << "Adult (13 years old and above): " ;
			cin >> adult;
			cout << "Child (6-12 years old): " ; 
			cin >> child;
			cout << "Infant (0-5 years old): ";
			cin >> infant;
			
			ofile << "ADULT" << "\t\t" << "CHILD" << "\t\t" << "INFANT" << endl;
			ofile << adult << "\t\t" << child << "\t\t" << infant << endl;
			ofile.close(); //close file
		}
		
		//print the booking date, place for depart and arrive, and print total cost
		void PrintTicket()
		{
			string a;
			string array2 [5];
			ifstream input("People.txt");		//read the inputfile name People.txt
			
			place.PrintPlace();		//call a function in class Place by using a composition
			PrintBook();		//call a funtion in class Book by using an inheritance
			
			for (int i=3; i>0; i--)
			{
				getline (input, a);
				array2[i] = a;
				a = " ";
				cout << endl;
				cout << array2[i];
			}

		}
};


//to give the user option
int menu ()
{
	int choice;
	
	cout << endl << endl << endl;
	cout << "==========Menu============" << endl;
	cout << "1. Booking Ticket" << endl;
	cout << "2. Print Ticket" << endl;
	cout << "3. Exit" << endl;
	
	cout << endl;
	cout << "Enter your choice => " ;
	cin >> choice;
	cout << endl;
	
	return choice;
}	//end of int menu()

int main()
{ 
	cout << "----------------------" << endl;
	cout << "|     WELCOME TO     |" << endl;
	cout << "|       AIRLINE      |" << endl;
	cout << "|  TICKETING SYSTEM  |" << endl;
	cout << "----------------------" << endl;
		
	Details det;
	Book bk;
	Place pl;
	Ticket t;
	
	
	int choice=0;
	
	while (choice !=3)
	{
		choice = menu();
		
		switch (choice)
		{
			case 1:	bk.BookingDate(); 
					pl.Destination();
					
					t.askTicket();
					t.askPeople();
					t.totalPay();
					t.PrintTicket();

					
					break;
					
			case 2: cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
					cout << "^  The confirmation ticket has been sent to your email.               ^" << endl;
					cout << "^  Please check your email                                            ^" << endl;
					cout << "^  You need to download the confirmation ticket through your email    ^" << endl;
					cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
					break;
		}	
	}
	
	cout << "Thank you for using our system!" << endl;	
		
	return 0;
}
