#include<iostream>
using namespace std;

double arithmetic(double anum1, char aoprtr, double anum2){
    double result;
    if(aoprtr== '+'){
        result= anum1 + anum2;
        return result;
    }
    
    if(aoprtr== '-'){
        result= anum1 - anum2;
        return result;
    }
    
    if(aoprtr== '/'){
        result= anum1 / anum2;
        return result;
    }
    
    if(aoprtr== '*'){
        result= anum1 * anum2;
        return result;
    }
    else{
        cout << "Syntax error";
    }
} ;

int power(double baseNum, int powerNum){
    int result=1;
    for(int i = 1; i <= powerNum; i++){
        result = result * baseNum;
    }
    return result;
}

double abs(double value) {
    return (value < 0) ? -value : value;
}

double sqrtNewtonRaphson(double x) {
    if (x < 0) {
        cout<< "Error: Negative input to sqrt." <<endl;
        return -1;
    }
    if (x == 0) return 0;

     double guess = x;
    double tolerance = 1e-10;
    double difference;

    do {
        double new_guess = 0.5 * (guess + x / guess);
        difference = abs(new_guess - guess);
        guess = new_guess;
    } while (difference >= tolerance);

    return guess;
}

long long factorial(int i){
    long long result=1;
    for(int n=0; n<i; i--){
        result= result*i;
    }
    return result;

}

double sinTaylor(double x) {
    double sum = 0.0;
    double term;
    int n = 0;

    do {
        term = (n % 2 == 0 ? 1 : -1) * (power(x, (2 * n) + 1) / factorial((2 * n) + 1));
        sum = sum+term;
        n++;
    } while (abs(term) > 1e-10);

    return sum;
}

double cosTaylor(double x) {
    double sum = 0.0;
    double term;
    int n = 0;

        do {
        term = (n % 2 == 0 ? 1 : -1) * (power(x, 2 * n) / factorial(2 * n));
        sum += term;
        n++;
    } while (abs(term) > 1e-10);

    return sum;
}

double tanFunction(double x) {
    double sine = sinTaylor(x);
    double cosine = cosTaylor(x);
    if (cosine == 0) {
        cout << "Error: Tangent undefined for this angle (cosine is zero)." << endl;
        return 0;
    }
    return sine / cosine;
}

double expTaylor(double x) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    double tolerance = 1e-10;

    while (true) {
        term *= x / n;
        if (term < tolerance) break;
        sum += term;
        ++n;
    }
    return sum;
}

double lnNewtonRaphson(double x) {
    if (x <= 0) {
        cout << "Error: Non-positive input to ln." << endl;
        return -1;
    }
    if (x == 1) return 0;

    double y = x;
    double tolerance = 1e-10;

    while (true) {
        double exp_y = expTaylor(y);
        double f = exp_y - x;
        double f_prime = exp_y;
        double y_new = y - f / f_prime;

        if (abs(y_new - y) < tolerance) break;
        y = y_new;
    }

    return y;
}

double QEsolve(double a, double b, double c){
    double D;
    double Z1, Z2;
    D = sqrtNewtonRaphson(b * b - 4.0 * a * c);
    Z1 = (-b + D) / (2 * a);
    Z2 = (-b - D) / (2 * a);
    cout << "The roots are " << Z1 << " and " << Z2 << endl;
}

int main() 
{
    int choice;
    cout << "Hello, this is a calculator!\n Please choose the type of calculation you want to perform:"<<endl;
    cout << "1. Arithmetic\n 2. Exponential\n 3. Square root\n 4. Absolute value\n 5. Factorial"<<endl;
    cout << "6. Sin(Angle)\n 7. Cos(Angle)\n 8. Tan(Angle)\n 9. Logarithmic\n 10. Quadratic Equation solver "<<endl;
    cin>> choice;
    if(choice == 1){
        cout << "Please enter the problem as (First number)(Operator)(Second number)";
        double num1, num2;
        char oprtr;
        cin >> num1 >> oprtr >> num2;
        cout << arithmetic(num1, oprtr, num2);
        
    }
    if(choice == 2){
        cout << "Please enter the exponential problem as (Base Number) (Exponent)";
        int powerNum;
        double baseNum;
        cin >> baseNum >> powerNum;
        cout<< power(baseNum, powerNum);
    }
    if(choice == 3){
        cout << "Please enter the number which you want to get square root of: ";
        double numTObeRooted;
        cin >> numTObeRooted;
    cout << sqrtNewtonRaphson(numTObeRooted);
    }
    if(choice == 4){
        cout<< "Enter the number of which you want to get absolute value of: ";
        double num;
        cin >> num;
        cout << abs(num);
    }
    if(choice == 5){
        cout<< "Please enter the natural number you want to calculate factorial of: ";
        int num;
        cin >> num;
        cout << factorial(num);
    }
    if(choice == 6){
        cout << "Please enter the angle in radians of which you have to calculate sin()"<<endl;
        double angle;
        cin >> angle;
        cout<< sinTaylor(angle);
    }
    if(choice == 7){
        cout << "Please enter the angle in radians of which you have to calculate cos()"<<endl;
        double angle;
        cin >> angle;
        cout<< cosTaylor(angle);
    }
    if(choice == 8){
        cout << "Please enter the angle in radians of which you have to calculate tan()"<<endl;
        double angle;
        cin >> angle;
        cout<< tanFunction(angle);
    }
    if(choice == 9){
        cout<< "Please enter the number for which you want to calculate the logarithm ln(): ";
        double num;
        cin >> num;
        cout <<lnNewtonRaphson(num);
    }
    if(choice == 10){
    cout << "Please enter the values of a, b, c: ( ax^2 + bx + c = 0)";
    int a, b, c;
    cin >> a >> b >> c;
    QEsolve(a, b, c);
    }
    else{
        cout<<"Please enter a number 1-9!";
    }
    return 0;
}
