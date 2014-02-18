#include "CPolynom.h"

using namespace std;

int getPolynomDegree(const string txt) {
    int x;
    do {
        x = getElem(txt);
        x = static_cast <int> (x);
    } while (x < 0 || x >= MAX_DEGREE);
    return x;
}

int menu() {
    int res;
    do {
        cout << endl;
        cout << "Choose the action: " << endl;
        cout << "1. Input A" << endl;
        cout << "2. Input B" << endl;
        cout << "3. Get A's degree" << endl;
        cout << "4. Get B's degree" << endl;
        cout << "5. Print A" << endl;
        cout << "6. Print B" << endl;
        cout << "7. Calc A at x0" << endl;
        cout << "8. Calc B at x0" << endl;
        cout << "9. Compare A & B" << endl;
        cout << "10. A + B" << endl;
        cout << "11. A - B" << endl;
        cout << "12. A * B" << endl;
        cout << "13. Integrate A" << endl;
        cout << "14. Integrate B" << endl;
        cout << "15. Differentiate A" << endl;
        cout << "16. Differentiate B" << endl;

        cout << "0. Exit";
        cout << endl;
        cin >> res;
    } while (res < 0 || res > 16); //only available variants
    return res;
}

int main() {
    int n, m;
    n = getPolynomDegree("First polynom's degree");
    m = getPolynomDegree("Second polynom's degree");
    Polynom a(n), b(m);
    a.input();
    b.input();
    int action = 0;
    do {
        action = menu();
        switch (action) {
            case 1: {
                a.input();
                break;
            }
            case 2: {
                b.input();
                break;
            }
            case 3: {
                cout << a.getDegree() << endl;
                break;
            }
            case 4: {
                cout << b.getDegree() << endl;
                break;
            }
            case 5: {
                a.print();
                break;
            }
            case 6: {
                b.print();
                break;
            }
            case 7: {
                int p = getElem("Enter x0");
                cout << a.calcAtPoint(p) << endl;
                break;
            }
            case 8: {
                int p = getElem("Enter x0");
                cout << b.calcAtPoint(p) << endl;
                break;
            }
            case 9: {
                cout << a.compare(b) << endl;
                break;
            }
            case 10: {
                (a+b).print();
                break;
            }
            case 11: {
                (a-b).print();
                break;
            }
            case 12: {
                (a*b).print();
                break;
            }
            case 13: {
                (a.integrate()).print();
                break;
            }
            case 14: {
                (b.integrate()).print();
                break;
            }
            case 15: {
                (a.differentiate()).print();
                break;
            }
            case 16: {
                (b.differentiate()).print();
                break;
            }
        }

    } while (action != 0);



    return 0;
}
