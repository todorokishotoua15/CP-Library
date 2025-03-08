#include<bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define nl "\n"
using namespace std;

ill ir = 0, ibr = 0, mar = 0, mbr = 0;

ill execute(ill mem[], ill pc) {
	while (pc < 1000) {
		mar = pc;
		mbr = *(mem + mar);
		cout << mbr << endl;
		break;
	}
}

int main()
{
	ill mem[1000];

	// Instructions:
	// 00001010 LOAD MQ
	// 00001001 LOAD MQ,M(X)
	// 00100001 STOR M(X)
	// 00000001 LOADM(X)
	// 00000010 LOAD-M(X)


	
	cout << "Give input in following format : "<<nl;
	cout < " If you want to perform add, type 'add' " << nl;
	cout << "If you want to perform subtraction, type 'sub' " << nl; 
	string s;
	cin >> s;
	if (s == "add") {
		cout << "Enter first number : " << nl;
		ill x, y;
		cin >> x;
		cout << "Enter second number : " <<nl;
		cin >> y;
		mem[0] = x;
		mem[1] = y;

		// Instruction : Load M(1), ADD M(0)
		mem[3] = 0x0100105000;
		
	}
	execute(mem,2);
}