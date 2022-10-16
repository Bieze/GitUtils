#include <io.h>
#include <string>
#include "config.h"
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

int gitCreateRepo(string repoName) {
    try {
        if (!fs::exists(string(repohome))) {
            fs::create_directory(string(repohome));
            fs::create_directory(string(repohome) + repoName);
            string initCmd = "git init --bare " + string(repohome) + repoName;
            system(initCmd.c_str());
        } else if (fs::exists(string(repohome) + repoName)) {
            cout << "The repository `" + repoName + "` already exists" << endl;
        } else if (!fs::exists(string(repohome) + repoName)) {
            fs::create_directory(string(repohome) + repoName);
            string initCmd = "git init --bare " + string(repohome) + repoName;
            system(initCmd.c_str());
        } else {
            cout << "Unknown error encountered." << endl;
        }
    }

    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}