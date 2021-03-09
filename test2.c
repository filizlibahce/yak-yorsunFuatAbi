int total_registration(char* course_code) {
	printf("deneme");
	FILE *fp;
	char line[1024] = "";
	char c;
	int len = 0;
	
	fp = open(LOGFILE,"r");
	fseek(fp, -1, SEEK_END);//next to last char, last is EOF
	c = fgetc(fp);
	
	// ilk satırlar için çalışmama durumu kontrolu
	for(int i = 0 ; i < 1 ; i ++) {
		if(fgets(line, LINESIZE, fp) == NULL) return SUCCESS;
	}
	
	while(c == '\n')
	{
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
	}

	while(c != EOL)
	{
		fseek(fp, -2, SEEK_CUR);
		++len;
		c = fgetc(fp);
	}

	fseek(fp, 1, SEEK_CUR);
	if (fgets(line, len, fp) != NULL) puts(line);
	else return FAIL;
	
	char *last_register = strtok(line,SEP);
	int total_register = last_register[0];
	fclose(fp);
	return total_register;

}
