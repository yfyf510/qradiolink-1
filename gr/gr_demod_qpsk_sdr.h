// Written by Adrian Musceac YO8RZZ , started March 2016.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef GR_DEMOD_QPSK_SDR_H
#define GR_DEMOD_QPSK_SDR_H

#include <gnuradio/hier_block2.h>
#include <gnuradio/endianness.h>
#include <gnuradio/filter/firdes.h>
#include <gnuradio/digital/clock_recovery_mm_cc.h>
#include <gnuradio/blocks/unpack_k_bits_bb.h>
#include <gnuradio/blocks/float_to_complex.h>
#include <gnuradio/digital/costas_loop_cc.h>
#include <gnuradio/digital/diff_decoder_bb.h>
#include <gnuradio/digital/cma_equalizer_cc.h>
#include <gnuradio/analog/agc2_cc.h>
#include <gnuradio/digital/fll_band_edge_cc.h>
#include <gnuradio/filter/pfb_arb_resampler_ccf.h>
#include <gnuradio/filter/rational_resampler_base_ccf.h>
#include <gnuradio/filter/freq_xlating_fir_filter_ccf.h>
#include <gnuradio/digital/map_bb.h>
#include <gnuradio/digital/constellation.h>
#include <gnuradio/digital/constellation_decoder_cb.h>
#include <gnuradio/digital/pfb_clock_sync_ccf.h>
#include <gnuradio/filter/fft_filter_ccf.h>
#include <gnuradio/digital/descrambler_bb.h>


class gr_demod_qpsk_sdr;

typedef boost::shared_ptr<gr_demod_qpsk_sdr> gr_demod_qpsk_sdr_sptr;
gr_demod_qpsk_sdr_sptr make_gr_demod_qpsk_sdr(int sps=125, int samp_rate=250000, int carrier_freq=1700,
                                          int filter_width=8000);

class gr_demod_qpsk_sdr : public gr::hier_block2
{
public:
    explicit gr_demod_qpsk_sdr(std::vector<int> signature, int sps=4, int samp_rate=8000, int carrier_freq=1600,
                               int filter_width=1800);


private:
    gr::blocks::unpack_k_bits_bb::sptr _unpack;
    gr::filter::freq_xlating_fir_filter_ccf::sptr _freq_transl_filter;
    gr::digital::cma_equalizer_cc::sptr _equalizer;
    gr::analog::agc2_cc::sptr _agc;
    gr::digital::fll_band_edge_cc::sptr _fll;
    gr::digital::clock_recovery_mm_cc::sptr _clock_recovery;
    gr::digital::pfb_clock_sync_ccf::sptr _clock_sync;
    gr::digital::costas_loop_cc::sptr _costas_loop;
    gr::digital::diff_decoder_bb::sptr _diff_decoder;
    gr::filter::pfb_arb_resampler_ccf::sptr _resampler_pfb;
    gr::filter::rational_resampler_base_ccf::sptr _resampler;
    gr::digital::map_bb::sptr _map;
    gr::digital::constellation_decoder_cb::sptr _constellation_receiver;
    gr::filter::fft_filter_ccf::sptr _shaping_filter;
    gr::filter::fft_filter_ccf::sptr _filter;
    gr::digital::descrambler_bb::sptr _descrambler;


    int _samples_per_symbol;
    int _samp_rate;
    int _carrier_freq;
    int _filter_width;
    int _target_samp_rate;

};

#endif // GR_DEMOD_QPSK_SDR_H
