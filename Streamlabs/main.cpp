#include <boost/program_options.hpp>
#include "Server.h"
#include "Client.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
   /*boost::program_options::options_description desc{"Options"};
   desc.add_options()
      ("help,h", "Help screen")
      ("server", "Run as server")
      ("client", "Run as client");

   boost::program_options::variables_map vm;
   store(parse_command_line(argc, argv, desc), vm);
   notify(vm);

   if (vm.count("help"))
      std::cout << desc << '\n';
   else if (vm.count("server"))
      std::cout << "Server" << '\n';
   else if (vm.count("client"))
      std::cout << "Client" << '\n';*/

   NamedPipe::Client("ClientSharedMemory", "ServerSharedMemory");
   NamedPipe::Server("ServerSharedMemory", "ClientSharedMemory");


   
   return 0;
}