#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct money {
    int n1;
    int n5;
    int n10;
    int n50;
    int nsum;

    int r1;
    int r2;
    int r5;
    int r10;
    int r50;
    int r100;
    int r500;
    int r1000;
    int r5000;
    int rsum;

    //100*r + n;
    int all;

    money operator+(money m); //do it easier p328
};

void init(money &m) {
    m.n1 = 0;
    m.n5 = 0;
    m.n10 = 0;
    m.n50 = 0;
    m.r1 = 0;
    m.r2 = 0;
    m.r5 = 0;
    m.r10 = 0;
    m.r50 = 0;
    m.r100 = 0;
    m.r500 = 0;
    m.r1000 = 0;
    m.r5000 = 0;

    //value init
    m.nsum = 0;
    m.rsum = 0;
    m.all = 0;
}

money money::operator+(money m) {
    n1 += m.n1;
    n5 += m.n5;
    n10 += m.n10;
    n50 += m.n50;
    r1 += m.r1;
    r2 += m.r2;
    r5 += m.r5;
    r10 += m.r10;
    r50 += m.r50;
    r100 += m.r100;
    r500 += m.r500;
    r1000 += m.r1000;
    r5000 += m.r5000;
    nsum += m.nsum;
    rsum += m.rsum;

    return *this;
}

//print n-value
void printValue(string txt, int val) {
    cout << txt << ": " << val / 100 << ',' << abs(val % 100);
}
//overloaded - for double-elem
void printValue(string txt, double val) {
    cout << txt << ": " << val;
}
//overloaded - print Money-type elem
void printValue(money &m, char ch = '\32') {
    //if sum for n[i]>=100
    int tmp = m.nsum / 100;
    m.nsum %= 100;
    m.rsum += tmp;
    cout << "Value: " << m.rsum << ',' << m.nsum << ch << endl;
}


int diff(money m1, money m2) {
    return abs(m1.all - m2.all);
}

//count value of sum
void count(money &m) {
    m.nsum = m.n1 + m.n5*5 + m.n10*10 + m.n50*50;
    m.rsum = m.r1 + m.r2*2 + m.r5*5 + m.r10*10 + m.r50*50
     + m.r100*100 + m.r500*500 + m.r1000*1000 + m.r5000*5000;

    m.all = m.nsum + m.rsum*100;
}


void mult(money &m, double d) {
	d = abs(d);
	m.n1 *= d;
    m.n5 *= d;
    m.n10 *= d;
    m.n50 *= d;
    m.r1 *= d;
    m.r2 *= d;
    m.r5 *= d;
    m.r10 *= d;
    m.r50 *= d;
    m.r100 *= d;
    m.r500 *= d;
    m.r1000 *= d;
    m.r5000 *= d;
    m.nsum *= d;
    m.rsum *= d;
	count(m);
    //m.all = floor(m.all * d);
}

//just double
double div(money m1, money m2) {
    return m1.all * 1.0 / m2.all ;
}



//compare x y; 1: x>y; 0: x==y; -1: x<y;
int compare(money *m1, money *m2) {
    if (m1->all > m2->all)
        return 1;
    else
        if (m1->all == m2->all)
            return 0;
        else
            return -1;
}

//get int with msg
int getInt(string txt) {
    cout << txt << ": " << endl;
    int value;
    while (true) {
        cin >> value;
        if(!cin) {
           cout << "Input error, try again." << endl;
           cin.clear();
           while (cin.get() != '\n');
        } else {
            break;
        }
    }
    return abs(value);
}

double getDouble(string txt) {
    cout << txt << ": " << endl;
    double value;
    while (true) {
        cin >> value;
        if(!cin) {
           cout << "Input error, try again." << endl;
           cin.clear();
           while (cin.get() != '\n');
        } else {
            break;
        }
    }
    return value;
}

