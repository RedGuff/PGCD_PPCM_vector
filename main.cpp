#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> Matrix(5, 0);

int PGCD(int a, int b) { // https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide
    while(a != b) {
        if(a > b) {
            a = a - b;
            }
        else {
            b = b - a;
            }
        }
    return a;
    }

int PPCM(int a, int b) { // https://codes-sources.commentcamarche.net/source/9638-ppcm-de-deux-nombres-tout-compilateur
    int x = a;
    int y = b;
    while(x != y) {
        while(x > y)
            y = y + b;
        while(x < y)
            x = x + a;
        }
    return x;
    }



int PGCD( vector <int> &test) {
    int fin = test[test.size() - 1]; // -1 because test starts at 0.
    test.erase(test.begin() + test.size() - 1); // -1 because test starts at 0.
    if(test.size() == 2) {
        return PGCD(test[0], test[1]);
        }
    else {
        return PGCD(PGCD(test), fin);
        }
    }

int PPCM( vector <int> &test) {
    int fin = test[test.size() - 1]; // -1 because test starts at 0.
    test.erase(test.begin() + test.size() - 1); // -1 because test starts at 0.
    if(test.size() == 2) {
        return PPCM(test[0], test[1]);
        }
    else {
        return PPCM(PPCM(test), fin);
        }
    }


void display(vector<int> &Matrice1D) {
    cout << "Matrice : " << endl;
    for(int a = 0; a < Matrice1D.size(); a++) {
        cout << "Matrice1D[" << a << "] = " << Matrice1D[a] << endl;
        }
    }


int main() {
    Matrix[0] = 30;
    Matrix[1] = 100;
    Matrix[2] = 10;
    Matrix[3] = 15;
    Matrix[4] = 40;
    int a = 10;
    int b = 40;
    cout << "Ints : " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "PGCD(a, b) = " << "PGCD(" << a << "," << b << ") = " << PGCD(a, b) << endl;
    cout << "PPCM(a, b) = " << "PPCM(" << a << "," << b << ") = " << PPCM(a, b) << endl << endl;
    display(Matrix);
    cout  << endl;
vector <int>    MatrixTemp = Matrix; // PGCD and PPCM will destroy the matrix.
    cout << "PGCD(Matrix) = " << PGCD(MatrixTemp) << endl;
    MatrixTemp = Matrix;
 cout << "PPCM(Matrix) = " << PPCM(MatrixTemp) << endl;
    return 0;
    }
