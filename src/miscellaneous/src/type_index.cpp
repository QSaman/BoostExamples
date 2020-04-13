#include <boost/type_index.hpp>
#include <iostream>
#include <vector>

template<typename T>
void f1(const T& param)
{
	using boost::typeindex::type_id_with_cvr;
	std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;	//const int*
	std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;	//const int* const&
}

template<typename T>
void f2(T&& param)
{
	using boost::typeindex::type_id_with_cvr;
	std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;	//const int*
	std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;	//const int*&&
}

int main()
{
	const std::vector<int> v(2, 7);
	f1(&v[0]);	//Note that operator & retunrs an rvalue, so lvalue reference should be const; otherwise it's syntax error
	f2(&v[0]);
}
