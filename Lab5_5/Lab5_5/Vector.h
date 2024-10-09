#ifndef VECTOR_H
#define VECTOR_H

/**
 * \class Vector
 * \brief A dynamic array class template for managing elements in a contiguous memory block.
 *
 * The Vector class provides functionality similar to standard library vectors, including
 * dynamic memory allocation, element access, and automatic resizing as new elements are added.
 *
 * \author Your Name
 * \date   01/10/2024
 * \version 1.0 initial version with core functionality.
 *
 * \author Your Name
 * \date   05/10/2024
 * \version 2.0 added bounds checking for element access in `at()` method.
 *
 * \author Your Name
 * \date   7/10/2024
 * \version 3.0
 *          1) Optimized `push_back()` to double capacity when full.
 *          2) Overloaded '[]' operators
 *          3) Included constructors for initialization with 1 argument for size
 *
* \author Joshua Khoo
 * \date   8/10/2024
 * \version 4.0
 *          1) Updated const at() method
 *          2) Updated elements to be new T [capacity]
 *
 *
 */
template <class T>
class Vector {

public:
    /**
     * \brief Default constructor for the Vector class.
     *
     * Initializes a vector with a capacity of 1 and size of 0. Allocates no memory until elements are added.
     */
    Vector() : capacity(1), size(0), elements(new T[capacity]) {}

    /**
     * \brief Constructor with a specified initial capacity.
     *
     * Initializes a vector with the given capacity and size of 0.
     *
     * \param new_capacity The initial capacity of the vector.
     */
    Vector(size_t new_capacity) : capacity(new_capacity), size(0), elements(new T[new_capacity]) {}


    /**
     * \brief Copy constructor for Vector class.
     *
     * Creates a copy of the given vector, copying all elements from the original vector into a new vector.
     *
     * \param other The Vector object to be copied.
     */
    Vector(const Vector& other);

    /**
     * \brief Move constructor for the Vector class.
     *
     * Transfers ownership of resources from the given vector to the new vector, leaving the original vector empty.
     *
     * \param other The Vector object to be moved.
     */
    Vector(Vector&& other) noexcept;

    /**
     * \brief Unified assignment operator for copy and move operations.
     *
     * Implements the copy-and-swap idiom to ensure strong exception safety during assignment. Copies or moves
     * the contents of the given vector into this vector.
     *
     * \param other The Vector object to assign from.
     * \return A reference to this Vector.
     */
    Vector& operator=(Vector other);

    /**
     * \brief Destructor for the Vector class.
     *
     * Frees all dynamically allocated memory used by the vector.
     */
    ~Vector();

    /**
     * \brief Accessor method to retrieve an element by its index.
     *
     * Provides bounds-checked access to the elements in the vector. Throws an out_of_range exception if
     * the index is invalid.
     *
     * \param index The index of the element to retrieve.
     * \return A reference to the element at the specified index.
     */
    T& at(size_t index);

    /**
     * \brief Const version of the accessor method for retrieving an element.
     *
     * Provides bounds-checked, read-only access to the elements in the vector. Throws an out_of_range exception
     * if the index is invalid.
     *
     * \param index The index of the element to retrieve.
     * \return A const reference to the element at the specified index.
     */
    const T& at(size_t index) const;

    /**
     * \brief Non-const version of the subscript operator for element access.
     *
     * Allows access to the elements of the vector using array-like indexing. No bounds checking is performed.
     * If an invalid index is used, behavior is undefined. Use `at()` for bounds-checked access.
     *
     * \param index The index of the element to retrieve.
     * \return A reference to the element at the specified index.
     */
    T& operator[](size_t index);

    /**
     * \brief Const version of the subscript operator for read-only element access.
     *
     * Allows read-only access to the elements of the vector using array-like indexing. No bounds checking is performed.
     * If an invalid index is used, behavior is undefined. Use `at()` for bounds-checked access.
     *
     * \param index The index of the element to retrieve.
     * \return A const reference to the element at the specified index.
     */
    const T& operator[](size_t index) const;

    /**
     * \brief Retrieves the capacity of the vector.
     *
     * \return The current capacity of the vector.
     */
    size_t getCapacity() const { return capacity; }

    /**
     * \brief Retrieves the size of the vector.
     *
     * \return The current number of elements in the vector.
     */
    size_t getSize() const { return size; }

    /**
     * \brief Adds a new element to the back of the vector.
     *
     * Appends the given element to the vector. If the vector is full, it doubles its capacity
     * before adding the new element.
     *
     * \param element The element to add to the vector.
     */
    void push_back(const T& element);

    /**
     * \brief Removes the last element from the vector.
     *
     * Reduces the size of the vector by one and returns the removed element.
     * If the vector is empty, the method does nothing.
     *
     * \return The removed element.
     */
    T pop_back();

    /**
     * \brief Reserves space for future elements by increasing the capacity.
     *
     * Allocates new memory for at least the specified number of elements without changing the size.
     * If the requested capacity is smaller than the current capacity, the function does nothing.
     *
     * \param new_capacity The new capacity to allocate.
     */
    void reserve(size_t new_capacity);

private:
    size_t capacity;   ///< The total capacity of the vector (the amount of memory allocated).
    size_t size;       ///< The current number of elements stored in the vector.
    T* elements;       ///< Pointer to the dynamically allocated array of elements.

    /**
     * \brief Swaps the contents of this vector with another vector.
     *
     * A utility function for implementing the copy-and-swap idiom.
     *
     * \param other The other vector to swap contents with.
     */
    void swap(Vector& other) noexcept;
};

// Copy constructor
template <class T>
Vector<T>::Vector(const Vector<T>& other) : capacity(other.capacity), size(other.size), elements(new T[other.capacity]) {
    for (size_t i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// Move constructor
template <class T>
Vector<T>::Vector(Vector<T>&& other) noexcept : capacity(0), size(0), elements(nullptr) {
    swap(other);
}

// Unified assignment operator (copy-and-swap idiom)
template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> other) {
    swap(other);
    return *this;
}

// Destructor
template <class T>
Vector<T>::~Vector() {
    delete[] elements;
}

// Swap function
template <class T>
void Vector<T>::swap(Vector<T>& other) noexcept {
    size_t temp_capacity = capacity;
    size_t temp_size = size;
    T* temp_elements = elements;

    capacity = other.capacity;
    size = other.size;
    elements = other.elements;

    other.capacity = temp_capacity;
    other.size = temp_size;
    other.elements = temp_elements;
}

// Accessor with bounds checking
template <class T>
T& Vector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Const accessor with bounds checking
template <class T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Non-const version for element access
template <typename T>
T& Vector<T>::operator[](size_t index) {
    return elements[index];
}

// Const version for element access
template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return elements[index];
}

// Adds an element to the back
template <class T>
void Vector<T>::push_back(const T& element) {
    if (size == capacity) {
        reserve(capacity * 2); // Double capacity if needed
    }
    elements[size++] = element;
}

// Removes the last element
template <class T>
T Vector<T>::pop_back() {
    if (size == 0) {
        // Vector is empty error message
        throw std::underflow_error("Cannot pop from an empty vector");
    }
    return elements[--size];
}

// Reserves additional capacity
template <class T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= capacity) return;

    T* new_elements = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_elements[i] = elements[i];
    }

    delete[] elements;
    elements = new_elements;
    capacity = new_capacity;
}

#endif // VECTOR_H
