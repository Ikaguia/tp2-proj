#include <data.hpp>

namespace grupoBatata{
	uint data::idade() const{
		time_t epoch_now = time(nullptr);
		tm* now = localtime(&epoch_now);
		if(uint(now->tm_mon) < mes or (uint(now->tm_mon) < mes and uint(now->tm_wday) < dia)) return now->tm_year - ano - 1;
		return now->tm_year - ano;
	}
	bool data::operator<(const data &v) const{
		if(ano != v.ano) return ano < v.ano;
		if(mes != v.mes) return mes < v.mes;
		return dia < v.dia;
	}
	data data::hoje(){
		time_t epoch_now = time(nullptr);
		tm* now = localtime(&epoch_now);
		return data{uint(now->tm_wday), uint(now->tm_mon), uint(now->tm_year)};
	}
};
