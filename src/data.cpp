#include <data.hpp>

namespace grupoBatata{
	uint data::idade() const{
		time_t epoch_now = time(nullptr);
		tm* now = localtime(&epoch_now);
		if(uint(now->tm_mon) < mes or (uint(now->tm_mon) < mes and uint(now->tm_wday) < dia)) return now->tm_year - ano - 1;
		return now->tm_year - ano;
	}
};
