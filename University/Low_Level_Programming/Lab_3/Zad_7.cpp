#include <iostream>
using namespace std;

extern "C" __int64 for_1(int N);

int main() {
	 constexpr int N = 6;
	 int result = for_1(N);
	 cout << result << endl;
}
