#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

namespace NamedPipe
{

using namespace boost::interprocess;

class Client
{
public:
	Client(std::string && sharedMemoryNameClient, std::string && sharedMemoryNameServer);
	void stop();

private:
	void read();

	std::string m_sharedClientName;
	std::string m_sharedServerName;
	shared_memory_object m_clientSharedMemory;
	shared_memory_object m_serverSharedMemory;

	
};
}//namespace NamedPipe