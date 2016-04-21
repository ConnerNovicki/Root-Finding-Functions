#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// IMPORTANT: Hard code function into this function
double f(double x) {
    return pow(x, 3) - 2 * x + 3;
}

//IMPORTANT: Hard code function into this function
double fPrime(double x) {
    return 3 * pow(x, 2) - 2;
}


void bisectionMethod() {
    
    double a, b, c, currVal, tolerance;
    int n = 0;
    
    cout << "Enter your lower bound, a: ";
    cin >> a;
    cout << "Enter your upper bound, b: ";
    cin >> b;
    
    cout << "Enter tolerance (e.g. .00001): " ;
    cin >> tolerance;

    cout << left << setw(6) << "n" << setw(12) << "a" << setw(12) << "b" << setw(12) << "x" << setw(12) << "f(x)" << endl;
    char separator = '-';
    cout << setw(48) << setfill(separator) << "" << endl;
    separator = ' ';
    
    do {
        c = 0.5 * (a + b);
        currVal = f(c);
        
        if (currVal < 0) { a = c;}
        else {b = c;}
        
        cout << left << setfill(separator) << setw(6) << n << setw(12) << setprecision(5) << a
        << setw(12) << b << setw(12) << c << currVal << endl;
        n++;
        
        if (n > 50) {
            cout << "Iteration terminated. No root found" << endl;
            break;
        }
    
    } while (abs(currVal) > tolerance);
    
}

void newtonsMethod() {
    
    double x0, tolerance, x1;
    int n = 0;
    
    cout << "Enter value (x0): ";
    cin >> x0;
    
    cout << "Enter tolerance (e.g. .000001): ";
    cin >> tolerance;
    
    cout << left << setw(6) << "n" << setw(12) << "x0" << setw(12) << "x1" << setw(12) << "f(x0)" << endl;
    char separator = '-';
    cout << setw(48) << setfill(separator) << "" << endl;
    separator = ' ';

    do {
        
        x1 = x0 - (f(x0) / fPrime(x0));
        
        cout << left << setfill(separator) << setw(6) << n << setw(12) << setprecision(6) << x0 << setw(12)
        << x1 << setw(12) << f(x0) << setw(12) << endl;
        
        x0 = x1;
        n++;
        
    } while (abs(f(x1)) > tolerance);
    
    
}

void secantMethod() {
    
    double x0, x1, x2, tolerance;
    int n = 2;
    cout << "Enter starting point, x0: ";
    cin >> x0;
    
    cout << "Enter starting point, x1: ";
    cin >> x1;
    
    cout << "Enter a tolerance: ";
    cin >> tolerance;
    
    cout << endl << left << setw(6) << "n"  << setw(15) << "x" << setw(15) << "f(x)" << "|x(i) - x(i-1)|" << endl;
    char separator = '-';
    cout << setw(50) << setfill(separator) << "" << endl;
    separator = ' ';
    
    do {
        
        x2 = x1 - (f(x1) * ((x1 - x0) / (f(x1) - f(x0))));
        
        cout << left << setfill(separator) << setw(6) << n << setw(15) << setprecision(6)
        << x2 << setw(16) << f(x2) << setw(16) << abs(x2 - x1) << endl;
        
        x0 = x1;
        x1 = x2;
        n++;
    
    } while (abs(f(x2)) > tolerance);
    cout << endl;
}

int main() {
    int choice;
    cout << "Which method would you like to use?\n" << "1) Bisection Method\n" << "2) Newtons Method\n" <<
    "3) Secant Method" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            bisectionMethod();
            break;
        
        case 2:
            newtonsMethod();
            break;
            
        case 3:
            secantMethod();
            break;
            
        default:
            cout << "Invalid input." << endl;
            break;
    }
    return 0;
}
