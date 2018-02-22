#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <tuple>
#include <type_traits>

void insertArray(std::string & st, std::vector<uint8_t> & arr)
{
	auto p = st.data();
	arr.insert(arr.end(), p, p + st.size());
}

void insertArray(char*  st, std::vector<uint8_t> & arr)
{
	auto ptr = st;
	while(*ptr != '\0')
	{
		arr.push_back(*ptr);
		ptr = ptr + sizeof(char); 
	}
}

template<class T>
void insertArray(T & st, std::vector<uint8_t> & arr)
{
	uint8_t * t;
	t = reinterpret_cast<std::uint8_t*>(&st);
	
	arr.insert(arr.end(), t, t+sizeof(T));
}

uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed) 
{
	uint32_t h = seed;
	if (len > 3) 
	{
	    const uint32_t* key_x4 = (const uint32_t*) key;
	    size_t i = len >> 2;
	    do 
	    {
	      	uint32_t k = *key_x4++;
		    k *= 0xcc9e2d51;
		    k = (k << 15) | (k >> 17);
		    k *= 0x1b873593;
		    h ^= k;
		    h = (h << 13) | (h >> 19);
		    h = (h * 5) + 0xe6546b64;
	    } while (--i);
	    key = (const uint8_t*) key_x4;
	}
	if (len & 3) 
	{
	    size_t i = len & 3;
	    uint32_t k = 0;
	    key = &key[i - 1];
	    do 
	    {
	        k <<= 8;
	        k |= *key--;
	    } while (--i);
	    k *= 0xcc9e2d51;
	    k = (k << 15) | (k >> 17);
	    k *= 0x1b873593;
	    h ^= k;
	}
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return h;
}

class value
{
public:
	template<size_t k, class Tuple, typename std::enable_if_t<k==0>>
	static void consume(Tuple args, std::vector<uint8_t> & arr)
	{
		auto key = std::get<0>(args);
		insertArray(key, arr);

	}

	template<size_t k, class Tuple, typename std::enable_if_t<k!=0>>
	static void consume(Tuple args, std::vector<uint8_t> & arr)
	{
		auto key = std::get<k>(args); 
		insertArray(key, arr);
		consume<k-1>(args, arr);

	}
};

class MurmurHash
{
public:
	template<class Function>
	auto apply(Function & function)
	{
		return function();
	}

	template<typename Tuple>
	void hash(Tuple args)
	{	
		value m_value;

		m_value.consume<std::tuple_size<Tuple>::value>(args, m_array);
		murmur3_32(m_array.data(), m_array.size()* sizeof(uint8_t), 1000);
	}

private:
	
	std::vector<std::uint8_t> m_array;
};


int main()
{
	auto t = std::make_tuple(1, "abc");
	auto func = [&](){
		return t;	
	};
	MurmurHash m;
	auto tup = m.apply(func);
	m.hash(tup); 
}
