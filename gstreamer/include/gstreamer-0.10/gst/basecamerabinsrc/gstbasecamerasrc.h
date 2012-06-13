/*
 * GStreamer
 * Copyright (C) 2010 Texas Instruments, Inc
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_BASE_CAMERA_SRC_H__
#define __GST_BASE_CAMERA_SRC_H__

#ifndef GST_USE_UNSTABLE_API
#warning "GstBaseCameraSrc is unstable API and may change in future."
#warning "You can define GST_USE_UNSTABLE_API to avoid this warning."
#endif

#include <gst/gst.h>
#include <gst/gstbin.h>
#include <gst/interfaces/photography.h>
#include <gst/interfaces/colorbalance.h>
#include "gstcamerabin-enum.h"
#include "gstcamerabinpreview.h"

G_BEGIN_DECLS
#define GST_TYPE_BASE_CAMERA_SRC \
  (gst_base_camera_src_get_type())
#define GST_BASE_CAMERA_SRC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_BASE_CAMERA_SRC,GstBaseCameraSrc))
#define GST_BASE_CAMERA_SRC_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_BASE_CAMERA_SRC, GstBaseCameraSrcClass))
#define GST_BASE_CAMERA_SRC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_BASE_CAMERA_SRC,GstBaseCameraSrcClass))
#define GST_IS_BASE_CAMERA_SRC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_BASE_CAMERA_SRC))
#define GST_IS_BASE_CAMERA_SRC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_BASE_CAMERA_SRC))
#define GST_BASE_CAMERA_SRC_CAST(obj) \
  ((GstBaseCameraSrc *) (obj))
GType gst_base_camera_src_get_type (void);

typedef struct _GstBaseCameraSrc GstBaseCameraSrc;
typedef struct _GstBaseCameraSrcClass GstBaseCameraSrcClass;

#define GST_BASE_CAMERA_SRC_VIEWFINDER_PAD_NAME "vfsrc"
#define GST_BASE_CAMERA_SRC_IMAGE_PAD_NAME "imgsrc"
#define GST_BASE_CAMERA_SRC_VIDEO_PAD_NAME "vidsrc"

#define GST_BASE_CAMERA_SRC_PREVIEW_MESSAGE_NAME "preview-image"

/**
 * GstBaseCameraSrc:
 */
struct _GstBaseCameraSrc
{
  GstBin parent;

  GstCameraBinMode mode;

  gboolean capturing;
  GMutex *capturing_mutex;

  /* Preview convert pipeline */
  GstCaps *preview_caps;
  gboolean post_preview;
  GstElement *preview_filter;
  GstCameraBinPreviewPipelineData *preview_pipeline;
  gboolean preview_filter_changed;

  /* Resolution of the buffers configured to camerabin */
  gint width;
  gint height;

  gfloat zoom;
  gfloat max_zoom;

  gpointer _gst_reserved[GST_PADDING_LARGE];
};


/**
 * GstBaseCameraSrcClass:
 * @construct_pipeline: construct pipeline must be implemented by derived class
 * @setup_pipeline: configure pipeline for the chosen settings
 * @set_zoom: set the zoom
 * @set_mode: set the mode
 */
struct _GstBaseCameraSrcClass
{
  GstBinClass parent;

  /* construct pipeline must be implemented by derived class */
  gboolean    (*construct_pipeline)  (GstBaseCameraSrc *self);

  /* optional */
  gboolean    (*setup_pipeline)      (GstBaseCameraSrc *self);

  /* set the zoom */
  void        (*set_zoom)            (GstBaseCameraSrc *self, gfloat zoom);

  /* set the mode */
  gboolean    (*set_mode)            (GstBaseCameraSrc *self,
                                      GstCameraBinMode mode);

  /* set preview caps */
  gboolean    (*set_preview)         (GstBaseCameraSrc *self,
                                      GstCaps *preview_caps);

  /* */
  GstCaps *   (*get_allowed_input_caps) (GstBaseCameraSrc * self);

  void (*private_start_capture) (GstBaseCameraSrc * src);
  void (*private_stop_capture) (GstBaseCameraSrc * src);
  gboolean (*start_capture) (GstBaseCameraSrc * src);
  void (*stop_capture) (GstBaseCameraSrc * src);

  gpointer _gst_reserved[GST_PADDING_LARGE];
};


#define MIN_ZOOM 1.0f
#define MAX_ZOOM 10.0f
#define ZOOM_1X MIN_ZOOM

GstPhotography * gst_base_camera_src_get_photography (GstBaseCameraSrc *self);
GstColorBalance * gst_base_camera_src_get_color_balance (GstBaseCameraSrc *self);

gboolean gst_base_camera_src_set_mode (GstBaseCameraSrc *self, GstCameraBinMode mode);
void gst_base_camera_src_setup_zoom (GstBaseCameraSrc * self);
void gst_base_camera_src_setup_preview (GstBaseCameraSrc * self, GstCaps * preview_caps);
GstCaps * gst_base_camera_src_get_allowed_input_caps (GstBaseCameraSrc * self);
void gst_base_camera_src_finish_capture (GstBaseCameraSrc *self);


void gst_base_camera_src_post_preview (GstBaseCameraSrc *self, GstBuffer * buf);
// XXX add methods to get/set img capture and vid capture caps..

#endif /* __GST_BASE_CAMERA_SRC_H__ */
