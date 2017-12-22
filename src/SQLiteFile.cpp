#include  <iostream>
using namespace std;
#include  <BufrRecord.hpp>
#include  <SQLiteFile.hpp>
#include  "libecbufr/bufr_api.h"

SQLiteFile::SQLiteFile()
{
   db = NULL;
}

SQLiteFile::~SQLiteFile()
{
   if (db) close();
}

int SQLiteFile::open( const char *filename , const char *mode )
   {
   int rc;

   setLocation( filename );
   rc = sqlite3_open( filename, &db);
//   if (rc==0)
//   error=(string)sqlite3_errmsg(db);
   return rc;
   }

int SQLiteFile::close()
   {
   sqlite3_close( db );
   }

void  SQLiteFile::add_dbInit_stmts( const char *stmt )
   {
   string *str;
   str = new string( stmt );
   dbinit_stmts.push_back( str );
   }

DataRecord *SQLiteFile::read( int *status )
   {
   cout << "SQLiteFile read  not implemented\n" ;  
   return NULL;
   }

int SQLiteFile::write( DataRecord *dr )
{
   cout << "SQLiteFile calling DataRecord  write()\n" ;  
   dr->write( this );
}
