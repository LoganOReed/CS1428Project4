#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

/*

TODO:
    -Add A0ID to the input file
    -Change all of the
*/

using namespace std;

//Reads info from a txt file and outputs it into another file formatted
//Latest Modification 4/8/2019

int main()
{

    //init file stream objects
    fstream fin;
    ofstream fout;

    //opening files
    fin.open("Project4_A04894030_Input.txt");
    fout.open("Project4_A04894030_Output.txt");

    if(!fin){
        cout << "Input File Could Not Be Opened, Closing Program";
        return 0;
    }

    int n;

    //init constants

    const int NUM_COURSES = 3, NUM_STUDENTS = 3;
    const int NUM_TESTS = 5;
    const double CURVE_ONE = 0.1, CURVE_TWO = 0.15, CURVE_THREE = 0.20, CURVE_FOUR = 0.25, CURVE_FINAL = 0.3;

    //init arrays
    string congrats[2];

    //name,A0ID,ssn,address,number,course1,course2,course3
    string nonNumeric[NUM_STUDENTS][8];

    //age, num years at texas state
    int numericOne[NUM_STUDENTS][2];

    //5 exam grades and final score
    double numericTwo[NUM_STUDENTS][NUM_COURSES][6];

    //keeps letter grade
    char letterGrade[NUM_STUDENTS][NUM_COURSES];

    //asking user how many students
    cout << "How many Students do you have? ";
    cin >> n;
    while(n != NUM_STUDENTS){
        cout << "You must exactly three students... " << endl;
        cout << "How many Students do you have? ";
        cin >> n;
    }

    //get pepTalks
    for(int i=0;i<2;i++){
        getline(fin, congrats[i]);
    }

    //reading input file

    //Students
    for(int i = 0; i < NUM_STUDENTS; i++)
        {

        //input string things into array
        getline(fin, nonNumeric[i][0]);
        fin >> numericOne[i][0];
        fin.ignore();
        getline(fin, nonNumeric[i][1]);
        getline(fin, nonNumeric[i][2]);
        fin >> numericOne[i][1];
        fin.ignore();
        getline(fin, nonNumeric[i][3]);
        getline(fin, nonNumeric[i][4]);

        //Courses
        for(int j = 0; j < NUM_COURSES; j++)
            {

            getline(fin, nonNumeric[i][j+5]);

            //Tests
            for(int k = 0; k < NUM_TESTS; k++)
                {

                fin >> numericTwo[i][j][k];

                }
                fin.ignore();
            }
        }


    //printing arrays to check if they read correct

    //nonNumeric
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 8; j++){
            cout << nonNumeric[i][j] << endl;
        }
    }

    //numericOne
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << numericOne[i][j] << endl;
        }
    }

    //numericTwo
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 5; k++){
                cout << numericTwo[i][j][k] << endl;
            }
        }
    }

    //close files
    fin.close();
    fout.close();

    return 0;
}
