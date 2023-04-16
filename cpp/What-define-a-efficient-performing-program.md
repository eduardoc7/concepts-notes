# What define a efficient e performing program in C++?
https://www.youtube.com/watch?v=qCjEN5XRzHc
1. No unnecessary work
    - No unnecessary copying
    - No unnecessary allocations
2. Use all computing power
    - Use all cores
    - Use SIMD
3. Avoid waits and stalls
    - Lockless data structures
    - Asynchronous apis
    - Job systems 
4. Use hardware efficiently
    - Cache friendliness
    - Well predictable code
5. OS-level efficiency

## How achieve this goals?
# 1. Build pipeline modifications
### 1.1 Set target architecture
Automatic detection of current processor's features, for x86:
- GCC, LLVM, ICC: -march=native -mtune=native
- MSVC: Needs to be specified manually
For Arm: 
-GCC, LLVM: -mcpu=native

##3 1.2 Use fast math
For floating point numbers, faster computation but less precise results:
- GCC, LLVM, ICC: -ffast-math (included in -Ofast)

### 1.3 Disable exceptions and RTTI
This flag should be applied be carefully, especially that nowadays their overhead tend be rather low
Limited performance gains 
- GCC, LLVM, ICC: -fno-exception

### 1.4 Enable link time optimization
The idea behind is that often the compiler has insufficient knowledge to properly optimize code at translation unit boundaries
- GCC, LLVM, ICC: -flto

### 1.5 Use unity builds
Combining multiples units translations into a single one
- CMake: -DCMAKE_UNITY_BUILD=ON

### 1.6 Link statically
Using static libraries instead of shared libraries or dlls
- Static is better optimizable
- Dynamic is more space efficient
- Dynamic can be updated independently of executable

### 1.7 Profile guided optimization
They make building code a three-step process
- The code is compiled with various performance counters embedded into it
- GCC, LLVM, ICC: -fprofile-generate, -fprofile-use

1.8 Try different compilers

1.9 Try different standard libraries

1.10 Keep your tools updated 

1.11 Preload with a replacement lib

1.12 Use binary post processing tools
- LLVM bolt

# 2. Effective use of C++ (Annotate your code)

### 2.1 Constexpr all the thing
It is used to declare variables, functions, and expressions that can be evaluated at compile-time, allowing the compiler to optimize code and potentially improve performance. A constexpr variable must be initialized with a constant expression, and its value is known at compile-time.

On the other hand, constinit is used to specify that a variable must be initialized at compile-time or runtime, but not dynamically at runtime. It is used to declare variables that have static or thread storage duration and must be initialized either with a constant expression or with a constructor that does not have any dynamic initialization. The constinit keyword was introduced in C++20 to provide a guarantee that a variable is initialized only once and before any code executes.

To take advantage we need to use the `constexpr` keyword:
- In functions, which may result in a constant expression
- The function must have a return statement, and that return statement must be an expression that can be evaluated at compile-time
- Additionally, all of the function's parameters must be of a literal type or a reference to a literal type

## When to use `constexpr`
- Constant expressions: If you have an expression that is known at compile time, such as a mathematical formula or a string concatenation, you can declare it as constexpr. This tells the compiler that the expression can be evaluated at compile time, rather than at runtime, which can improve code performance. For example:
- Compile-time initialization: If you have a variable that can be initialized at compile time, such as an array or a string, you can declare it as constexpr. This tells the compiler to generate the value of the variable at compile time, rather than at runtime. For example:

### 2.2 Make variables const
- Declare variables as const, allows the compiler performing optimizations like hoisting
- Declare member functions const: `constexpr size_t() const noexcept {};`

### 2.3 Noexcept all the things
This allows the compiler to optimize the function by eliminating exception-handling code that would otherwise be generated. For example, the compiler may be able to remove try-catch blocks that surround the function call, or eliminate code that cleans up the stack after an exception is thrown

### 2.4 Use static for internal linkage
`static` is a keyword that can be used to declare objects and functions with internal linkage. Internal linkage means that the object or function can only be referred to within the translation unit (i.e., the source file and any headers it includes) in which it is declared. Other translation units cannot refer to objects or functions with internal linkage by name.
If a function has internal linkage, the compiler knows that it can only be called from within the same translation unit, and can therefore decide to inline the function's code at the call site rather than generating a separate function call. Inlining can eliminate the overhead of a function call, which can improve code performance, particularly in tight loops or frequently-called functions.

