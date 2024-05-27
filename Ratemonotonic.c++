#include <iostream>
#include<vector>
#include<cstring>
#include<math.h>

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
val.push_back(0);

    }
    
    float d=0;

for(int i=0;i<n;i++){

        d+=float(exp[i])/time[i];

}

float d1=0,q1=0;
q1=float(1)/n;
d1=n*(pow(2,q1)-1);


int result = findLCM(time, n);

int systematic[result];
 memset(systematic,0,sizeof(systematic));
if(d<d1){
vector<vector<int>>index;
    vector<vector<int>>checkindex;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(exp[i]>exp[j]){
                    swap(exp[i],exp[j]);
                    swap(task[i],task[j]);
                     swap(time[i],time[j]);
                }
            }
        }


for(int i=0;i<n;i++){
        vector<int>innervect;
for(int j=0;j<result;j++){

        if(time[i]*j<=result){
                innervect.push_back(time[i]*j);


        }
    }
index.push_back(innervect);

}

int j=0;
while( j<n){
for(int i=0;i<index[j].size()-1;i++){
int q1=index[j][i];
int q2=index[j][i+1];
for(int i=0;i<exp[j];i++){
for(int w=q1;w<q2;w++){
if(systematic[w]==0){ q1=w;break;}
}systematic[q1]=task[j];
}
continue;
}
 j++;}
}
else{
cout<<"It does not suitable for for rate monotonic scheduling algorithm"<<endl;
}
cout<<"\n";
for(int i=0;i<result;i++){
        if(systematic[i]==0){cout<<"Time peroid" <<" "<<i<<"  "<< "Ideal time"<<endl;}
                        else{cout<<"Time period"<< " "<<i<<"  "<< "Task"<<"  " << systematic[i]<<endl;}}
 return 0;
}

