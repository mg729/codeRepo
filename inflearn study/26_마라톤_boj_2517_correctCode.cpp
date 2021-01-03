#include<bits/stdc++.h>
using namespace std;
struct Data{
	int idx, speed, rank;	
};

vector<Data> a(500000), tmp(500000);
int res[500000];

void divide(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		divide(lt, mid);
		divide(mid+1, rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt){
			if(a[p1].speed<a[p2].speed) tmp[p3++]=a[p1++];
			else{
				tmp[p3]=a[p2++];
				tmp[p3].rank+=mid-p1+1;
				p3++;
			}
		}
		while(p1<=mid) tmp[p3++]=a[p1++];
		while(p2<=rt) tmp[p3++]=a[p2++];
		
		for(int i=lt; i<=rt; i++){
			a[i]=tmp[i];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	int n, t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].speed;
		a[i].idx=i;
		a[i].rank=0;	
	} 
	divide(0, n-1);
	for(int i=0; i<n; i++){
		res[a[i].idx]=a[i].rank+1;
	}
	for(int i=0; i<n; i++){
		cout<<res[i]<<"\n";
	}
	return 0;
}
