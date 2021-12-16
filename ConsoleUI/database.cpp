#include "database.h"
#include <iostream>

database::database()
{
}

void database::runDB()
{
    //Open database
    std::ifstream database_file("example_database.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(database_file, obj);

    //Read Node names
    const Json::Value& appkeys = obj["appKeys"];
    cout << "Network name: " << obj["meshName"].asString() << endl;
    cout << "This network contains " << appkeys.size() << " nodes" << endl;
    for (int i = 0; i < appkeys.size(); i++) {
        cout << "   NodeName " << i + 1 << ": " << appkeys[i]["name"].asString() << endl;
    }
}
