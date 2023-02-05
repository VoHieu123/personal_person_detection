/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "detection_responder.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include <stdio.h>
#include <stdint.h>
#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"

#define THRESH_HOLD 80u

// This dummy implementation writes person and no person scores to the error
// console. Real applications will want to take some custom action instead, and
// should implement their own versions of this function.
void RespondToDetection(int8_t person_score, int8_t no_person_score)
{
  uint8_t person_percentage = 0;

  person_percentage = uint8_t((person_score + 0x80)*100/256);
  if (person_percentage > THRESH_HOLD)
  {
    sl_led_turn_on(&sl_led_led0);
  }
  else
  {
    sl_led_turn_off(&sl_led_led0);
  }
}
