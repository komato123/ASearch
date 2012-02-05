#ifndef SUFFIX_ARRAY_H_
#define SUFFIX_ARRAY_H_

#include <vector>
#include <string>
#include <algorithm>

namespace a_search
{

class SuffixArray
{
	struct WorkData {
		int	si;
		const char* p_head;
	};

	class CompareWorkData {
	public:
		bool operator()(const WorkData& lhs, const WorkData& rhs) const {

			const char* p_lhs = lhs.p_head;
			const char* p_rhs = rhs.p_head;
			for (; *p_lhs != '\0' && *p_rhs != '\0'; ++p_lhs, ++p_rhs) {
				if (*p_lhs < *p_rhs) return true;
				else if (*p_lhs > *p_rhs) return false;
			}
			return *p_lhs < *p_rhs;
		}
	};

public:

	int makeSuffixArray(const int str_size, const char* in_str, std::vector<int>& out_array) const
	{
		WorkData* p_wd = new WorkData[str_size];

		for (int i = 0; i < str_size; ++i) {
			p_wd[i].si		= i + 1;
			p_wd[i].p_head	= in_str + i;
		}

		std::sort(p_wd, p_wd + str_size, CompareWorkData());

		for (int i = 0; i < str_size; ++i) {
			out_array.push_back(p_wd[i].si);
		}

		delete p_wd;

		return 0;
	}
};

}

#endif
