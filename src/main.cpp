#include "config.h"
#include <iostream>
#include <cmds/createRepo.hpp>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {

    string project_name = string(PROJECT_NAME);
    string project_ver = string(PROJECT_VER);
    string project_hash = string(GIT_HASH);

    try {
        po::options_description desc(project_name + " v" + project_ver);
        desc.add_options()
            ("help,h", "Displays this help message")
            ("version,v", "Prints program version information")
            ("create,c", po::value<string>()->required()->value_name("REPO-NAME"), "Creates a new repository")
            ("delete,d", po::value<string>()->required()->value_name("REPO-NAME"), "Deletes a repository");

        po::variables_map vm;

        po::parsed_options parsed = po::command_line_parser(argc, argv).
            options(desc).
            allow_unregistered().
            run();
        po::store(parsed, vm);
        

        if(vm.count("help") || argc == 1) {
            cout << desc << "\n";
            cout << project_name + " Project Version: " + 
                project_ver << " Git hash: " << 
                project_hash << " C++ standard: " <<
                __cplusplus << "\n";
        } else if (vm.count("version")) {
            cout << project_name + " Project Version: " + 
                project_ver << " Git hash: " << 
                project_hash << " C++ standard: " <<
                __cplusplus << "\n";
        } else if (vm.count("create")) {
            gitCreateRepo(vm["create"].as<std::string>());
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