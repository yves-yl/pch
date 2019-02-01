
#ifndef __PCH_UTIL__
#define __PCH_UTIL__
#include "./pch_cpp.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


template<typename T>
T bytes2T(unsigned char *bytes) {
	T res = 0;
	int n = sizeof(T);
	memcpy(&res, bytes, n);
	return res;
}

template<typename T>
auto T2bytes(T u)->std::shared_ptr<unsigned char> {
	int n = sizeof(T);
	auto share_buf = std::shared_ptr< unsigned char>(new (std::nothrow) unsigned char[n],
													 [](unsigned char* ptr){
														 delete [] ptr;
														 printf("del addr : %ld\n",ptr);
														 ptr = nullptr;
													 });
	if(auto ptr_buf = share_buf.get()){
		printf("new addr : %ld\n",ptr_buf);
		memcpy(ptr_buf, &u, n);
	}


	return share_buf;
}

void printLIst(ListNode* node){

	while(node){

		cout << std::right << std::setw(4) << node->val<<"\t";
		node = node->next;
	}
	cout <<endl;
}
//
//
//
//ListNode* reverse_node(ListNode* node){
//
//	ListNode* prevNode = nullptr;;
//	ListNode* curNode = node;
//	ListNode* nextNode = nullptr;
//
//	while(curNode){
//		nextNode = curNode->next;
//		curNode->next = prevNode;
//		prevNode = curNode;
//		curNode =  nextNode;
//
//	}
//
//
//	return prevNode;
//}


template<class PodType, class Allocator>
void printVec(std::vector<PodType, Allocator>& Vec,bool toInt = false) {

	size_t index = 0;
	for (auto element : Vec) {
		if(toInt)
			cout << std::right << std::setw(4) << index << " : " << std::right << std::setw(10) << "[" <<(uint32_t)element << "]" << endl;
		else
			cout << std::right << std::setw(4) << index << " : " << std::right << std::setw(10) << "[" <<element << "]" << endl;
		++index;
	}
}
template<class Type>
std::string getTypeName() {
	return  typeid(Type).name();
}

template<class Type>
std::string getTypeName(Type && type) {
	return  typeid(Type).name();
}

#define printTypeName(f)	do{cout << #f << "\t: " << getTypeName<f>() << endl;}while(0);
#define printTypeName2(f)	do{cout << #f << "\t: " << getTypeName<>(f) << endl;}while(0);



//递归终止函数
template<typename T>
void format_expand(std::stringstream & ss,std::string& fmt, std::string::size_type index, T end)//递归到最后一次，调用单参数函数
{
	ss.clear();
	std::string str;
	ss << end;
	ss >> str;

	for (auto i = index; i < fmt.size(); ++i) {

		if (fmt.at(i) == '?') {
			fmt.replace(i, 1, str);
			break;
		}

	}


}


//int gcd(int a,int b){
//
//	int temp;
//	while(b != 0){
//
//		temp = a % b;
//		a = b;
//		b = temp;
//	}
//
//	return a;
//}

//递归调用函数
template<typename T, class ...Args>
void format_expand(std::stringstream & ss,std::string& fmt,std::string::size_type index,T head, Args... rest)
{

	ss.clear();
	std::string str;
	ss << head;
	ss >> str;

	for (auto i = index; i < fmt.size(); ++i) {

		if (fmt.at(i) == '?') {

			fmt.replace(i, 1, str);
			print_expand(ss,fmt, i + 1, rest...);
			break;

		}

	}

}

//调用函数
template<class ...Args>
std::string getFormatStr(std::string fmt, Args... rest)
{

	std::stringstream ss;
	format_expand(ss,fmt,0, rest...);

	return fmt;


}

template<int N>
class aTMP{
public:
	//enum:size_t { ret = N + aTMP<N-1>::ret };
	static const size_t ret = N + aTMP<N-1>::ret;

};
template<>
class aTMP<0>{
public:
	//enum:size_t { ret = 1 };
	static const size_t ret = 1;
};
#endif __PCH_UTIL__