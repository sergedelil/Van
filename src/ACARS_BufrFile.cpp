#include  <iostream>
using namespace std;
#include  "DataRecord.hpp"
#include  "ACARS_Record.hpp"
#include  "ACARS_BufrFile.hpp"
#include  "libecbufr/bufr_api.h"

DataRecord *ACARS_BufrFile::read( int *status )
{
   ACARS_Record *r;
   BUFR_Message *msg;
 
   cout << "ACARS_BufrFile  reading()\n" ;  
   *status = bufr_read_message( this->getFileStream(), &msg );
   if (*status > 0 )
      {
      r = new ACARS_Record( msg );
      r->setTablesList( this->btl );
      return r;
      }
   else 
      return NULL;
}

int ACARS_BufrFile::write( DataRecord *dr )
{
   cout << "ACARS_BufrFile  calling DataRecord write...\n" ;  
   dr->write ( this );
}
