/*
  Dinic �㷨�������
  N������
  e, lst: �߼��ͱ�ͷ
  S, T: Դ��
  tips: e[i]��e[i^1]����Ϊ����
*/

const int N = 1010;

int iter[N], d[N];
queue <int> Q;

inline int Bfs(Edge * e, int * lst, int S, int T) {
	for(int i = 1; i <= T; ++i)
		d[i] = 0, iter[i] = lst[i];
	d[S] = 1, Q.push(S);
	while(!Q.empty()) {
		int x = Q.front(); Q.pop();
		for(int i = lst[x]; i >= 0; i = e[i].next)
			if(!d[e[i].to] && e[i].w) 
				d[e[i].to] = d[x] + 1, Q.push(e[i].to);		
	}
	return d[T];
}

int Dfs(Edge * e, int * lst, int T, int x, int f) {
	if(x == T || !f)
		return f;
	int sf = 0;
	for(int i = iter[x]; i >= 0; i = e[i].next)
		if(d[e[i].to] == d[x] + 1 && e[i].w) {
			int w = Dfs(e, lst, T, e[i].to, min(e[i].w, f));
			if(f) {
				e[i].w -= w;
				e[i ^ 1].w += w;
				f -= w, sf += w;
			}
		}
	return sf;
}
				

int Dinic(Edge * e, int * lst, int S, int T) {
	int ans = 0;
	while(Bfs(e, lst, S, T))
		ans += Dfs(e, lst, T, S, 1e9);
	return ans;
}
