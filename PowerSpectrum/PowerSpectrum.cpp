/*
This program calculates the power spectrum using forier transform. 
Reference :: http://www.fftw.org/fftw2_doc/fftw_2.html
*/

#include<fftw.h>
#include<iostream>
#include <fstream>

#define N 500

int v, i=0;
double a, b, power;

using namespace std;

void OneD(){
    fftw_complex in[N], out[N];
    fftw_plan p;

    ifstream fin1("values_1D.txt");
    ofstream fout1("PowerSpectrumOutput1D.txt");
    
    while(fin1>>v){
        in[i][0] = v; in[i][1] = 0; //getting the function values
        i++;
    }

    p = fftw_create_plan(N, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_one(p, in, out);

    for(i=0; i<N; i++){
         a = out[i][0];  b = out[i][1];
         power = a*a + b*b;
         fout1 << power <<endl;
    }

    fin1.close();
    fout1.close();
    fftw_destroy_plan(p);  
}

void TwoD(){

    fftw_complex in[N][N];
    fftwnd_plan p;
    p = fftw2d_create_plan(N, N, FFTW_FORWARD, FFTW_MEASURE);

    ifstream fin2("values_2D.txt");
    ofsteeam fout2("PowerSpectrumOutput2D.txt");
    for(i=0; i<N; i++)
        for(int j=0; j<N; j++)
            {
                fin2>>v;
                in[i][j][0] = v; in[i][j][1] = 0;
            }

    fftwnd_one(p, in, out);

    for(i=0; i<N; i++)
        for(int j=0; j<N; j++)
            {
                a = out[i][j][0];  b = out[i][j][1];
                power = a*a + b*b;
                fout3 << power <<endl;
            }
    fout2.close();
    fin2.close();
    fftwnd_destroy_plan(p); 
}

void ThreeD(){

    fftw_complex in[N][N][N];
    fftwnd_plan p;
    p = fftw3d_create_plan(N, N, N, FFTW_FORWARD, FFTW_MEASURE | FFTW_IN_PLACE);

    ifstream fin3("values_3D.txt");
    ofsteeam fout3("PowerSpectrumOutput3D.txt");
    for(i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++){
                fin3>>v;
                in[i][j][k][0] = v; in[i][j][k][1] = 0;
            }

    fftwnd_one(p, in, out);

    for(i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++){
                a = out[i][j][k][0];  b = out[i][j][k][1];
                power = a*a + b*b;
                fout3 << power <<endl;
            }
    fout3.close();
    fin3.close();
    fftwnd_destroy_plan(p); 
}

int main() {

    cout<<"[+] Calculating power spectrum."<<endl;

    OneD(); 
    TwoD(); 
    ThreeD();

    return 0;
}