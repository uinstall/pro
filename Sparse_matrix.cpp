// Name: Patel Vinit Ashok
//Roll No : 240
#include<iostream>
using namespace std;
class sparseMatrix{
int mat1[100][100], rows1, cols1;
int sparse[100][3];
public:
void accept_matrix();
void display_Matrix();
void create_sparseMatrix();
void display_sparseMatrix();
void transpose();
void addition(sparseMatrix &mat2);
};
void sparseMatrix::accept_matrix(){
cout<<"Enter number of rows : "<<endl;
cin>>rows1;
cout<<"Enter number of columns : "<<endl;
cin>>cols1;
for(int i=0;i<rows1;i++){
for(int j=0;j<cols1;j++){
cout<<"Enter element ["<<i<<"] ["<<j<<"]"<<endl;
cin>>mat1[i][j];
} }
create_sparseMatrix();
}



void sparseMatrix::display_Matrix(){
cout<<"Matrix :"<<endl;
for(int i=0;i<=rows1;i++){
for(int j=0;j<cols1;j++){
cout<<mat1[i][j]<<"\t";
}
cout<<endl;
} }





void sparseMatrix::create_sparseMatrix(){
int k=1;
for(int i=0;i<rows1;i++){
for(int j=0;j<cols1;j++){
if(mat1[i][j] != 0){
sparse[k][0] = i;
sparse[k][1] = j;
sparse[k][2] = mat1[i][j];
k++;
} } }
sparse[0][0] = rows1;
sparse[0][1] = cols1;
sparse[0][2] = k-1;
}
void sparseMatrix::display_sparseMatrix(){
cout<<"Row\tColumn\tValue"<<endl;
for(int i=0;i<=sparse[0][2];i++){
for(int j=0;j<3;j++){
cout<<sparse[i][j]<<"\t";
}
cout<<endl;
} }
void sparseMatrix::transpose(){
int transpose[100][3], k =1;
for(int i=0;i<sparse[0][1];i++){
for(int j=0;j<=sparse[0][2];j++){
if(sparse[j][1] == i){
transpose[k][0] = sparse[j][1];
transpose[k][1] = sparse[j][0];
transpose[k][2] = sparse[j][2];
k++;
} } }
transpose[0][0] = sparse[0][1];
transpose[0][1] = sparse[0][0];
transpose[0][2] = k-1;
cout<<"Transpose Matrix : "<<endl;
for(int i=0;i<k;i++){
for(int j=0;j<3;j++){
cout<<transpose[i][j]<<"\t";
}
cout<<endl;
} }
void sparseMatrix::addition(sparseMatrix &mat2){
int l1, l2, i = 1, j = 1, k = 1;
int result[100][3];
l1 = sparse[0][2];
l2 = mat2.sparse[0][2];
result[0][0] = sparse[0][0];
result[0][1] = sparse[0][1];
while(i<=l1 && j<=l2)
{
if(sparse[i][0] == mat2.sparse[j][0])
{
if(sparse[i][1] == mat2.sparse[j][1])
{
result[k][0] = sparse[i][0];
result[k][1] = sparse[i][1];
result[k][2] = sparse[i][2] + mat2.sparse[j][2];
cout<<endl<<sparse[i][2]<<"\t"<<mat2.sparse[j][2];
i++;
j++; 
k++;
}else
{
if(sparse[i][1] < mat2.sparse[j][1])
{
result[k][0] = sparse[i][0];
result[k][1] = sparse[i][1];
result[k][2] = sparse[i][2];
i++; k++;
}
else
{
if(sparse[i][1] > mat2.sparse[j][1])
{
result[k][0] = mat2.sparse[j][0];
result[k][1] = mat2.sparse[j][1];
result[k][2] = mat2.sparse[j][2];
j++; k++;
} } }}
else
{
if(sparse[i][0] > mat2.sparse[j][0])
{
result[k][0] = mat2.sparse[j][0];
result[k][1] = mat2.sparse[j][1];
result[k][2] = mat2.sparse[j][2];
j++; 
k++;
}
else
{
if(sparse[i][0] < mat2.sparse[j][0]){
result[k][0] = sparse[i][0];
result[k][1] = sparse[i][1];
result[k][2] = sparse[i][2];
i++;
k++;
} } } }
while((i>=l1) && (j<=l2))
{
result[k][0] = mat2.sparse[j][0];
result[k][1] = mat2.sparse[j][1];
result[k][2] = mat2.sparse[j][2];
j++; k++;
}
while((i<=l1) && (j>=l2))
{
result[k][0] = sparse[i][0];
result[k][1] = sparse[i][1];
result[k][2] = sparse[i][2];
i++; k++;
}
result[0][2] = k-1;
cout<<"Addition Result : \n";
cout<<"Rows\tColumns\tValues"<<endl;
for(int i=0;i<k;i++)
{
for(int j=0;j<3;j++)
{
cout<<result[i][j]<<"\t";
}
cout<<endl;
} }
int main(){
sparseMatrix sp1, sp2;
sp1.accept_matrix();
sp1.display_Matrix();
sp1.display_sparseMatrix();
sp1.transpose();
sp2.accept_matrix();
sp2.display_sparseMatrix();
sp1.addition(sp2);
return 0;
}
