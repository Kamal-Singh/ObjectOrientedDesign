#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}