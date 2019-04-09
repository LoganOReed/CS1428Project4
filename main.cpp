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

        //verifying information

        if(numericOne[i][0] < 1 || numericOne[i][0] > 90){
            fout << "Age is not of the correct type" << endl;
            continue;
        }

        if(numericOne[i][1] < 1 || numericOne[i][1] > 90){
            fout << "Years is not of the correct type" << endl;
            continue;
        }


        if(nonNumeric[i][0].length() > 50){
            fout << "Name is not of the correct type" << endl;
            continue;
        }

        if(nonNumeric[i][1].length() > 50){
            fout << "Student ID is not of the correct type" << endl;
            continue;
        }

        if(nonNumeric[i][2].length() > 50){
            fout << "Address is not of the correct type" << endl;
            continue;
        }

        if(nonNumeric[i][3].length() > 30){
            fout << "Telephone Number is not of the correct type" << endl;
            continue;
        }

        if(nonNumeric[i][4].length() > 20){
            fout << "SSN is not of the correct type" << endl;
            continue;
        }

        //Courses
        for(int j = 0; j < NUM_COURSES; j++)
            {

            getline(fin, nonNumeric[i][j+5]);

            if(nonNumeric[i][j+5].length() > 10){
                fout << "Course Number is not of the correct type" << endl;
                continue;
            }

            //Tests
            for(int k = 0; k < NUM_TESTS; k++)
                {

                fin >> numericTwo[i][j][k];

                if(numericTwo[i][j][k] < 1.00 || numericTwo[i][j][k] > 100.0){
                        fout << "Grade is not within bounds" << endl;
                        break;
                    }

                }
                fin.ignore();

                //compute final grade for course

                numericTwo[i][j][5] = CURVE_ONE*numericTwo[i][j][0] + CURVE_TWO*numericTwo[i][j][1]+
                CURVE_THREE*numericTwo[i][j][2]+ CURVE_FOUR*numericTwo[i][j][3] + CURVE_FINAL*numericTwo[i][j][4];

                //compute letter grade

                if(numericTwo[i][j][5] < 70)
            {
                letterGrade[i][j] = 'F';
            }else if(numericTwo[i][j][5] < 80)
            {
                letterGrade[i][j]= 'C';
                }else if(numericTwo[i][j][5] < 90)
            {
                letterGrade[i][j] = 'B';
                }else
            {
                letterGrade[i][j] = 'A';
                }

            }
        }


    //printing info in a table

    //students

    fout << setw(41) << "Student Grade Sheet: " << endl << endl;

    for (int i = 0; i < NUM_STUDENTS; i++)
        {
        fout << right << setw(25) << "Student Name" << setw(10) << "" << left << setw(30) << nonNumeric[i][0] << endl;
        fout << right << setw(25) << "Student Age" << setw(10) << "" << left << setw(30) << numericOne[i][0] << endl;
        fout << right << setw(25) << "Student ID" << setw(10) << "" << left << setw(30) << nonNumeric[i][1] << endl;
        fout << right << setw(25) << "Student Address" << setw(10) << "" << left << setw(30) << nonNumeric[i][2] << endl;
        fout << right << setw(25) << "Years at Texas State" << setw(10) << "" << left << setw(30) << numericOne[i][1] << endl;
        fout << right << setw(25) << "Telephone Number" << setw(10) << "" << left << setw(30) << nonNumeric[i][3] << endl;
        fout << right << setw(25) << "Social Security Number" << setw(10) << "" << left << setw(30) << nonNumeric[i][4] << endl << endl;

        //classes
        for (int j = 0; j < NUM_COURSES; j++)
            {

            fout << right << setw(25) << "Course Code" << setw(10) << "" << left << setw(30) << nonNumeric[i][5+j] << endl;


            fout << right << setw(25) << "Test One Score" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][0] << endl;
            fout << right << setw(25) << "Test Two Score" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][1] << endl;
            fout << right << setw(25) << "Test Three Score" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][2] << endl;
            fout << right << setw(25) << "Test Four Score" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][3] << endl;
            fout << right << setw(25) << "Final Test Score" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][4] << endl;
            fout << right << setw(25) << "Final Grade for Class" << setw(10) << "" << left << setw(30) << setprecision(4) << numericTwo[i][j][5] << endl << endl;
            fout << right << setw(25) << "Final Letter Grade" << setw(10) << "" << left << setw(30) << setprecision(4) << letterGrade[i][j] << endl << endl;

            if(numericTwo[i][j][5] >= 90){
                fout << "" << congrats[1] << endl << endl;
            }else if (numericTwo[i][j][5] < 70){
                fout << "" << congrats[0] << endl << endl;
            }

            }
        }

    //close files
    fin.close();
    fout.close();

    return 0;
}
