#include <Client.h>

namespace NamedPipe
{

Client::Client(std::string && sharedMemoryNameClient, std::string && sharedMemoryNameServer) :
	m_sharedClientName(std::move(sharedMemoryNameClient)),
	m_sharedServerName(std::move(sharedMemoryNameServer))
{
	shared_memory_object::remove(m_sharedClientName);
	m_clientSharedMemory(open_or_create, m_sharedClientName, read_write);
	m_serverSharedMemory(open_or_create, m_sharedServerName, read);
}

void sendCommand(std::string && command)
{
	int comm;
	//Set of commands
	mapped_region region{m_clientSharedMemory, read_write};
   	std::memset(region.get_address(), comm, sizeof(comm));
}

void Client::read()
{
	mapped_region region{m_serverSharedMemory, read_only};
  	int *i2 = static_cast<int*>(region.get_address());
 	//Do something with the data
}


void Client::stop()
{
	shared_memory_object::remove(m_sharedClientName);	
}


}//namespace NamedPipe