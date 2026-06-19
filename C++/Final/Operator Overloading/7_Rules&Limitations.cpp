    /*
    · Only existing operators can be overloaded. We cannot create a new operator.
    · Overloaded operator should contain one operand of user-defined data type. (only for classes. We cannot overload the operator for built-in data types)
    . Overloaded operators have the same syntax as the original operator.
    · Operator overloading is applicable within the scope (extent) in which overloading occurs.
    · Binary operators overloaded through a member function take one explicit argument and those which are overloaded through a friend function
    take two explicit arguments.
    . Overloading of an operator cannot change the basic idea of an operator.
        (- For example A and B are objects. The following statement => A += B;
        - assigns addition of objects A and B to A.
        - Overloaded operator must carry the same task like riginal operator according to the language.
        - Following statement must perform the same operation like the last statement => A = A + B;)
    · Overloading of an operator must never change its natural meaning.
        - An overloaded operator + can be used for subtraction of two objects, but this type of code decreases the utility of the program.
        
    · Limitations of Operator Overloading:
        1. Only built-in operators can be overloaded. New operators can not be created
        2. Arity of the operators cannot be changed. 
        3. Overloaded operators cannot have default arguments except the function call operator () which can have default arguments. 
        4. The overloaded operator contains atleast one operand of the user-defined data type. 
        5. We cannot use friend function to overload certain operators. However, the member function can be used to overload those operators.

    */