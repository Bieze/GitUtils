#include <iostream>
#include "global.h"
#include <sys/stat.h>
#include <io.h>
#include <string>
#include <filesystem>


using namespace std;

int deleteRepo(string repo) {

    struct stat info;
    string dirname = REPOSITORY_LOCATION + repo;
    if (stat(dirname.c_str(), &info) != 0) {
        cout << "Repository does not exist or name is not spelled correctly.";
    } else if( info.st_mode & S_IFDIR ) {
        filesystem::remove_all(dirname.c_str());
        cout << "Deleted repository" << dirname << endl;
    }

    return 0;
}