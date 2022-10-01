#include <iostream>
#include "global.h"
#include <sys/stat.h>
#include <io.h>
#include <string>
#include <filesystem>


using namespace std;



int deleteRepo(string repo) {

    struct stat info;
    string fulldir = REPOSITORY_LOCATION + repo;

    const char *dirname = fulldir.c_str();
    cout << dirname;
    if (stat(dirname, &info) != 0) {
        cout << "Repository does not exist or name is not spelled correctly.";
    } else if( info.st_mode & S_IFDIR ) {
        filesystem::remove_all(dirname);
    }

    return 0;
}