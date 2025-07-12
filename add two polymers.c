#include <stdio.h>
void polyadd(int a[20][10],int b[20][10],int n,int m)
{
    int s[20][10],i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if (a[1][i]=b[1][j])
        {
            s[0][k]=a[0][i]+b[0][j];
            s[1][k]=a[1][i];
            i++;
            j++;
            k++;
        }
        else if (a[i][j]<b[i][j])
        {
            s[0][k]=a[0][i];
            s[1][k]=a[1][i];
            i++;
            k++;
        }
        else
        {
            s[0][k]=b[0][j];
            s[1][k]=b[1][j];
            j++;
            k++;
        }
        
    }
    while(i<n)
    {
        s[0][k]=a[0][i];
        s[1][k]=a[1][i];
        i++;
        k++;
    }
    while(j<m)
    {
        s[0][k]=b[0][j];
        s[1][k]=b[1][j];
        j++;
        k++;
    }
    printf("The sum of the two polynomials is:\n");
    for (i=0; i<k; i++)
    {
        if (s[0][i] != 0)
        {
            printf("%dx^%d ", s[0][i], s[1][i]);
            if (i < k - 1)
                printf("+ ");
        }
         else
         { 
           printf("%dx^%d ", s[0][i], s[1][i]);
         } 
    }
}    
int main() 
{
    int a[20][10], b[20][10], n, m, i;
    
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and degrees of the first polynomial:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[0][i], &a[1][i]);
    }
    
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &m);
    printf("Enter the coefficients and degrees of the second polynomial:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &b[0][i], &b[1][i]);
    }
    
    polyadd(a, b, n, m);
    
    return 0;
}
