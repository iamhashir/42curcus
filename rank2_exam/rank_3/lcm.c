int gcd(int a,int b){
		while(a!=b){
			if(a>b){
				a-=b;
			}
			else{
				b-=a;
			}
		}
		return a;
}

unsigned int    lcm(unsigned int a, unsigned int b){
	if(a == 0 || b == 0){
		return 0;
	}
	return a * b / gcd(a,b);
}
int main(int c, char **v){

}