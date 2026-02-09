
int		max(int* tab, unsigned int len){
	int i = 0;
	int res=0;
	while(i<=len){
		if(tab[i]>res){
			res = tab[i];
		}
		i++;
	}
	return res;
}
