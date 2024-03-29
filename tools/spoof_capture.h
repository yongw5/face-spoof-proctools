#ifndef FACE_SPOOF_PROCTOOLS_TOOLS_SPOOF_CAPTURE_H_
#define FACE_SPOOF_PROCTOOLS_TOOLS_SPOOF_CAPTURE_H_

#include <opencv2/opencv.hpp>
#include "unit/display_capture_unit.h"
#include "unit/encode_dumping_unit.h"
#include "unit/loading_decode_unit.h"

class Background;
class SpoofCapture {
 public:
  SpoofCapture(const std::string& src, const std::string& dst, int begin,
               int end, int batch_size, int queue_capacity,
               Background* background = nullptr);
  ~SpoofCapture();
  void Start(int display_delay, int capture_delay, int camera_id,
             const cv::Size& frame_size = cv::Size(0, 0));
  void StartDisplay(int display_delay);
  void Stop();

 private:
  std::atomic_bool loading_;
  CVMatQueue in_;
  CVMatQueue out_;
  LoadingDecodeUnit loading_decode_unit_;
  DisplayCaptureUnit display_capture_unit_;
  EncodeDumpingUnit encode_dumping_unit_;
};

#endif  // FACE_SPOOF_PROCTOOLS__FACE_SPOOF_PROCTOOLS_H_
