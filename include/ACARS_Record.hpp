#ifndef _ACARS_Record_h_
#define  _ACARS_Record_h_

#include  <cstdio>
#include  <list>
#include "BufrRecord.hpp"
#include "BufrFile.hpp"
#include "BufrTables.hpp"
#include "SQLiteFile.hpp"
#include "libecbufr/bufr_message.h"
#include "libecbufr/bufr_dataset.h"

class ACARS_Record : public BufrRecord {
   public:
      ACARS_Record();
      ACARS_Record(BUFR_Message *msg);
      ~ACARS_Record();
// overloading write for ACARS  in SQLite
      int write( SQLiteFile *ds );
};

#endif
