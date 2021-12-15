#include "database.h"

database::database()
{
}

void database::openDB()
{
    std::ifstream database_file("example_database.json", std::ifstream::binary);
    //database_file >> dBase;

}

int database::readDB(char result)
{
    return 0;
}