//input 1 elem
money getMoney(){
    money m;
    cout << "Enter the number of coins: " << endl;
    m.n1 = getInt("0.01 rub");
    m.n5 = getInt("0.05 rub");
    m.n10 = getInt("0.1 rub");
    m.n50 = getInt("0.5 rub");

    m.r1 = getInt("1 rub");
    m.r2 = getInt("2 rub");
    m.r5 = getInt("5 rub");
    m.r10 = getInt("10 rub");
    m.r50 = getInt("50 rub");
    m.r100 = getInt("100 rub");
    m.r500 = getInt("500 rub");
    m.r1000 = getInt("1000 rub");
    m.r5000 = getInt("5000 rub");

    count(m);
    printValue(m);
    cout << endl;
    return m;
}

void printVector(vector <money> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << "Sum[" << i+1 << "] == ";
        printValue(a[i], ' ');
        cout << endl;
    }
}

int menu(int n) {
    int res;
    do {
        if (n > 0) {
            cout << endl;
            cout << "Choose the action: " << endl;
            cout << "1. Mult i'th by number" << endl;
            cout << "2. Edit i'th" << endl;
            if (n>1) {
                cout << "3. Sum of i'th & j'th elements" << endl;
                cout << "4. Difference of i'th & j'th elements" << endl;
                cout << "5. Division i'th into j'th" << endl;
                cout << "6. Compare i'th & j'th" << endl;
                cout << "7. Print all" << endl;
            }
        }
        cout << "0. Exit";
        cout << endl;
        cin >> res;
    } while ((n == 1) ? (res < 0 || res > 2) : (res < 0 || res > 7)); //only available variants
    return res;
}


int main() {
    int n = getInt("enter num of elements to input");
    vector <money> a(n);

    //input
    for (int i = 0; i < n; i++) {
        cout << i+1 << " elem: ";
        a[i] = getMoney();
        //init(a[i]);
    }
    cout << endl;

    //print
    printVector(a);

    int i, j = 0, k = 0;
    do {
        k = menu(n);
        switch (k) {
            case 1: {
                double g;
                do {
                    cout << "Mult i'th by number" << endl;
                    i = getInt("Input i");
                    //cout << "Input g: " << endl;
                    //cin >> g;
                    g = getDouble("Input g");
                } while (i <= 0 || i > n);
				money tmp = a[i-1];
				mult(tmp, g);
				printValue(tmp);
                //printValue("Mult", mult(a[i-1], g));
                break;
            }
            case 2: {
                do {
                    cout << "Edit i'th" << endl;
                    i = getInt("Input i");
                } while (i <= 0 || i > n);
                a[i-1] = getMoney();
                break;
            }
            case 3: {
                do {
                    cout << "Sum of i'th & j'th elements" << endl;
                    i = getInt("Input i");
                    j = getInt("Input j");
                } while (i <= 0 || i > n || j <= 0 || j > n);
                printValue(a[i-1] + a[j-1]);
                break;
            }
            case 4: {
                do {
                    cout << "Diff of i'th & j'th elements" << endl;
                    i = getInt("Input i");
                    j = getInt("Input j");
                } while (i <= 0 || i > n || j <= 0 || j > n);
                printValue("Diff", diff(a[i-1], a[j-1]));
                break;
            }
            case 5: {
				 bool zero;
                 do {			
					zero = false;
                    cout << "Division i'th into j'th" << endl;
                    i = getInt("Input i");
                    j = getInt("Input j");
					if (j > 1)
						if (a[j-1].all == 0) {
							cout << "Division by zero, retry.";
							zero = true;
						}
                } while (i <= 0 || i > n || j <= 0 || j > n);
                if (!zero)
					printValue("Div", div(a[i-1], a[j-1]));
				break;
            }
            case 6: {
                do {
                    cout << "Compare i'th & j'th" << endl;
                    i = getInt("Input i");
                    j = getInt("Input j");
                } while (i <= 0 || i > n || j <= 0 || j > n);
                cout << compare(&a[i-1], &a[j-1]) << endl;;
                break;
            }
            case 7: {
                printVector(a);
                break;
            }
            case 0:
                return 0;
        }

    } while (k != 0);

    return 0;
}
