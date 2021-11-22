#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	char c = getchar(); x = 0;
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		x = x * 10 + c - '0';
		c = getchar();
	}
}
const int N = 100007;
struct node{
	ll tag0, tag1, tag2, val3, val2, val1, len;
	node (ll val1_ = 0, ll val2_ = 0, ll val3_ = 0, ll len_ = 1){
		tag0 = 0; tag1 = 1; tag2 = -1;
		val1 = val1_, val2 = val2_, val3 = val3_, len = len_;
	}
}T[4 * N];
int n, sz[N], son[N], dep[N], fa[N], top[N], b[N], id[N], cnt;
vector<int> a[N];
ll w[N];
void dfs0(int x){
	dep[x] = dep[fa[x]] + 1;
	for(int y : a[x]){
		if(y == fa[x]) continue;
		fa[y] = x; dfs0(y); sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}
void dfs1(int x, int top_){
	b[++cnt] = x; id[x] = cnt; top[x] = top_;
	if(son[x]) dfs1(son[x], top_);
	for(int y : a[x]){
		if(y == fa[x] || y == son[x]) continue;
		dfs1(y, y);
	}
}
node merge(node a, node b){
	ll val1 = a.val1 + b.val1, val2 = a.val2 + b.val2, val3 = a.val3 + b.val3, len = a.len + b.len;
	if(val1 >= mo) val1 -= mo; if(val2 >= mo) val2 -= mo; if(val3 >= mo) val3 -= mo;
	node ans = node(val1, val2, val3, len);
	return ans;
}
void build(int x, int l = 1, int r = n){
	if(l == r){
		ll tmp = w[b[l]];
		T[x] = node(tmp, tmp * tmp % mo, tmp * tmp % mo * tmp % mo);
		return;
	}
	int mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	T[x] = merge(T[x * 2], T[x * 2 + 1]);
}
void update_add(int x, ll tmp){
	ll tmp_ = tmp * tmp % mo, tmp__ = tmp_ * tmp % mo;
	T[x].tag0 += tmp; if(T[x].tag0 >= mo) T[x].tag0 -= mo;
	T[x].val3 = (T[x].val3 + 3ll * T[x].val2 * tmp % mo 
			+ 3ll * T[x].val1 * tmp_ % mo + T[x].len * tmp__ % mo) % mo;
	T[x].val2 = (T[x].val2 + 2ll * T[x].val1 * tmp % mo
			+ T[x].len * tmp_ % mo) % mo;
	T[x].val1 += T[x].len * tmp % mo;
	if(T[x].val1 >= mo) T[x].val1 -= mo;
}
void update_muti(int x, ll tmp){
	ll tmp_ = tmp * tmp % mo, tmp__ = tmp_ * tmp % mo;
	T[x].tag0 = T[x].tag0 * tmp % mo;
	T[x].tag1 = T[x].tag1 * tmp % mo;
	T[x].val1 = T[x].val1 * tmp % mo;
	T[x].val2 = T[x].val2 * tmp_ % mo;
	T[x].val3 = T[x].val3 * tmp__ % mo;
}
void push_down(int x){
	if(T[x].tag2 != -1){
		T[x * 2].tag0 = T[x * 2 + 1].tag0 = 0;
		T[x * 2].tag1 = T[x * 2 + 1].tag1 = 1;
		ll tmp = T[x].tag2; T[x].tag2 = -1; T[x * 2].tag2 = T[x * 2 + 1].tag2 = tmp;
		T[x * 2].val1 = T[x * 2].len * tmp % mo;
		T[x * 2].val2 = T[x * 2].val1 * tmp % mo;
		T[x * 2].val3 = T[x * 2].val2 * tmp % mo;
		T[x * 2 + 1].val1 = T[x * 2 + 1].len * tmp % mo;
		T[x * 2 + 1].val2 = T[x * 2 + 1].val1 * tmp % mo;
		T[x * 2 + 1].val3 = T[x * 2 + 1].val2 * tmp % mo;
	}
	if(T[x].tag1 != 1){
		ll tmp = T[x].tag1; T[x].tag1 = 1;
		update_muti(x * 2, tmp); update_muti(x * 2 + 1, tmp);
	}
	if(T[x].tag0){
		ll tmp = T[x].tag0; T[x].tag0 = 0;
		update_add(x * 2, tmp); update_add(x * 2 + 1, tmp);
	}
}
void assIgn(int x, int ml, int mr, ll val, int l = 1, int r = n){
	if(ml <= l && r <= mr){
		ll tmp = val * T[x].len % mo, tmp_ = tmp * val % mo, tmp__ = tmp_ * val % mo;
		T[x] = node(tmp, tmp_, tmp__, r - l + 1);
		T[x].tag2 = val; return;
	}
	push_down(x);
	int mid = (l + r) >> 1;
	if(ml <= mid) assIgn(x * 2, ml, mr, val, l, mid);
	if(mr > mid) assIgn(x * 2 + 1, ml, mr, val, mid + 1, r);
	T[x] = merge(T[x * 2], T[x * 2 + 1]);
}
void modify1(int x, int ml, int mr, ll val, int l = 1, int r = n){
	if(ml <= l && r <= mr){ update_add(x, val); return;}
	push_down(x);
	int mid = (l + r) >> 1;
	if(ml <= mid) modify1(x * 2, ml, mr, val, l, mid);
	if(mr > mid) modify1(x * 2 + 1, ml, mr, val, mid + 1, r);
	T[x] = merge(T[x * 2], T[x * 2 + 1]);
}
void modify2(int x, int ml, int mr, ll val, int l = 1, int r = n){
	if(ml <= l && r <= mr){ update_muti(x, val); return;}
	push_down(x);
	int mid = (l + r) >> 1;
	if(ml <= mid) modify2(x * 2, ml, mr, val, l, mid);
	if(mr > mid) modify2(x * 2 + 1, ml, mr, val, mid + 1, r);
	T[x] = merge(T[x * 2], T[x * 2 + 1]);
}
void lca1(int x, int y, int z){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		assIgn(1, id[top[x]], id[x], z);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	assIgn(1, id[y], id[x], z);
}
void lca2(int x, int y, int z){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		modify1(1, id[top[x]], id[x], z);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	modify1(1, id[y], id[x], z);
}
void lca3(int x, int y, int z){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		modify2(1, id[top[x]], id[x], z);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	modify2(1, id[y], id[x], z);
}
ll query(int x, int ql, int qr, int l = 1, int r = n){
	if(ql <= l && r <= qr) return T[x].val3;
	push_down(x);
	int mid = (l + r) >> 1; ll ans = 0;
	if(ql <= mid) ans += query(x * 2, ql, qr, l, mid);
	if(qr > mid) ans += query(x * 2 + 1, ql, qr, mid + 1, r);
	return ans % mo;
}
int query(int x, int y){
	ll ans = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += query(1, id[top[x]], id[x]);
		if(ans >= mo) ans -= mo;
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	ans += query(1, id[y], id[x]);
	if(ans >= mo) ans -= mo;
	return ans;
}
int main(){
	int t; read(t);
	for(int I = 1; I <= t; I++){
		read(n);
		for(int i = 1; i <= n; i++){
			a[i].clear();
			sz[i] = 1; son[i] = top[i] = fa[i] = 0;
		}
		for(int i = 1; i < n; i++){
			int x, y; read(x); read(y);
			a[x].push_back(y); a[y].push_back(x);
		}
		for(int i = 1; i <= n; i++) read(w[i]);
		cnt = dep[0] = 0; dfs0(1); dfs1(1, 1);
		build(1);
		int q; read(q); cout << "Case #" << I << ":\n";
		for(int i = 1; i <= q; i++){
			ll opt, x, y, z;
			read(opt);
			if(opt != 4){read(x); read(y); read(z);}
			if(opt == 1) lca1(x, y, z);
			if(opt == 2) lca2(x, y, z);
			if(opt == 3) lca3(x, y, z);
			if(opt == 4){
				read(x); read(y);
				cout << query(x, y) << '\n';
			}
		}
	}
} 