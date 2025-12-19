#include <stdlib.h>
#include <unistd.h>

int process_input(char *input)
{
	int len = 0;

	while(input[len])
		len++;
	
	
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
}
