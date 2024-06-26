#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
	int arr[] = { 1, 50, 8 };
    int arr2[100];
    int b=0;
	int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]>=10){
            while(arr[i]!=0){
               arr2[b]=arr[i]%10;
              arr[i]=arr[i]/10;
                cout<<arr2[b]<<endl;
              b++;
             }
            }
            else{
                arr2[b]=arr[i];
                cout<<arr2[b]<<endl;
                b++;
            }
            
    }
	sort(arr2, arr2 + b,cmp);
	cout << "\nArray after sorting using "
			"default sort is : \n";
	for (int i = 0; i < b; ++i){
		cout << arr2[i];
        }

	return 0;
}
