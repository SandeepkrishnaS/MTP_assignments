/*
* This is a cpp function generator for generating a signal in 1D, 2D and 3D
* For each case, the angular frequencies are defined as W, WW and WWW respectively for simplicity
* The output of each case is saved in separate files with appropriate and easily identifiable names
*/

#include<iostream>
#include <fstream> 
#include<cmath>

#define W 2*3.1415*2 // these are the angular frequencies in format 2*Pi*frequency
#define WW 2*3.1415*3
#define WWW 2*3.1415*5

#define STEPS 500 //space between each step is 1

using namespace std;

double v; //common variable used throught the finctions

void fun_gen_1D() {

    ofstream file_1("values_1D.txt");

    for(int i=0; i<STEPS; i++){
        v = sin(W*i/STEPS);
        file_1 << v << endl;
    }
    cout<<"[=] Output saved in values_1D.txt"<<endl;
    file_1.close(); //good practise to close the file object to free up memory
}

void fun_gen_2D() {

    ofstream file_2("values_2D.txt");

    for(int i=0; i<STEPS; i++){
        for(int j=0; i<STEPS; i++){
            v = sin(W*i/STEPS) + sin(WW*j/STEPS);
            file_2 << v << endl;
        }
    }
    cout<<"[=] Output saved in values_2D.txt"<<endl;
    file_2.close();
}

void fun_gen_3D() {

    ofstream file_3("values_3D.txt");

    for(int i=0; i<STEPS; i++){
        for(int j=0; i<STEPS; i++){
            for(int k=0; i<STEPS; i++){
                v = sin(W*i/STEPS) + sin(WW*j/STEPS) + sin(WWW*k/STEPS);
                file_3 << v << endl;
            }
        }
    }
    cout<<"[=] Output saved in values_3D.txt"<<endl;
    file_3.close();
}

int main(){

    cout<<"[+] Generating function values in 1D."<<endl;
    fun_gen_1D();

    cout<<"[+] Generating function values in 2D."<<endl;
    fun_gen_2D();

    cout<<"[+] Generating function values in 3D."<<endl;
    fun_gen_3D();

    return 0;
}