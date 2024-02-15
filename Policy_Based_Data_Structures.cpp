// Mainly 2 Functions: find_by_order() [normal array accessing] and order_of_key() 
// Baaki set ke functions: erase(), size(), begin(), end(), etc.

//Include the following header files in your code to use PBDS:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
//Namespace 
using namespace __gnu_pbds;
using namespace std;


//Templates

 //defining template when all elements are distinct 
template <class T> using My_Set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;

 //defining template when duplicate elements are also used
template <class T> using My_Multi_Set = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


int main() {
    My_Multi_Set <int> a;
    a.insert(2);
    a.insert(2);
    a.insert(3);
    a.insert(7);
    a.insert(5);
    cout << *a.find_by_order(4) << endl; //output is 7
    cout << (a.order_of_key(10)) << endl; //output is 5
}
