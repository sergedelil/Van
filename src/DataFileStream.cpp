#include  <iostream>
using namespace std;
#include  <cstdlib>
#include  <cstring>
#include  <DataFileStream.hpp>

DataFileStream::DataFileStream()
   {
   cout << "Instantiating DataFileStream\n" ;
//   this->set_location( NULL );
   this->fp = NULL;
   }

DataFileStream::~DataFileStream()
   {
   cout << "Destroying DataFileStream:" << this->getLocation() << "\n" ;
   if (this->fp)
      this->close();
   }

FILE *DataFileStream::getFileStream() 
{
   return this->fp;
}

int DataFileStream::open( const char *fname, const char *modestr )
{
   this->setLocation( fname );
   this->fp = fopen( fname, modestr );

   cout << " opened:" << fname << "\n" ;
   if (this->fp == NULL)
      return -1;
   else
      return 0;
}

int DataFileStream::close()
   {
   if (this->fp)
      {
      fclose( this->fp );
      this->fp = NULL;
      cout << " closed:" << this->getLocation() << "\n" ;
      }
   }

DataRecord * DataFileStream::read( int *status )
{
   cout << "DataFileStream  read()\n" ;
}

int DataFileStream::write( DataRecord *br )
{
   cout << "DataFileStream  write()\n" ;
}
