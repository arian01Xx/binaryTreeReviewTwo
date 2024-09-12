void prim(int n, int startNode, vector<vector<pair<int,int>>>& graph){
	vector<bool> visited(n, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	visited[startNode]=true;
	for(auto &edge: graph[startNode]){
		int weight=edge.first;
		int node=edge.second;
		pq.push({weight,node});
	}
	while(!pq.empty()){
		auto[weight,node]=pq.top();
		pq.pop();
		if(!visited[node]){
			visited[node]=true;
			for(auto &edge: graph[node]){
				int newWeight=edge.first;
				int adjacentNode=edge.second;
				if(!visited[adjacentNode]){
					pq.push({newWeight,adjacentNode});
				}
			}
		}
	}
}