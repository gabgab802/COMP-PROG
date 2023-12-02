#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
int main() {
//functionality 1: Login
//Enter user: francis then pass: 1111 to login//
string user,pass;
cout<<setw(64)<<"Customer Login"<<endl;
do {
cout<<"Enter your username: ";
cin>>user;
cout<<"Enter your pin     : ";
cin>>pass;
if (user=="francis" && pass=="1111"){
//functionality 2: header information: Displays customer's information and the current billing period for the current invoice
cout<<"------------------------------------------------------------------------------------------------------------------------\n";
cout<<setw(70)<<"GAB ELECTRIC COMPANY\n\n";
cout<<"Account Number: 202310805";
cout<<setw(96)<<"Billing Period  : December 1, 2023 - December 31, 2023\n";
cout<<"Customer Name : Francis Gabriel Abundo";
cout<<setw(76)<<"Customer Address: 45 FEU street, Marikina City\n\n";
cout<<"------------------------------------------------------------------------------------------------------------------------\n";
//functionality 3: summary of charges; displays previous and current bill and also the total amount due. Also shows the due date.
float prevuse= 870,prevbal,curruse= 940,currbal,totalchar;
float novrate = 12.34, decrate=13.26;
prevbal = prevuse* novrate;
currbal = curruse*decrate;
totalchar = prevbal + currbal;
cout<<setw(66)<<"Your Electric Bill"<<endl;
cout<<"Previous Rate   : P"<<fixed<<setprecision(2)<<novrate;
cout<<setw(65)<<"Your rate this month: P"<<fixed<<setprecision(2)<<decrate<<endl;
cout<<"Previous Reading: "<<prevuse<<" kWh";
cout<<setw(60)<<"Current reading     : "<<curruse<<" kWh"<<endl;
cout<<"Previous Balance: P"<<fixed<<setprecision(2)<<prevbal;
cout<<setw(62)<<"Current Balance     : P"<<fixed<<setprecision(2)<<currbal<<endl;
cout<<setw(89)<<"Total Charges       : P"<<fixed<<setprecision(2)<<totalchar<<endl;
cout<<setw(104)<<"Payment Due Date    : January 12, 2023"<<endl<<endl;
cout<<"------------------------------------------------------------------------------------------------------------------------\n";
//functionality 4: display of the computation for your current bill
cout<<setw(70)<<"Bill Computation Summary\n";
cout<<"Charges for this billing period: "<<currbal<<endl;
cout<<"Generation  : "<<fixed<<setprecision(2)<<currbal*0.85<<endl;
cout<<"transmission: "<<fixed<<setprecision(2)<<currbal*0.08<<endl;
cout<<"System Loss : "<<fixed<<setprecision(2)<<currbal*0.06<<endl;
if (curruse>prevuse){
	cout<<"Your consumption this month is "<<curruse-prevuse<<" kWh higher than last billing period.";}
else if (curruse<prevuse){
	cout<<"Your consumption this month is "<<prevuse-curruse<<" kWh less than last billing period.";}
cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
//functionality 4 bills payment with payment method
cout<<setw(66)<<"Bills Payment \n";
float gcash = 15000.00, bdo = 30000.00, gpay=0,bdopay=0,baltopay,gbal,bbal;
char opt;
do {
gbal=gcash-gpay;
bbal=bdo-bdopay;
baltopay=totalchar-bdopay-gpay;
if (totalchar-gpay-bdopay<0&&(gpay<=gcash&&bdopay<=bdo)){
	cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"You have overpaid P"<<abs(totalchar-bdopay-gpay)<<"."<<"This will be deducted in your next bill.\n";
	cout<<"Press any key to continue.\n";
	getch();
}
cout<<"Choose Payment method: \n";
cout<<"[A] - GCASH\n";
cout<<"[B] - BDO\n";
cout<<"[X] - EXIT\n";
cout<<"Select an option above. ";
cin >> opt;
cout<<endl;
switch (opt) {
	case 'A':case 'a': {
		cout<<"You  have P"<<gbal<<" GCASH balance.\n";
		cout <<"Enter Payment amount: ";
		cin >> gpay;
		if (gbal>=gpay){
			cout <<"You have paid: P"<< gpay<<endl<<"Amount due: P"<<baltopay<<endl<<"Remaining GCASH balance: " << gcash-gpay<<endl<<endl;
			}
		else {
			cout <<"Insufficient Balance. Please try an alternative payment method.\n";
			cout<<"Press any key to continue.\n";getch();
			}
		break;}
	case 'B':case 'b': {
		cout<<"You  have P"<<bdo-bdopay<<" BDO balance.\n";
		cout <<"Enter Payment amount: ";
		cin >> bdopay;
		if (bbal>=bdopay){
			cout<<"You have paid: P"<<bdopay<<endl<<"Amount due: P"<<baltopay<<endl<<"Remaining BDO balance : " << bbal<<endl<<endl;
			}
		else {
			cout <<"Insufficient Balance. Please try an alternative payment method.\n";
			cout<<"Press any key to continue.\n";getch();
			}
		break;}
	case 'X':case 'x':break;
	default:cout<<"Please enter a valid option.";break;
		}
	}
	//functionality 5 message whether you still have an amount to pay and message if you overpaid your bill.
		while (opt!='X' && opt!='x');
		if (baltopay>0){
			cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"You still have an amount due of P"<<baltopay<<". Please remember to pay on time to avoid disconnection!";	
			}
		else if(baltopay<=0){
		cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"Thank you for using our services!";
		}	
	}
	
		else {
		cout<<"Incorrect username or pin. Please try again.\n";}}
		while (user != "francis" && pass !="1111");
	return 0;}

