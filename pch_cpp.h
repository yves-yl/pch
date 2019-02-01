#ifndef __PCH_CPP__
#define __PCH_CPP__

#include <iostream>
#include <fstream>
#include <sstream>


#include <vector>
#include <list>
#include <tuple>
#include <deque>
#include <map>
#include <unordered_map>


#include <mutex>
#include <thread>
#include <chrono>
#include <functional>
#include <future>
#include <iomanip>


#include <memory>

#include <cstring>
#include <cstdlib>
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <cerrno>
#include <cctype>


#define _toStr_(str)  std::string(#str)

using std::cout;
using std::cin;
using std::stringstream;
using std::endl;
using std::fstream;
using std::string;
using std::toupper;
using std::tolower;
using std::to_string;
using std::stoi;
using std::stol;
using std::stof;
using std::stod;

using std::vector;
using std::list;
using std::tuple;
using std::unordered_map;
using std::deque;

using std::mutex;
using std::lock_guard;

using std::shared_ptr;
using std::function;
using std::thread;
using std::future;
using std::promise;
using std::async;
using std::packaged_task;
using std::enable_shared_from_this;

using namespace std::placeholders;

template<std::size_t... I>
std::vector<std::size_t> make_index_vector(std::index_sequence<I...>){
	return {I...};
}

template<int N>
inline std::vector<std::size_t> range(){
	return make_index_vector(std::make_index_sequence<N>());
}

template<class T>
class CSingleton{
public:
	static T* getInstance(){
		if(nullptr == self){
			mtx.lock();
			if(nullptr == self)
				self = new  CSingleton<T>();
			mtx.unlock();
		}
		return &(self->instance_);
	}
private:
	CSingleton() {};
private:
	T instance_ ;
	static CSingleton<T>* self ;
	static std::mutex mtx;
};
template<class T>
CSingleton<T>* CSingleton<T>::self= nullptr;

#endif // __PCH_CPP__