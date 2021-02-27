//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
using namespace std;
/*
class DBLinkedList -> head +
        -> tile+
    .size
    .find
    .add

class DBLinkedListItem
    -> prev
    -> next
    .value


               begin
    null <-> item1 <-> item2 <-> item3 <-> item4 <-> null
*/
template<typename T>
class DBLinkedItem {
public:
    DBLinkedItem* prev, *next;
    T value;

    DBLinkedItem(T v, DBLinkedItem* prevPtr, DBLinkedItem* nextPtr) {
        value = v;
        prev = prevPtr;
        next = nextPtr;
    }

    void updateNextPtr(DBLinkedItem* nextPtr) {
        next = nextPtr;
    }

    void updatePrevPtr(DBLinkedItem* prevPtr) {
        prev = prevPtr;
    }
};

template<typename T>
class DBLinkedList {
public:

    T get_element(int index) {
        return get_element_link(index) -> value;
    }

    void remove_back() {
        if (size == 1) {
            delete end;
            --size;
            return;
        }

        DBLinkedItem<T>* linkBefore = get_element_link(get_size() - 2);
        delete end;
        end = linkBefore;
        linkBefore->updateNextPtr(nullptr);
        --size;
    }

    void push_back(T value) {
        DBLinkedItem<T>* item = new DBLinkedItem<T>(value, end, nullptr);
        end->updateNextPtr(item);
        if (!size++) {
            begin = item;
        }
        end = item;
    }

    void insert(T value, int index) {
        if (index >= size || index < 1) {
            cout << "Fuck you!!!" << endl;
            return;
        }
        ++size;
        DBLinkedItem<T>* linkBefore = get_element_link(index-1);
        DBLinkedItem<T>* linkAfter = get_element_link(index);
        DBLinkedItem<T>* item = new DBLinkedItem<T>(value, linkBefore, linkAfter);
        linkBefore->updateNextPtr(item);
        linkAfter->updatePrevPtr(item);
    }

    void clear() {
        int s = get_size();
        for (int i = 0; i < s; ++i) {
            remove_front();
        }
    }

    void remove(int index) {
        if (index >= size || index < 1 && !size) {
            cout << "Poshel naher kozel!!!" << endl;
            return;
        }
        --size;
        DBLinkedItem<T>* linkBefore = get_element_link(index - 1);
        DBLinkedItem<T>* linkAfter = get_element_link(index + 1);
        delete get_element_link(index);
        linkBefore->updateNextPtr(linkAfter);
        linkAfter->updatePrevPtr(linkBefore);
    }

    void remove_front() {
        if (size==1) {
            delete begin;
            --size;
            return;
        }
        DBLinkedItem<T>* linkAfter = get_element_link(1);
        delete begin;
        begin = linkAfter;
        linkAfter->updatePrevPtr(nullptr);
        --size;
    }

    void push_front(T value){
        DBLinkedItem<T>* item = new DBLinkedItem<T>(value, nullptr, begin);
        begin->updatePrevPtr(item);
        if (!size++) {
            end = item;
        }
        begin = item;
    }

    int get_size() {
        return size;
    }

private:
    DBLinkedItem<T>* begin = (DBLinkedItem<T>*)malloc(sizeof(DBLinkedItem<T>));
    DBLinkedItem<T>* end = (DBLinkedItem<T>*)malloc(sizeof(DBLinkedItem<T>));
    int size;

    void update_last_end(DBLinkedItem<T>* item) {
        end->updateNextPtr(item);
    }
    void update_last_begin(DBLinkedItem<T>* item) {
        begin->updatePrevPtr(item);
    }

    DBLinkedItem<T>* get_element_link(int index) {
        DBLinkedItem<T>* link = begin;

        for (int i = 0; i < index; ++i) {
            link = link->next;
        }

        return link;
    }
};

int main() {
    DBLinkedList<int> tup;
    tup.push_back(1);
    tup.push_back(3);
    tup.push_back(4);
    cout << "Kill me please!!!" << endl;
    tup.push_front(0);
    tup.insert(2, 2);
    tup.clear();
    for (int i = 0; i < tup.get_size(); ++i) {
        cout << tup.get_element(i) << endl;
    }
    return 0;
}
