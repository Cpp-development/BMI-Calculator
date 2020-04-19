#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

float getWeight() 
{
    float weight;
    bool inputOk = false;
    
    while (!inputOk)
    {
        // Get the weight from the user
        cout << "Please provide your weight in kg: ";
        cin >> weight;

        // Check if the weight is a logical value, if not throw an error
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            cout <<  "Weight must be a number!" << endl;
            continue;
        }
        else if (weight <= 0)
        {
            cout <<  "Your weight cannot not be 0 or a negative value." << endl;
        }
        else if (weight < 40)
        {
            cout << "BMI can not be calculated correctly for people weighing less than 40kg." << endl;
        }
        else if (weight >= 200)
        {
            cout << weight << "?? Are you sure you weigh this much?" << endl;
        }
        else
        {
            // Everything is fine, continue
            inputOk = true;   
        }
    }

    return weight;
}

float getHeight() 
{
    float height;
    bool inputOK = false;
        
    while (!inputOK)
    {
        // Get the height from the user
        cout << "Please provide your height in m: ";
        cin >> height;

        // Check if the height is a logical value, if not throw an error
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            cout <<  "Height must be a number!" << endl;
            continue;
        }
        else if (height <= 0)
        {
            cout << "Your height cannot not be 0.\n";
        }
        else if (height < 1.4)
        {
            cout << "BMI can not be calculated correctly for people smaller than 1.4m.\n";
        }
        else if (height >= 2.5)
        {
            cout << "Either you are really tall or you entered a weight here\n";
        }
        else
        {
            // Everything is fine, continue
            inputOK = true;    
        }
    }

    return height;
}

float calculateBMI(float weight, float height) 
{
    float yourBMI = weight / pow(height,2);
    return yourBMI;
}

string getBmiMessage(float yourBMI)
{
    string bmiMessage = ""; 
    if (yourBMI < 18.5)
    {
        bmiMessage = "You are underweight, you should gain some weight!";
    }
    else if (yourBMI < 25)
    {
        bmiMessage = "You have a healthy weight, try to keep it that way.";
    }
    else if (yourBMI < 30)
    {
        bmiMessage = "You are overweight, you should lose some weight!";
    }
    else if (yourBMI > 30)
    {
        bmiMessage = "You suffer from severe obesity. Try to lose weight with supervision!!";
    }
    
    return bmiMessage;
}

int main()
{
    /*float weight = 0;
    float height = 0;
    float yourBMI = 0;*/
    char ContinueAnswer;
    do
    {
        /*
        cout << "Please provide your weight in kg: ";
        cin >> weight;
        cout << "Please provide your height in m: ";
        cin >> height;
        yourBMI = weight / pow(height,2);
        */
        float weight = getWeight();
        float height = getHeight();
        float yourBMI = calculateBMI(weight, height);
        string bmiMessage = getBmiMessage(yourBMI);
        cout.precision(3);
        cout << "\n\tYour BMI is: " << yourBMI << endl;
        cout << "\t" + bmiMessage + "\n";
        cout << "\nDo you want to calculate another BMI? (Y/N)";
        cin >> ContinueAnswer;
        if (!(ContinueAnswer == 'Y' || ContinueAnswer == 'y'))
        {
            cout << "Ending program. Good bye.";
        }
    } while (ContinueAnswer == 'Y' || ContinueAnswer == 'y');
    
    return 0;
}

