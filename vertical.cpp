#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
//adakwdko
double x, f, t, T, v0, v, c, A, aX, aY, p, m, l, h, g = 9.80665, L = 1000;
double pi = (4 * atan(1));

double popravka() {
    double alpha1 = 0, alpha2 = 45 * pi / 180, mid, hCur=0;
    double vX, vY, h = 0, hTarget = -5;

    while (abs(hTarget - hCur) > 0.01) {
        mid = (alpha1 + alpha2) / 2;
        vX = v0 * cos(mid);
        vY = v0 * sin(mid);
        hCur = h;
        T = 0;
        l = 0;

        cout << "vY = " << vY << endl;

        while (l < L) {
            T += t;

            f = c * p * A * vX * vX / 2;
            aX = f / m;
            vX -= aX * t;

            aY = g;
            vY -= g * t;

            hCur += vY * t;

            l += vX * t;

            //cout << "hCur = " << hCur << endl;
            //cout << "vY = " << vY << endl;
            //getch();
        }
        cout << "hCur = " << hCur << endl;

        if (hCur > hTarget) alpha2 = mid;
        else alpha1 = mid;
    }
    return mid;
}

int main() {


    //тестові дані для 308 калібру

    l = 0;
    A = 4.8e-5;
    p = 1.2;
    c = 0.253;
    v0 = 807.72;
    m = 0.010886;
    t = 0.001;
    T = 0.0;


    double alpha = popravka();
    cout << "popravka = " << alpha * 180/pi;
}