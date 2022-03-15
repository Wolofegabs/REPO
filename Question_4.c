
#include <sys/types.h>

#include <md5.h>

#include <stdio.h>

#include <stdlib.h>



int main(int argc, char *argv[])

{

  char buffer[1000];

  if (argc != 2)
   {

	printf ("Le nombre de parametres n'est pas respecte");
  
	exit(1);
   }

else 
	{

		unsigned char *var=NULL;

		var=MD5File(argv[1], buffer);

		printf("le code MD5 est: %s %s \n", var, argv[1] );

	}


}


