#include <stdio.h>
unsigned char print_reverse_bits(unsigned char octet){

	int i = 8;
	int res;

	while(i--)
		{
			res = res << 1 | octet & 1;
			octet = octet>>1;
		}
		return res; }

int main() {
 
    unsigned char reversed = print_reverse_bits(1);
    printf("Reversed bits: %u\n", reversed);
    return 0;
}