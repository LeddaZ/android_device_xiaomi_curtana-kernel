/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __MEDIA_INFO_H__
#define __MEDIA_INFO_H__
#ifndef MSM_MEDIA_ALIGN
#define MSM_MEDIA_ALIGN(__sz,__align) (((__align) & ((__align) - 1)) ? ((((__sz) + (__align) - 1) / (__align)) * (__align)) : (((__sz) + (__align) - 1) & (~((__align) - 1))))
#endif
#ifndef MSM_MEDIA_ROUNDUP
#define MSM_MEDIA_ROUNDUP(__sz,__r) (((__sz) + ((__r) - 1)) / (__r))
#endif
#ifndef MSM_MEDIA_MAX
#define MSM_MEDIA_MAX(__a,__b) ((__a) > (__b) ? (__a) : (__b))
#endif
enum color_fmts {
  COLOR_FMT_NV12,
  COLOR_FMT_NV21,
  COLOR_FMT_NV12_MVTB,
  COLOR_FMT_NV12_UBWC,
  COLOR_FMT_NV12_BPP10_UBWC,
  COLOR_FMT_RGBA8888,
  COLOR_FMT_RGBA8888_UBWC,
  COLOR_FMT_RGBA1010102_UBWC,
  COLOR_FMT_RGB565_UBWC,
  COLOR_FMT_P010_UBWC,
  COLOR_FMT_P010,
  COLOR_FMT_RGBA16161616_F_UBWC,
  COLOR_FMT_NV12_512,
};
#define COLOR_FMT_RGBA16161616_F_UBWC COLOR_FMT_RGBA16161616_F_UBWC
#define COLOR_FMT_RGBA1010102_UBWC COLOR_FMT_RGBA1010102_UBWC
#define COLOR_FMT_RGB565_UBWC COLOR_FMT_RGB565_UBWC
#define COLOR_FMT_P010_UBWC COLOR_FMT_P010_UBWC
#define COLOR_FMT_P010 COLOR_FMT_P010
#define COLOR_FMT_NV12_512 COLOR_FMT_NV12_512

static __inline__ unsigned int VENUS_EXTRADATA_SIZE(int width, int height)
{
	return 16 * 1024;
}

static __inline__ unsigned int VENUS_Y_STRIDE(int color_fmt, int width)
{
	unsigned int alignment, stride = 0;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_NV12_MVTB:
	case COLOR_FMT_NV12_UBWC:
		alignment = 128;
		stride = MSM_MEDIA_ALIGN(width, alignment);
		break;
	case COLOR_FMT_NV12_512:
		alignment = 512;
		stride = MSM_MEDIA_ALIGN(width, alignment);
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width, 192);
		stride = MSM_MEDIA_ALIGN(stride * 4/3, alignment);
		break;
	case COLOR_FMT_P010_UBWC:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width * 2, alignment);
		break;
	case COLOR_FMT_P010:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width*2, alignment);
		break;
	default:
		break;
	}
invalid_input:
	return stride;
}

static __inline__ unsigned int VENUS_UV_STRIDE(int color_fmt, int width)
{
	unsigned int alignment, stride = 0;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_NV12_MVTB:
	case COLOR_FMT_NV12_UBWC:
		alignment = 128;
		stride = MSM_MEDIA_ALIGN(width, alignment);
		break;
	case COLOR_FMT_NV12_512:
		alignment = 512;
		stride = MSM_MEDIA_ALIGN(width, alignment);
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width, 192);
		stride = MSM_MEDIA_ALIGN(stride * 4/3, alignment);
		break;
	case COLOR_FMT_P010_UBWC:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width * 2, alignment);
		break;
	case COLOR_FMT_P010:
		alignment = 256;
		stride = MSM_MEDIA_ALIGN(width*2, alignment);
		break;
	default:
		break;
	}
invalid_input:
	return stride;
}

