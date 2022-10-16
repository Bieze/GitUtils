#include <io.h>
#include <string>
#include <cctype>
#include "config.h"
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;


int removeRepo(string repoName) {
    if (!fs::exists(string(repohome) + repoName)) {
        cout << "The repository `" + string(repohome) + repoName + "` does not exist, did you mean gitutils --create?";
    } else if (fs::exists(string(repohome) + repoName)) {
        
        if (Backup == true) {
            if (!fs::exists(string(BACKUPS_DIR))) {
                fs::create_directories(string(BACKUPS_DIR));
                fs::copy(string(repohome) + repoName, string(BACKUPS_DIR) + repoName, fs::copy_options::recursive);
                fs::remove_all(string(repohome) + repoName);
                cout << "Copied repository to `" + string(BACKUPS_DIR) + repoName + "` and removed it from `" + string(repohome) << endl;
            } else if (fs::exists(string(BACKUPS_DIR))) {
                if (fs::exists(string(BACKUPS_DIR) + repoName)) {

                        int i = 0;
                        while(i < 1) {
                            char inp;
                            cout << "A folder with the name `" + repoName + "` already exists, do you want to replace it ? [Y/N] ";
                            cin >> inp;
                            if(toupper(inp) == 'Y') {
                                fs::remove_all(string(BACKUPS_DIR) + repoName);
                                fs::copy(string(repohome) + repoName, string(BACKUPS_DIR) + repoName, fs::copy_options::recursive);
                                fs::remove_all(string(repohome) + repoName);
                                i = 2;
                                cout << "Copied repository to `" + string(BACKUPS_DIR) + repoName + "` and removed it from `" + string(repohome) << endl;
                            } else if (toupper(inp) == 'N') {
                                string newName;
                                cout << "Please enter a new name for the folder: ";
                                cin >> newName;

                                fs::copy(string(repohome) + repoName, string(BACKUPS_DIR) + newName, fs::copy_options::recursive);
                                fs::remove_all(string(repohome) + repoName);
                                i = 2;
                                cout << "Copied repository to `" + string(BACKUPS_DIR) + newName + "` and removed it from `" + string(repohome) << endl;
                            } else {
                                cout << "Please answer with Y or N.";
                                i = 0;
                            }
                        }
                    
                } else {
                    fs::copy(string(repohome) + repoName, string(BACKUPS_DIR) + repoName, fs::copy_options::recursive);
                    fs::remove_all(string(repohome) + repoName);
                }
            } else {
                cout << "Unknown error encountered.";
            }
        } else if (Backup == false) {
            fs::remove_all(string(repohome) + repoName);
            cout << "Deleted `" + string(repohome) + repoName + "`" << endl;
        }
    } else {
        cout << "Unknown error encountered.";
    }
}