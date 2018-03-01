#ifndef METAFUN_TPP
#define METAFUN_TPP
#include <iostream>

namespace metafun{

template<bool isEnable, typename = void>
struct ENABLE_IF{};

template<>
struct ENABLE_IF<false> {};

template<typename mytype>
struct ENABLE_IF<true,mytype> {
    using type = mytype;
    typedef mytype tDefType;
};


template<typename A, typename = void>
struct got_type : std::false_type {};

template<typename A>
struct got_type<A> : std::true_type {
    typedef A type;
};


/*typedef*/
#define GENERATE_TYPEDEF_CHECKER(typeDefName) \
template<typename targetClass>\
struct hasTypedef_##typeDefName{\
    typedef char(&yes)[2];\
    template<typename U>\
    static yes __runMagic__(typename U::typeDefName*){}\
    template<typename U>\
    static char(&__runMagic__(...))[1]{}\
    static constexpr const bool value = sizeof(yes) == sizeof(__runMagic__<targetClass>(nullptr));\
}


/*ENUM*/
#define GENERATE_ENUM_CHECKER(enumName) \
template<typename T, typename = std::true_type> struct hasEnum_##enumName : std::false_type {};\
template<typename T>\
struct hasEnum_##enumName\
<T, std::integral_constant<bool, std::is_enum<typename got_type<typename T::enumName>::type>::value >> : std::true_type {}

/*Segítség function ellenőrzéshez:*/
template<typename T,typename V = void>\
struct typeOfFunction {\
    using type = int;\
    typedef int vtype;\
};\
template<typename T,typename V>\
struct typeOfFunction<T V::*> {\
    using type = T;\
    typedef T vtype;\
};\

/*Function ellenőrzés*/
#define GENERATE_FUNCTION_CHECKER(functionName) template<class ClassName>\
struct hasFunction_##functionName{\
    typedef char(&CAN_NOT_BE_FUNCTION)[1];\
    template<typename V>\
    static decltype(&V::functionName) existName(decltype(&V::functionName));\
    template<typename>\
    static CAN_NOT_BE_FUNCTION existName(...);\
    static const constexpr bool value = std::is_function<typename typeOfFunction<decltype(existName<ClassName>(nullptr))>::vtype>::value;\
}

/*HELPER*/

template<bool ,bool>
struct bothTrue{
    static const constexpr bool result = false;
};
template<>
struct bothTrue<true,true>{
   static const constexpr bool result = true;
};


#define GENERATE_MEMBER_CHECK(memberName) template<typename targetClass>\
struct hasMember_##memberName{\
    typedef char(&yes)[2];\
    typedef char(&no)[1];\
    template<typename U>\
    static yes __runMagic__(decltype(&U::memberName));\
    template<typename U>\
    static no __runMagic__(...);\
    static const constexpr bool value = \
        bothTrue<  sizeof(__runMagic__<targetClass>(nullptr)) == sizeof(yes) , !(hasFunction_##memberName<targetClass>::value)  >::result;\
}


#define GENERATE_ALL_CHECKS(name) GENERATE_TYPEDEF_CHECKER(name); \
                                GENERATE_ENUM_CHECKER(name);\
                                GENERATE_FUNCTION_CHECKER(name); \
                                GENERATE_MEMBER_CHECK(name)

} //metafun namespace end_:)

/* generálásnál muszáj a metafun namespacen belül generálni:  namespace metafun{ (
            GENERATE_ALL_CHECKS(func);
        };
*/

#endif // metafun

/*DB - '18*/
