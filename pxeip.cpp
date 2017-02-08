// Program for converting hostnames or ip addresses into the form
// suitable for a PXE server.
// For example the IP address 10.10.10.10 would convert to 0A0A0A0A

#include <iostream>
#include <netdb.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
using namespace std;

void help() {
}

const long iptoi(const string& s)
{
  string buff{""};
  long addr = 0;
 
  for(auto n:s)
  {
    if(n != '.') buff+=n; else
    if(n == '.' && buff != "") { addr = (addr * 256) + stoi(buff); buff = ""; }
  }
  if(buff != "") addr = (addr * 256) + stoi(buff);
 
  return addr;
}


int main(int argc, char *argv[]) {
  hostent * record = gethostbyname(argv[1]);
  if(record == NULL)
  {
    printf("%s is unavailable\n", argv[1]);
    exit(1);
  }
  in_addr * address = (in_addr * )record->h_addr;
  string ip_address = inet_ntoa(* address);
  long ip = iptoi(ip_address);

  cout << hex << uppercase << ip << "\n";
  
  return 0;
}

