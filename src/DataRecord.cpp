#include <iostream>
using  namespace std;
#include <DataRecord.hpp>

DataRecord::DataRecord()
{
   cout << "Instantiated: DataRecord\n";
}

DataRecord::~DataRecord()
{
   cout << "Destroying: DataRecord\n";
}

int DataRecord::decode()
{
   cout << "Called DataRecord decode\n";
}

void DataRecord::print()
{
   cout << "Called DataRecord print\n";
}

int DataRecord::write( DataStorage *ds )
{
   cout << "DataRecord write to DataStorage not implemented\n";
}

int DataRecord::write( BufrFile *ds )
{
   cout << "DataRecord write to BufrFile not implemented\n";
}

int DataRecord::write( SQLiteFile *ds )
{
   cout << "DataRecord write to SQLiteFile not implemented\n";
}
