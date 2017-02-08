// Program for converting hostnames or ip addresses into the form
// suitable for a PXE server.
// For example the IP address 10.10.10.10 would convert to 0A0A0A0A

#include <iostream>
#include <netdb.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
#include <time.h>
using namespace std;

void help() {
}

string ipToPXE(string ip) {
  vector<unsigned char> octets[4];
}


int main(int argc, char *argv[]) {
if(argc != 2)
  {
    printf("usage: %s <hostname>\n", argv[0], argv[1]);
    exit(1);
  }
    
  hostent * record = gethostbyname(argv[1]);
  if(record == NULL)
  {
    printf("%s is unavailable\n", argv[1]);
    exit(1);
  }
  in_addr * address = (in_addr * )record->h_addr;
  string ip_address = inet_ntoa(* address);

  // get the current time
  time_t rawtime;
  tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  
  cout << argv[1] << " (" << ip_address << ")\n";
  
  // log this information to ipaddr.log
  ofstream ipaddr_log("ipaddr.log", ios::app);
  ipaddr_log << (ptm->tm_hour) << ":" << (ptm->tm_min) << " " << argv[1] << " (" << ip_address << ")" << endl;
  ipaddr_log.close();
  return 0;
}

