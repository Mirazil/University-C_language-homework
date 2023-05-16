#include <iostream>
#include <string>

class Tree {
public:
    virtual void draw() const = 0;
};

class ChristmasTree : public Tree {
public:
    void draw() const override {
        std::cout << "  /\\\n //\\\\\n////\\\\\\n";
    }
};

class PineTree : public Tree {
public:
    void draw() const override {
        std::cout << "  /\\\n /**\\\n";
    }
};

class LeaflessTree : public Tree {
public:
    void draw() const override {
        std::cout << "  / \\\n/++\\\n";
    }
};

int main() {
    Tree* trees[3];
    trees[0] = new ChristmasTree();
    trees[1] = new PineTree();
    trees[2] = new LeaflessTree();

    for (int i = 0; i < 3; i++) {
        std::cout << "Drawing " << (i + 1) << ":\n";
        trees[i]->draw();
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++) {
        delete trees[i];
    }

    return 0;
}
