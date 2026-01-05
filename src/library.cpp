#include <array>
#include <library.hpp>

constexpr std::array<const char*, 20> answers{
    "It is certain",
    "It is decidedly so",
    "Without a doubt",
    "Yes definitely",
    "You may rely on it",
    "As I see it, yes",
    "Most likely",
    "Outlook good",
    "Yes",
    "Signs point to yes",
    "Reply hazy, try again",
    "Ask again later",
    "Better not tell you now",
    "Cannot predict now",
    "Concentrate and ask again",
    "Don't count on it",
    "My reply is no",
    "My sources say no",
    "Outlook not so good",
    "Very doubtful"
};

Paul::Paul()
	: Paul({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1})
{}

Paul::Paul(const std::array<double, 20>& weights, std::optional<std::uint_fast32_t> seed)
	: weights(weights.begin(), weights.end())
	, random_generator(seed ? *seed : std::mt19937::default_seed)
{
}

std::string_view Paul::answer(std::string_view)
{
	return {answers[weights(random_generator)]};
}

void Paul::updateWeights(const std::array<double, 20>& newWeights)
{
	weights.param({newWeights.begin(), newWeights.end()});
}

std::vector<double> Paul::getWeights() const
{
	return weights.probabilities();
}