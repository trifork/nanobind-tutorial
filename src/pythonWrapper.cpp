//
// Created by pbe on 05.01.2026.
//

#include <library.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h> // To define ParameterSet
#include <nanobind/stl/string_view.h>
#include <nanobind/stl/vector.h> // To convert from getWeights
#include <nanobind/stl/array.h> // To convert to updateWeights

using namespace nanobind::literals;

NB_MODULE(paul, m)
{
	using ParameterSet = nanobind::ndarray<double, nanobind::shape<20>, nanobind::device::cpu>;

	nanobind::class_<Paul>(m, "Paul", "The Perfect Awesome Ultimate LLM")
		.def(nanobind::init())
		.def("answer", &Paul::answer, "question"_a )
		.def_prop_rw("weights", &Paul::getWeights, &Paul::updateWeights)
		.def("update_weights", [](Paul &self, const ParameterSet& newWeights)
				{
					std::array<double, 20> weights;
					for (int i = 0; i < weights.size(); i++)
					{
						weights[i] = newWeights(i);
					}
					self.updateWeights(weights);
				}
		);
}