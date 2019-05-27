#include <iostream>
#include <memory>


struct ShelfItem{
public:
    ShelfItem() {}
    ~ShelfItem() {
        std::cout << "shelfitem was freed" << std::endl;
    }
};

class Shelf{
private:
    ShelfItem* item1;
    ShelfItem* item2;
    ShelfItem* item3;
public:
    void reshelfInvert(){
        ShelfItem item1;
    }
    void reshelf() {
        std::unique_ptr<ShelfItem> sp1 = std::unique_ptr<ShelfItem>(item1);
        sp1 = std::unique_ptr<ShelfItem>(item2);
        sp1 = std::unique_ptr<ShelfItem>(item3);
        // sp1 = std::unique_ptr<int>(item2);
        // sp1 = std::unique_ptr<int>(item3);
    }
    void inventory(){
        std::cout << item1 << " " << item2 << " " << item3 << std::endl;
    }
    Shelf(): item1{new ShelfItem()}, item2{new ShelfItem()}, item3{new ShelfItem()} { }
    ~Shelf() { }
};

int main(){
    Shelf shelf;
    shelf.inventory();
    shelf.reshelf();
    shelf.inventory();
    shelf.reshelfInvert();
    std::cout << "done" << std::endl;
}