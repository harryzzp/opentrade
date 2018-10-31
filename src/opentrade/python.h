#ifndef OPENTRADE_PYTHON_H_
#define OPENTRADE_PYTHON_H_

#include <Python.h>

#include "algo.h"

namespace opentrade {

struct PyModule {
  PyObject* on_start = nullptr;
  PyObject* on_stop = nullptr;
  PyObject* on_market_trade = nullptr;
  PyObject* on_market_quote = nullptr;
  PyObject* on_confirmation = nullptr;
  PyObject* get_param_defs = nullptr;
};

class Python : public Algo {
 public:
  static Python* Load(const std::string& fn);
  std::string OnStart(const ParamMap& params) noexcept override;
  void OnStop() noexcept override;
  void OnMarketTrade(const Instrument& inst, const MarketData& md,
                     const MarketData& md0) noexcept override;
  void OnMarketQuote(const Instrument& inst, const MarketData& md,
                     const MarketData& md0) noexcept override;
  void OnConfirmation(const Confirmation& cm) noexcept override;
  const ParamDefs& GetParamDefs() noexcept override;

 private:
  PyModule py_;
};

void InitalizePy();

}  // namespace opentrade

#endif  // OPENTRADE_PYTHON_H_
