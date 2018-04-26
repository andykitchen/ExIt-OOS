#ifndef OZ_GOOFSPIEL2_ENCODER_H
#define OZ_GOOFSPIEL2_ENCODER_H

#include <ATen/ATen.h>

#include "encoder.h"

#include "game.h"
#include "oos.h"

#include "games/goofspiel2.h"

namespace oz {

using std::vector;
using std::map;

using at::Tensor;

class goofspiel2_encoder_t final : public encoder_t {
 public:
  goofspiel2_encoder_t(int n_cards): n_cards_(n_cards) { };

  int encoding_size() override;
  int max_actions() override;
  void encode(oz::infoset_t infoset, Tensor x) override;
  map<oz::action_t, prob_t> decode(oz::infoset_t infoset, Tensor x) override;
  action_prob_t decode_and_sample(oz::infoset_t infoset, Tensor x, rng_t &rng) override;

 private:
  int n_cards_;
};

};

#endif // OZ_GOOFSPIEL2_ENCODER_H