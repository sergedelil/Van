#ifndef _Data_File_Stream_h_
#define  _Data_File_Stream_h_

#include  <cstdio>
#include  <DataStorage.hpp>

class DataFileStream : public DataStorage {
   protected:
      FILE *fp;
   public:
      DataFileStream();
      ~DataFileStream();

      int          open( const char *filename, const char *mode );
      int          close();
      DataRecord  *read( int *status );
      int          write( DataRecord  *r );
      FILE        *getFileStream();
};

#endif
