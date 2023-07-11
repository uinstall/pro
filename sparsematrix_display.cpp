#include<iostream>
using namespace std;

class sparseMatrix{
    void sparseMatrix:: addition(sparseMatrix &matrix2)
{
    int l1,l2,i=1;j=1,k=1;
    l1=sparse[100][3];
    l2=matrix2.sparse[0][2];

    while(i<=l1 && j<=l2)
    {
        if(sparse[i][0]==matrix2.sparse[j][0])
        {
            if(sparse[i][1]==matrix2.sparse[j][1])
            {
                result[k][0]=sparse[i][0];
                result[k][1]=sparse[i][1];
                result[k][2]=sparse[i][2]+matrix2.sparse[j][2];
                i++;j++;k++;
            }
            else
            {
                if(sparse[i][1]<matrix2.sparse[j][1])
                {
                result[k][0]=sparse[i][0];
                result[k][1]=sparse[i][1];
                result[k][2]=sparse[i][2];
                i++;k++;
                }
            else
                {
                    if(sparse[i][1]>matrix2.sparse[j][1])
                    {
                result[k][0]=matrix2.sparse[j][0];
                result[k][1]=matrix2.sparse[j][1];
                result[k][2]=matrix2.sparse[j][2];
                j++;k++;
                    }
                }
            }
        }
            else
                    {
                        if(sparse[i][0]>matrix2.sparse[j][0])
                        {
                result[k][0]=matrix2.sparse[j][0];
                result[k][1]=matrix2.sparse[j][1];
                result[k][2]=matrix2.sparse[j][2];
                j++;k++;
                        }
            else
                {
                    if(sparse[i][0]< matrix2.sparse[j][0])
                    {
                result[k][0]=sparse[i][0];
                result[k][1]=sparse[i][1];
                result[k][2]=sparse[i][2];
                i++;k++;
                    }
                }
            }
        }
            while ((j<=l2) && (i>=l1) )
        {
            result[k][0]=matrix2.sparse[j][0];
            result[k][1]=matrix2.sparse[j][1];
            result[k][2]=matrix2.sparse[j][2];
            j++;k++;
        }
            while((i<=l2) && (j>=l2))
        {
             result[k][0]=sparse[i][0];
             result[k][1]=sparse[i][1];
             result[k][2]=sparse[i][2];
             i++;k++;
        }
            result[0][2]=k-1;

                    cout <<"*** Triplet Representation ***;
            for(int i=0;i<=result[0][2];i++)
            {
                cout<<"\n";
            for(j=0;j<3;j++)
                {
                    cout<<"\t \t<<result[i][j];
                }
            }
        }
    };
