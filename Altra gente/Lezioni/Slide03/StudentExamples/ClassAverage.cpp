// LevelGrades.cpp
// Using a switch statement to count letter grades.
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;

int main(){
    int total{0}; // sum of grades
    unsigned int gradeCounter{0}; //number of grades entered
    unsigned int aCount{0}; // count of A grades
    unsigned int bCount{0}; // count of B grades
    unsigned int cCount{0}; // count of C grades
    unsigned int dCount{0}; // count of D grades
    unsigned int fCount{0}; // count of F grades

    cout << "Enter the integer grades in the range 0-100 .\n"
         << " Type the end-of-file indicator to terminate input: \n"
         << " On UNIX/Linux/Mac OS X type <Ctrl>-d and press enter \n"
         << " On Windows type <Ctrl>-z then press Enter \n";

    int grade;

    // loop until user enters the end-of-file indicator
    while(cin >>grade){
        total += grade; // add grade to total
        ++gradeCounter; // increment number of grades

        // increment appropriate letter-grade counter
        switch(grade / 10 ){
            case 9:
            case 10: // grade was between 90 and 100, inclusive
            ++aCount;
            break; //exits switch

            case 8: // grade was between 80 and 90
            ++aCount;
            break; //exits switch

            case 7: // grade was between 70 and 80
            ++cCount;
            break; //exits switch

            case 6: // grade was between 60 and 70
            ++dCount;
            break; //exits switch

            default: // grade with less then 60
            ++fCount;
            break; //exits switch
        }//end switch
    }// end while

    //set floating-point number format
    cout << fixed << setprecision(2);

    //display grade report
    cout <<" \n Grade report: \n";

    // if user entered at least one grade...
    if(gradeCounter != 0){
        //calculate average of all grades entered
        double average = static_cast<double>(total) / gradeCounter;

        //output summary of results
        cout << "Total of the "<< gradeCounter << "grades entered is"
        << total << "\nClass average is "<< average
        << "\nNumber of students who received each grade:"
        <<"\nA: "<<aCount << "\nB:"<<bCount<<"\nC:"<<cCount
        <<"\nD:"<<dCount<< "\n F:"<<fCount<<endl;
    }
    else{//no grades were entered, so output appropiate message
        cout<< "No grades were entered"<< endl;
    }
}