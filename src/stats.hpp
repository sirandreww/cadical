#ifndef _stats_hpp_INCLUDED
#define _stats_hpp_INCLUDED

#include <cstdlib>

namespace CaDiCaL {

class Internal;

struct Stats {

  Internal * internal;

  long conflicts;    // generated conflicts in 'propagate'
  long decisions;    // number of decisions in 'decide'
  long propagations; // propagated literals in 'propagate'
  long restarts;     // actual number of happened restarts
  long reused;       // number of reused trails
  long reports;      // 'report' counter
  long sections;     // 'section' counter
  long bumped;       // seen and bumped variables in 'analyze'
  long touched;      // touched literals in deleted clauses
  long bumplast;     // bumped variables on last decision level
  long trailbumped;  // bumped 'reverse' instead of 'earlier'
  long analyzed;     // analyzed redundant clauses
  long searched;     // searched decisions in 'decide'
  long reductions;   // 'reduce' counter
  long reduced;      // number of reduced clauses
  long collected;    // number of collected bytes
  long collections;  // number of garbage collections
  long shrunken;     // removed literals in learned clauses
  long shrinktried;  // number of tried to shrink literals
  long sublast;      // number of eagerly subsumed clauses
  long subsumed;     // number of subsumed clauses
  long strengthened; // number of strengthened clauses
  long subirr;       // number of subsumed irredundant clauses
  long subred;       // number of subsumed redundant clauses
  long subtried;     // number of tried subsumptions
  long subchecks;    // number of pair-wise subsumption checks
  long subchecks2;   // same but restricted to binary clauses
  long subsumptions; // number of subsumption phases
  long resolved;     // number of resolved clauses in eliminations
  long resolved2;    // number of resolved binary clauses
  long restried;     // number of tried resolved clauses
  long eliminations; // number of subsumption phases
  long learned;      // learned literals
  long minimized;    // minimized literals
  long redundant;    // number of current redundant clauses
  long irredundant;  // number of current irredundant clauses
  long garbage;      // number of current garbage clauses
  long units;        // learned unit clauses
  long binaries;     // learned binary clauses
#ifdef STATS
  long visits;       // visited clauses in propagation
  long traversed;    // traversed literals in propagation
#endif

  int fixed;         // number of top level assigned variables
  int eliminated;    // number of eliminated variables

  size_t allocated;  // number of (explicitly) allocated bytes
  size_t implicit;   // implicitly approximated allocated bytes
  size_t maxbytes;   // maximum number of allocated bytes

  Stats ();
  void print (Internal *);
};

/*------------------------------------------------------------------------*/

#ifdef STATS
#define EXPENSIVE_STATS_ADD(STAT,INC) do { stats.STAT += (INC); } while (0)
#else
#define EXPENSIVE_STATS_ADD(STAT,INC) do { } while (0)
#endif

/*------------------------------------------------------------------------*/

};

#endif
