#pragma once

#include "common.h"

#include <iostream>
#include <type_traits>

namespace jngen {

template<int N> struct PTag : PTag<N-1> {};
template<> struct PTag<0> {};
struct PTagMax : PTag<20> {};

struct OutputModifier {
    int addition = 0;
    bool printN = false;
    bool printM = false;

    int printParents;
    bool printEdges = true;
    bool printWeights = true;

    char sep = ' ';
};

JNGEN_EXTERN OutputModifier defaultMod;

template<typename T>
class Repr {
    friend std::ostream& operator<<(std::ostream& out, const Repr& repr) {
        repr.print(out);
        return out;
    }

    template<typename P>
    friend Repr<P> repr(const P& t);

    template<typename P>
    friend class ReprProxy;

protected:
    Repr() = delete;
    Repr(const Repr<T>&) = default;
    Repr<T>& operator=(const Repr<T>&) = default;
    Repr(Repr<T>&&) = default;
    Repr<T>& operator=(Repr<T>&&) = default;

public:
    Repr(const T& object) :
        object_(object),
        mod_(defaultMod)
    {  }

    Repr<T>& add1(bool value = true) {
        mod_.addition = value;
        return *this;
    }

    Repr<T>& printN(bool value = true) {
        mod_.printN = value;
        return *this;
    }

    Repr<T>& printM(bool value = true) {
        mod_.printM = value;
        return *this;
    }

    Repr<T>& printParents(int value = -1) {
        mod_.printParents = value;
        mod_.printEdges = false;
        return *this;
    }

    Repr<T>& printEdges(bool value = true) {
        mod_.printEdges = value;
        if (!value) {
            mod_.printParents = -1;
        }
        return *this;
    }

    Repr<T>& printWeights(bool value = true) {
        mod_.printWeights = value;
        return *this;
    }

    Repr<T>& endl(bool value = true) {
        mod_.sep = value ? '\n' : ' ';
        return *this;
    }

private:
    void print(std::ostream& out) const {
        printValue(out, object_, mod_, PTagMax{});
    }

    const T& object_;

protected:
    OutputModifier mod_;
};

class BaseReprProxy {};

template<typename T>
class ReprProxy : public BaseReprProxy {
    friend std::ostream& operator<<(std::ostream& out, const ReprProxy& proxy) {
        Repr<T> repr(static_cast<const T&>(proxy));
        return out << repr;
    }

public:
    Repr<T> add1(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.add1(value);
        return repr;
    }

    Repr<T> printN(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.printN(value);
        return repr;
    }

    Repr<T> printM(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.printM(value);
        return repr;
    }

    Repr<T> printParents(int value = -1) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.printParents(value);
        return repr;
    }

    Repr<T> printEdges(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.printEdges(value);
        return repr;
    }

    Repr<T> printWeights(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.printWeights(value);
        return repr;
    }

    Repr<T> endl(bool value = true) {
        Repr<T> repr(static_cast<const T&>(*this));
        repr.endl(value);
        return repr;
    }

protected:
    ReprProxy() {
        static_assert(
            std::is_base_of<ReprProxy<T>, T>::value,
            "ReprProxy<T> must be inherited by T");
    }
};

template<typename T>
Repr<T> repr(const T& t) {
    return Repr<T>(t);
}

class DefaultModSetter : public Repr<int> {
    friend DefaultModSetter setMod();

private:
    DefaultModSetter(int val) :
        Repr<int>(val)
    {  }

public:
    ~DefaultModSetter() {
        defaultMod = mod_;
    }

    Repr<int>& reset() {
        mod_ = OutputModifier();
        return *this;
    }
};

inline DefaultModSetter setMod() {
    static int dummy = 0;
    return DefaultModSetter(dummy);
}

} // namespace jngen

using jngen::repr;
using jngen::setMod;
