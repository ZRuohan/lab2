#include "intbst.h"

int main() {
    IntBST t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    
    cout << "pre "; t.printPreOrder(); cout << endl;
    cout << "in "; t.printInOrder(); cout << endl;
    cout << "post "; t.printPostOrder(); cout << endl;
    cout << "sum " << t.sum() << endl;
    cout << "cnt " << t.count() << endl;
    cout << "has5 " << t.contains(5) << endl;
    cout << "pr10 " << t.getPredecessor(10) << endl;
    cout << "su10 " << t.getSuccessor(10) << endl;
    cout << "rm10 " << t.remove(10) << endl;

    return 0;
}