## When to use `static` to internal linkage
- Private implementation details: If you have a class that has private implementation details that should not be visible to other parts of the program, you can use static to declare those details with internal linkage. For example, if you have a class with a private data member that should only be accessed by member functions of the class, you can declare that data member as static to give it internal linkage and prevent it from being accessed from outside the class.

- Utility functions: If you have a function that is only used within a single translation unit, you can declare that function as static to give it internal linkage. This can help to reduce naming conflicts and make the code easier to understand. For example, you might have a utility function that performs a specialized operation that is only used within a single module of your program.

- Caching: As I mentioned in my previous answer, you can use static to cache the result of a function or expression, so that it only needs to be computed once. By declaring the cache variable as static, you give it internal linkage and ensure that it is not visible outside of the translation unit where it is defined.

- Global state: If you have a global variable that is only used within a single translation unit, you can declare that variable as static to give it internal linkage. This can help to reduce naming conflicts and make it clear that the variable is only used within a specific context. However, you should be careful when using global state, as it can make the code harder to reason about and lead to subtle bugs.

Local variables: You can use static to declare local variables with static storage duration. Unlike automatic variables, which are destroyed when they go out of scope, static variables persist across function calls. This can be useful for maintaining state across multiple calls to a function, or for initializing a variable only once.

### 2.5 Use [[noreturn]]
Used to mark a function as never returning to its caller, usually used for error reporting functions which either from an exception or terminate the program. This can allow the compiler to better optimize code at is call side. Indicating that a function never returns to its caller, the compiler can eliminate code that would normally be executed after the function call.

### 2.6 Use [[likely]] and [[unlikely]]
C++20 attributes that provide hints to the compiler about the likelihood. These attributes can help the compiler generate more efficient code by guiding its branch prediction and instruction scheduling.

- [[likely]]: This attribute is used to indicate that a particular branch of code is likely to be executed. For example, in a function that processes user input, you might use [[likely]] to indicate that the branch that handles valid input is more likely to be taken than the branch that handles invalid input. Here's an example:
```c++
void process_input(int input) {
    if (input > 0) {
        do_something();
    } else [[unlikely]] {
        handle_error();
    }
}
```

- [[unlikely]]: This attribute is used to indicate that a particular branch of code is unlikely to be executed. For example, in a loop that processes a large dataset, you might use [[unlikely]] to indicate that the branch that handles the end of the dataset is less likely to be taken than the branch that processes each element. Here's an example:
```c++
void process_dataset(const std::vector<int>& data) {
    for (int x : data) {
        do_something_with(x);
    }
    if (data.empty()) [[unlikely]] {
        handle_empty_dataset();
    }
}
```

### 2.7 Use [[assume(condition)]]
Similar to an assert. The [[assume]] attribute in C++ is used to tell the compiler that a certain condition is assumed to be true at a particular point in the program. This attribute is typically used in performance-critical code where certain assumptions can be made, but where the cost of checking those assumptions at runtime is too high. By using the [[assume]] attribute, the programmer can tell the compiler to optimize the code based on the assumption, without having to check the assumption at runtime.
For example, consider the following code:
```c++
void foo(int* p) {
  if (p == nullptr) {
    throw std::invalid_argument("null pointer");
  }
  // use p...
}
```
In this code, we check whether p is nullptr and throw an exception if it is. However, if we know that p can never be nullptr at this point in the program, we can use the [[assume]] attribute to tell the compiler to optimize based on that assumption:
```c++
void foo(int* p) {
  [[assume: p != nullptr]];
  // use p...
}
```

### 2.8 Use __restrict
This can help the compiler generate more optimized code by allowing it to make certain assumptions about the pointer and the memory it points to. Specifically, the __restrict keyword can allow the compiler to perform more aggressive loop optimizations and better utilize CPU register allocation.
In general, the __restrict keyword should be used when a pointer is known to be unique and not aliased by any other pointer in the same scope. This typically occurs in cases where pointers are passed as function arguments, and the function body uses the pointers to perform computations that do not depend on or modify any other memory locations. By using __restrict, the programmer can help the compiler generate more efficient code by avoiding unnecessary memory loads and stores.
It's important to note that the use of __restrict is not always necessary or even beneficial. In some cases, using __restrict can actually harm performance by preventing certain compiler optimizations or by introducing additional memory access overhead. As with any optimization technique, the decision to use __restrict should be based on careful benchmarking and profiling of the specific application code.

