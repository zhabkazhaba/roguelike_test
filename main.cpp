#include "src/Utility/jsonMaker/jsonMaker.h"
#include "src/Utility/Parser.h"
int main() {
    Parser test(readMode::NPC, "test");
    test.parse();
    return 0;
}