	   int main(void)
	   {
			int n = 225225;

			int i = 1;
			while (i <= n)
			{
				int factor = 0;
				int j = 1;
				while (j <= i)
				{
					if (i % j == 0)
						factor++;
					j++;
				}
				if (factor == 2 && n % i == 0)
				{
					printf("%i*", i);
					n = n / i;
					continue;
				}
				i++;
			}
	   }


void fprime(int n){

	int i= 1;
	if(n ==1){
		printf("1");
	}
	while(++i <= n){
		if(n % i ==0){
			printf("%d",i);
			if(i == n)
				break;
			printf("*");
		n/=i;
		i=1;
		}
	}

}

int main(int c , char **v){

	// if(c ==2)
		fprime(atoi(v[1]));
	// printf("\n");
}