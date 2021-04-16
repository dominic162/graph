#include<bits/stdc++.h>
using namespace std;
class graph{
public:
	int v,e;
	unordered_map<int,list<int>> mp1;
	void addedge(int v1,int v2){
		mp1[v1].push_back(v2);
	}
	void bfs(int snode){
		queue<int> q1;
		int status[v],r,i;
		for(i=0;i<v;i++){
			status[i]=1;
		}
		q1.push(snode);
		status[snode]=2;
		while(!q1.empty()){
			r=q1.front();
            q1.pop();
			cout<<r<<" ";
			status[r]=3;
			auto p=mp1[r].begin();
			for(;p!=mp1[r].end();p++){
				if(status[*p]==1){
					q1.push(*p);
					status[*p]=2;
				}
			}
		}
	}
	graph(int v1,int e1){
		this->v=v1;
		this->e=e1;
	}	
};
int main(){
	int v,e,i,v1,v2;
	cin>>v>>e;
	graph g1(v,e);
	for(i=0;i<e;i++){
		cin>>v1>>v2;
		g1.addedge(v1,v2);
	}
	cout<<"enter source node ";
	cin>>v1;
	g1.bfs(v1);
	return 0;
}