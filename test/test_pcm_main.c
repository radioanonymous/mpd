/*
 * Copyright (C) 2003-2011 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "test_pcm_all.h"
#include "test_glib_compat.h"

#include <glib.h>

int
main(int argc, char **argv)
{
	g_test_init (&argc, &argv, NULL);
	g_test_add_func("/pcm/dither/24", test_pcm_dither_24);
	g_test_add_func("/pcm/dither/32", test_pcm_dither_32);
	g_test_add_func("/pcm/pack/pack24", test_pcm_pack_24);
	g_test_add_func("/pcm/pack/unpack24", test_pcm_unpack_24);
	g_test_add_func("/pcm/channels/16", test_pcm_channels_16);
	g_test_add_func("/pcm/channels/32", test_pcm_channels_32);
	g_test_add_func("/pcm/byteswap/16", test_pcm_byteswap_16);
	g_test_add_func("/pcm/byteswap/32", test_pcm_byteswap_32);

	g_test_run();
}
