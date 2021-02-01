
#include "../include/my_cp_command.h"

int my_cp_command (int argc , char **argv)
{
	if (argc < 3)
		return 1;

	int fdSrcFile = open(argv[1] , O_RDONLY);
	if (fdSrcFile == -1)
	{
		return 2;
	}

	int fdDstFile = open(argv[2] , O_CREAT | O_WRONLY , S_IRUSR | S_IWUSR);
	if (fdDstFile == -1)
	{
		return 3;
	}

	char buffer[2];
	ssize_t charCount;

	while ((charCount = read(fdSrcFile , buffer , sizeof(buffer))) !=0 )
	{
		write(fdDstFile , buffer , charCount);
	}

    return 0;
}
