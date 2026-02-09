
void	print_bits(unsigned char octet){
	int i = 8;
	while(i--){
		int bit = (octet >>i &1) +'0';
		write(1,&bit,1);
	}
}
int main(){

}