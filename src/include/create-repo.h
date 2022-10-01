#include <iostream>
#include <io.h>
#include "global.h"
#ifdef linux
#include <unistd.h>
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
    mkdir(dirname);
    chdir(dirname);
    system("git init --bare");
  


    return 0;
}