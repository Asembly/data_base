#include"import/import.h"
using namespace database;

int main()
{
    setlocale(LC_ALL,"");
    Importer database("console/database/data.txt");
    database.loop();
    return 0;
}