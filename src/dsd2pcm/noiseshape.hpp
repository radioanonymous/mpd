#ifndef NOISE_SHAPE_HXX_INCLUDED
#define NOISE_SHAPE_HXX_INCLUDED

#include <stdexcept>
#include "noiseshape.h"

/**
 * C++ wrapper for the noiseshape C library
 */

class noise_shaper
{
	noise_shape_ctx ctx;
public:
	noise_shaper(int sos_count, const float *bbaa)
	{
		if (noise_shape_init(&ctx,sos_count,bbaa))
			throw std::runtime_error("noise shaper initialization failed");
	}

	noise_shaper(noise_shaper const& x)
	{
		if (noise_shape_clone(&x.ctx,&ctx))
			throw std::runtime_error("noise shaper initialization failed");
	}

	~noise_shaper()
	{ noise_shape_destroy(&ctx); }

	noise_shaper& operator=(noise_shaper const& x)
	{
		if (this != &x) {
			noise_shape_destroy(&ctx);
			if (noise_shape_clone(&x.ctx,&ctx))
				throw std::runtime_error("noise shaper initialization failed");
		}
		return *this;
	}

	float get() { return noise_shape_get(&ctx); }

	void update(float error) { noise_shape_update(&ctx,error); }
};

#endif /* NOISE_SHAPE_HXX_INCLUDED */

