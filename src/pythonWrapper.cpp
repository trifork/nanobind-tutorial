//
// Created by pbe on 05.01.2026.
//

#include <library.hpp>

#include <nanobind/nanobind.h>
#include <nanobind/stl/string_view.h>

using namespace nanobind::literals;

NB_MODULE(paul, m)
{
	nanobind::class_<Paul>(m, "Paul", "The Perfect Awesome Ultimate LLM")
		.def(nanobind::init())
		.def("answer", &Paul::answer, "question"_a );
}