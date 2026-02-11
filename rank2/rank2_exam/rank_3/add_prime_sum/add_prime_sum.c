int is_prime(int s){
	int i = 2;

	if(num<=1)
		return 0;
	while(i*i<=s){
		if(s%i==0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
void put_nbr(int r){

	if(r>=10){
		put_nbr(r/10);
	}
	write(1,"0123456789"[r%10],1);

}
int main(){
	int i = 0;
	int r = 0;
	if(c ==2){
		while(0<n){
			if(is_prime(n))
				r = r + n;
			n--;
		}
		put_nbr(r);
	}
}