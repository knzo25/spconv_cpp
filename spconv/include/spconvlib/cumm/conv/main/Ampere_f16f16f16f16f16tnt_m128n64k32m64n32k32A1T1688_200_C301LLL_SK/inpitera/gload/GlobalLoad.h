#pragma once
namespace spconvlib {
namespace cumm {
namespace conv {
namespace main {
namespace Ampere_f16f16f16f16f16tnt_m128n64k32m64n32k32A1T1688_200_C301LLL_SK {
namespace inpitera {
namespace gload {
struct GlobalLoad {
  template <typename Frag>
  __forceinline__ __device__ static void run(Frag & frag, void const* ptr, bool pred)   {
    
    uint32_t* frag_ptr = reinterpret_cast<uint32_t*>(&frag);
    #if (CUDA_VERSION >= 11040 && (__CUDA_ARCH__ >= 750))
      asm volatile (
          "{\n"
          "  mov.b32 %0,%0;\n"
          "  mov.b32 %1,%1;\n"
          "  mov.b32 %2,%2;\n"
          "  mov.b32 %3,%3;\n"
          "  .reg .pred p;\n"
          "  setp.ne.b32 p,%4,0;\n"
          "  @p ld.global.L2::128B.v4.b32 {%0, %1, %2, %3},[%5];\n"
          "}\n"
          : "+r"(frag_ptr[0]), "+r"(frag_ptr[1]), "+r"(frag_ptr[2]), "+r"(frag_ptr[3])
          : "r"((int)pred), "l"(ptr)
      );
    #else
      asm volatile (
          "{\n"
          "  mov.b32 %0,%0;\n"
          "  mov.b32 %1,%1;\n"
          "  mov.b32 %2,%2;\n"
          "  mov.b32 %3,%3;\n"
          "  .reg .pred p;\n"
          "  setp.ne.b32 p,%4,0;\n"
          "  @p ld.global.v4.b32 {%0, %1, %2, %3},[%5];\n"
          "}\n"
          : "+r"(frag_ptr[0]), "+r"(frag_ptr[1]), "+r"(frag_ptr[2]), "+r"(frag_ptr[3])
          : "r"((int)pred), "l"(ptr)
      );
    #endif
  }
};
} // namespace gload
} // namespace inpitera
} // namespace Ampere_f16f16f16f16f16tnt_m128n64k32m64n32k32A1T1688_200_C301LLL_SK
} // namespace main
} // namespace conv
} // namespace cumm
} // namespace spconvlib