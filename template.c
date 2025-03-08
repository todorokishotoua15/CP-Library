#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define rep(i,a,b) for(int i = a; i<b; i++)
#define inf 1e20
#define Mod 1e8
#define mod 1e5
#define ll long long
#define ld double
#define ill int long long

ld stand(ld a[])
{
	
	ld sum = 0;
	
	rep(i,0,5){
		sum += a[i];
	}
	ld mean = sum/5;
	
	ld sd_n = 0;
	rep(i,0,5){
		sd_n += (a[i] - mean)*(a[i] - mean);
	}
	ld ans = sqrt((sd_n)/5);
	
	return ans;
}
int main()
{
	ld ar[5];
	rep(i,0,5){
		scanf("%lf", &ar[i]);
	}
	ld ans = stand(ar);
	printf("%lf\n", ans);
}