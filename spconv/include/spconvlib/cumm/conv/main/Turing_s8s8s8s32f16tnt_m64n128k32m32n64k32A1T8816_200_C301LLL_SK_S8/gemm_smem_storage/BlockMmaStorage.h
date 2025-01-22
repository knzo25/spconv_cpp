#pragma once
namespace spconvlib {
namespace cumm {
namespace conv {
namespace main {
namespace Turing_s8s8s8s32f16tnt_m64n128k32m32n64k32A1T8816_200_C301LLL_SK_S8 {
namespace gemm_smem_storage {
struct BlockMmaStorage {
  tv::alignedarray<int8_t, 4096, 16> smem_A;
  tv::alignedarray<int8_t, 8192, 16> smem_B;
};
} // namespace gemm_smem_storage
} // namespace Turing_s8s8s8s32f16tnt_m64n128k32m32n64k32A1T8816_200_C301LLL_SK_S8
} // namespace main
} // namespace conv
} // namespace cumm
} // namespace spconvlib