#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Student{
    char name[40];
    char Middle_School[35];
    float grade;
    int options[6] = {-1} ;
};

struct High_School{
    char name[40];
    int capacity;
    int id;
    int size;
};


int distribution(int index, High_School hs[], Student st[])
{   // this function "distributes" students, if the high school has vacancies , the student id distributed
    for(int i = 0; i < 5 && st[index].options[i] != -1; i++){
        if(hs[st[index].options[i]].size < hs[st[index].options[i]].capacity){
            hs[st[index].options[i]].size++;
            return st[index].options[i];
        }
    }

    return -1;
}

void swap_grade(float &a, float &b)
{
    float aux;
    aux = a;
    a = b;
    b = aux;

}

void swap_string(char a[50], char b[50])
{
    char aux[50];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);

}

void change_value(Student st[], int j)
{ //for a better functionality, this is used
   for(int i = 0; i < 6; i++)
    st[j].options[i] = -1;

}

void swap_options(Student st[], int i, int j)
{
    int k = 0, aux[6] = {-1};


    while(st[i].options[k] != -1 && k < 5){
        aux[k] = st[i].options[k];
        k++;
    }


    change_value(st,i);
    k = 0;


    while(st[j].options[k] != -1 && k < 5){
        st[i].options[k] = st[j].options[k];
        k++;
    }


    change_value(st,j);
    k = 0;


    while(aux[k] != -1 && k < 5){
        st[j].options[k] = aux[k];
        k++;
    }

}

void display_results_by_categories(Student st[], High_School hs[], int nr_students)
{ //the function displays the results depending on the high school where the student was assigned or not

    fstream file3("distributed.txt");
    fstream file4("undistributed.txt");
    fstream file5("GH. M. Murgoci.txt");
    fstream file6("N. Balcescu.txt");
    fstream file7("N. Iorga.txt");
    fstream file8("Ana Aslan.txt");
    fstream file9("P. Cerna.txt");


    int cod, i;
    for(i = 0; i < nr_students; i++){
        cod = distribution(i, hs, st);
        if(cod == 0){
            file5 << st[i].name;
            file5 << "  -  ";
            file5 << st[i].Middle_School;
            file5 << "  -  ";
            file5 << st[i].grade;
            file5 << '\n';
        }

        if(cod == 1){
            file6 << st[i].name;
            file6 << "  -  ";
            file6 << st[i].Middle_School;
            file6 << "  -  ";
            file6 << st[i].grade;
            file6 << '\n';
        }

        if(cod == 2){
            file7 << st[i].name;
            file7 << "  -  ";
            file7 << st[i].Middle_School;
            file7 << "  -  ";
            file7 << st[i].grade;
            file7 << '\n';
        }

        if(cod == 3){
            file8 << st[i].name;
            file8 << "  -  ";
            file8 << st[i].Middle_School;
            file8 << "  -  ";
            file8 << st[i].grade;
            file8 << '\n';
        }

        if(cod == 4){
            file9 << st[i].name;
            file9 << "  -  ";
            file9 << st[i].Middle_School;
            file9 << "  -  ";
            file9 << st[i].grade;
            file9 << '\n';
        }

        if(cod != -1){
            file3 << st[i].name;
            file3 << "  -  ";
            file3 << st[i].Middle_School;
            file3 << "  -  ";
            file3 << st[i].grade;
            file3 << '\n';
        }
        else{
            file4 << st[i].name;
            file4 << "  -  ";
            file4 << st[i].Middle_School;
            file4 << "  -  ";
            file4 << st[i].grade;
            file4 << '\n';
        }
    }


    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
}


void get_data_about_HS(High_School hs[])
{ // the function reads data about high school and makes certain conversions
    fstream file2("High_Schools.txt");

    char aux[50], data[50], str[11] = "1234567890";

    int i = 0;
    while(file2.getline(data,50)){
        aux[0] = data[0];
        aux[1] = '\0';
        hs[i].id = atoi(aux);
        int k = 2;
        int k2 = 0;

        while(!strchr(str,data[k+1])){
            aux[k2] = data[k];
            k2++;
            k++;
        }
        aux[k2] = '\0';
        strcpy(hs[i].name,aux);
        k++;
        k2 = 0;

        while(strchr(str,data[k])){
            aux[k2] = data[k];
            k++;
            k2++;
        }
        aux[k2] = '\0';
        hs[i].capacity = atoi(aux);
        hs[i].size = 0;
        i++;
    }

    file2.close();
}

void get_data_about_st(Student st[], int &nr_students)
{// the function reads data about students
    fstream file("Students.txt");


    int i = -1, j;
    char data[50];

    while(file.getline(data,50)){
        i++;
        if(i == 4)
            i = 0;

        if(i == 0)
            strcpy(st[nr_students].name, data);

        if(i == 1)
            strcpy(st[nr_students].Middle_School, data);

        if(i == 2)
            st[nr_students].grade = atof(data);

        if(i == 3){
            int j2 = 0;
            for(j = 0; j < strlen(data); j = j + 2){
                st[nr_students].options[j2] = data[j] - '0';
                j2++;
            }
            nr_students++;
        }
    }

    file.close();

}

void order_st(Student st[], int nr_students)
{// this function orders the students acording to the grade
    int i, j;
    for(i = 0; i < nr_students - 1; i++)
        for(j = i; j < nr_students; j++)
            if(st[i].grade < st[j].grade){

                swap_grade(st[i].grade, st[j].grade);

                swap_string(st[i].name, st[j].name);

                swap_string(st[i].Middle_School, st[j].Middle_School);

                swap_options(st, i, j);
            }
}


int main()
{
    High_School hs[6];
    Student *st = new Student[300];
    char data[50];
    int nr_students = 0;


    get_data_about_HS(hs);

    get_data_about_st(st, nr_students);

    order_st(st,nr_students);

    display_results_by_categories(st, hs, nr_students);



    return 0;
}
