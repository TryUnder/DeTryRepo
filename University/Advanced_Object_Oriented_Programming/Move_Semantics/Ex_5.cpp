struct A{
    A() = default;

    A(int x) {}
};

int main() {
    A a, b(1);
}