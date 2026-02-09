char *ft_strrev(char *str){
	
	char *start=str;
	char *end = str;
	char temp;
	while(*end!='\0'){
		end++;
	}
	end--;
	while (start<end){
		temp=*start;
		*start=*end;
		*end=temp;
		str++;
		end--;
	}

	return str;
}