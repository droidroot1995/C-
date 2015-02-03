#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char * argv[])
{
	DIR * dir;
	struct dirent * dirct;
	struct stat file;
	time_t ln;
	int size;

	if(argc < 2)
	{
		printf("Too few arguments!!!");
		exit(-1);
	}

	dir = opendir(argv[1]);
	if(NULL == dir)
	{
		printf("No such directory!!!");
		exit(-1);
	}

while((dirct = readdir(dir)) != NULL)
	{
		stat(dirct->d_name, &file);
		printf("File name is: %s\n", dirct->d_name);
		printf("File inode is: %d\n", (int)file.st_ino);
		//size = (int) file.st_blocks * (int) file.st_blksize;
		printf("File size is: %d\n", (int)file.st_size);
		printf("File uid is: %d\n", (int)file.st_uid);
		printf("File gid is: %d\n", (int)file.st_gid);
		ln = (time_t)file.st_mtime;
		printf("File time is: %s\n", ctime(&ln));
	}

	closedir(dir);
	return 1;
}
