#include  <iostream>
using namespace std;
#include  <BufrRecord.hpp>
#include  <BufrFile.hpp>
#include  "libecbufr/bufr_api.h"

BufrFile::BufrFile()
{
   btl = NULL;
}

BufrFile::~BufrFile()
{
}

void BufrFile::setTablesList( BufrTablesList *list )
   {
   btl = list;
   }

DataRecord *BufrFile::read( int *status )
{
   BufrRecord *r;
   BUFR_Message *msg;
 
   cout << "BufrFile  reading()\n" ;  
   *status = bufr_read_message( this->getFileStream(), &msg );
   if (*status > 0 )
      {
      r = new BufrRecord( msg );
      r->setTablesList( this->btl );
      return r;
      }
   else 
      return NULL;
}

int BufrFile::write( DataRecord *dr )
{
   cout << "BufrFile  calling DataRecord write...\n" ;  
   dr->write ( this );
}
