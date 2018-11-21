#ifndef HPP_DATA
#define HPP_DATA

#include <common.hpp>

namespace grupoBatata{
	struct data{
		uint dia, mes, ano;
		uint idade() const;
		bool operator<(const data&) const;
		static data hoje();
	};
};

#endif//HPP_DATA
