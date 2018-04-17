// This program simulates a vending machine
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    //declare integers for quarters, dimes, and nickels
    int quarters, dimes, nickels;
    //declare a double storing the total amount of money the user inputted into the vending machine
    double amountEntered;
    //declare an int for the user's item selection
    int selection = 10;
    //declare integers for the amount of potato chips, cookies, and candies currently in stock
    int chipQ=1, cookieQ=2, candyQ=4; //these can be initialized to whatever you want
    //declare doubles for costs of items
    const double chipC=1.25, cookieC=.85, candyC=.95;
    //declare double for the amount user owes depending on their selection
    double amountOwed;
    //declare a bool for whether or not the selected food item is in stock
    bool inStock;
    //int used to help calculate number of quarters, dimes, and nickels to spit out as change
    int change;
    //choice variable to determine when the user is finished buying from the vending machine
    int choice;
    //declare a bool to determine when the user is finished buying from the vending machine
    bool finished = false;
    //variable counter for a loop that will only execute if this counter is above 0, representing the number of times the main loop has run, the for loop will enter a bunch of
    //endl characters to clear up a new start for the vending machine program
    int separationCounter=0;
    //create a while loop with condition being whether or not the user states he is done buying food (everything following that is indented will be in the while loop)
    while (finished == false){
        //title
        if(separationCounter>0){
            for(int x=0; x<20; x++){
                cout<<endl;
            }
        }
        cout << setw(45)<<"VENDING MACHINE"<<endl<<endl;
        cout << left<<setw(15)<<"potato chips"<< setw(8)<<"- $1.25"<<endl;
        cout << left<<setw(15)<<"cookie"<< setw(8)<<"- $0.85"<<endl;
        cout << left<<setw(15)<<"candy"<< setw(8)<<"- $0.95"<<endl<<endl;
        //prompt user for the amount of money they insert into the vending machine in quarters, dimes, and nickels
        cout << "How many quarters? -> ";
        cin >> quarters;
        cout <<"How many dimes? -> ";
        cin >> dimes;
        cout <<"How many nickels? -> ";
        cin >> nickels;
        amountEntered = (.25*quarters)+(.1*dimes)+(.05*nickels);
        cout<<endl<<"amount deposited: $"<<amountEntered<<endl;
        //display a selection of food items for the user
        while(selection >3 || selection <1){
            cout << endl << endl;
            cout << "Please select a food item by entering a corresponding number:" <<endl<<"1)  "<<setw(15)<<"Potato chips" << "($1.25)"<<endl<<"2)  "<<setw(15)<<"Cookies"<<"($0.85)"<<endl<<"3)  "<<setw(15)<<"Candies"<<"($0.95)"<<endl<<"-> ";
            //take buyer's selection
            cin >> selection;
            cout << endl;
        }
        //check if user's selection is in stock with a bunch of if statements
        if(selection==1){
            if(chipQ>0){
                inStock=true;
                amountOwed = chipC;
            }
            else
                inStock=false;
        }
        if(selection==2){
            if(cookieQ>0){
                inStock=true;
                amountOwed = cookieC;
            }
            else
                inStock=false;
        }
        if(selection==3){
            if(candyQ>0){
                inStock=true;
                amountOwed = candyC;
            }
            else
                inStock=false;
        }

        if(inStock==true){
            //if the buyer's selected food item is in stock, check if the buyer has inserted sufficient funds for their selected food item
            if(amountEntered>=amountOwed){
                //if so, the selected food will be dispensed, and a message is shown saying "please take your (whatever they selected)"
                //now change quantity of the item that was dispensed
                if(selection==1){
                    cout << "please take your potato chips"<<endl;
                    chipQ--;
                }
                if(selection==2){
                    cout << "please take your cookie"<<endl;
                    cookieQ--;
                }
                if(selection==3){
                    cout << "please take your candy"<<endl;
                    candyQ--;
                }

                //also if the user entered more money than the cost of the item, print out change dispensed
                if(amountEntered!=amountOwed){
                    cout << endl << "here is your change:" << endl;
                    change=(amountEntered-amountOwed)*100.0;
                    while(change%5!=0){ //to compensate for the integer conversion imprecision
                        change++;
                    }
                    if(change>=25){
                        cout << "quarters: " << change/25 <<endl;
                        change-=(change/25*25);
                        cout << "dimes: " << change/10 <<endl;
                        change-=(change/10*10);
                        cout << "nickels: "<<change/5 <<endl<<endl;
                    }
                    else if(change>=10){
                        cout << "quarters: " << change/25 <<endl;
                        cout << "dimes: " << change/10 <<endl;
                        change-=(change/10*10);
                        cout << "nickels: "<<change/5 <<endl<<endl;
                    }
                    else{
                        cout << "quarters: " << change/25 <<endl;
                        cout << "dimes: " << change/10 <<endl;
                        cout << "nickels: "<<change/5 <<endl<<endl;
                    }
                }
                else{
                    cout <<endl;
                }
                //ask if user wants to continue buying food

                cout << "would you like to buy more food? (enter 1 for yes or 0 for no) -> ";
                cin >> choice;
                if(choice==1){
                    finished=false;
                    cout<<endl<<endl;
                }
                else{
                    finished=true;
                }
            }
            else{
                //if the user didn't insert enough money, give them a choice to insert more money or to get their money back
                int choice2; //int for user to choose whether or not they want to insert more money or to get their money back
                cout << "you have insufficient funds, would you like to insert more money or get your"<< endl <<"money back? (enter 1 for insert more money and 0 for money back) -> ";
                cin >> choice2;
                if(choice2==1){
                    //while loop that asks for money until enough is paid
                    while(amountEntered<amountOwed){
                        //if they want to insert more money, ask them to insert the selected item price minus the amount they already entered in quarters, dimes, and nickels respectively
                        cout << endl <<"How many quarters? -> ";
                        cin >> quarters;
                        cout << "How many dimes? -> ";
                        cin >> dimes;
                        cout << "How many nickels? -> ";
                        cin >> nickels;
                        amountEntered += (.25*quarters)+(.1*dimes)+(.05*nickels);
                        cout<<endl<<endl<<"combined amount deposited right before buying: $"<<amountEntered<<endl;
                        //check again if user entered enough money
                    }
                    //if enough money is entered,the selected food will be dispensed, and a message is shown saying "please take your (whatever they selected)"
                    //now change quantity of the item that was dispensed
                    if(selection==1){
                    cout << "please take your potato chips"<<endl;
                    chipQ--;
                    }
                    if(selection==2){
                        cout << "please take your cookie"<<endl;
                        cookieQ--;
                    }
                    if(selection==3){
                        cout << "please take your candy"<<endl;
                        candyQ--;
                    }
                    //also if the user entered more money than the cost of the item, print out change dispensed
                    if(amountEntered!=amountOwed){
                        cout << endl << "here is your change:" << endl;
                        change=(amountEntered-amountOwed)*100;
                        while(change%5!=0){ //to compensate for the integer conversion imprecision
                            change++;
                        }
                        if(change>=25){
                            cout << "quarters: " << change/25 <<endl;
                            change-=(change/25*25);
                            cout << "dimes: " << change/10 <<endl;
                            change-=(change/10*10);
                            cout << "nickels: "<<change/5 <<endl<<endl;
                        }
                        else if(change>=10){
                            cout << "quarters: " << change/25 <<endl;
                            cout << "dimes: " << change/10 <<endl;
                            change-=(change/10*10);
                            cout << "nickels: "<<change/5 <<endl<<endl;
                        }
                        else{
                            cout << "quarters: " << change/25 <<endl;
                            cout << "dimes: " << change/10 <<endl;
                            cout << "nickels: "<<change/5 <<endl<<endl;
                        }
                    }
                    //ask if user wants to continue buying food
                    cout<<"would you like to buy more food? (enter 1 for yes or 0 for no) -> ";
                    cin >> choice;
                    if(choice==1){
                        finished=false;
                        cout<<endl<<endl;
                    }
                    else{
                        finished=true;
                    }
                }
                else{
                    //if they want their money back, spit out change and ask if user wants to continue buying food
                    cout << endl<<"please take your $"<<amountEntered<<endl<<endl;
                    cout << "would you like to buy more food? (enter 1 for yes or 0 for no) -> ";
                    cin >> choice;
                    if(choice==1){
                        finished=false;
                    }
                    else{
                        finished=true;
                    }
                }
            }
        }
        else{
            //if the buyer's selected food is sold out, state the item is currently not in stock and ask if user wants to continue buying food
            cout << "that item is currently sold out" <<endl<<endl;
            cout<< "here is your money back:" <<endl;
            cout<< quarters <<" quarters" <<endl;
            cout<< dimes <<" dimes"<<endl;
            cout<< nickels <<" nickels"<<endl<<endl;
            cout << "would you like to buy more food? (enter 1 for yes or 0 for no) -> ";
            cin >> choice;
            if(choice==1){
                finished=false;
                cout<<endl<<endl;
            }
            else{
                finished=true;
            }
        }
        separationCounter++;
        selection=10; //reset selections for while loop to work
    }
    return 0;
}
