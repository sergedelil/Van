#ifndef _ACARS_Bufr_File_h_
#define  _ACARS_Bufr_File_h_

#include  <cstdio>
#include  <list>
#include "BufrTables.hpp"
#include "DataFileStream.hpp"
#include "libecbufr/bufr_message.h"
#include "libecbufr/bufr_dataset.h"

class ACARS_BufrFile : public BufrFile {
   public:
// overload  read and write to use ACARS_Record 
      DataRecord  *read( int *status );
      int write( DataRecord  *r );
};

#endif
