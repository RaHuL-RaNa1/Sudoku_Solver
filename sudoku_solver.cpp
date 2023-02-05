#include<bits/stdc++.h>
using namespace std;
bool kya_mai_num_daal_shkta_hu_i_j_pe(int mat[9][9],int i,int j,int num,int n){
//veritcal check
for(int l=0;l<n;l++){
if(mat[l][j]==num){
return false;
}
}
//horizontal check
for(int k=0;k<n;k++){
    if(mat[i][k]==num){//row constant hai 
        return false;
    }
}
//root[n] x root[n] matrix mai check krna hai
int p=sqrt(n);
int si=(i/p)*p;//i=4-->3
int sj=(j/p)*p;//j=5-->3
for(int l=si;l<si+p;l++){//3 or l<=si+2 bhi likh shkte hai
for(int k=sj;k<sj+p;k++){//3 kya 3<3+3?
if(mat[l][k]==num){
    return false;
}
}
}
return true; //agar tino m se kissi m se bhi false nhi aya to return true and you can able to put that no in (i,j) index
}



bool sudokusolver(int mat[9][9],int i,int j,int n){
//base case
if(i==n){
   for(int l=0;l<n;l++){
    for(int k=0;k<n;k++){

       
         if(k == 3 || k == 6)
            cout << " | ";


        cout<<mat[l][k]<<" ";
    }
     if(l == 2 || l == 5){
         cout << endl;
         for(int i = 0; i<n-1; i++)
            cout <<"---";
      }
      cout << endl;
   }

   

  // return true;//ki solution exist krta hai
  return false; //agar sare solution dekhne more than one solution
}




//recursive case
if(j==n){
    sudokusolver(mat,i+1,0,n);//jab j ki value 9 ho jayegi to next line mai ane k liye
}

//agar already filled hogi to 
if(mat[i][j]!=0){
    return sudokusolver(mat,i,j+1,n);//jab bhi recursive call lagate hai to return likhte hai
}
//unfilled
for(int num=1;num<=9;num++){
if(kya_mai_num_daal_shkta_hu_i_j_pe(mat,i,j,num,n)==true){
mat[i][j]=num;

bool kya_agese_ans_mila = sudokusolver(mat,i,j+1,n);
if(kya_agese_ans_mila==true){//agar false mila to means 1nhi daal shkte to 1 ko dubara 0 bna do
    return true;
}

mat[i][j]=0;//else //backtracking
}
}
return false;//jab num ki value 10 hogi tb loop se bhar ayega or bolega return false solution exist  hi ni krta
}



int main(){
int mat[9][9]=
{{5,3,0,0,7,0,0,0,0},
 {6,0,0,1,9,5,0,0,0},
 {0,9,8,0,0,0,0,6,0},
 {8,0,0,0,6,0,0,0,3},
 {4,0,0,8,0,3,0,0,1},
 {7,0,0,0,2,0,0,0,6},
 {0,6,0,0,0,0,2,8,0},
 {0,0,0,4,1,9,0,0,5},
 {0,0,0,0,8,0,0,7,9}};


// {{3, 0, 6, 5, 0, 8, 4, 0, 0},
//    {5, 2, 0, 0, 0, 0, 0, 0, 0},
//    {0, 8, 7, 0, 0, 0, 0, 3, 1},
//    {0, 0, 3, 0, 1, 0, 0, 8, 0},
//    {9, 0, 0, 8, 6, 3, 0, 0, 5},
//    {0, 5, 0, 0, 9, 0, 6, 0, 0},
//    {1, 3, 0, 0, 0, 0, 2, 5, 0},
//    {0, 0, 0, 0, 0, 0, 0, 7, 4},
//    {0, 0, 5, 2, 0, 6, 3, 0, 0}
// };
sudokusolver(mat,0,0,9);//matrix row column,n

return 0;
}