/*
    * Standard Template Library (STL):
        The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and 
        functions such as lists, stacks, arrays, etc.

    * STL has 4 components: 
        • Algorithms
        • Containers
        • Functors
        • Iterators

    * Containers:
        A container is a class template in STL that stores collections of data. It manages the storage space for its elements 
        and provides member functions to access them. It helps in recreating and implementing complex data structures efficiently. 
        The STL provides a range of containers, such as vector, list, map, set, and stack, which can be used to store and manipulate data.
        Types of containers:
            ● Sequence containers – elements in a linear order:
                - vector, list, deque
            ● Associative containers – store key-value pairs:
                - set, map, multiset, multimap
            ● Unordered containers – fast key-based access using hashing:
                - unordered_set, unordered_map

    * Iterators:
        Iterators are used to access data in the containers, and it helps in traversing through elements of containers using its functions.
        They can be incremented and decremented as per choice and help in the manipulation of data in the container. Iterator functions are:
        begin(): This function points the iterator to the first element of the container.
        end(): This function points the iterator to the last element of the container.
        Using begin() and end() iterators and by dereferencing them we can access the elements
        cout << "First element: " << *(vec1.begin()) << endl; 
        cout << "Last element: " << *(vec1.end() - 1) << endl; 
        cout << " End element: " << *(vec1.end()) << endl; // Output: garbage value (not included in the range)

    * Algorithms:
        The algorithm defines a collection of functions specially designed to be used on a range of elements. They act on containers and provide
        means for various operations for the contents of the containers. Algorithms can be defined as function template applied to the containers
        and provide operations like searching, sorting, counting, manipulating, etc. for the content of the container using iterators.

    * Function Objects or Functors:
        A function object is also known as a functor, it is an object of a class that provides a definition for the operator(). Suppose you have
        declared an object of some class, then you can use that object just like the function.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    // Creating a vector(container) of integers
    vector<int> vec1;// Initialize an empty vector
    vector<int> vec2(5); // Initialize a vector of size 5 with default values (0 for int)
    vector<int> vec3(5, 10); // Initialize a vector of size 5 with all elements will be 10
    vector<int> vec4 = {1, 2, 3, 4, 5}; // Initialize a vector with a list of values 
    vector<int> vec5(vec4); // Copy constructor, creates a vector with the same elements as vec4

    // Checking if the vector is empty
    cout << "Size of vector 1(Initial) : " << vec1.size() << endl; // Output: 0 (size of the vector)

    // Adding elements to the vector
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    vec1.push_back(50); 

    // We can also add elements using emplace_back
    vec1.emplace_back(40); // Adds 40 to the end of the vector

    // Checking the size and capacity of the vector1
    cout << "Size of vector 1: " << vec1.size() << endl; // Output: 5
    cout << "Capacity of vector 1: " << vec1.capacity() << endl; // Output: 8 

/* 
    * Capacity: 
        The number of elements that can be stored in the vector. And it increases automatically when the number of elements exceeds
        the current capacity. It increases by doubling the current capacity. Like, capacity=1 size=1, if we add one more element then capacity 
        becomes 2 and size becomes 2, if we add one more element then capacity becomes 4 and size becomes 3.
*/

    // Displaying the elements of the vector 
    cout << "Elements in the vector 1: ";
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    // Using begin() and end() iterators to print all elements of the vector
    cout << "Elements in vector: ";
    vector<int> :: iterator it;
        for (it = vec1 . begin(); it != vec1.end(); it++){
            cout << *it << " ";
        }
        cout << endl;

    // Using rbegin() and rend() iterators to print all elements of the vector in reverse order
    cout << "Elements in vector in reverse order: ";
    vector<int> :: reverse_iterator i;
    for (i = vec1.rbegin(); i != vec1.rend(); i++){//rbegin() points to the last element and rend() points to the element before the first element
        cout << *i << " ";
    }
    cout << endl;

    // We can also define iterator in loop like this:
    /*
        for (vector<int> :: iterator it = vec1.begin(); it != vec1.end(); it++){
            cout << *it << " ";
        }
    -> It will also work the same way as above. But it makes the code complicated so we can use auto keyword to define the iterator like this:
        for (auto it = vec1.begin(); it != vec1.end(); it++){
            cout << *it << " ";
        }
    */

    // Removing the last element from the vector
    vec1.pop_back();

    // Accessing elements using at() method or the subscript operator []
    cout << "Element at index 2 : " << vec1.at(2) << " or " << vec1[2] << endl; // Output: 30

    // Checking the first and last elements of the vector
    cout << "First element(Vector 1): " << vec1.front() << endl; // Output: 10
    cout << "Last element(Vector 1): " << vec1.back() << endl; // Output: 50

    // Ereasing elements from the vector using erase() method with begin() iterator
    vec1.erase(vec1.begin()); // Erases the first element (10)
