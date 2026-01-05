#ifndef PAUL_LIBRARY_H
#define PAUL_LIBRARY_H
#include <cstdint>
#include <optional>
#include <random>

class Paul
{
	public:
		Paul();
		explicit Paul(const std::array<double, 20>& weights, std::optional<std::uint_fast32_t> seed=std::nullopt);
		std::string_view answer(std::string_view s);
		void updateWeights(const std::array<double, 20>& newWeights);
		[[nodiscard]] std::vector<double> getWeights() const;
	private:
		std::discrete_distribution<> weights;
		std::mt19937 random_generator;
};

#endif // PAUL_LIBRARY_H