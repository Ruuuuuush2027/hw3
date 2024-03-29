#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
    /**
     * @brief Construct a new Heap object
     * 
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m=2, PComparator c = PComparator()): ary(m), compare(c), data(){};

    /**
     * @brief Destroy the Heap object
     * 
     */
    ~Heap() {};

    /**
     * @brief Push an item to the heap
     * 
     * @param item item to heap
     */
    void push(const T& item);

    /**
     * @brief Returns the top (priority) item
     * 
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const & top() const;

    /**
     * @brief Remove the top priority item
     * 
     * @throw std::underflow_error if the heap is empty
     */
    void pop();

    /// returns true if the heap is empty

    /**
     * @brief Returns true if the heap is empty
     * 
     */
    bool empty() const;

    /**
     * @brief Returns size of the heap
     * 
     */
    size_t size() const;

/// Add whatever helper functions and data members you need below

    void print() const;
private:
    int ary;
    PComparator compare;
    std::vector<T> data;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T, PComparator>::print() const{
    for(size_t i = 0; i < data.size(); i ++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
    size_t i = data.size();
    data.push_back(item);

    while(i > 0 && compare(data[i], data[(i-1)/ary])){
        T temp = data[i];
        data[i] = data[(i-1)/ary];
        data[(i-1)/ary] = temp;
        i = (i-1)/ary;
    }
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
    return data.empty();
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
    return data.size();
}
    // We will start top() for you to handle the case of 
    // calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
        throw std::underflow_error("Heap empty!");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return data[0];
}


    // We will start pop() for you to handle the case of 
    // calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop(){
    if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
        throw std::underflow_error("Heap empty!");
    }
    data[0] = data.back();
    data.pop_back();
    size_t i = 0, j = 0;
    if(empty())
        return;
    
    do{
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i = j;

        for(size_t k = i * ary + 1; k <= i * ary + ary; k ++){
            if(k < data.size() && compare(data[k], data[j]))
                j = k;
        }
    } while(j != i);
}

#endif