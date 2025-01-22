#pragma once
#include <spconvlib/cumm/common/TensorViewNVRTC.h>
#include <spconvlib/cumm/common/GemmBasicKernel.h>
#include <spconvlib/cumm/gemm/main/Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1/inpitera/maskiter/PitchLinearWarpRaked.h>
#include <spconvlib/cumm/gemm/main/Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1/mma/mma_ns_sa/layout/VoltaTensorOpCrosswise.h>
namespace spconvlib {
namespace cumm {
namespace gemm {
namespace main {
namespace Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1 {
namespace mma {
namespace mma_ns_sa {
using TensorViewNVRTC = spconvlib::cumm::common::TensorViewNVRTC;
using GemmBasicKernel = spconvlib::cumm::common::GemmBasicKernel;
using ThreadMap = spconvlib::cumm::gemm::main::Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1::inpitera::maskiter::PitchLinearWarpRaked;
using Layout = spconvlib::cumm::gemm::main::Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1::mma::mma_ns_sa::layout::VoltaTensorOpCrosswise;
struct VoltaSmemTileIteratorCrosswise {
  tv::array<tv::half_t, 4> * pointers_[2];
  __forceinline__ __device__  VoltaSmemTileIteratorCrosswise(int stride, tv::half_t * ptr, int thread_id)   {
    auto layout = Layout(stride);
    auto thread_offset_base = ThreadMap::initial_offset(thread_id);
    // int offs[2];
    TV_PRAGMA_UNROLL
    for (int i = 0; i < 2; ++i) {
        pointers_[i] = reinterpret_cast<tv::array<tv::half_t, 4> *>(
            ptr + layout(thread_offset_base[0] + i * 8,
                        thread_offset_base[1]));
    }
  }
  __forceinline__ __device__ void tile_increment(int num_tile)   {
    TV_PRAGMA_UNROLL
    for (int i = 0; i < 2; ++i) {
        pointers_[i] +=
            num_tile * 8192 / 4;
    }
  }
  __forceinline__ __device__ VoltaSmemTileIteratorCrosswise & operator++()   {
    TV_PRAGMA_UNROLL
    for (int i = 0; i < 2; ++i) {
        pointers_[i] += 8192 / 4;
    }
    return *this;
  }
  __forceinline__ __device__ void store_with_pointer_offset(tv::array<tv::half_t, 32, 0> const& frag, int32_t pointer_offset)   {
    const tv::array<tv::half_t, 4> * frag_ptr = reinterpret_cast<const tv::array<tv::half_t, 4> *>(&frag);
    int32_t vec_pointer_offset = pointer_offset / 4;
    TV_PRAGMA_UNROLL
    for (int s = 0; s < 4; ++s) {
        // TODO remove this
        tv::array<tv::half_t, 4> * access_ptr = pointers_[(s & 1) ^ ((s >> 1) & 1)];
        // check next tile
        access_ptr += 16 * (s / 2);
        TV_PRAGMA_UNROLL
        for (int c = 0; c < 1; ++c) {
            TV_PRAGMA_UNROLL
            for (int sub = 0; sub < 2; ++sub) {
                int idx =
                    sub + 2 * (c + s * 1);
                int access_offset =
                    c * 32 * 256 / 4 +
                    vec_pointer_offset + sub * 256;
                // the right part (next k iter) should be put to next k block.
                // access_offset += sub * 256;
                access_ptr[access_offset] = frag_ptr[idx];
            }
        }
    }
  }
  __forceinline__ __device__ void store(tv::array<tv::half_t, 32, 0> const& frag)   {
    store_with_pointer_offset(frag, 0);
  }
};
} // namespace mma_ns_sa
} // namespace mma
} // namespace Volta_f16f16f16f16f16ttt_m256n128k32m64n64k32A1T884_200_S1
} // namespace main
} // namespace gemm
} // namespace cumm
} // namespace spconvlib