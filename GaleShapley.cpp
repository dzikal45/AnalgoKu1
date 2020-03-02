#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define n 5

bool chooseMan(int prefer[2 * n][n],int w,int m,int m1){
    for(int i=0;i<n;i++){
        if(prefer[w][i]== m1){
            return true;
        }
        if(prefer[w][i]==m){
            return false;
        }
    }
}

void stableMatching (int prefer[2*n] [n]){
    int wPartner[n];
    bool mFree[n];

    memset(wPartner, -1, sizeof(wPartner)); 
    memset(mFree, false, sizeof(mFree)); 
    int freeCount = n; 
    
    while (freeCount > 0) 
    { 
        
        int m; 
        for (m = 0; m < n; m++) 
            if (mFree[m] == false) 
                break; 
  
        for (int i = 0; i < n && mFree[m] == false; i++) 
        { 
            int w = prefer[m][i]; 
            if (wPartner[w-n] == -1) 
            { 
                wPartner[w-n] = m; 
                mFree[m] = true; 
                freeCount--; 
            } 
             else  
            { 
                int m1 = wPartner[w-n]; 
  
                if (chooseMan(prefer, w, m, m1) == false) 
                { 
                    wPartner[w-n] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } // End of Else 


        }
    }
     cout << "Pria Wanita" << endl; 
     string pria;
     string wanita;
    for (int i = 0; i < n; i++) {
        if(i<n){
            if(wPartner[i]==0){
                pria="victor";
            }
            if(wPartner[i]==1){
                pria="Wyatt";
            }
            if(wPartner[i]==2){
                pria="Xavier";
            }
            if(wPartner[i]==3){
                pria="Yancey";
            }
            if(wPartner[i]==4){
                pria="Zeus";
            }
            if(i==0){
                wanita="Amy";
            }
            if(i==1){
                wanita="Bertha";
            }
            if(i==2){
                wanita="Clare";
            }
            if(i==3){
                wanita="Diane";
            }
            if(i==4){
                wanita="Erika";
            }
            cout<<" "<< pria << "\t"<<wanita<<endl;
        }
    }
      
}
int main() 
{ 
    int prefer[2*n][n] = { {6, 5, 8, 9,7}, 
        {8, 6, 5, 7,9}, 
        {6, 9, 8, 7,5}, 
        {5, 8, 7, 6,9}, 
        {6, 8, 5, 9,7}, 
        {4, 0, 1, 3,2}, 
        {2, 1, 3, 0,4}, 
        {1, 2, 3, 4,0},
        {0,4,3,2,1},
        {3,1,4,2,0}
    }; 
    stableMatching(prefer); 
  
    return 0; 
} 