static __inline__ unsigned int VENUS_Y_SCANLINES(int color_fmt, int height)
{
	unsigned int alignment, sclines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_NV12_MVTB:
	case COLOR_FMT_NV12_UBWC:
	case COLOR_FMT_P010:
		alignment = 32;
		break;
	case COLOR_FMT_NV12_512:
		alignment = 512;
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
	case COLOR_FMT_P010_UBWC:
		alignment = 16;
		break;
	default:
		return 0;
	}
	sclines = MSM_MEDIA_ALIGN(height, alignment);
invalid_input:
	return sclines;
}

static __inline__ unsigned int VENUS_UV_SCANLINES(int color_fmt, int height)
{
	unsigned int alignment, sclines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_NV12_MVTB:
	case COLOR_FMT_NV12_BPP10_UBWC:
	case COLOR_FMT_P010_UBWC:
	case COLOR_FMT_P010:
		alignment = 16;
		break;
	case COLOR_FMT_NV12_512:
		alignment = 256;
		break;
	case COLOR_FMT_NV12_UBWC:
		alignment = 32;
		break;
	default:
		goto invalid_input;
	}

	sclines = MSM_MEDIA_ALIGN((height+1)>>1, alignment);

invalid_input:
	return sclines;
}

static __inline__ unsigned int VENUS_Y_META_STRIDE(int color_fmt, int width)
{
	int y_tile_width = 0, y_meta_stride = 0;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV12_UBWC:
	case COLOR_FMT_P010_UBWC:
		y_tile_width = 32;
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
		y_tile_width = 48;
		break;
	default:
		goto invalid_input;
	}

	y_meta_stride = MSM_MEDIA_ROUNDUP(width, y_tile_width);
	y_meta_stride = MSM_MEDIA_ALIGN(y_meta_stride, 64);

invalid_input:
	return y_meta_stride;
}

static __inline__ unsigned int VENUS_Y_META_SCANLINES(int color_fmt, int height)
{
	int y_tile_height = 0, y_meta_scanlines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV12_UBWC:
		y_tile_height = 8;
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
	case COLOR_FMT_P010_UBWC:
		y_tile_height = 4;
		break;
	default:
		goto invalid_input;
	}

	y_meta_scanlines = MSM_MEDIA_ROUNDUP(height, y_tile_height);
	y_meta_scanlines = MSM_MEDIA_ALIGN(y_meta_scanlines, 16);

invalid_input:
	return y_meta_scanlines;
}

static __inline__ unsigned int VENUS_UV_META_STRIDE(int color_fmt, int width)
{
	int uv_tile_width = 0, uv_meta_stride = 0;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV12_UBWC:
	case COLOR_FMT_P010_UBWC:
		uv_tile_width = 16;
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
		uv_tile_width = 24;
		break;
	default:
		goto invalid_input;
	}

	uv_meta_stride = MSM_MEDIA_ROUNDUP((width+1)>>1, uv_tile_width);
	uv_meta_stride = MSM_MEDIA_ALIGN(uv_meta_stride, 64);

invalid_input:
	return uv_meta_stride;
}

static __inline__ unsigned int VENUS_UV_META_SCANLINES(int color_fmt, int height)
{
	int uv_tile_height = 0, uv_meta_scanlines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_NV12_UBWC:
		uv_tile_height = 8;
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
	case COLOR_FMT_P010_UBWC:
		uv_tile_height = 4;
		break;
	default:
		goto invalid_input;
	}

	uv_meta_scanlines = MSM_MEDIA_ROUNDUP((height+1)>>1, uv_tile_height);
	uv_meta_scanlines = MSM_MEDIA_ALIGN(uv_meta_scanlines, 16);

invalid_input:
	return uv_meta_scanlines;
}

static __inline__ unsigned int VENUS_RGB_STRIDE(int color_fmt, int width)
{
	unsigned int alignment = 0, stride = 0, bpp = 4;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_RGBA8888:
		alignment = 128;
		break;
	case COLOR_FMT_RGB565_UBWC:
		alignment = 256;
		bpp = 2;
		break;
	case COLOR_FMT_RGBA8888_UBWC:
	case COLOR_FMT_RGBA1010102_UBWC:
		alignment = 256;
		break;
	case COLOR_FMT_RGBA16161616_F_UBWC:
		alignment = 256;
		bpp = 8;
		break;
	default:
		goto invalid_input;
	}

	stride = MSM_MEDIA_ALIGN(width * bpp, alignment);

