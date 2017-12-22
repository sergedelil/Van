#include  <iostream>
#include  "BufrRecord.hpp"
#include  "BufrTables.hpp"
#include  "libecbufr/bufr_api.h"

BufrRecord::BufrRecord()
{
   message = NULL;
   dataset = NULL;
}

BufrRecord::BufrRecord( BUFR_Message *msg )
{
   std::cout << "Instantiated: BufrRecord\n";
   message = msg;
   dataset = NULL;
}

BufrRecord::~BufrRecord()
{
   std::cout << "Destroying BufrRecord\n" ;
   if (this->message) bufr_free_message( this->message );
   if (this->dataset) bufr_free_dataset( this->dataset );
}

int BufrRecord::getTableVersion()
{
   if (this->message)
      return this->message->s1.master_table_version ;
   else
      return -1;
}

int BufrRecord::decode()
{
   return decode( this->btl->use( getTableVersion() ) );
}
 
int BufrRecord::decode( BufrTablesList *tlist )
{
   return decode( tlist->use( getTableVersion() ) );
}
 
int BufrRecord::decode( BufrTables *tables )
{
   if (tables == NULL)
      {
      std::cout << "Cannot decode with NULL tables";
      return -1;
      }
   std::cout << "Decoding BufrRecord using table version:"  << tables->getVersion() << "\n" ;
   this->dataset = bufr_decode_message( this->message, tables->getTables());
   if (this->dataset == NULL)
      {
      std::cout << "Can't decode message\n" ;
      }
   return 0;
}

int BufrRecord::encode( bool compress )
   {
   if (this->dataset == NULL)
      {
      std::cout << "Warning: can't encode without dataset defined";
      return -1;
      }
   if (this->message) bufr_free_message( this->message );
   this->message = bufr_encode_message( this->dataset, compress?1:0 );
   return (this->message ? 0 : -1);
   }

void BufrRecord::print()
{
   bufr_print_message( this->message, bufr_print_output );
}

BUFR_Message * BufrRecord::getMessage()
   {
   return this->message;
   }

BUFR_Dataset * BufrRecord::getDataset()
   {
   return this->dataset;
   }

void BufrRecord::setMessage( BUFR_Message *msg )
{
   if (this->message) bufr_free_message( this->message );
   message = msg;
}

void BufrRecord::setDataset( BUFR_Dataset *dts )
{
   if (this->dataset) bufr_free_dataset( this->dataset );
   dataset = dts;
}

void BufrRecord::setTablesList( BufrTablesList *list )
   {
   btl = list;
   }

int BufrRecord::write( BufrFile *ds )
{
   std::cout << "   writing BufrRecord\n" ;
   if (this->message)
      bufr_write_message( ds->getFileStream(), this->message );
}

int BufrRecord::write( SQLiteFile *ds )
{
   std::cout << "I don't know how to save this record in SQLiteFile\n" ;
}
