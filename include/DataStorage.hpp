#ifndef _Data_Storage_h_
#define _Data_Storage_h_

#include <exception>
#include "DataRecord.hpp"

class DataStorage : public std::exception {
   protected:
      char *location;
   public:
      DataStorage();
     ~DataStorage();

      void    setLocation( const char *fn );
      char   *getLocation();

      virtual DataRecord  *read( int *status ) = 0;
      virtual int          write( DataRecord  *r ) = 0;
      virtual int          open( const char *str1, const char *str2 ) = 0;
      virtual int          close() = 0;

};

#endif
