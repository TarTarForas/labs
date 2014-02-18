//for 0.3 seconds faster for 27k elements
//log(n) search
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include <fstream>



using namespace std;

const double GAS_PRICE = 39.9;
const double MOTOR_OIL_PRICE = 100.500;
const int MAX_PARAM = 1000;
const int MIN_OCTAN = 76;
const int MAX_OCTAN = 111;
const int MAX_OIL = 15;

#define cin fin
ifstream fin ("input.txt");



//search by surname, octanN, hp, model
struct car {
    string surname;
    string model;
    string code;
    int octanN;
    int hp; //horse power
    int gasV;
    int gasInTank; // <= gasV
    int oilV;
};

typedef vector <car> carBase;

///strict comparation
//str cmp: return true if a < b (strict!)
bool compStr(const string &a, const string &b) {
    if (a.compare(b) < 0)
        return true;
    else
        return false;
}

bool compBySurname(const car &a, const car &b) {
    return compStr(a.surname, b.surname);
}

bool compByModel(const car &a, const car &b) {
    return compStr(a.model, b.model);
}

bool compByHp(const car &a, const car &b) {
    return (a.hp < b.hp);
}

bool compByOctanN(const car &a, const car &b) {
    return (a.octanN < b.octanN);
}
/// end of strict comparation

//array, key, comparator (a<b == true)
int binarySearch(carBase a, car key, bool (*cmp)(const car &a, const car &b)) {
    int first = 0;
    int last = a.size();
    int mid = first + (last - first) / 2;

    //if zero == key
    if (a.size() == 1) {
        if (!cmp(a[0], key) && !cmp(key, a[0]))
            return 0;
        else
            return -1;
    }

    if (a.size() == 0) {
        return -1;
    } else
        if (cmp(key, a[0])) // a[0] > x
            return -1; //
        else
            if (cmp(a[last-1], key))
                return -1;

    while (first < last) {
        //key <= a[mid]
        if (cmp(key, a[mid]) || (!cmp(a[mid], key) && !cmp(key, a[mid])))
            last = mid;
        else
            first = mid + 1;
        mid = first + (last - first) / 2;
    }
    // if key == a[last]
    if (last < a.size() && !cmp(key, a[last]) && !cmp(a[last], key))
        return last;
    else
        return -1;
}


