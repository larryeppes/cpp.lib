//
// Created by PC on 2017/12/28.
//

#include <iostream>
#include <vector>

int test_vector() {
    // constructors used in the same order as described above:
    std::vector<int> first; // 空向量
    std::vector<int> second (4,100); // 4个值为100的int向量
    std::vector<int> third (second.begin(), second.end()); // iterating through second
    std::vector<int> fourth (third); // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}