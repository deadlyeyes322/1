#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void my_name() {
    cout << "Hi, my name is Pisarev Egor" << endl;
}

void ariphmetic() {
    double a, b;
    cout << "Input a, b: "; 
    cin >> a >> b;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << " b - a = " << b - a << endl;
    cout << "a * b = " << a * b << endl;
    if (b != 0) {
        cout << "a / b = " << a / b << endl;
        return;
    }
    cout << "I cant divide because b == 0" << endl;

}

enum root_type { noroots = 0, oneroot, tworoots, infinity_roots };

root_type solve_equal(double b, double c, double& x) {
    if (b == 0 and c == 0) {
        return infinity_roots;
    }
    else if (b == 0) {
        return noroots;
    }
    else {
        x = -c / b;
        return oneroot;
    }
}

root_type solve_square_equal(double a, double b, double c, double& x1, double& x2) {
    if (a == 0 and b == 0 and c == 0) return infinity_roots;
    else if (a == 0 and b == 0) return noroots;
    else if (a == 0) {
        x1 = -c / b;
        return oneroot;
    }
    else if (b * b - 4 * a * c < 0) return noroots;
    else if (b * b - 4 * a * c == 0) { x1 = -b / (2 * a); return oneroot; }
    else {
        x1 = (-b + pow(b * b - 4 * a * c, 0.5)) / (2 * a);
        x2 = c / x1;
        return tworoots;
    }
}

void solve_equal() {
    double b, c;
    cout << "Type b, c: ";
    cin >> b >> c;
    double x;

    auto rt_equal = solve_equal(b, c, x);

    switch (rt_equal)
    {
    case noroots:
        cout << "no roots" << endl; break;
    case oneroot:
        cout << "one root x = " << x << endl; break;
    case infinity_roots:
        cout << "infinity roots" << endl; break;
    }

    double a;
    cout << "Input a, b, c: ";
    cin >> a >> b >> c;
    double x1, x2;

    auto rt_square_equal = solve_square_equal(a, b, c, x1, x2);

    switch (rt_square_equal)
    {
    case noroots:
        cout << "no roots" << endl; break;
    case oneroot:
        cout << "one root, x = " << x1 << endl; break;
    case tworoots:
        cout << "two roots x1 = " << x1 << " x2 = " << x1
            << endl; break;
    case infinity_roots:
        cout << "infinity roots" << endl;
    };
}

void check_room_light() {
    bool day, curtain, lamp;
    cout << "Is it daytime outside? 1 - yes, 0 - no: ";
    cin >> day;
    cout << "Are the curtains drawn? 1 - yes, 0 - no: ";
    cin >> curtain;
    if (day && curtain) {
        cout << "The room is light" << endl; return;
    }
    
    cout << "Is lamp On? 1 - yes, 0 - no: ";
    cin >> lamp;
    if (lamp) {
        cout << "The room is light" << endl; return;
    }
    cout << "The room isn't light" << endl;
}

int main()
{
    my_name();
    ariphmetic();
    solve_equal();
    check_room_light();
}
