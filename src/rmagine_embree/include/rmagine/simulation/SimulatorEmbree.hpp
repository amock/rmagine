/*
 * Copyright (c) 2025, University Osnabrück. 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University Osnabrück nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL University Osnabrück BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * 
 * @brief Contains @link rmagine::SimulatorEmbree SimulatorEmbree @endlink
 *
 * @date 03.01.2025
 * @author Alexander Mock
 * 
 * @copyright Copyright (c) 2025, University Osnabrück. All rights reserved.
 * This project is released under the 3-Clause BSD License.
 * 
 */

#ifndef RMAGINE_SIMULATION_SIMULATOR_EMBREE_HPP
#define RMAGINE_SIMULATION_SIMULATOR_EMBREE_HPP

#include <rmagine/map/EmbreeMap.hpp>
#include <rmagine/types/Memory.hpp>
#include <rmagine/types/sensor_models.h>
#include <rmagine/simulation/SimulationResults.hpp>

namespace rmagine
{

class SimulatorEmbree {
public:
  SimulatorEmbree();
  SimulatorEmbree(EmbreeMapPtr map);
  virtual ~SimulatorEmbree();

  void setMap(EmbreeMapPtr map);

  void setTsb(const MemoryView<Transform, RAM>& Tsb);
  void setTsb(const Transform& Tsb);

  inline EmbreeMapPtr map() const 
  {
      return m_map;
  }

  protected:
  EmbreeMapPtr m_map;
  
  RTCRayQueryContext  m_context;
  
  Memory<Transform, RAM> m_Tsb;
};

} // namespace rmagine


#endif // RMAGINE_SIMULATION_SIMULATOR_EMBREE_HPP