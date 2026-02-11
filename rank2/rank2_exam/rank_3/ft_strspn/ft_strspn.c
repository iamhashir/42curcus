int ft_strcmp(char *s1,char *s2){
	int i =0;
	while(s1[i] && s2[i] && s1[i]==s2[i])
		i++;
	return s1[i]-s2[i];
}

size_t ft_strcspn (const char *s, const char * reject){
	int i = 0;
	int j = 0;
	while(s[i]){
		j=0
		while(reject[j])
		{
			if(s[i]==reject[j])
				return i;
			j++;
		}
		i++;
	}
	return i;
}

char *ft_strdup(char *src){
	int length = 0;
	int i = 0;
	while(src[length]){
		length++;
	}
	char *strcpy = malloc(sizeof(char)*length +1);

	while(src[i]){
		strcpy[i]=src[i];
		i++;
	}
	strcpy[i]='\0';
	return strcpy;
}

char *ft_strpbrk(const char *s1, const char *s2){

	int i =0;
	if(!s1 || !s2)
		return 0;
	while(*s1){
		while(s2[i]){
			if(*s1 == s2[i])
				return char *(s1)
			i++;
		}
		s1++;
	}
			return NULL;

}

char *strchr(char *accept , char a){
	while(*accept){
		if(*accept ==a)
			return (char * ) accept;
		accept++;
	}
	return 0;
}

size_t ft_strspn(const char *s, const char *accept){
	int i = 0;
	while(s[i]){

		if(strchr(accept,s[i])==0)	
			break;
		i++;
	}
	return i;

char *ft_strrev(char *str){
	int i = -1;
	int length = 0;
	char temp;
	while(str[length ])
		length++;
	while(++i <length/2){
		temp = str[i];
		str[i] = str[length-1-i];
		str[length-1-i]=temp;
	}
	return str;

}