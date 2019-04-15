#include <stdio.h>
#include <dirent.h>
#include <string.h>

void goThroughPath(const char* path)
{
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("null dir path %s\n", path);
        return;
    }
    struct dirent* ptr = NULL;
    while ((ptr = readdir(dir)) != NULL) {
        if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0)) {
            continue;
        }
        else if (ptr->d_type == 4) {
            printf("dir: %s\n", ptr->d_name);
        }
        else {
            printf("file: %s\n", ptr->d_name);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("please input dir path!\n");
        return 0;
    }
    goThroughPath(argv[1]);
    return 0;
}
