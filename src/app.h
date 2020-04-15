#ifndef BLBENCH_APP_H
#define BLBENCH_APP_H

#include <blend2d.h>
#include "./module.h"

namespace blbench {

// ============================================================================
// [bench::BenchApp]
// ============================================================================

struct BenchApp {
  // Command line
  int _argc;
  char** _argv;

  // Configuration.
  bool _isolated;
  bool _deepBench;
  bool _saveImages;
  uint32_t _compOp;
  uint32_t _repeat;
  uint32_t _quantity;

  // Assets.
  BLImage _sprites[4];

  // --------------------------------------------------------------------------
  // [Construction / Destruction]
  // --------------------------------------------------------------------------

  BenchApp(int argc, char** argv);
  ~BenchApp();

  // --------------------------------------------------------------------------
  // [Args]
  // --------------------------------------------------------------------------

  bool hasArg(const char* key) const;
  const char* valueOf(const char* key) const;
  int intValueOf(const char* key, int defaultValue) const;

  // --------------------------------------------------------------------------
  // [Init / Info]
  // --------------------------------------------------------------------------

  bool init();
  void info();

  bool readImage(BLImage&, const char* name, const void* data, size_t size) noexcept;

  // --------------------------------------------------------------------------
  // [Helpers]
  // --------------------------------------------------------------------------

  bool isStyleEnabled(uint32_t style);

  // --------------------------------------------------------------------------
  // [Run]
  // --------------------------------------------------------------------------

  int run();
  int runModule(BenchModule& mod, BenchParams& params);
};

} // {blbench}

#endif // BLBENCH_APP_H
