#ifndef  _SQLite_File_h_
#define  _SQLite_File_h_

#include  <exception>
#include  <cstdio>
#include  <DataStorage.hpp>
#include  <sqlite3.h>
#include  <string>

class SQLiteFile : public DataStorage {
   protected:
      sqlite3   *db;
      std::list<std::string *> dbinit_stmts;
   public:
      SQLiteFile();
      ~SQLiteFile();

      int                 open( const char *filename, const char *mode );
      int                 close();
      virtual DataRecord *read( int *status );
      virtual int         write( DataRecord *br );

      void        add_dbInit_stmts( const char *stmt );
};

#endif
