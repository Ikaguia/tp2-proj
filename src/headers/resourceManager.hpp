#ifndef HEADER_RESOURCEMANAGER
#define HEADER_RESOURCEMANAGER

#include <common.hpp>

namespace grupoBatata{
	template<typename T1, typename T2>
	struct TresourceManager{
		map<T1, shared_ptr<T2>> resources;
		bool exists(const T1 &key){ return resources.count(key); }
		shared_ptr<T2> get(const T1 &key){
			if(not resources.count(key)) resources[key] = shared_ptr<T2>{new T2(key)};
			return resources[key];
		}
		void clear(){
			if(resources.empty()) return;
			resources.clear();
		}
		void clearUnused(){
			if(resources.empty()) return;
			for(auto it = resources.begin(); it != resources.end(); ){
				if(it->ss.use_count() == 1) it = resources.erase(it);
				else it++;
			}
		}
	};
};


#endif//HEADER_RESOURCEMANAGER
