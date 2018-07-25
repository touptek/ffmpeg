#include "ffmpeg.h"

#define MY_IMPL_FUN0(r, f)							r my_##f() { return f(); }
#define MY_IMPL_FUN1(r, f, at)						r my_##f(at av)	{ return f(av);	}
#define MY_IMPL_FUN2(r, f, at0, at1)				r my_##f(at0 av0, at1 av1) { return f(av0, av1); }
#define MY_IMPL_FUN3(r, f, at0, at1, at2)			r my_##f(at0 av0, at1 av1, at2 av2)	{ return f(av0, av1, av2); }
#define MY_IMPL_FUN4(r, f, at0, at1, at2, at3)		r my_##f(at0 av0, at1 av1, at2 av2, at3 av3) { return f(av0, av1, av2, av3); }
#define MY_IMPL_FUN5(r, f, at0, at1, at2, at3, at4)	r my_##f(at0 av0, at1 av1, at2 av2, at3 av3, at4 av4) { return f(av0, av1, av2, av3, av4); }

MY_IMPL_FUN4(int, av_dict_set, AVDictionary**, const char*, const char*, int);
MY_IMPL_FUN1(void, av_dict_free, AVDictionary**);
MY_IMPL_FUN0(AVFrame*, av_frame_alloc);
MY_IMPL_FUN4(int, avformat_open_input, AVFormatContext**, const char*, AVInputFormat*, AVDictionary**);
MY_IMPL_FUN1(void, avformat_close_input, AVFormatContext**);
MY_IMPL_FUN1(void, av_frame_free, AVFrame**);
MY_IMPL_FUN1(void, av_packet_unref, AVPacket*);
MY_IMPL_FUN2(int, av_write_frame, AVFormatContext*, AVPacket*);
MY_IMPL_FUN4(int, avcodec_decode_video2, AVCodecContext*, AVFrame*, int*, const AVPacket*);
MY_IMPL_FUN1(AVCodec*, avcodec_find_decoder, AVCodecID);
MY_IMPL_FUN1(AVCodecContext*, avcodec_alloc_context3, const AVCodec*);
MY_IMPL_FUN2(int, avcodec_parameters_to_context, AVCodecContext*, const AVCodecParameters*);
MY_IMPL_FUN3(int, avcodec_open2, AVCodecContext*, const AVCodec*, AVDictionary**);
MY_IMPL_FUN1(int, av_read_play, AVFormatContext*);
MY_IMPL_FUN4(int, av_seek_frame, AVFormatContext*, int, int64_t, int);
MY_IMPL_FUN1(void, av_init_packet, AVPacket*);
MY_IMPL_FUN0(AVFormatContext*, avformat_alloc_context);
MY_IMPL_FUN3(AVOutputFormat*, av_guess_format, const char*, const char*, const char*);
MY_IMPL_FUN2(AVStream*, avformat_new_stream, AVFormatContext*, const AVCodec*);
MY_IMPL_FUN5(int, avio_open2, AVIOContext**, const char*, int, const AVIOInterruptCB*, AVDictionary**);
MY_IMPL_FUN2(int, avcodec_parameters_from_context, AVCodecParameters*, const AVCodecContext*);
MY_IMPL_FUN2(int, av_read_frame, AVFormatContext*, AVPacket*);
MY_IMPL_FUN2(int, avformat_write_header, AVFormatContext*, AVDictionary**);
MY_IMPL_FUN1(int, avio_closep, AVIOContext**);
MY_IMPL_FUN1(int, av_write_trailer, AVFormatContext*);
MY_IMPL_FUN1(int, avcodec_close, AVCodecContext*);
MY_IMPL_FUN1(void, avformat_free_context, AVFormatContext*);
MY_IMPL_FUN2(int, avformat_find_stream_info, AVFormatContext*, AVDictionary**);
MY_IMPL_FUN2(int, av_interleaved_write_frame, AVFormatContext*, AVPacket*);
MY_IMPL_FUN4(int, avformat_alloc_output_context2, AVFormatContext**, AVOutputFormat*, const char*, const char*);
MY_IMPL_FUN4(void, av_dump_format, AVFormatContext*, int, const char*, int);
MY_IMPL_FUN3(int, avio_open, AVIOContext**, const char*, int);
MY_IMPL_FUN1(void, avcodec_free_context, AVCodecContext**);
MY_IMPL_FUN1(void, av_packet_free, AVPacket**);
MY_IMPL_FUN2(int, av_frame_get_buffer, AVFrame*, int);
MY_IMPL_FUN1(AVCodec*, avcodec_find_encoder_by_name, const char*);
MY_IMPL_FUN0(AVPacket*, av_packet_alloc);
MY_IMPL_FUN2(int, avcodec_receive_packet, AVCodecContext*, AVPacket*);
MY_IMPL_FUN2(int, avcodec_send_frame, AVCodecContext*, const AVFrame*);
MY_IMPL_FUN3(void, av_packet_rescale_ts, AVPacket*, AVRational, AVRational);
MY_IMPL_FUN1(void, sws_freeContext, SwsContext*);
SwsContext* my_sws_getCachedContext(SwsContext *context, int srcW, int srcH, AVPixelFormat srcFormat, int dstW, int dstH, AVPixelFormat dstFormat, int flags, SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
	return sws_getCachedContext(context, srcW, srcH, srcFormat, dstW, dstH, dstFormat, flags, srcFilter, dstFilter, param);
}
SwsContext* my_sws_getContext(int srcW, int srcH, AVPixelFormat srcFormat, int dstW, int dstH, AVPixelFormat dstFormat, int flags, SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
	return sws_getContext(srcW, srcH, srcFormat, dstW, dstH, dstFormat, flags, srcFilter, dstFilter, param);
}
int my_sws_scale(SwsContext *c, const uint8_t *const srcSlice[], const int srcStride[], int srcSliceY, int srcSliceH, uint8_t *const dst[], const int dstStride[])
{
	return sws_scale(c, srcSlice, srcStride, srcSliceY, srcSliceH, dst, dstStride);
}
