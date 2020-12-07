#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
double endOfProgram(double finalCustomerTotal, double totalCustomerFunds);
int displayAisles(int aisle);
double displayAisle1();
double displayAisle2();
double displayAisle3();
void intro();


int main()
{
    double customerCash, customerDebit, customerCredit, totalCustomerFunds;
    double customerTotal = 0;
    bool continueShopping = true;
    int aisle = 0;
    int stayShopping = 0;

    cout << fixed << showpoint << setprecision(2);
    intro();

    cout << "In order to begin shopping we will need to collect your total ammount of funds. Acceptable funds are \n"
    << "Debit, Credit, and Cash!\n\n";

    cout << "How much cash do you have on you?: ";// Determining amount of funds customer has to spend
    cin >> customerCash;
    cout << "How much is on your debit card?: ";
    cin >> customerDebit;
    cout << "How much is on your credit card?: ";
    cin >> customerCredit;
    totalCustomerFunds = customerCash + customerCredit + customerDebit;
    cout << "\nThe total ammount you have to spend with us today is: $" << totalCustomerFunds << "\n\n";

    cout << "Would you like to shop with us today? Press Y/y and enter if yes: ";
        char y;
        cin >> y;
        cout << endl;
        if (y != 'Y' && y != 'y'){
        continueShopping = false;
        }

    system ("CLS"); // Clears the screen of Previous information
    intro(); // Re-Applies Intro
    //////////////////////////////////////////////////////////////////////////
    // Starting Shopping Mode
    //////////////////////////////////////////////////////////////////////////
    while(continueShopping){


        aisle = displayAisles(aisle); // display items on aisles



    //////////////////////////////////////////////////////////////////////////
    //Taking Customer down a specific aisle based on input
    //////////////////////////////////////////////////////////////////////////
        switch(aisle){
    case 1:
        cout << "Displaying Aisle 1..........\n";
        customerTotal = customerTotal + displayAisle1();
        cout << "This is your total so far: " << customerTotal;
        cout << endl << endl;
        break;
    case 2:
        cout << "Displaying Aisle 2..........\n";
        customerTotal = customerTotal + displayAisle2();
        cout << "This is your total so far: " << customerTotal;
        cout << endl << endl;
        break;
    case 3:
        cout << "Displaying Aisle 3..........\n";
        customerTotal = customerTotal + displayAisle3();
        cout << "This is your total so far: " << customerTotal;
        cout << endl << endl;
        break;
    default :
        break;
        }

        //////////////////////////////////////////////////////////////////////////
        //Asks the customer if after three times would they like to keep shopping:
        //////////////////////////////////////////////////////////////////////////

        stayShopping++;
        if(stayShopping == 3){
        cout << "Would you like to continue shopping with us? Press Y for Yes:";
        char y;
        cin >> y;
        stayShopping = 0;
        cout << endl;
        if (y != 'Y' && y != 'y'){
        continueShopping = false;
        }

        }
        system ("CLS"); // Clears the screen of Previous information
        intro(); // Re-Applies Intro
    }
    //////////////////////////////////////////////////////////////////////////
    //end of while loop
    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////
    //Begin total of Customers transaction and inform of ammount spend
    //////////////////////////////////////////////////////////////////////////

    endOfProgram(customerTotal, totalCustomerFunds);
    return 0;
}

//////////////////////////////////////////////////////////////////////////
//Aisle 1 in Grocery Store
//////////////////////////////////////////////////////////////////////////

double displayAisle1(){
     int userInput = 0;
     double customerTotal;
     ifstream infile;
     infile.open("aisle1.txt");
     string aisleOneItems;
     while(getline(infile,  aisleOneItems)){
        cout << aisleOneItems << "\n";
     }
     infile.close();

/*
cout << "Aisle 1\n"
     << "1. Canned Beans .50 \n"
     << "2. Canned Corn .50\n"
     << "3. Canned Green Beans .50\n"
     << "4. Canned Peas .50\n"
     << "5. Canned Pasta 1.00\n";

     */

        cout << "\nType in the number for item you wish to purchase: ";
        cin >> userInput;

            switch(userInput){
        case 1:
        customerTotal = .50;
        break;
        case 2:
            customerTotal = .50;
        break;
        case 3:
            customerTotal = .50;
        break;
        case 4:
            customerTotal = .50;
        break;
        case 5:
            customerTotal = 1;
        break;
        default:
    break;
    }

     return customerTotal;
}

//////////////////////////////////////////////////////////////////////////
//Aisle 2 in Grocery Store
//////////////////////////////////////////////////////////////////////////

