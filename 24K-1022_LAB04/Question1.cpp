#include <iostream>
using namespace std;
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"  ";
	}
}
int main(){
	int count=0;
	int arr[]={64,32,25,12,22,11,90};
	int size=sizeof(arr) / sizeof(arr[0]);
	cout<<"Original Array:\n";
	display(arr,size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1;j++){
		
			if(arr[j]>arr[j+1]){
			    	count++;
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"\nSorted Array:\n";
	display(arr,size);
	cout<<"\nTotal Comparision: "<<count<<endl;
return 0;
}
