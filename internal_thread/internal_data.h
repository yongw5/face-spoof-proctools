#ifndef FACE_SPOOF_PROCTOOLS_INTERNAL_THREAD_INTERNAL_DATA_H_
#define FACE_SPOOF_PROCTOOLS_INTERNAL_THREAD_INTERNAL_DATA_H_

#include <atomic>
#include <opencv2/opencv.hpp>
#include "utils/bounded_blocking_queue.h"

using EncodedImgVec = std::vector<std::vector<unsigned char>>;
using CVMatQueue = BoundedBlockingQueue<cv::Mat>;
using EncodedImgVecPair = std::pair<EncodedImgVec, EncodedImgVec>;

enum Action { DISPLAY_ONLY, STOP, NEXT };
using DisplayAction = std::atomic<Action>;

#endif  // FACE_SPOOF_PROCTOOLS_INTERNAL_THREAD_INTERNAL_DATA_H_
