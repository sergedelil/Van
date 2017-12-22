#ifndef _Data_Record_h_
#define _Data_Record_h_

// forward declarations
class DataStorage;
class BufrFile;
class SQLiteFile;

class DataRecord {
   protected:
      void *data;
   public:
      DataRecord();
      virtual ~DataRecord();

      virtual int   write( DataStorage * );
      virtual int   write( BufrFile *ds );
      virtual int   write( SQLiteFile *ds );
      virtual int   decode();
      virtual void  print();

      void *get_data() { return this->data; };
      void  set_data(void *ptr) { this->data = ptr; };
};


#endif
