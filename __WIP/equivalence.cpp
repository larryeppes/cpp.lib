//
// Created by PC on 2017/12/27.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define TEST(s) if (!(s)) { std::cout << __LINE__ << " " << #s << std::endl; exit(-1);}

// specify operator ==
template<class T, class F>
void equivalence(std::vector<T> x, F eq) {
    std::vector<int> parent(x.size());
//    for (int i = 0; i < x.size(); ++i) {
//        parent[i] = i;
//        for (int j = 0; j < i; ++j) {
//            parent[j] = parent[parent[j]];
//            if (eq(x[i], x[j]))
//                parent[parent[parent[j]]] = i;
//        }
//    }
//    for(int i = 0; i < x.size(); ++i) parent[i] = parent[parent[i]];
//
//    for(int i = 0; i < parent.size(); ++i)
//        std::cout << x[i] << " " << parent[i] << std::endl;
};