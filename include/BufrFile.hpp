#ifndef _Bufr_File_h_
#define  _Bufr_File_h_

#include  <cstdio>
#include  <list>
#include "BufrTables.hpp"
#include "DataFileStream.hpp"
#include "libecbufr/bufr_message.h"
#include "libecbufr/bufr_dataset.h"

class BufrFile : public DataFileStream {
   protected:
      BufrTablesList  *btl;
   public:
      BufrFile();
      ~BufrFile();

      virtual DataRecord  *read( int *status );
      virtual int write( DataRecord  *r );

      void setTablesList( BufrTablesList *list );
};

#endif