### 2.9 Make functions pure
A pure function is a function that has no side effects and always returns the same result for a given set of input arguments. Pure functions are also known as "referentially transparent" functions, because they can be replaced with their return value without affecting the behavior of the program. Pure functions are often used in functional programming paradigms, where the emphasis is on building programs using functions that operate solely on their input data and produce predictable, deterministic results. In C++, pure functions can be useful in a variety of contexts, such as:
- Memoization: Pure functions can be memoized, or cached, to avoid recomputing the same results for the same inputs. This can be especially useful in performance-critical code where certain computations are expensive and frequently repeated.
- Parallelism: Pure functions are inherently thread-safe and can be safely executed in parallel without requiring synchronization or locks.
- Testability: Pure functions are easy to test, because their behavior is solely determined by their inputs and does not depend on any external state.

# 3. Effective use of C++ (No redundant copies)
### 3.1 Take parameters properly
Call site: func(x);
declaration: void func(<type parameter>x);
Here's an example of a function template that uses perfect forwarding to forward a type parameter:
```c++
template <typename T>
void forward_param(T&& param) {
    some_other_function(std::forward<T>(param));
}
```
A parameter that needs ownership in C++ is a parameter that represents an object or resource whose ownership is being transferred to a function or method. In other words, the function or method assumes responsibility for managing the lifetime of the object or resource, including allocating and deallocating memory as necessary.

Does x need to be perfectly fowarded?

    - yes: Take by universal reference `type&&`
        - not: If x is a range:
            - If x is a readonly string
            - yes: Take std::string
            - not:
            - yes: Does x need to be a contiguous array?
                - yes: Take std::span
                - not: Can x be an arbitrary range?
                    - yes: Take std::ranges
                    - not: Does x need to be a specific container?
                        - yes: Take the container
                        - not: Take a iterator pair
            - not: If x can be null:
                - yes: Take `std::optional` of x
                - not: If needing ownership of x:
                    - yes: Take by std::unique_ptr, std::shared_ptr
                    - not: If x is moved from:
                        - yes: Take by rvalue reference type&&x
                        - not: If x is copied:
                            - yes: Take by value
                            - not: If x is modified:
                                - yes: Take by lvalue reference type&x
                                - not: if x is cheap to copy:
                                    - yes: take by value type x
                                    - not: take by const lvalue reference const type&x


### 3.2 Avoid allocations in loops
This avoids the need for repeated memory allocations and deallocations inside the loop, which can be time-consuming for large data sets.
By pre-allocating memory outside of the loop, we can improve the performance of our program and avoid potential memory allocation issues.
#### Use reserve() when an upper bound on size is known ahead of time
Another way to avoid allocations in loops in C++ is by using the reserve() function
```c++
    // Create an empty vector of integers
    std::vector<int> v;
    // Set the upper bound on the number of elements to insert
    const int num_elements = 100000;
    // Reserve memory for the vector
    v.reserve(num_elements);
    // Loop over the upper bound and insert each element into the vector
    for (int i = 0; i < num_elements; i++) {
        v.push_back(i);
    }
```

### 3.3 Avoid copying exceptions
In C++, exceptions can be expensive when it comes to copying data during the unwinding process. One way to avoid copying exceptions is to use move semantics instead of copying. Here's an example of how to do that:
```c++
    try {
        foo();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
        // Do something to handle the exception
    }
```
To avoid copying the exception object during the unwinding process, we can change the catch block to use a reference to an rvalue instead of a const reference:
```c++
try {
    foo();
} catch (std::exception&& e) { // Use an rvalue reference instead of a const reference
    std::cerr << "Caught exception: " << e.what() << '\n';
    // Do something to handle the exception
}
```

### 3.4 Avoid copies in range-for
Passing the value by reference
### 3.5 Avoid copies in lambda captures
Passing the value by reference
### 3.5 Avoid copies in str. bindings
Passing the value by reference
### 3.6 Provide ref qualified methods

# 4. Manual hardware oriented optimizations