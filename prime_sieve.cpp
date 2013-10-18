/*
AUTHOR: Akhilesh Anandh
Optimized sieve of Eratosthenes to generate primes upto a number MAX
*/

#define MAX 10000000 //number upto which primes are generated
#define RT 3120 // square root of MAX

int isNotPrime[1+(MAX>>5)]; //bit-vector to mark non-prime numbers
int primes[MAX>>3]; //Array to store primes. Make size more than MAX/8 for small MAX
int no_of_primes;
#define set_num(n) isNotPrime[n>>5] |= (1<<(n&31))
#define get_num(n) isNotPrime[n>>5] & (1<<(n&31))


/*
after genearte() is executed,
the array primes[] contains the prime nos from 2 to MAX
no_of_primes contains the number of primes
get_num(i) -> 0 if i is prime, 1 otherwise
*/

void generate(){
	register int i,j,k=1;
	primes[0] = 2;
	for(i=3;i<=RT;i+=2){
		if(get_num(i))
			continue;
		primes[k++] = i;
		for(j=i*i;j<=MAX;j+=i)
			set_num(j);
	}
	for(;i<=MAX;i++)
		if(!get_num(i))
			primes[k++] = i;
	no_of_primes = k;
}

