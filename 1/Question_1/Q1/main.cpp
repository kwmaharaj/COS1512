#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double getPrize(int ticketNumber, char gender);
double getPrize(int ticketNumber, int age);
void showPrize(double prize);

int main()
{

    int ticketNumber;
    char gender;
    int age;
    double prize;

    cout << "Enter ticket number: ";
    cin >> ticketNumber;
    cout << endl;

//Divisible by 100 logic
    if((ticketNumber % 100) == 0){
        cout << "Enter gender, 'm' for male, 'f' for female: ";
        cin >> gender;
        cout << endl;

        //Check valid gender entered
        if(gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F'){
            cout << "Invalid gender entered: " << gender << endl;
            cout << "Exiting program." << endl;
            return 0;
        }

        prize = getPrize(ticketNumber, gender);

//Divisible by 6 and 7 and not 100 logic
    }else if(((ticketNumber % 7) == 0) && ((ticketNumber % 6) == 0)) {
        cout << "Enter your age: ";
        cin >> age;
        if(age < 0){
            cout << "Invalid age entered: " << age << endl;
            cout << "Exiting program.";
            return 0;
        }
        prize = getPrize(ticketNumber, age);

//Losing ticket
    }else{
        prize = 0.00;
    }

//Display the prize
    showPrize(prize);
    return 0;
}

//Prize based on gender
double getPrize(int ticketNumber, char gender)
{
    double prize = 0.0;

    if((gender == 'm' || gender == 'M') && ticketNumber > 30000){
        prize = ticketNumber / 90.00;
    }else
    if((gender == 'f' || gender == 'F') && ticketNumber > 20000){
        prize = ticketNumber / 80.00;
    }

    return prize;
}
//Prize based on age
double getPrize(int ticketNumber, int age)//test with 42 as ticketnumber
{
    double prize = 0.00;

    if(age <= 21){
        prize = age * 40;
    }else{
        prize = age * 30;
    }

    return prize;
}

void showPrize(double prize){
    cout << endl;
    if(prize > 0){
        cout << "Congratulations, you won: R " << setprecision (2) << fixed << prize;
    }else{
        cout << "Sorry you did not win anything.";
    }
    cout << endl;
}
