#include <iostream>
#include <btree.hpp>

int main(int argc, char** argv) {
    (void)argc, (void)argv;

    WritableBNodeInterface* bnode = new BNodeImpl();
    bnode->Get();
    //bnode->Keys();
    //bnode->SetHeader(BNodeType::BNODE_LEAF, 2);
    //bnode->Type();
}