invalid_input:
	return stride;
}

static __inline__ unsigned int VENUS_RGB_SCANLINES(int color_fmt, int height)
{
	unsigned int alignment = 0, scanlines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_RGBA8888:
		alignment = 32;
		break;
	case COLOR_FMT_RGBA8888_UBWC:
	case COLOR_FMT_RGBA1010102_UBWC:
	case COLOR_FMT_RGB565_UBWC:
	case COLOR_FMT_RGBA16161616_F_UBWC:
		alignment = 16;
		break;
	default:
		goto invalid_input;
	}

	scanlines = MSM_MEDIA_ALIGN(height, alignment);

invalid_input:
	return scanlines;
}

static __inline__ unsigned int VENUS_RGB_META_STRIDE(int color_fmt, int width)
{
	int rgb_tile_width = 0, rgb_meta_stride = 0;

	if (!width)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_RGBA8888_UBWC:
	case COLOR_FMT_RGBA1010102_UBWC:
	case COLOR_FMT_RGB565_UBWC:
		rgb_tile_width = 16;
		break;
	case COLOR_FMT_RGBA16161616_F_UBWC:
		rgb_tile_width = 8;
		break;
	default:
		goto invalid_input;
	}

	rgb_meta_stride = MSM_MEDIA_ROUNDUP(width, rgb_tile_width);
	rgb_meta_stride = MSM_MEDIA_ALIGN(rgb_meta_stride, 64);

invalid_input:
	return rgb_meta_stride;
}

static __inline__ unsigned int VENUS_RGB_META_SCANLINES(int color_fmt, int height)
{
	int rgb_tile_height = 0, rgb_meta_scanlines = 0;

	if (!height)
		goto invalid_input;

	switch (color_fmt) {
	case COLOR_FMT_RGBA8888_UBWC:
	case COLOR_FMT_RGBA1010102_UBWC:
	case COLOR_FMT_RGB565_UBWC:
	case COLOR_FMT_RGBA16161616_F_UBWC:
		rgb_tile_height = 4;
		break;
	default:
		goto invalid_input;
	}

	rgb_meta_scanlines = MSM_MEDIA_ROUNDUP(height, rgb_tile_height);
	rgb_meta_scanlines = MSM_MEDIA_ALIGN(rgb_meta_scanlines, 16);

invalid_input:
	return rgb_meta_scanlines;
}

