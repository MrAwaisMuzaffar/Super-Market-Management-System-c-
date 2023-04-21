// Hotel Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>

#include<iostream>
#include <fstream>
using namespace std;

class shopping {

public:
	int pcode;
	
	float  price;
	float dis;
	
	char pname[20];




	public:

		void menu();
		void admin();
		void buyer();
         
		void add();
		void edit();
		void rem();
		void list();
		void recept();





};



void shopping::menu() {
  m:
	int choice;
	char email[20];
	char password[20];
	

	cout << "\t\t\t\t\t__________________________\n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t     Awais Supermarkit    \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t__________________________\n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t   1) Administrator    |\n";
	cout << "\t\t\t\t\t                        \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t   2) Administrator    |\n";
	cout << "\t\t\t\t\t                        \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t   3) Administrator    |\n";
	cout << "\t\t\t\t\t                        \n";
	cout << "\t\t\t\t\t                          \n";
	cout << "\t\t\t\t\t    Please select !   |\n";
	cout << "\t\t\t\t\t                        \n";

	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\t\t\t Please login  \n";
		cout << "\t\t\t Enter Email  \n";
		cin >> email;
		cout << "\t\t\t Enter password  \n";
		cin >> password;

		if (email == "mehomosapion@gmail.com" and password == "123") {
			admin();
		}
		else
		{
			cout << "\nInvalid email or password";
		}

		break;

	case 2:
		buyer();
		break;

	case 3:
		exit(0);
		break;

	default:

		cout << "\nInvalid command.\n";


	}
	goto m;

};
	
	 void shopping::admin() {
		int choice;
		cout << "\t\t\t\t\t  Administrator menu                      \n";
		cout << "\t\t\t\t\t                          \n";
		cout << "\t\t\t\t\t  1) Add product   |\n";
		cout << "\t\t\t\t\t                        \n";
		cout << "\t\t\t\t\t  2) Please select !   |\n";
		cout << "\t\t\t\t\t                        \n";
		cout << "\t\t\t\t\t  3) Delete the product.   |\n";
		cout << "\t\t\t\t\t                        \n";
		cout << "\t\t\t\t\t  4) Back to menu.   |\n";
		cout << "\t\t\t\t\t                        \n";

		cout << "\n\n\t Please Enter your choice ";
		cin >> choice;

		switch (choice) {
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;

		default:
			cout << "Invalid choice!";

		}
		menu();
	
	 }
	 void shopping::buyer() {
		 m:
		 int choice;
		 cout << "\t\t\t  Buyer \n";
		 cout << "\t\t\t 1)Buyer product  \n";
		 cout <<"\t\t\t                \n";
		 cout << "\t\t\t 2)Go back  \n";
		 cout << "\t\t\t                \n";
		 cout << "\t\t\t Enter your choice : \n";
	
		 cin >> choice;

		 switch (choice)
		 {
		 case 1:
			 recept();
			 break;
		 case 2:
			 menu();
			 break;
		 default:
			 cout<<"Invalid choice.";
			 break;

		 }

		goto m;

	 }
	 void shopping::add() {
	 m:

		 fstream data;
		 int c;
		 int token = 0;
		 float p;
		 float d;
		 string n;
		 cout << "\t\t\t Add new product : \n";
		 cout << "\t\t Product code of product : \n";
		 cin >> pcode;
		 cout << "\n\t\t\t Name of the product ";
		 cin >> pname;
		 cout << "\n\t\t\t Enter price of product ";
		 cout <<"\n\t\t\t Enter price of product ";
		 cin >> price;
		 cout << "\n\t\t Discount on the product.";
		 cin >> dis;


		 data.open("data.txt", ios::in);
		 if (!data) {
			 data.open("database.txt", ios::app | ios ::out);
			 data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			 data.close();
		 }
		 else {
			 data >> c >> n >> p >> d;

			 while (!data.eof()) {

				 if (c == pcode) {
					 token++;
				 }
				 data >> c >> n >> p >> d;

			 }

			 data.close();


			 goto m;
			 /*if (token == 1)
				 menu();*/

			 cout << "\n\t\t\t\t Record inserted.  ";


		 }



	 }

	 void shopping::edit() {

		 fstream data,data1;
        
		 int pkey;
		 int token = 0;
		 int c;
		 float p;
		 float d;
		 string n;

		 cout << "\n\t\t\t\t Modify the record ";
		 cout << "\n\t\t\t\t Product code :";
		 cin >> pkey;

		 data.open("database.txt",ios::in);
		 if (!data) {
			 cout << "\n\t\t\t File doesnt exist.";
		 }
		 else {
			 data.open("database1.txt", ios::app | ios::out);

			 data >> pcode >> pname >> price >> dis;
			 while (data.eof()) {
				 if (pkey == pcode) {
					 cout << "\n\t\t\t Product of  new code";
					 cin >> c;
					 cout << "\n\t\t\t Name of the product :";
					 cin >> n;
					 cout << "\n\t\t\t Price :";
					 cin >> p;
					 cout << "\n\t\t\t Discount ";
					 data1 << " " << c << " " << n << " " << p << " " <<  "\n";
					 cout << "\n\t\t\tRecord edited.";
					 token++;
				 }
				 else {
					 data1 << " " << pcode << " " << price << dis<<"\n";


				 }
				 data >> pcode >> pname >> price >> dis;

			 }
			 data.close();
			 data1.close();

			 remove("database.txt");
			 rename("database1.txt","database.txt");

			 if (token == 0)
				 cout << "\n\t\t\t\t Record not found. ";
		 }
		  
		 
	 }

	 //void shopping::rem() {
		// fstream data1, data2;
		// int pkey;
		// int token = 0;
		// cout << "\n\nt Delete product ";
		// cout << "\n\n\t Product code :";
		// cin >> pkey;
		// data1.open("database.txt", ios::in);
		// if (!data1) {
		//	 cout <<"\n\t\t\t File doesnt exist.";
		// }
		// else {
		//	 data2.open("database1.txt", ios::app | ios::out);
		//	 data1 >> pcode >> pname >> price >> dis;
		//	 while (!data1.eof()) {
		//		 if (pkey == pcode) {
		//			 cout << "\n\t\t\t Record deleted.";
		//			 token++;
		//		 }
		//		 else {
		//			 data2 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		//		 }
		//		 data1 >> pcode >> pname >> price >> dis;
		//	 }
		//	 data1.close();
		//	 data2.close();
		//	 remove("database.txt");
		//	 rename("database1.txt", "database.txt");
		//	 if (token == 0)
		//		 cout << "\n\t\t\t\t Record not found. ";



		// }
	 //}

	 void shopping::rem() {

		 fstream d1, d2;
		 int pkey;
		 int token = 0;
		 

		 cout << "\n\t\t\t Delete product ";
		 cout << "\n\t\t\t  product code";
		 cin >> pkey;
		 d1.open("database.txt", ios::in);
		 if (!d1) {
			 cout << "\n\t\t\tFile couldnt open";
		 }
		 else {

			 d1.open("database1.txt", ios::app | ios::out);
			 d1>>pcode>>pname>>price>>dis;
			

			 while (!d1.eof()) {
				 if (pcode == pkey) {
					 cout << "\n\n\t\t\t Producted deleted sucessfully.";
					 token++;
				 }
				 else {
					 d1 << " " << pcode << " " << pname << " " << price << " " << dis<<"\n";


				 }
				 d1 >> pcode >> pname >> price >> dis;

			 }
			 d1.close();
			 d2.close();

			 remove("d1.txt");
			 rename("d2.txt", "d1.txt");

			 if (token == 0)
				 cout <<"\n\t\t\t\t Record not found. ";

		 }



	 }

	 void shopping::list() {
		 fstream data;
		 data.open("database.txt", ios::in);
	 
		 cout << "\n\n------------------------------------------------------\n";
		 cout << "Procuct No,\t Name \tPrice \n";
		 cout << "\n\n------------------------------------------------------\n";
		 data >> pcode >> pname >> price >> dis;
		 while (!data.eof()) {
			 cout << "Code \t " << pname << "\t " << price << dis;
		 }
		 data.close();
		 
	 }

	 void shopping::recept() {
		 m:
		 fstream data;
		 

		 int arr[100];
		 int arrq[100];
		 int c = 0;
		 float ammount = 0;
		 float dis =  0;
		 float total = 0;
		 char option;

		 cout << "\n\n\t\t\t Recipt ";
		 data.open("database.txt", ios::in);

		 if (!data) {
			 cout << "\n\t\t\tEmpty data base";
			 }
		 else {
			 data.close();

			 list();
			 cout << "\nt\t------------------------------------------\n";
			 cout << "\nt\t                                          \n";
			 cout << "\nt\t  Please place dorder                     \n";
			 cout << "\nt\t                                          \n";
			 cout << "\nt\t                                          \n";

			 do {

				 cout <<"\n\n Enter product code. ";
				 cin >> arr[c];
				 cout << "\n\n Enter product quantity. ";
				 cin >> arr[c];

				 for (int i = 0; i < c; i++) {
					 if (arr[i] == arr[c]) {
						 cout << "\n\n Dupiceate product code, Please try again!";
						 goto m;
					 }
					 c++;
					 cout << "\n\n Do you want to buy anther product if yes press else no \n";
					 cin >> option;


				 }
				
			 } while (option == 'y');

			 cout << "\nt\t\t\t----------------------------------Recipt----------------------\n";
			 cout << "\nProcuct number No \t Product Name \t Procduct Quantity. \t Price \n";
		 
				 for (int  i = 0; i < c; i++)
				 {
					 data.open("databse.txt", ios::in);
					 data >> pcode >> pname >> price >> dis;

					 while (!data.eof()) {
						 if (pcode == arr[i]) {
							 ammount = price * arrq[i];
							 dis = ammount - (ammount * dis) / 100;
							 total = total + dis;
							 cout << "\n" << pcode << "\t" << pname << "\t" << arr[i] << "\t" << price << "\t" << ammount << dis;

						 }
						 data >> pcode >> pname >> price >> dis;
					 
					 }
				 }
				 data.close();
		 
		 
		 }
		 cout << "\n\n-----------------------------------------------------\n";
		 cout << "\n Total Ammount : " << total;


	 }

int main()
{

	shopping s;
	

	s.menu();


	return  0;
}
