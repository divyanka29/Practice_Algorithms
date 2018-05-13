#include <Server.h>


namespace NamedPipe
{

using namespace boost::interprocess;

Server::Server(std::string && sharedMemoryNameServer, std::string && sharedMemoryNameClient) :
	m_sharedServerName(std::move(sharedMemoryNameServer)),
	m_sharedClientName(std::move(sharedMemoryNameClient))
	{

        shared_memory_object::remove(m_sharedServerName);
		m_serverSharedMemory(open_or_create, m_sharedServerName, read_write);
		m_clientSharedMemory(open_or_create, m_sharedClientName, read);
	}

void Server::handleCommand(int command)
{
	//various commands and write to m_serverSharedMemory
}


void Server::read()
{
	mapped_region region{m_clientSharedMemory, read_only};
  	int *i2 = static_cast<int*>(region.get_address());
  	handleCommand(*i2);
} 




void Server::stop()
{
	shared_memory_object::remove(m_sharedServerName);	
}

}//namespace NamedPipe