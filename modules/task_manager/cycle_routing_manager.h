/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "modules/common/status/status.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/task_manager/proto/task_manager.pb.h"

namespace apollo {
namespace task_manager {

class CycleRoutingManager {
 public:
  CycleRoutingManager();

  /**
   * @brief module initialization function
   * @return initialization status
   */
  common::Status Init(const task_manager::CycleRoutingTask& cycle_routing_task);

  /**
   * @brief check if the vehicle reaches the destination
   * @return false/true
   */
  bool CheckIfReachDestination(const localization::Pose &pose);

  /**
   * @brief get remaining cycle number
   * @return remaining cycle number
   */
  int GetCycle() const;

  /**
   * @brief make cycle number minus 1
   * @return void
   */
  void MinusCycle();

  /**
   * @brief destructor
   */
  virtual ~CycleRoutingManager() = default;

 private:
  int cycle_;
  int waypoint_num_;
  apollo::common::PointENU begin_point_;
  apollo::common::PointENU end_point_;
  apollo::common::PointENU last_point_;
};

}  // namespace task_manager
}  // namespace apollo
