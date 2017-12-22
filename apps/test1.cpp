#include  <complex>
#include  <cstdio>
#include  <iostream>
#include  <DataFileStream.hpp>
#include  <BufrTables.hpp>
#include  <BufrRecord.hpp>
#include  <BufrFile.hpp>
#include  <SQLiteFile.hpp>
using namespace std;

#define  NB_TABLES 8

int main(int argc, char *argv[])
{
   DataFileStream   df;
   BufrTablesList   btlist;
   BufrTables     *tbl;
   BufrFile         bfi, bfo;
   DataRecord      *dr;
   BufrRecord      *br;
   SQLiteFile       sqlitef;
   int              status;

   int   tbnos[NB_TABLES] = { 28,27,25,23,19,18,14,13 };

   btlist.load( NULL, tbnos, NB_TABLES );

   tbl = btlist.use( 23 );
   if (tbl)
     std::cout << "Using BUFR Tables version:" << tbl->getVersion() << "\n" ;
   else
     std::cout << "Table not found\n" ;

   if (argc != 3)
      {
      cout << "Usage: pgm inputfile outputfile\n" ;
      exit(0);
      }

   if (bfi.open( argv[1], "r" ) >= 0 )
      {
      bfi.setTablesList( &btlist );
      bfo.open( argv[2], "w" );
      while (dr = bfi.read( &status ))
         {
         br = (BufrRecord *)dr;
//         dr->decode ();
//         br->decode ( &btlist );
//         br->write( &bfo );
           bfo.write( dr );
//         tbl = btlist.use( br->getTableVersion() );
 //        if (tbl)
//            br->decode( tbl );
//         dr->print();
         delete dr;
         }
      }

   bfi.close();
   bfo.close();
}
