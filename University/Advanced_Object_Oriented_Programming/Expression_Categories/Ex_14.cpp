class B;

B& boo() {
    return *static_cast<B*>(0);
}

int main() {
    &boo(); // Zadziała. "boo()" jest l-wartością
    //B(); 

    /*
    Wyrażenia niekompletnych typów mogą być tylko l-wartościami, co za tym idzie,
    r-wartości mogą być tylko kompletnych typów.
    Wyrażenie "B()" się nie skompiluje, bo bo jest r-wartością, a klasa "B" jest niekompletna.
    */
}