static __inline__ unsigned int VENUS_BUFFER_SIZE(
	int color_fmt, int width, int height)
{
	unsigned int uv_alignment = 0, size = 0;
	unsigned int y_plane, uv_plane, y_stride,
		uv_stride, y_sclines, uv_sclines;
	unsigned int y_ubwc_plane = 0, uv_ubwc_plane = 0;
	unsigned int y_meta_stride = 0, y_meta_scanlines = 0;
	unsigned int uv_meta_stride = 0, uv_meta_scanlines = 0;
	unsigned int y_meta_plane = 0, uv_meta_plane = 0;
	unsigned int rgb_stride = 0, rgb_scanlines = 0;
	unsigned int rgb_plane = 0, rgb_ubwc_plane = 0, rgb_meta_plane = 0;
	unsigned int rgb_meta_stride = 0, rgb_meta_scanlines = 0;

	if (!width || !height)
		goto invalid_input;

	y_stride = VENUS_Y_STRIDE(color_fmt, width);
	uv_stride = VENUS_UV_STRIDE(color_fmt, width);
	y_sclines = VENUS_Y_SCANLINES(color_fmt, height);
	uv_sclines = VENUS_UV_SCANLINES(color_fmt, height);
	rgb_stride = VENUS_RGB_STRIDE(color_fmt, width);
	rgb_scanlines = VENUS_RGB_SCANLINES(color_fmt, height);

	switch (color_fmt) {
	case COLOR_FMT_NV21:
	case COLOR_FMT_NV12:
	case COLOR_FMT_P010:
	case COLOR_FMT_NV12_512:
		uv_alignment = 4096;
		y_plane = y_stride * y_sclines;
		uv_plane = uv_stride * uv_sclines + uv_alignment;
		size = y_plane + uv_plane;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_NV12_MVTB:
		uv_alignment = 4096;
		y_plane = y_stride * y_sclines;
		uv_plane = uv_stride * uv_sclines + uv_alignment;
		size = y_plane + uv_plane;
		size = 2 * size;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_NV12_UBWC:
		y_sclines = VENUS_Y_SCANLINES(color_fmt, (height+1)>>1);
		y_ubwc_plane = MSM_MEDIA_ALIGN(y_stride * y_sclines, 4096);
		uv_sclines = VENUS_UV_SCANLINES(color_fmt, (height+1)>>1);
		uv_ubwc_plane = MSM_MEDIA_ALIGN(uv_stride * uv_sclines, 4096);
		y_meta_stride = VENUS_Y_META_STRIDE(color_fmt, width);
		y_meta_scanlines =
			VENUS_Y_META_SCANLINES(color_fmt, (height+1)>>1);
		y_meta_plane = MSM_MEDIA_ALIGN(
			y_meta_stride * y_meta_scanlines, 4096);
		uv_meta_stride = VENUS_UV_META_STRIDE(color_fmt, width);
		uv_meta_scanlines =
			VENUS_UV_META_SCANLINES(color_fmt, (height+1)>>1);
		uv_meta_plane = MSM_MEDIA_ALIGN(uv_meta_stride *
			uv_meta_scanlines, 4096);

		size = (y_ubwc_plane + uv_ubwc_plane + y_meta_plane +
			uv_meta_plane)*2;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_NV12_BPP10_UBWC:
		y_ubwc_plane = MSM_MEDIA_ALIGN(y_stride * y_sclines, 4096);
		uv_ubwc_plane = MSM_MEDIA_ALIGN(uv_stride * uv_sclines, 4096);
		y_meta_stride = VENUS_Y_META_STRIDE(color_fmt, width);
		y_meta_scanlines = VENUS_Y_META_SCANLINES(color_fmt, height);
		y_meta_plane = MSM_MEDIA_ALIGN(
				y_meta_stride * y_meta_scanlines, 4096);
		uv_meta_stride = VENUS_UV_META_STRIDE(color_fmt, width);
		uv_meta_scanlines = VENUS_UV_META_SCANLINES(color_fmt, height);
		uv_meta_plane = MSM_MEDIA_ALIGN(uv_meta_stride *
					uv_meta_scanlines, 4096);

		size = y_ubwc_plane + uv_ubwc_plane + y_meta_plane +
			uv_meta_plane;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_P010_UBWC:
		y_ubwc_plane = MSM_MEDIA_ALIGN(y_stride * y_sclines, 4096);
		uv_ubwc_plane = MSM_MEDIA_ALIGN(uv_stride * uv_sclines, 4096);
		y_meta_stride = VENUS_Y_META_STRIDE(color_fmt, width);
		y_meta_scanlines = VENUS_Y_META_SCANLINES(color_fmt, height);
		y_meta_plane = MSM_MEDIA_ALIGN(
				y_meta_stride * y_meta_scanlines, 4096);
		uv_meta_stride = VENUS_UV_META_STRIDE(color_fmt, width);
		uv_meta_scanlines = VENUS_UV_META_SCANLINES(color_fmt, height);
		uv_meta_plane = MSM_MEDIA_ALIGN(uv_meta_stride *
					uv_meta_scanlines, 4096);

		size = y_ubwc_plane + uv_ubwc_plane + y_meta_plane +
			uv_meta_plane;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_RGBA8888:
		rgb_plane = MSM_MEDIA_ALIGN(rgb_stride  * rgb_scanlines, 4096);
		size = rgb_plane;
		size =  MSM_MEDIA_ALIGN(size, 4096);
		break;
	case COLOR_FMT_RGBA8888_UBWC:
	case COLOR_FMT_RGBA1010102_UBWC:
	case COLOR_FMT_RGB565_UBWC:
	case COLOR_FMT_RGBA16161616_F_UBWC:
		rgb_ubwc_plane = MSM_MEDIA_ALIGN(rgb_stride * rgb_scanlines,
							4096);
		rgb_meta_stride = VENUS_RGB_META_STRIDE(color_fmt, width);
		rgb_meta_scanlines = VENUS_RGB_META_SCANLINES(color_fmt,
					height);
		rgb_meta_plane = MSM_MEDIA_ALIGN(rgb_meta_stride *
					rgb_meta_scanlines, 4096);
		size = rgb_ubwc_plane + rgb_meta_plane;
		size = MSM_MEDIA_ALIGN(size, 4096);
		break;
	default:
		break;
	}
invalid_input:
	return size;
}

