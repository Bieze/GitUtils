#include <iostream>
#include <io.h>
#include "global.h"
#include <string.h>

using namespace std;

int createRepo(string repo) {
    cout << "Created repo " << repo << "\n";

    string dir = REPOSITORY_LOCATION + repo;
    system(("git init --bare "+dir).c_str());

    return 0;
}