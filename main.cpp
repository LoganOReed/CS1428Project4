#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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



    //init variables
    double tOne, tTwo, tThree, tFour, tFinal, grade;
    string name, ssn, address, number, pepTalk, course, warning, great;
    char lGrade;
    int age, years, n;
    const int NUM_COURSES = 3, NUM_STUDENTS = 3, NUM_HEADERS = ;
    const int NUM_TESTS = 5;
    const double CURVE_ONE = 0.1, CURVE_TWO = 0.15, CURVE_THREE = 0.20, CURVE_FOUR = 0.25, CURVE_FINAL = 0.3;

    //init arrays
    string congrats[2];
    //name,A0ID,ssn,address,number,course1,course2,course3
    string nonNumeric[NUM_STUDENTS][8];

    //age, num years at texas state
    int numericOne[NUM_STUDENTS][2]

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
        fin >> congrats[i];
    }
    cout << congrats[0] << endl << congrats[1];

    //reading input file

    //students
    for(int i = 0; i < n; i++){

        //getting info
        getline(fin, name);
        fin >> age;
        fin.ignore();
        getline(fin, address);
        fin >> years;
        fin.ignore();
        getline(fin, number);
        getline(fin, ssn);

        //verifying information

        if(name.length() > 30){
            fout << "Name is not of the correct type" << endl;
            continue;
        }

        if(age < 1 || age > 90){
            fout << "Age is not of the correct type" << endl;
            continue;
        }

        if(address.length() > 50){
            fout << "Address is not of the correct type" << endl;
            continue;
        }

        if(years < 1 || years > 90){
            fout << "Years is not of the correct type" << endl;
            continue;
        }

        if(number.length() > 30){
            fout << "Telephone Number is not of the correct type" << endl;
            continue;
        }

        if(ssn.length() > 20){
            fout << "SSN is not of the correct type" << endl;
            continue;
        }

        //displaying info
        fout << setw(41) << "Student Grade Sheet: " << endl << endl;
        fout << right << setw(25) << "Student Name" << setw(10) << "" << left << setw(30) << name << endl;
        fout << right << setw(25) << "Student Age" << setw(10) << "" << left << setw(30) << age << endl;
        fout << right << setw(25) << "Student Address" << setw(10) << "" << left << setw(30) << address << endl;
        fout << right << setw(25) << "Years at Texas State" << setw(10) << "" << left << setw(30) << years << endl;
        fout << right << setw(25) << "Telephone Number" << setw(10) << "" << left << setw(30) << number << endl;
        fout << right << setw(25) << "Social Security Number" << setw(10) << "" << left << setw(30) << ssn << endl;


        //courses
        for(int i = 0; i < NUM_COURSES; i++){

            getline(fin, course);

            if(course.length() > 30){
            fout << "Course is not of the correct type" << endl;
            continue;
        }

            fout << right << setw(25) << "Course Code" << setw(10) << "" << left << setw(30) << course << endl;

                //course grade
                for (int i = 0; i < NUM_TESTS; i++){
                    double testHolder;
                    fin >> testHolder;

                    //validating test grade

                    if(testHolder < 1.00 || testHolder > 100.0){
                        fout << "Grade is not within bounds" << endl;
                        break;
                    }

                    if (i == 0)
                        tOne = testHolder;
                    else if (i == 1)
                        tTwo = testHolder;
                    else if (i == 2)
                        tThree = testHolder;
                    else if (i == 3)
                        tFour = testHolder;
                    else
                        tFinal = testHolder;


            }
             //Calculating Grade
            grade = CURVE_ONE*tOne + CURVE_TWO*tTwo + CURVE_THREE*tThree + CURVE_FOUR*tFour + CURVE_FINAL*tFinal;
            if(grade < 70)
            {
                lGrade = 'F';
            }else if(grade < 80)
            {
                lGrade = 'C';
                }else if(grade < 90)
            {
                lGrade = 'B';
                }else
            {
                lGrade = 'A';
                }

            fout << right << setw(25) << "Test One Score" << setw(10) << "" << left << setw(30) << tOne << endl;
            fout << right << setw(25) << "Test Two Score" << setw(10) << "" << left << setw(30) << tTwo << endl;
            fout << right << setw(25) << "Test Three Score" << setw(10) << "" << left << setw(30) << tThree << endl;
            fout << right << setw(25) << "Test Four Score" << setw(10) << "" << left << setw(30) << tFour << endl;
            fout << right << setw(25) << "Final Test Score" << setw(10) << "" << left << setw(30) << tFinal << endl;
            fout << right << setw(25) << "Final Grade for Class" << setw(10) << "" << left << setw(30) << grade << endl << endl;
            fout << right << setw(25) << "Final Letter Grade" << setw(10) << "" << left << setw(30) << lGrade << endl << endl;

            if(grade >= 90){
                fout << "" << great << endl << endl;
            }else if (grade < 70){
                fout << "" << warning << endl << endl;
            }

            fin.ignore();
        }
    }

    //close files
    fin.close();
    fout.close();

    return 0;
}
