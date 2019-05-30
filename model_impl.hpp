// In this header file, define your model!
// This includes functions to describe each reaction.
// Make sure that you've first completed reaction_list.h and specie_list.h
#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H
#include "core/reaction.hpp"
#include "core/specie.hpp"
#include "core/model.hpp"
#include "sim/base.hpp"
//#include "context.hpp"
#include <cstddef>
#include <cmath>

/*

Define all of your reaction rate functions in `model_impl.hpp`.
For example, if you enumerated a reaction `R_ONE`, you should declare a
   function like this:

 RATETYPE reaction<R_ONE>::active_rate(const Ctxt& c) { return 6.0; }


Or, for a more interesting reaction rate, you might do something like:


 RATETYPE reaction<R_TWO>::active_rate(const Ctxt& c) {
   return c.getRate(R_TWO) * c.getCon(SPECIE_ONE) * c.neighbors.calculateNeighborAvg(SPECIE_TWO);
 }

Refer to the Context API (Section ) for instructions on how to get delays
   and critical values for more complex reaction rate functions.

*/
template<>
template<class Ctxt>
RATETYPE reaction<radical>::active_rate(const Ctxt& c) {
    return c.getRate(radical);
}

template<>
template<class Ctxt>
RATETYPE reaction<non_radical>::active_rate(const Ctxt& c) {
    return c.getRate(non_radical)*(c.getCon(I)+1)*(c.getCon(HIO));
}


template<>
template<class Ctxt>
RATETYPE reaction<hio_decay>::active_rate(const Ctxt& c) {
    return c.getRate(hio_decay)*c.getCon(HIO);
}

template<>
template<class Ctxt>
RATETYPE reaction<i_decay>::active_rate(const Ctxt& c) {
    return c.getRate(i_decay)*(c.getCon(I));
}


#endif // MODEL_IMPL_H
