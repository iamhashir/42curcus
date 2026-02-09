void 	inter(char*s1,char *21){

	int seen[255]={0};
	int i = 0;
	int j = 0;

	while(s1[i]){
		while(s2[j])
		{
			if(s1[i]==s2[j])
			{
				if(!seen[s1[i]])
				{
					write(1,seen[i],1);
					seen[s1[i]]=1;
				}
				break;
			}
			j++;
		}
		i++;
	}

}