/* 
    If we want to erase other elements we can use the iterator like=> vec1.erase(vec1.begin() + 2); // Erases the third element (30) 
    We can also erase a range of elements using iterators like=> vec1.erase(vec1.begin() + 1, vec1.begin() + 3); // Erases the second and third elements (20 and 40)
    Erease only change the size of the vector, it does not change the capacity of the vector.
*/

//  If we want to add elements at a specific position we can use insert() method. By inserting an element at a position, the elements after that position are shifted to the right.
    
    vec2.insert(vec2.begin() + 1, 15); // Inserts 15 at the second position

    // We can also insert a range of elements using iterators like vec2.insert(vec2.begin() + 2, vec4.begin(), vec4.end()); // Inserts all elements of vec4 at the third position 

    // We can clear the vector using clear() method
    vec3.clear(); // Clears all elements from the vector

    cout << "Size of vec3 after clear: " << vec3.size() << endl; // Output: 0
    cout << "Capacity of vec3 after clear: " << vec3.capacity() << endl; // Output: 5 (capacity remains the same)

    // We can also check if the vector is empty using empty() method it gives 1(yes) and 0(no) as output
    if (vec3.empty()) {
        cout << "vec3 is empty" << endl; // Output: vec3 is empty
    } else {
        cout << "vec3 is not empty" << endl;
    }

    /* Sort Algorithm: sorts the elements in a range in ascending order by default. We can also sort in descending order using=> greater<int>() as a third argument. */
    //sort(vec1.begin(), vec1.end());
    sort (vec1.begin() , (vec1.begin() + vec1.size())); // Alternative way to sort using the vector name and size
    sort(vec1.begin(), vec1.end(), greater<int>());

    /* Reverse algorithm: reverses the order of elements in a range. */
    reverse(vec1.begin(), vec1.end()); //If the input vector was like 1 5 6 8 4 than the output will be 4 8 6 5 1.
    reverse(vec2.begin() + 1, vec2.end() - 1); // Reverses the elements from the second element(2) to the second last element(6)
    // If the input vector was like 1 5 6 8 4 than the output will be 1 8 6 5 4.

    /*Maximum and Minimum algorithms: find the maximum and minimum elements in a range.*/
    int maxElement = *max_element(vec1.begin(), vec1.end());
    int minElement = *min_element(vec1.begin(), vec1.end());
    cout << endl << "Maximum element: " << maxElement << endl; 
    cout << "Minimum element: " << minElement << endl;
    /*
    The max_element() and min_element() functions return an iterator to the maximum and minimum elements, respectively. By dereferencing the iterator with the * operator,
    we can get the actual value of the maximum and minimum elements. */
    int maxInRange = *max_element(vec1.begin() + 1, vec1.end() - 1); // Finds the maximum element from the second element to the second last element
    int minInRange = *min_element(vec1.begin() + 1, vec1.end() - 1); // Finds the minimum element from the second element to the second last element
    cout << "Maximum element in range: " << maxInRange << endl;
    cout << "Minimum element in range: " << minInRange << endl;

    /*Binary Search algorithm: searches for a specific element. It returns 0 or 1 as output so we use if statement to check if the element is found or not.
    Note: The vector must be sorted before performing binary search.*/
    int target = 4;
    bool found = binary_search(vec1.begin(), vec1.end(), target);
    if (found) {
        cout << "Element " << target << " found in the vector." << endl;
    } else {
        cout << "Element " << target << " not found in the vector." << endl;
    }

    /*Count algorithm: counts the occurrences of a specific element in a range.*/
    int countTarget = count(vec1.begin(), vec1.end(), target); // Counts the occurrences of the target element in the vector
    cout << "Count of " << target << ": " << countTarget << endl;
    cout << endl;

    /*Swap function : Swaps the values of vectors*/
    vector<int> foo (3,100);   // three ints with a value of 100
    vector<int> bar (5,200);   // five ints with a value of 200
    foo.swap(bar);

    /*Find algorithm: finds the first occurrence of a specific element in a range.*/
    auto itfound = find(vec1.begin(), vec1.end(), 6);
    if (itfound == vec1.end())
     {
        cout << "6 not found in range" << endl;
    }
    else
     {
        cout << *itfound << endl;
        cout << "Index: " << itfound - vec1.begin() << endl;
    }

    /*Accumulate : Accumulates or gives the sum of elements in the specified range.. It takes three arguments: the starting iterator, the ending iterator, and the
    initial value (0 in this case)*/
    int sum = accumulate(vec1.begin(), vec1.end(), 0); // Sums all elements in the vector, starting from 0
    cout << "Sum of elements: " << sum << endl;


    return 0;
}