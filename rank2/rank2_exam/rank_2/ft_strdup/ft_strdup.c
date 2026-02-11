char *ft_strdup(char *src){
	
	int i = 0;
	int length = 0;
	char *strcpy;
	char *strcp;

	while(src[length])
		length++;
	strcpy = malloc(sizeof(char)*length +1);
	strcp=strcpy;
	while(*src){
		*strcpy++ = *src++;
	}
	strcpy='\0';

	return strcp;
}