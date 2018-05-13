#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

namespace NamedPipe
{

using namespace boost::interprocess;

class Server
{
public:
	Server(std::string && sharedMemoryNameServer, std::string && sharedMemoryNameClient);
	void stop();

private:
	void read();
	void handleCommand(int command);

	std::string m_sharedServerName;
	std::string m_sharedClientName;
	shared_memory_object m_serverSharedMemory;
	shared_memory_object m_clientSharedMemory;

	
};
}//namespace NamedPipe