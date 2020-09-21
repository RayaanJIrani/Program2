// Rayaan J Irani
// Program 2
// CS 1342 - Epanov
// September 21, 2020

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void continue_looping(char& keep_looking); //This method checks to see if the user wishes to continue looking at policies
string policy_selection(); // This method prompts the user to select a policy to look at
void policy_flow(string selection_name); // This method interprats the user's policy selection and directs to more directed information
void medical(); // calculates user's medical premium based on questions asked
void life(); // calculates user's life premium based on questions asked
void automobile(); // calculates user's automobile premium based on questions asked
string make_lowercase(string unedited); //converts inputed string to lowercase O(n)
int in_range_response(string prompt, int min, int max); // ensures user input between acceptable values
double in_range_response(string prompt, double min, double max); // overloaded for doubles

int main(){
    char keep_looking = 'Y'; // This is the conditional variable for the loop to see if the user wants to continue looking at policies
    string selection_name; // value of the policy which is selcted by user
    cout << "Hello Dr. Epanov." << endl;
    cout << "Thank you for choosing Fake Insurance Company for your insurance needs." << endl;
    do {
        selection_name = make_lowercase(policy_selection()); // This makes the user select a type of policy which they would like to use and insures selection is in lowercase.
        policy_flow(selection_name);
        continue_looping(keep_looking);
    }
    while(keep_looking == 'Y');
    
    cout << "Thank you for shopping with us." << endl;
    return 0;
}


void continue_looping(char& keep_looking){
    cout << "Do you want to keep looking at policies? (Y/N)" << endl;
    cin >> keep_looking;
}

string policy_selection(){
    cout << "We have multiple insurance types for you to choose from." << endl << endl;
    cout << "1. Medical" << endl;
    cout << "2. Life" << endl;
    cout << "3. Automobile" << endl << endl;
    cout << "Please Enter the name of the type of insurance you would like to select." << endl;
    
    // collection of user menu selection
    string selection_name;
    cin >> selection_name;
    cout << endl;
    return selection_name;
   
    
}

void policy_flow(string selection_name){
    if(selection_name == "medical"){
        medical();
    }
    else if(selection_name == "life"){
        life();
    } else if(selection_name == "automobile"){
        automobile();
    } else {
        cout << "This input is not valid." << endl;
    }
}

void medical(){
    
    // According to Healthcare.gov, the below factors are the only factors which can affect health care premiums.
    // Variable declarations
    int age;
    int zip;
    char tobbaco;
    double deductable;
    char dependents;
    double premium;
    
    // User questions and data collection
    cout << "We have a few short questions for you to determine your policy quote." << endl << endl;
    
    zip = in_range_response("What is the zip code of your primary residence?",0,100000);
    
    
    age = in_range_response("How old are you?",0,100);
    
    cout << "Have you ever consumed Tobacco? (Y/N)" << endl;
    cin >> tobbaco;
    
    deductable = in_range_response("How large of a deductable would you like to have?", 1.0, 1000000.0);
    
    cout << "Will your children (or other dependents) be covered under this plan? (Y/N)" << endl;
    cin >> dependents;
    
    // Calculation of Premium price
    premium = 25 + 10 * age + (abs(zip-75205) / 5.0) + (100 * (tobbaco == 'Y')) + 100 * (10000.0 / deductable) + 50 * (dependents == 'Y');
    
    // Prints out table
    cout << fixed << setprecision(2)<<  endl;
    cout << "Base:                  $ " << 25.00 << endl;
    cout << "Age:                   $ " << 10 * age << endl;
    cout << "Zip code:              $ " << (abs(zip - 75205) / 5)  << endl;
    cout << "Tobbaco user:          $ " << (100 * (tobbaco == 'Y')) << endl;
    cout << "Deductable:            $ " << setprecision(2) << 100 * (10000.0 / deductable) << endl;
    cout << "Dependents on plan:    $ " << 50 * (dependents == 'Y') << endl;
    cout << "Premium:               $ " << setprecision(2) << premium << endl;

}

