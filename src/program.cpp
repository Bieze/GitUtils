#include <iostream>
#include <algorithm>
#include "include/create-repo.h"
#include "include/delete-repo.h"

using namespace std;

char* fetchCmdOption(char ** begin, char ** end, const string & option) {
    char ** itr = find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char ** begin, char ** end, const string& option) {
    return find(begin, end, option) != end;
}

int main(int argc, char * argv[]) {

    if (cmdOptionExists(argv, argv+argc, "help")) {
        cout << "GitUtils v0.1.6 usage:\n";
        cout << "   help                         Print this help message.\n";
        cout << "   create  [repository]         Create a new repository.\n";
        cout << "   delete  [repository]         Delete a repository.\n";
    }

    char * repo = fetchCmdOption(argv, argv + argc, "create");

    if (repo) {
        createRepo(repo);
    }

    char * todelrepo = fetchCmdOption(argv, argv + argc, "delete");

    if (todelrepo) {
        deleteRepo(todelrepo);
    }

    return 0;

}