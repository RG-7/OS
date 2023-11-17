#include <bits/stdc++.h>
using namespace std;

int pageFaults(int pages[],int n,int capacity){
	unordered_set<int> s;
	queue<int> indexes;
	int page_faults =0;
	for(int i=0;i<n;i++){
		if(s.size() < capcity){
			if(s.find(pages[i]==s.end()){
				s.insert(pages[i]);
				page_faults++;
				indexes.push(pages[i]);
			}
		}else{
			if(s.find(page[i]==s.end()){
				int val = index.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(page[i])
				page_faults++;
				s.insert(pages[i]);
	
			}
		}
	}
}