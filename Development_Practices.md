# Software Development Practices

Here's a rundown of the established mission-critical practices applied in this project:

**Design by Contract** — every public function documents its preconditions, postconditions, and error returns. Callers and implementers have explicit, verifiable obligations.

**Failure-safe defaults** — `SONAR_ERR_GENERIC = 0` means uninitialized status variables represent failure, not success. This prevents silent pass-through when a developer forgets to check a return value — a principle from IEC 61508 and NASA's JPL Coding Standard.

**Single exit point per function** — every function sets a `status` variable and returns it once at the end. This is a MISRA C / DO-178C requirement that simplifies reasoning about control flow and facilitates code coverage analysis.

**No dynamic memory allocation** — no `malloc` or `new`. All memory is static or stack-allocated. This eliminates heap fragmentation and non-deterministic allocation failure — required by MISRA C, DO-178C, and the JPL Coding Standard.

**Explicit timeouts on all hardware waits** — `SONAR_ECHO_TIMEOUT_US` bounds the ultrasonic pulse wait. Unbounded waits are prohibited in safety-critical systems because they can cause the system to hang.

**Hardware Abstraction Layer** — all hardware access is isolated, enabling host-side testing without physical hardware. This supports the V-model development process used in IEC 61508 and DO-178C.

**Systematic test design (EP + BVA)** — test cases are derived by equivalence partitioning and boundary value analysis, not ad hoc. This gives traceable coverage of the input space, a requirement in safety standards.

**Test-driven increments** — skeleton compiled first, tests written to fail, then implementation until tests pass. This ensures every requirement has a corresponding test before the code is written.

**Type safety via `enum class`** — scoped enumerations prevent implicit integer conversion into pin level/direction arguments, eliminating a class of interface misuse errors at compile time.

**Defensive argument validation at public boundaries** — every function that can receive an invalid argument checks it and returns `SONAR_ERR_ARG` with a descriptive error string. This is a CERT C / CWE mitigation pattern.

**Graceful degradation** — if the OLED fails to initialise, the system falls back to Serial output rather than halting. Fault tolerance and continued operation under partial failure is a core requirement in IEC 61508 higher SIL levels.

**Named constants, no magic numbers** — all hardware parameters are named constants in one place. Prevents subtle bugs from scattered literals and makes parameter changes safe.