void life(){
    
    // According to Investopedia, the below factors affect the price of Life Insurance
    // Variable Declarations
    int age;
    char tobbaco;
    char gender;
    char pre_Existing_Conditions;
    double death_Benefit;
    double premium;
    
    // User questions and data collections
    age = in_range_response("How old are you?",0,100);
    
    cout << "Have you ever consumed Tobacco? (Y/N)" << endl;
    cin >> tobbaco;
    
    cout << "What was your sex at birth? (M/F)" << endl;
    cin >> gender;
    
    cout << "Do you have pre-existing conditions? (Y/N)" << endl;
    cin >> pre_Existing_Conditions;
    
    death_Benefit = in_range_response("How large of a death benifit do you want?", 1000.0, 10000000.0);
    
    // Premium calculation
    premium = 20 * abs(100 - age) - 10 * (gender == 'F') + 10 * (pre_Existing_Conditions == 'Y') + 10 * (tobbaco == 'Y') + 25 + 100 * (1000000.0 / death_Benefit);
    
    // Table creation
    cout << fixed << setprecision(2) << endl;
    cout << "Base:                      $ " << 25.00 << endl;
    cout << "Age:                       $ " << 20 * abs(100 - age) << endl;
    cout << "Tobbaco user:              $ " << 10 * (tobbaco == 'Y') << endl;
    cout << "Gender:                    $ " << -10 * (gender == 'F') << endl;
    cout << "Pre-Existing Conditions:   $ " << 10 * (pre_Existing_Conditions == 'Y') << endl;
    cout << "Death Benifit:             $ " << setprecision(2) << 100 * (1000000.0 / death_Benefit) << endl;
    cout << "Premium:                   $ " << setprecision(2) << premium << endl;

}

void automobile(){
    
    // According to the Insurance Information Institute, the below factors affect the price of Automobile Insurance
    // Variable Declaration
    int age;
    double auto_Value;
    int num_Of_DUIs;
    int num_Accidents;
    double premium;
    
    // User questions and data collection
    age = in_range_response("How old are you?",16,100);
    
    auto_Value = in_range_response("What is the value of your cars?",1000.0,1000000.0);
    
    num_Of_DUIs =  in_range_response("How many DUIs have you had?",0,4);
    
    num_Accidents = in_range_response("How many accidents have you had?",0,10);
    
    
    // Premium calculation
    premium = (auto_Value / 100) + (num_Accidents) * 10 + 100 * num_Of_DUIs - (age - 16) + 5;
    
    // Table creation
    cout << fixed << setprecision(2) <<  endl;
    cout << "Base:                      $ " << 5.00 << endl;
    cout << "Age:                       $ " << -(age - 16) << endl;
    cout << "Auto Value:                $ " << setprecision(2) << (auto_Value / 100) << endl;
    cout << "Number of DUIs:            $ " << 100 * num_Of_DUIs << endl;
    cout << "Number of Accidents:       $ " << num_Accidents * 10 << endl;
    cout << "Premium:                   $ " << setprecision(2) << premium << endl;

}

string make_lowercase(string unedited){
    string lower = "";
    for (int i = 0; i < unedited.length(); ++i){
        lower += tolower(unedited[i]);
    }
    return lower;
}

int in_range_response(string prompt, int min, int max){
    string user_input;
    cout << prompt << endl;
    do {
        cout << "please enter a value between: " << min << " and " << max << endl;
        cin >> user_input;
        if ( ! isdigit(user_input[0]) || stoi(user_input) < min || stoi(user_input) > max) {
            cout << "That is an invalid input" << endl;
        }
    } while (! isdigit(user_input[0]) || stoi(user_input) < min || stoi(user_input) > max);
    return stoi(user_input);
}

double in_range_response(string prompt, double min, double max){
    string user_input;
    cout << prompt << endl;
    do {
        cout << fixed << setprecision(2);
        cout << "please enter a value between: " << min << " and " << max << endl;
        cin >> user_input;
        if ( ! isdigit(user_input[0]) || stod(user_input) < min || stod(user_input) > max) {
            cout << "That is an invalid input" << endl;
        }
    } while (! isdigit(user_input[0]) || stod(user_input) < min || stod(user_input) > max);
    return stod(user_input);
}