double displayAisle2(){
     int userInput = 0;
     double customerTotal;
     ifstream infile;
     infile.open("aisle2.txt");
     string aisleTwoItems;
     while(getline(infile,  aisleTwoItems)){
        cout << aisleTwoItems << "\n";
     }
     infile.close();
/*
    cout << "Aisle 2\n"
     << "1. Pasta Sauce 3.00 \n"
     << "2. Spaghetti Noodles 1.00 \n"
     << "3. White Rice 1.50 \n"
     << "4. Brown Rice 2.00 \n"
     << "5. Boxed Potatoes 1.00\n";

     */

    cout << "\nType in the number for item you wish to purchase: ";
    cin >> userInput;

    switch(userInput){
case 1:
customerTotal = 3;
break;
case 2:
    customerTotal = 1;
break;
case 3:
    customerTotal = 1.50;
break;
case 4:
    customerTotal = 2;
break;
case 5:
    customerTotal = 1;
break;
default:
    break;
    }

     return customerTotal;
}

//////////////////////////////////////////////////////////////////////////
//Aisle 3 in Grocery Store
//////////////////////////////////////////////////////////////////////////

double displayAisle3(){
     int userInput = 0;
     double customerTotal;

     ifstream infile;
     infile.open("aisle3.txt");
     string aisleThreeItems;
     while(getline(infile,  aisleThreeItems)){
        cout << aisleThreeItems << "\n";
     }
     infile.close();
    /*
    cout << "Aisle 3\n"
     << "1. Coffee 5.00\n"
     << "2. Sugar 4.00\n"
     << "3. Flour 2.00\n"
     << "4. Bread 2.00\n"
     << "5. Cake Mix 2.00\n";
    */
    cout << "\nType in the number for item you wish to purchase: ";
    cin >> userInput;

    switch(userInput){
case 1:
customerTotal = 5.00;
break;
case 2:
    customerTotal = 4.00;
break;
case 3:
    customerTotal = 2.00;
break;
case 4:
    customerTotal = 2.00;
break;
case 5:
    customerTotal = 2.00;
break;
default:
    break;
    }

     return customerTotal;
}


//////////////////////////////////////////////////////////////////////////
//Displaying all the items in store.
//////////////////////////////////////////////////////////////////////////


int displayAisles(int aisle){
    cout << "**********************************************************\n";
    cout << "**********************************************************\n";
    cout << setw(18) <<  "Aisle1" << setw(20) <<"Aisle 2" << setw(20) << "Aisle 3\n";
    cout << setw(18) << "Canned Beans" << setw(20) <<"Pasta Sauce" << setw(20) << "Coffee\n";
    cout << setw(18) << "Canned Corn" << setw(20) <<"Spaghetti Noodles" << setw(20) << "Sugar\n";
    cout << setw(18) << "Canned Green Beans" << setw(20) <<"White Rice" << setw(20) << "Flour\n";
    cout << setw(18) << "Canned Peas" << setw(20) <<"Brown Rice" << setw(20) << "Bread\n";
    cout << setw(18) << "Canned Pasta" << setw(20) <<"Boxed Potatoes" << setw(20) << "Cake Mix\n";
    cout << "**********************************************************\n";
    cout << "**********************************************************\n";
    cout << endl << endl;
    cout << "Which aisle would you like to go down?\n";
    cin >> aisle;
    cout << endl;
    system("CLS"); // Clears the screen of Previous information
    intro(); // Re-Applies Intro
return aisle;
}

void intro(){
    cout << "**********************************************************************************\n";
    cout << "**********************************************************************************\n";
    cout << "***************Welcome to Eric's Store. We are happy to serve you!****************\n";
    cout << "**********************************************************************************\n";
    cout << "**********************************************************************************\n\n";
}

//////////////////////////////////////////////////////////////////////////
//End of Program. Cashing out customer
//////////////////////////////////////////////////////////////////////////


double endOfProgram(double finalCustomerTotal, double totalCustomerFunds){

    cout << "Your total today for shopping with us is $" << finalCustomerTotal << "\n";
    cout << "Your total funds available: " << totalCustomerFunds << "\n";

if(finalCustomerTotal > totalCustomerFunds){
    cout << "You do not have sufficient funds to cover purchase!";
    cout << endl;
}
else{
    cout << "Total funds available after purchase: " << totalCustomerFunds - finalCustomerTotal << "\n\n";
    cout << endl;
}
    cout << "Thank you for shopping with us. We hope to see you again soon here at Eric's Mart!\n\n";
}
