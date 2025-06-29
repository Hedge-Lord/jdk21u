#ifndef SHARE_SERVICES_PROFILEINJECTION_GLOBALS_HPP
#define SHARE_SERVICES_PROFILEINJECTION_GLOBALS_HPP

#include "runtime/globals_shared.hpp"

//
// Defines all profile injection specific flags. This file contains only flags,
// no other code. It is included multiple times by globals.hpp and
// other files, each time with a different macro definition.
//

#define PROFILEINJECTION_FLAGS(develop,                                        \
                               develop_pd,                                     \
                               product,                                        \
                               product_pd,                                     \
                               range,                                          \
                               constraint,                                     \
                               writeable)                                      \
                                                                               \
  product(bool, InjectProfiles, false, DIAGNOSTIC,                            \
          "Inject profiling data from ReplayDataFile and resume execution")   \
                                                                               \
  product(bool, TraceProfileInjection, false, DIAGNOSTIC,                     \
          "Trace profile injection operations")                               \
                                                                               \

// end of PROFILEINJECTION_FLAGS

DECLARE_FLAGS(PROFILEINJECTION_FLAGS)

#endif // SHARE_SERVICES_PROFILEINJECTION_GLOBALS_HPP 