#include <iostream>

using namespace std;

struct student {
	int numOfCourses;
	int* grades;
};

int main()
{
    char **student_grades = new char*[5];

        student_grades[0] = new char[7];
        student_grades[1] = new char[6];
        student_grades[2] = new char[5];
        student_grades[3] = new char[8];
        student_grades[4] = new char[6];

        for(int i=0; i<7; i++){
            cin>> student_grades[0][i];
            cout<< student_grades[0][i]<< " ";
        }
        for(int i=0; i<6; i++){
            cin>> student_grades[1][i];
            cout<< student_grades[1][i]<< " ";
        }
        for(int i=0; i<5; i++){
            cin>> student_grades[2][i];
            cout<< student_grades[2][i]<< " ";
        }
        for(int i=0; i<8; i++){
            cin>> student_grades[3][i];
            cout<< student_grades[3][i]<< " ";
        }
        for(int i=0; i<6; i++){
            cin>> student_grades[4][i];
            cout<< student_grades[4][i]<< " ";
        }




}
