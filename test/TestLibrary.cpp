//
// Created by pbe on 05.01.2026.
//

#include <library.hpp>
#include <catch2/catch_test_macros.hpp>

SCENARIO("Default object")
{
	GIVEN("a default constructed object")
	{
		auto DUT = Paul();
		WHEN("asking a question")
		{
			auto answer = DUT.answer("What is the meaning of life?");
			THEN("an answer is given")
			{
				REQUIRE_FALSE( answer.empty());
			}
		}
		WHEN("the weights are requested")
		{
			auto weights = DUT.getWeights();
			THEN("There are 20 possible weights")
			{
				REQUIRE(weights.size() == 20);
			}
		}
		WHEN("setting the weights to a single answer")
		{
			std::array<double, 20> newWeights{0};
			newWeights[8] = 1.0;
			DUT.updateWeights(newWeights);
			THEN("That answer will be given")
			{
				REQUIRE( DUT.answer("Am I good looking?") == "Yes");
			}
		}
	}
}