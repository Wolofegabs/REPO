#include <sys/types.h>

#include <md5.h>

#include <stdio.h>

#include <stdlib.h>



int main(int argc, char *argv[])

	{

	     char fich[1000];

	     char buffer[1000];

	     unsigned char * var=NULL;


	     int i=1;
	     
while (i<=1000)
	     
{

		printf("Nom du fichier (%d) : ", i+1);

		scanf("%s",fich);
var=MD5File(fich, buffer);

		printf("le code MD5 est: %s %s \n", var, fich );
		
i=i+1;

	     }

	
} 
