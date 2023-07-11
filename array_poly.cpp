const int MaxSize = 100;
 typedef struct
 {
 float coefficient;
 int exponent;
 } polynomial_term;
 class Polynomial
 {
 private:
 polynomial_term Poly[MaxSize];
 int Total_Terms;
 public:
 Polynomial() { Total_Terms = 0;}
 void Read_Poly();
 void Display_Poly();
 double Evaluate(double value);
 Polynomial Add_Poly(Polynomial B);
 Polynomial Mult_Poly(Polynomial B);
 };

 double Polynomial :: Evaluate(double Value)
 {
 int i = 0;
 double result = 0;
 while (i <= Total_Terms)
 {
 result+=Poly[i].coefficient*pow(val,Poly[i].exponent);
 // pow() is the exponential function to compute xy
 i++;
 }
 return result;
 }
 void Polynomial :: Read_Poly()
 {
 int i;
 cout << "Let us read the polynomial now" << endl;
 cout << "Enter total number of terms in polynomial";
 cin >> Total_Terms;
 for(i = 0; i <= Total_Terms; i++)
 {
 cout << "Enter Exponent of" << i+1 << "Term";

 cin << Poly[i].Exp;
 cout<< "Enter Coeffi cient of" << i+1 << "Term";
 cin << Poly[i].Coef;
 }
 }
 void Polynomial :: Display_Poly()
 {
 int i;
 for(i = 0; i <= Total_Terms; i++)
 cout << Poly[i].Coef << "x^" << Poly[i].Exp << "+";
 cout << "\b" << endl;
 }
 void main()
 {
 Polynomial A;
 double answer;
 A.Read_Poly();
 answer = A.Evaluate(69.45);
// Let 69.45 be the value of x
 }

