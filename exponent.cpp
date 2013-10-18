/*
AUTHOR: Akhilesh Anandh
Algo. to find (base^exp)%mod
time complexity: log(exp)
*/

long long pow(long long base, long long exp, long long mod){
	long long result = 1;
	while(exp>0){
		if(exp&1) result*=base;
		base*=base;
		if(base>mod) base%=mod;
		if(result>mod) result%=mod;
		exp/=2;
	}
	return result;
}
