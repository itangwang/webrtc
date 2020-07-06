/*
 *  Copyright (c) 2020 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/desktop_capture/win/window_capturer_win_wgc.h"

#include <assert.h>
#include <memory>

#include "modules/desktop_capture/desktop_capturer.h"

namespace webrtc {

WindowCapturerWgc::WindowCapturerWgc() = default;
WindowCapturerWgc::~WindowCapturerWgc() = default;

bool WindowCapturerWgc::GetSourceList(SourceList* sources) {
  return false;
}

bool WindowCapturerWgc::SelectSource(SourceId id) {
  return false;
}

void WindowCapturerWgc::Start(Callback* callback) {
  assert(!callback_);
  assert(callback);

  callback_ = callback;
}

void WindowCapturerWgc::CaptureFrame() {
  assert(callback_);

  callback_->OnCaptureResult(Result::ERROR_TEMPORARY, nullptr);
}

// static
std::unique_ptr<DesktopCapturer> WindowCapturerWgc::CreateRawWindowCapturer(
    const DesktopCaptureOptions& options) {
  return std::unique_ptr<DesktopCapturer>(new WindowCapturerWgc());
}

}  // namespace webrtc