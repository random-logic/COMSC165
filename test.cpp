#include <string>
using std::string;

struct TestStruct {
    int number;
    string name;
};

int main() {
    TestStruct test;
    test.name = "hello world";

    return 0;
}