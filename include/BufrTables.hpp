#ifndef _Bufr_Tables_h_
#define  _Bufr_Tables_h_

#include  <cstdio>
#include  <list>
#include "libecbufr/bufr_tables.h"

class BufrTables {
   protected:
      BUFR_Tables *tables;
   public:
      BufrTables( BUFR_Tables * );
      ~BufrTables();
      BUFR_Tables  *getTables();
      int getVersion();
};

class BufrTablesList {
   protected:
      std::list<BufrTables *> list;

   public:
      BufrTablesList();

      ~BufrTablesList();

      int load( const char *path, int tbnos[], int nb );
      void merge( BufrTables *tblm );
      BufrTables *use( int version );
};

#endif
