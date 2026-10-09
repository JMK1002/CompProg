#include <iostream>
#include <string>
using namespace std;
int n,m;
string s1,s2;
void s__(){
	cin>>n>>m>>s1>>s2;
	int l=0,p=0;
	for(int i=0;i<n;i++){
		char c=s1[i];
		if(p<m&&c==s2[p]){
			p++;
			if(c=='0') l=p;

		}
		else if(c=='0'){
			p=l;
			if(!p)
			break;
		}
	}
	cout<<((p==m)?"yes\n":"no\n");
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		s__();
	return 0;
}

