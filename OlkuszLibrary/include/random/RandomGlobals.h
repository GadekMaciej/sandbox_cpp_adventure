#pragma once

#include <random>
#include <array>

namespace olk::random::globals
{
	std::vector<uint32_t> create_random_seed_sequence(std::size_t seed_size = global_default_seed_size);

	inline constexpr std::size_t global_default_seed_size = 8;
	inline std::array<uint32_t, global_default_seed_size> global_random_seed_vector = create_random_seed_sequence();

	/* Seed sequences provide a better random results than a single uin32_t when passed to a pseudo random generator like mt19937 */
	std::vector<uint32_t> create_random_seed_sequence(size_t seed_size = global_default_seed_size)
	{
		std::random_device random_device;
		std::vector<std::uint32_t> seeds;
		seeds.reserve(seed_size);
		for (size_t i = 0; i < seed_size; ++i)
		{
			// using random_device() in a loop might be slow on some systems if it relies on hardware entropy
			seeds.push_back(random_device());
		}
		return seeds;
	}

	inline std::mt19937 global_random_engine(std::random_device{}());
	// Function to get a reference to the global random engine
	inline std::mt19937& get_global_random_engine()
	{
		return global_random_engine;
	}
}