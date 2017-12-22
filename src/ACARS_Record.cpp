#include  <iostream>
#include  "ACARS_Record.hpp"
#include  "SQLiteFile.hpp"
#include  "libecbufr/bufr_api.h"

ACARS_Record::ACARS_Record()
{
}

ACARS_Record::ACARS_Record( BUFR_Message *msg )
{
   std::cout << "Instantiated: ACARS_Record\n";
   this->setMessage( msg );
}

ACARS_Record::~ACARS_Record()
{
   std::cout << "Destroying ACARS_Record\n" ;
}

int ACARS_Record::write( SQLiteFile *ds )
{
   std::cout << "I don't know how to save ACARS_Record in SQLiteFile\n" ;
}
