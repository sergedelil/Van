#include   <iostream>
#include   <sys/stat.h>
//#include   <cstdio>
#include   <stdio.h>
#include   <cstdlib>
#include   <cstring>
#include   <BufrTables.hpp>

using namespace std;


BufrTables::BufrTables( BUFR_Tables *tbls )
   {
   this->tables = tbls;
   }


BufrTables::~BufrTables()
   {
   bufr_free_tables( tables );
   }

BUFR_Tables  *BufrTables::getTables()
   {
   return tables;
   }

int BufrTables::getVersion()
   {
   return tables->master.version;  
   }


BufrTablesList::BufrTablesList()
   {
   cout  << "Instantiated: BufrTablesList\n" ;
   }

BufrTablesList::~BufrTablesList()
   {
   cout  << "Destroyed: BufrTablesList\n" ;
   }


int BufrTablesList::load( const char *path, int tbnos[], int nb )
   {
   char        *env;
   char         filename[512];
   int          rtrnB, rtrnD;
   BufrTables  *tbls;
   BUFR_Tables *tables;
   int          version;
   int          i, tb, cnt;
   struct       stat buf;

   if (path == NULL)
      {
      env = getenv( "BUFR_TABLES" );
      if (env == NULL) return -1;
      path = env;
      }

   cnt = 0;
   for (i = 0; i < nb ; i++)
      {
      tb = tbnos[i];
      tables = bufr_create_tables();
      std::sprintf( filename, "%s/table_b_bufr-%d", path, tb );
      cout << "Loading: " << filename ;
      if( stat(filename,&buf) == 0 )
         if ( !S_ISDIR( buf.st_mode ) )
            {
            rtrnB = bufr_load_m_tableB( tables, filename );
            if (tables->master.version < 0)
               tables->master.version = tb;
            cout << " version=" << tables->master.version << "\n";
            }
      sprintf( filename, "%s/table_d_bufr-%d", path, tb );
      cout << "Loading: " << filename << "\n" ;
      if( stat(filename,&buf) == 0 )
         if ( !S_ISDIR( buf.st_mode ) )
            {
            rtrnD = bufr_load_m_tableD( tables, filename );
            }

      if (!bufr_table_is_empty( tables))
         {
         tbls = new BufrTables(tables);
         list.push_back( tbls );
         ++cnt;
         }
      else
         bufr_free_tables( tables );
      }

   cout << "BUFR Tables List contains: " << list.size() << "\n" ;
   return cnt;
   }

BufrTables * BufrTablesList::use( int version )
   {
   BufrTables  *btn = NULL;
   BufrTables  *ltn = NULL;
   int           lv, bv;
   int           tversion;

   cout << "Looking for version:" << version << "\n" ;

   for ( BufrTables *tbls : this->list ) {
//      cout << "Table version:" << tbls->master.version << "\n";
      tversion = tbls->getVersion();
      if (tversion == version) return tbls;
      if (tversion > version)
         {
         if (btn == NULL)  
            {
            bv = tversion;
            btn = tbls;
            }
      // use the latest version 
         else if (bv < tversion)
            {
            bv = tversion;
            btn = tbls;
            }
         }
      else if ( ltn == NULL )
         {
         lv = tversion;
         ltn = tbls;
         }
      else if (lv < tversion)
         {
         lv = tversion;
         ltn = tbls;
         }
      }
   // use latest version if no better version can be found
   if (btn == NULL) btn = ltn;

   return btn;
   }

void BufrTablesList::merge ( BufrTables *tblm )
   {
//      bufr_merge_tables( tbl, tblm );
   }

