#ifndef _Bufr_Record_h_
#define  _Bufr_Record_h_

#include  <cstdio>
#include  <list>
#include "BufrFile.hpp"
#include "BufrTables.hpp"
#include "SQLiteFile.hpp"
#include "libecbufr/bufr_message.h"
#include "libecbufr/bufr_dataset.h"

class BufrRecord : public DataRecord {
   protected:
      BUFR_Message  *message;
      BUFR_Dataset  *dataset;
      BufrTablesList  *btl;
   public:
      BufrRecord();
      BufrRecord( BUFR_Message *msg );
      ~BufrRecord();

      void setMessage ( BUFR_Message *msg );
      BUFR_Message *getMessage();

      void setDataset (  BUFR_Dataset *dts );
      BUFR_Dataset *getDataset();

      void setTablesList( BufrTablesList *list );

      int decode();
      int decode( BufrTablesList *tlist );
      int decode( BufrTables *tbl );

      int  encode( bool compress );
      void print();

      int getTableVersion();
      virtual int write( BufrFile *ds );
      virtual int write( SQLiteFile *ds );
};

#endif
