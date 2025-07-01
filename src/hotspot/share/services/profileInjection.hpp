#ifndef SHARE_SERVICES_PROFILEINJECTION_HPP
#define SHARE_SERVICES_PROFILEINJECTION_HPP

#include "memory/allocation.hpp"
#include "utilities/exceptions.hpp"

//
// Profile injection functionality - loads profiling data from replay files
// and resumes normal execution (unlike ReplayCompiles which exits after replay).
//
// Usage:
//   java -XX:+UnlockDiagnosticVMOptions -XX:+InjectProfiles -XX:ReplayDataFile=profiles.txt MyApp
//

// class ciMethod;
// class ciInlineRecord;
// template<typename T> class GrowableArray;

// class CompileReplay : public StackObj {
//  public:
//   CompileReplay(const char* filename, TRAPS);
//   bool  can_replay();
//   void  process(TRAPS);
//   bool  had_error();
//   const char* error_message();

//   void* process_inline(ciMethod* imethod, Method* m,
//                        int entry_bci, int comp_level, TRAPS);
// };

class ProfileInjection : public AllStatic {
public:
  // Main entry point - inject profiling data from ReplayDataFile and continue execution
  static void inject_profiles(TRAPS);

private:
  // Internal implementation
  static bool should_inject_profiles();
  static void trace_injection(const char* message);
};



#endif // SHARE_SERVICES_PROFILEINJECTION_HPP 