static __inline__ unsigned int VENUS_BUFFER_SIZE_USED(
	int color_fmt, int width, int height, int interlace)
{
	unsigned int size = 0;
	unsigned int y_stride, uv_stride, y_sclines, uv_sclines;
	unsigned int y_ubwc_plane = 0, uv_ubwc_plane = 0;
	unsigned int y_meta_stride = 0, y_meta_scanlines = 0;
	unsigned int uv_meta_stride = 0, uv_meta_scanlines = 0;
	unsigned int y_meta_plane = 0, uv_meta_plane = 0;

	if (!width || !height)
		goto invalid_input;

	if (!interlace && color_fmt == COLOR_FMT_NV12_UBWC) {
		y_stride = VENUS_Y_STRIDE(color_fmt, width);
		uv_stride = VENUS_UV_STRIDE(color_fmt, width);
		y_sclines = VENUS_Y_SCANLINES(color_fmt, height);
		y_ubwc_plane = MSM_MEDIA_ALIGN(y_stride * y_sclines, 4096);
		uv_sclines = VENUS_UV_SCANLINES(color_fmt, height);
		uv_ubwc_plane = MSM_MEDIA_ALIGN(uv_stride * uv_sclines, 4096);
		y_meta_stride = VENUS_Y_META_STRIDE(color_fmt, width);
		y_meta_scanlines =
			VENUS_Y_META_SCANLINES(color_fmt, height);
		y_meta_plane = MSM_MEDIA_ALIGN(
			y_meta_stride * y_meta_scanlines, 4096);
		uv_meta_stride = VENUS_UV_META_STRIDE(color_fmt, width);
		uv_meta_scanlines =
			VENUS_UV_META_SCANLINES(color_fmt, height);
		uv_meta_plane = MSM_MEDIA_ALIGN(uv_meta_stride *
			uv_meta_scanlines, 4096);
		size = (y_ubwc_plane + uv_ubwc_plane + y_meta_plane +
			uv_meta_plane);
		size = MSM_MEDIA_ALIGN(size, 4096);
	} else {
		size = VENUS_BUFFER_SIZE(color_fmt, width, height);
	}
invalid_input:
	return size;
}

static __inline__ unsigned int VENUS_VIEW2_OFFSET(
	int color_fmt, int width, int height)
{
	unsigned int offset = 0;
	unsigned int y_plane, uv_plane, y_stride,
		uv_stride, y_sclines, uv_sclines;
	if (!width || !height)
		goto invalid_input;

	y_stride = VENUS_Y_STRIDE(color_fmt, width);
	uv_stride = VENUS_UV_STRIDE(color_fmt, width);
	y_sclines = VENUS_Y_SCANLINES(color_fmt, height);
	uv_sclines = VENUS_UV_SCANLINES(color_fmt, height);
	switch (color_fmt) {
	case COLOR_FMT_NV12_MVTB:
		y_plane = y_stride * y_sclines;
		uv_plane = uv_stride * uv_sclines;
		offset = y_plane + uv_plane;
		break;
	default:
		break;
	}
invalid_input:
	return offset;
}
#endif
