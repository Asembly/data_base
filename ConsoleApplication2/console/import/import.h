#include"../Header.h"

namespace database {
class Importer {
private:
    string names_           = {};
    string password_        = {};
    ifstream input_         = {};
    ofstream output         = {};
    int command_            = {};
    int indexer_            = {};
    string path_            = {};

    void checkPassword        ();
    void checkFile            ();
    void printAll             ();

public:
    void loop                 ();

    Importer  (string path);
    ~Importer                 ();
   
    };
}