#include <cstring>
#include <cstdlib>
#include <iostream>
#include <DataStorage.hpp>
using  namespace std;

DataStorage::DataStorage()
{
   this->location = NULL;
   cout << "Instantiated: DataStorage\n";
}

DataStorage::~DataStorage()
{
   cout << "Destroying: DataStorage\n";
   setLocation( NULL );
}

void  DataStorage::setLocation( const char *fn ) 
{
   cout << "DataStorage::setLocation\n";
   if (this->location) free( this->location );
   if (fn)
      this->location = strdup( fn );
   else
      this->location = NULL;
}

char *DataStorage::getLocation()
{
   return this->location;
}

DataRecord  *read( int *status )
{
   cout << "DataStorage::read\n";
}


int  write( DataRecord  *r )
{
   cout << "DataStorage::write\n";
}

