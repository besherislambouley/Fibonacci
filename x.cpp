/*
 * let res [i] = a [i] + b [i] 
 * greedily when res [i] = 1 & res [i+1] = 1 replace them with res [i+2] = 1 ( since fib [i] + fib[i+1] = fib[i+2] ) 
 * when res [i] >= 2 , replace it with res [i] -=2 , res [i+1] ++ , res [i-2] ++ ( I actually found that by trying examples ) 
 * https://cp-algorithms.com/algebra/fibonacci-numbers.html#toc-tgt-1 this may help
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
#define mp make_pair
#define mid (l+r)/2
#define Le Node * 2 
#define Ri Node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=1e18;
const ll Mod=1e9+7;
const ld pai=acos(-1) ;
int n , m ;
int a [2000009] ;
int main () {
	scanf("%d",&n) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int x ;
		scanf("%d",&x) ;
		a [i] += x ;
	}
	scanf("%d",&m) ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int x ;
		scanf("%d",&x) ;
		a [i] += x ;
	}
	for ( int i = n + m ; i >= 0 ; i -- ) {
		if ( a [i] == 1 && a [i+1] == 1 ) {
			a [i] -- ;
			a [i+1] -- ;
			a [i+2] ++ ;
			i += 3 ;
			C ;
		}
		if ( a [i] >= 2 ) {
			a [i] -= 2 ;
			a [i+1] ++ ;
			if ( i - 2 >= 0 ) a [i-2] ++ ;
			else if ( i - 1 >= 0 ) a [0] ++ ;
			i += 2 ;
			C ;
		}
	}
	int N = 0 ;
	for ( int i = n + m ; i >= 0 ; i -- ) {
		if ( a [i] ) {
			N = i + 1 ;
			break ;
		}
	}
	printf("%d ",N) ;
	for ( int i = 0 ; i < N ; i ++ ) printf("%d ",a[i]) ;
	cout << endl ; 

}
