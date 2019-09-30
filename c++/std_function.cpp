/*
std::function use
 */


// In your header file

std::function<void(const std::string & str)> my_callback;


// ---------------------------------------------------------------------------

// Calling the callback

if(my_callback)
{
    my_callback("foo");
}

// ---------------------------------------------------------------------------

// Binding to a call back

// Lambda
my_callback = [](const std::string & str) -> void
{
    foo();
};


// member function
my_callback = std::bind(&MyClass::func, this, std::placeholders::_1);



