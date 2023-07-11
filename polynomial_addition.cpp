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
 Result+=Poly[i].Coef*pow(val,Poly[i].Exp);
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

 Polynomial Polynomial :: Add_Poly(Polynomial B)
 {
 int i = j = k = 0;
 Polynomial C;
 while (i < A.Total_Terms && j < B.Total_Terms)
 {
 if(A.Poly[i].Exp == B.Poly[j].Exp)
 {
 C.Poly[k].Coef = A.Poly[i].Coef + B.Poly[j].Coef
 C.Poly[k].Exp = A.Poly[i].Exp;
 i++; j++; k++;
 }
 else if(A.Poly[i].Exp > B.Poly[j].Exp)
 {
 C.Poly[k].Coef = A.Poly[i].Coef;
 C.Poly[k].Exp = A.Poly[i].Exp;
 i++; k++;
 }
 else
 {
 C.Poly[k].Coef = B.Poly[j].Coef;
 C.Poly[k].Exp = B.Poly[j].Exp;
 j++; k++;
 }
 } // end of while
 while(i < A.Total_Terms)
 {
 C.Poly[k].Coef = A.Poly[i].Coef;
 C.Poly[k].Exp = A.Poly[i].Exp;
 i++; k++;
 }
 while(j < B.Total_Terms)
 {
 C.Poly[k].Coef = B.Poly[j].Coef;
 C.Poly[k].Exp = B.Poly[j].Exp;
 j++; k++;
 }
 C.Total_Terms = k - 1;
 return C;
 } // end of function

void main()
 {
 Polynomial A, B, C;
 double answer;
 A.Read_Poly();
 B.Read_Poly();
 .
 .
 .
 C = A.Add_Poly(B);
 }
