#include <string>
#include "config.h"
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

int listKeys() {
    if (!fs::exists(repohome)) {
        fs::create_directory(repohome);
    }
    for (const auto & entry : fs::directory_iterator(string(repohome)))
        cout << fs::canonical(entry.path()) << endl;

    return 0;
}