int getInt(const string txt = "") {
    if (txt != "")
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

int getIntInRange(const int minimal, const int maximal, const string txt = "") {
    int x;
    cout << " range: [" << minimal << ", " << maximal << "]";//<< endl;
    do {
        x = getInt(txt);
        x = static_cast <int> (x);
    } while (x < minimal || x > maximal);
    return x;
}

void showMessage(string txt) {
    cout << txt << ": ";
}

void inputCar(car &first) {
    showMessage("Enter owner's surname");
    cin >> first.surname;
    showMessage("Enter car's model");
    cin >> first.model;
    showMessage("Enter car's code");
    cin >> first.code;
    showMessage("Enter car's fuel octan number");
    first.octanN = getIntInRange(MIN_OCTAN, MAX_OCTAN);
    showMessage("Enter car's horse power");
    first.hp = getIntInRange(0, MAX_PARAM);
    showMessage("Enter car's tank size");
    first.gasV = getIntInRange(0, MAX_PARAM);
    showMessage("Enter current amount of gas");
    first.gasInTank = getIntInRange(0, first.gasV);
    showMessage("Enter max amount of motor oil");
    first.oilV = getIntInRange(0, MAX_OIL);
}

void printCar(const car &first) {
    cout << endl;
    cout << "Owner: " << first.surname << endl;
    cout << "Model: " << first.model << " " << first.code << endl;
    cout << "Horse Power & oil: " << first.hp << " hp; " << first.oilV << " lit." << endl;
    cout << "Gas: " << first.octanN << " oct; " << first.gasInTank << " of " << first.gasV << " lit.";
    cout << endl;
}

//void fillBase(carBase &base) {
void fillBase(carBase &surnameOrder, carBase &modelOrder, carBase &hpOrder, carBase &octanOrder) {
    showMessage("How much elems do you want to input?");
    int n = abs(getInt());
    car tmp;
    for (int i = 0; i < n; i++) {
        inputCar(tmp);
/// Let the madness start
        //base.push_back(tmp);
        surnameOrder.push_back(tmp);
        modelOrder.push_back(tmp);
        hpOrder.push_back(tmp);
        octanOrder.push_back(tmp);
    }
    //lolwut
    sort(surnameOrder.begin(), surnameOrder.end(), compBySurname);
    sort(modelOrder.begin(), modelOrder.end(), compByModel);
    sort(hpOrder.begin(), hpOrder.end(), compByHp);
    sort(octanOrder.begin(), octanOrder.end(), compByOctanN);
}

//we may not use that
//void addToBase(carBase &base) {
void addToBase(carBase &surnameOrder, carBase &modelOrder, carBase &hpOrder, carBase &octanOrder) {
    car first;
    inputCar(first);
    //base.push_back(first);

    //add
    surnameOrder.push_back(first);
    modelOrder.push_back(first);
    hpOrder.push_back(first);
    octanOrder.push_back(first);
    //sort
    sort(surnameOrder.begin(), surnameOrder.end(), compBySurname);
    sort(modelOrder.begin(), modelOrder.end(), compByModel);
    sort(hpOrder.begin(), hpOrder.end(), compByHp);
    sort(octanOrder.begin(), octanOrder.end(), compByOctanN);
}

void printBase(const carBase &base) {
    if (base.empty()) {
        cout << "Base is empty!" << endl;
    } else {
        carBase :: const_iterator it = base.begin();
        while (it != base.end()) {
            printCar(*it++);
        }
    }
}



//search procedures
//collects all found items in result
void searchByOctan(const int octan, const carBase &a, carBase &result) {
/*    carBase :: const_iterator it = base.begin();
    while (it != base.end()) {
        if (it->octanN == octan)
            result.push_back(*it);
        it++;
    }
*/
    car temp;
    temp.octanN = octan;
    int ind = binarySearch(a, temp, compByOctanN); //first of
    if (ind != -1) {
        result.push_back(a[ind]);
        ind++;
        //from first include to latest we add to result
        while (ind < a.size()) {
            if (!compByOctanN(a[ind], temp) && !compByOctanN(temp, a[ind])) {
                result.push_back(a[ind]);
                ind++;
            } else
                break;
        }
    }
}

void searchByOwner(const string surname, const carBase &a, carBase &result) {
    /*carBase :: const_iterator it = base.begin();
    while (it != base.end()) {
        if (it->surname == surname)
            result.push_back(*it);
        it++;
    }*/
    car temp;
    temp.surname = surname;
    int ind = binarySearch(a, temp, compBySurname); //first of
    if (ind != -1) {
        result.push_back(a[ind]);
        ind++;
        //from first include to latest we add to result
        while (ind < a.size()) {
            if (!compBySurname(a[ind], temp) && !compBySurname(temp, a[ind])) {
                result.push_back(a[ind]);
                ind++;
            } else
                break;
        }
    }
}

void searchByModel(const string model, const carBase &a, carBase &result) {
    car temp;
    temp.model = model;
    int ind = binarySearch(a, temp, compByModel); //first of
    if (ind != -1) {
        result.push_back(a[ind]);
        ind++;
        //from first include to latest we add to result
        while (ind < a.size()) {
            if (!compByModel(a[ind], temp) && !compByModel(temp, a[ind])) {
                result.push_back(a[ind]);
                ind++;
            } else
                break;
        }
    }
}


void searchByHp(const int hp, const carBase &a, carBase &result) {
    car temp;
    temp.hp = hp;
    int ind = binarySearch(a, temp, compByHp); //first of
    if (ind != -1) {
        result.push_back(a[ind]);
        ind++;
        //from first include to latest we add to result
        while (ind < a.size()) {
            if (!compByHp(a[ind], temp) && !compByHp(temp, a[ind])) {
                result.push_back(a[ind]);
                ind++;
            } else
                break;
        }
    }
}



int menu(bool empty) {
    int res;
    do {
        cout << endl;
        cout << "Choose the action: " << endl;
        cout << "1. Fill base" << endl;
        cout << "2. Add car to base" << endl;
        if (!empty) {
            cout << "3. Print base" << endl;
            cout << "4. Search by owner" << endl;
            cout << "5. Search by HP" << endl;
            cout << "6. Search by model" << endl;
            cout << "7. Search by octan" << endl;
        }
        cout << "0. Exit";
        cout << endl;
        cin >> res;
    } while ((empty) ? (res < 0 || res > 2) : (res < 0 || res > 7)); //only available variants
    return res;
}

int main() {
    carBase base;
    carBase surnameOrder, modelOrder, hpOrder, octanOrder, result;
    int action = 0;
    do {
        action = menu(surnameOrder.empty());
        if (action >= 4)
            result.clear();
        switch (action) {
            case 1: {
                fillBase(surnameOrder, modelOrder, hpOrder, octanOrder);
                break;
            }
            case 2: {
                addToBase(surnameOrder, modelOrder, hpOrder, octanOrder);
                break;
            }
            case 3: {
                //printBase(base);
                //any of this
                printBase(surnameOrder);
                break;
            }
            case 4: {
                showMessage("Enter owner's surname to search");
                string s;
                cin >> s;
                searchByOwner(s, surnameOrder, result);
                //if (!result.empty())
                    printBase(result);
                break;
            }
            case 5: {
                showMessage("Enter Horse Power to search");
                int tmp = getIntInRange(0, MAX_PARAM);
                searchByHp(tmp, hpOrder, result);
                //if (!result.empty())
                    printBase(result);
                break;
            }
            case 6: {
                showMessage("Enter car's model to search");
                string s;
                cin >> s;
                searchByModel(s, modelOrder, result);
                //if (!result.empty())
                    printBase(result);
                break;
            }
            case 7: {
                showMessage("Enter gas octan to search");
                int tmp = getIntInRange(MIN_OCTAN, MAX_OCTAN);
                searchByOctan(tmp, octanOrder, result);
                //if (!result.empty())
                    printBase(result);
                break;
            }
        }
    } while (action != 0);

    return 0;
}
