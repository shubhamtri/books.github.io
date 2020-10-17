#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i;
    cin>>s;
    int ar[26]={0}; 
    for(i=0;i<s.size();i++)
        ar[s[i] - 'a']++;  
        
    string s1="";
    vector <int> freq;
    for(i=0;i<s.size();i++){
        if(ar[s[i] - 'a']!=0){   
            freq.push_back(ar[s[i] - 'a']); 
            s1+=char(s[i]);  
            ar[s[i]]=0;  
        }
    }
    
    for(i=0;i<freq.size();i++){
        cout<<char(s1[i])<<" "<<freq[i]<<" ";
    }
    cout<<"\n";
    int t;
    cin>>t;
    while(t--){
        int n,count=0,flag=0,first,last;
        cin>>n;
        for(i=0;i<freq.size();i++){
            if(freq[i]==n){
                if(flag==0){
                    first=i;
                    flag=1;
                }else{
                    last=i;
                }
            }
        }
        
        i=first+1;
        
        while(i <= last){
            if(freq[i]>n){
                char test_char=char(s1[i]);
                int test_int=freq[i];
                s1.erase(s1.begin()+i);
                freq.erase(freq.begin()+i);
                freq.push_back(test_int);
                s1.push_back(test_char);
                
            }else if(freq[i]<n){
                char test_char=char(s1[i]);
                int test_int=freq[i];
                s1.erase(s1.begin()+i);
                freq.erase(freq.begin()+i);
                s1.insert(s1.begin(),test_char);
                freq.insert(freq.begin(),test_int);
                i++;
                last--;
            }else{
                i++;
                continue;
            }
            
        }
        for(i=0;i<freq.size();i++){
        cout<<char(s1[i])<<" "<<freq[i]<<" ";
    }
    cout<<"\n";
    }

	
	return 0;
}
