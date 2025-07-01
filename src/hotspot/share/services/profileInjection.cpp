#include "precompiled.hpp"
#include "services/profileInjection.hpp"
#include "ci/ciReplay.hpp"
#include "compiler/compiler_globals.hpp"
#include "services/profileInjection_globals.hpp"
#include "utilities/ostream.hpp"

void ProfileInjection::inject_profiles(TRAPS) {
  if (!should_inject_profiles()) {
    return;
  }

  trace_injection("Starting profile injection");

  // Call the new ciReplay function that does profile injection without VM exit
  int result = ciReplay::inject_profiles_impl(THREAD);

  if (result != 0) {
    tty->print_cr("ERROR: ProfileInjection failed with exit code: %d", result);
    return;
  }

  trace_injection("Profile injection completed successfully - resuming normal execution");
  tty->print_cr("ProfileInjection: Successfully injected profile data from %s", ReplayDataFile);
  
  // Note: Unlike ciReplay::replay(), we do NOT call vm_exit() here.
  // We let the VM continue with the injected profile data.
}

bool ProfileInjection::should_inject_profiles() {
  return InjectProfiles;
}

void ProfileInjection::trace_injection(const char* message) {
  if (TraceProfileInjection) {
    tty->print_cr("ProfileInjection: %s", message);
  }
} 