#include <iostream>
#include <io.h>
#include "global.h"
#ifdef __linux__
#include <unistd.h>
#include <sys/stat.h>
#endif

using namespace std;

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

int createRepo(string repo) {
    cout << "Created repo " << repo << "\n";
    const char *location = REPOSITORY_LOCATION.c_str();
    chdir(location);

    const char *dirname = repo.c_str();
    #ifdef __linux__
        mkdir(dirname, 777);
    #else
        mkdir(dirname);
    #endif
    chdir(dirname);
    system("git init --bare");
  


    return 0;
}