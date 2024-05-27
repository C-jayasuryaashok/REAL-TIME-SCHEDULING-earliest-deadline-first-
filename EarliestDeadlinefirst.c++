#include <iostream>
#include<vector>
#include<map>
#include <bits/stdc++.h>
int allcount=0,row=0,col=0,temprow=0,tempcol=0, mul=0;
int arr[]={1,1,1};
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}



int findLCM(int arr[], int n) {
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }

    return result;
}

int main()
{

int n;

    cout<<"Enter the no of tasks:"<<endl;
    cin>>n;

    int name[n],extime[n],deadline[n],timeperoid[n];
    for(i=0;i<n;i++){
        cout<<"Enter the task no:"<<endl;
        cin>>name[i];
        cout<<"Enter the Expired time:"<<endl;
        cin>>extime[i];
        cout<<"Enter the deadline:"<<endl;
        cin>>deadline[i];
        cout<<"Enter the timeperiod:"<<endl;
        cin>>timeperoid[i];


    }
    
float d=0;
for(int i=0;i<n;i++){

        d+=extime[i]*100/timeperoid[i];

}
int result = findLCM(timeperoid, n);
vector<vector<int>>name;
vector<vector<int>>index;
vector<int>findmin;






int systematic[n][result];
 memset(systematic,0,sizeof(systematic));


if(d<100){



for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(extime[i]>extime[j]){
                    swap(extime[i],extime[j]);
                    swap(name[i],name[j]);
                    swap(deadline[i],deadline[j]);
                    swap(timeperoid[i],timeperoid[j]);
                }
            }
        }


for(int i=0;i<n;i++){
        vector<int>innervect;
        vector<int>innerindex;


    for(int j=1;j<result;j++){

        if(timeperoid[i]*j<=result){
                innervect.push_back(timeperoid[i]*j);
                innerindex.push_back(0);


        }
    }
name.push_back(innervect);
index.push_back(innerindex);
}

for(int j=0;j<result;j++){

 for(int j=0;j<index[row].size();j++){
        if(index[row][j]!=1){


                 tempcol=j;
                 break;
                 }}
                 if(arr[row]==0){
                    continue;
                 }


                 if(name[row][tempcol]==result && arr[row]==1){
                    arr[row]=0;
                 }

                 for(int i=0;i<extime[row];i++){
                    systematic[row][allcount]=1;
                    allcount++;
                 }
                 index[row][tempcol]=1;

                 for(int i=0;i<deadline[i]  ;i++){
                        for(int j=0;j<index[i].size();j++){
                                if(row!=i){if(index[i][j]!=1 ){


                     findmin.push_back(abs(name[i][j]-allcount));

                     break;}
                                }else{
                        findmin.push_back(12345);
                        break;
                     }
                         }
                 }

            int  lowest=findmin[0];
                   for(auto t:findmin){
                    lowest=min(lowest,t);
                   }
                 for(int i=0;i<findmin.size();i++){
                    if(lowest==findmin[i]){
                        row=i;
                        break;
                    }
                 }
                 map<int,int>mapval;
                 map<int,int>mapval1;
                 int qw=0;
                 for(auto i:findmin){
                    mapval[i]++;
                    mapval1[i]=qw;
                    qw++;
                    }



        map<int,int>::iterator q;
                    for(auto q=mapval.begin(); q!=mapval.end();q++){
                        if(findmin[row]==q->first){

                            if(q->second>1){

                                for(int i=0;i<findmin.size();i++){
                                    if(lowest==findmin[i] && i!=row){
                                        row=i;
                                        break;
                                    }
                                }
                                break;                           }
                        }
                        break;
                    }
                    findmin={};
                    mapval1={};
                    mapval={};




                    for(int i=0;i<n ;i++){
                        for(int j=0;j<result ;j++){
                                if(systematic[i][j]!=0){
                            cout<<" task "<<i<<"  time period "<<j<<"\n";
                                }
                        }cout<<"\n";
                    }
}
}

else{
    cout<<"IT IS NOT POSSIBLE TO IMPLEMENT THE REAL TIME ALGORITHM"<<endl;
}
    return 0;
}
